#include <iostream>
#include <sstream>

#include "../Headers/SplashState.hpp"
#include "../Headers/MainMenuState.hpp"
#include "../Headers/DEFINITION.hpp"

SplashState::SplashState(GameDataRef data) : _data(data)
{

}

void SplashState::Init()
{

    _data->assets.LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

}

void SplashState::HandleInput()
{
    sf::Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _data->window.close();
        }
    }
}

void SplashState::Update(float deltaTime)
{

    if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_DURATION)
        _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
}

void SplashState::Draw(float deltaTime)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}