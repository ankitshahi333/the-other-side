#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

class SplashState: public State 
{
    public:
        SplashState ( GameDataRef data ) ;

        void Init ( );

        void HandleInput ( );
        void Update ( float deltaTime );
        void Draw ( float deltaTime );

    private:

        GameDataRef _data;

        sf::Sprite _background;

        sf::Clock _clock;

};