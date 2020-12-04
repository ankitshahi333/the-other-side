#include "../Headers/MainMenuState.hpp"
#include "../Headers/DEFINITION.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/GameState.hpp"

#include <iostream>
#include <sstream>

MainMenuState::MainMenuState ( GameDataRef data ) : _data ( data )
{

} 

void MainMenuState::Init ( )
{
    //Fonts
    _data->assets.LoadFont ( "Marker Felt" , FONT_FILEPATH );

//play button properties
    _playText.setFont ( _data->assets.GetFont ( "Marker Felt" ) );
    _playText.setString ( "Play" ) ; 
    _playText.setCharacterSize ( 45 );
    _playText.setFillColor ( sf::Color::White );
    _playText.setOrigin ( _playText.getGlobalBounds ( ).width / 2, _playText.getGlobalBounds ( ).height / 2 );
    _playText.setPosition ( WINDOW_WIDTH / 2 , 300 );

//quit button properties
    _quitText.setFont ( _data->assets.GetFont ( "Marker Felt" ) );
    _quitText.setString ( "Quit" ) ; 
    _quitText.setCharacterSize ( 45 );
    _quitText.setFillColor ( sf::Color::White );
    _quitText.setOrigin ( _quitText.getGlobalBounds ( ).width / 2, _quitText.getGlobalBounds ( ).height / 2 );
    _quitText.setPosition ( WINDOW_WIDTH / 2 , 360);


    //Sprites
    _data->assets.LoadTexture ( "Main BackGround" , MAIN_MENU_BACKGROUND_FILEPATH );
    _data->assets.LoadTexture ( "Main Title" , MAIN_MENU_TITLE_FILEPATH );

    _background.setTexture ( _data->assets.GetTexture ( "Main BackGround" ) );
    _title.setTexture ( _data->assets.GetTexture ( "Main Title" ) );

    _title.setOrigin ( _title.getGlobalBounds ( ).width / 2, _title.getGlobalBounds ( ).height / 2 );
    _title.setScale(0.75,0.75);
    _title.setPosition ( WINDOW_WIDTH / 2 , WINDOW_HEIGHT * 0.2);


}

void MainMenuState::HandleInput ( )
{
    sf::Event event;
    while ( _data->window.pollEvent ( event ) )
    {
        if ( sf::Event::Closed == event.type ) 
        {
            _data->window.close ( );
        }

        //handle cases here

        if ( _data->input.IsTextClicked ( _quitText, sf::Mouse::Left , _data->window ) )
        {
            _data->window.close ( );
        }
    
        if (_data->input.IsTextClicked(_playText, sf::Mouse::Left, _data->window))
        {
            _data->machine.AddState(StateRef(new GameState(_data)), true);
        }
    }
}

void MainMenuState::Update ( float deltaTime )
{
//playtext update
    if( _data->input.IsTextHovered ( _playText , _data->window ) )
        _playText.setFillColor ( sf::Color::Green ); 
    else
        _playText.setFillColor ( sf::Color::White );

//quittext update
    if( _data->input.IsTextHovered ( _quitText , _data->window ) )
        _quitText.setFillColor ( sf::Color::Red );  
    else
        _quitText.setFillColor ( sf::Color::White );
        


}

void MainMenuState::Draw ( float deltaTime )
{
    _data->window.clear ( );
    _data->window.draw ( _background );
    _data->window.draw ( _title );
    _data->window.draw ( _playText );
    _data->window.draw ( _quitText );
    _data->window.display ( );
}
