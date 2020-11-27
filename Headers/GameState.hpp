#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "State.hpp"

class GameState: public State
{
    public:
        GameState ( GameDataRef );

        void Init ( );

        void HandleInput ( );
        void Update ( float deltaTime );
        void Draw ( float deltaTime );

    private:
        GameDataRef _data;
        
        sf::Clock clock;

};