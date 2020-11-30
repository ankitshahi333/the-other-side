#include "../Headers/GameState.hpp"
#include "../Headers/DEFINITION.hpp"

#include <iostream>
#include <sstream>

GameState::GameState ( GameDataRef data ) : _data ( data )      //assigns value of data to _data when constructor is called
{

}

void GameState::Init ( )
{

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

} 

void GameState::Draw ( float deltaTime)
{
    _data->window.clear ( );
    _data->window.display ( );
}


