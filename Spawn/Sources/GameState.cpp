#include "../Headers/GameState.hpp"
#include "../Headers/DEFINITION.hpp"
#include <iostream>
#include <sstream>

GameState::GameState ( GameDataRef data ) : _data ( data )      //assigns value of data to _data when constructor is called
{

}

void GameState::Init ( )
{

        //Texture loading section
        _data->assets.LoadTexture ( "Game Background" , GAME_BACKGROUND_FILEPATH ); 
        _data->assets.LoadTexture ( "Car Sprite" , CAR_SPRITE_FILEPATH );


        //Setting texture for sprites
        _background.setTexture ( _data->assets.GetTexture ( "Game Background" ) );

        //object creation section
        vehicleLeft = new Vehicle ( _data );
        vehicleRight = new Vehicle ( _data );
        logsLeft = new Logs ( _data );
        logsRight = new Logs ( _data ); 

}

void GameState::HandleInput ( )
{

    sf::Event event;
    
    while( _data->window.pollEvent ( event ) ){
        
        if( sf::Event::Closed == event.type ){
            _data->window.close ( );
        }

    }

}

void GameState::Update ( float deltaTime)
{
    vehicleLeft->moveVehicleLeft ( deltaTime );
    vehicleRight->moveVehicleRight ( deltaTime );

    logsLeft->moveLogsLeft ( deltaTime );
    logsRight->moveLogsRight ( deltaTime );

    if ( clock.getElapsedTime ( ).asSeconds ( ) > CAR_SPAWN_FREQUENCY ){

        int LRlane = rand () % 3;       //LRLane :  choose Left Random Lane
        vehicleLeft->spawnVehicleLeft ( LRlane );

        int RRLane = 3 + rand () % 2;   //RRLane :  choose Right Random Lane
        vehicleRight->spawnVehicleRight ( RRLane );
        clock.restart ( );
    }

    if ( clock2.getElapsedTime ( ).asSeconds ( ) > 4.0f ){

        int LLRlane = rand () % 2;       //LRLane :  choose Left Random Lane
        logsLeft->spawnLogsLeft ( LLRlane );

        int LRRLane = 3 + rand () % 2;   //RRLane :  choose Right Random Lane
        logsRight->spawnLogsRight ( LRRLane );
        clock2.restart ( );
    }

    
} 

void GameState::Draw ( float deltaTime)
{
    _data->window.clear ( );
    _data->window.draw ( _background );
    vehicleLeft->drawVehicle ( ) ;
    vehicleRight->drawVehicle ( ) ;
    logsLeft->drawLogs ( );
    logsRight->drawLogs ( ) ;
    _data->window.display ( );
}


