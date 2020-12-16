#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "State.hpp"

class GameOverState : public State
{
    public:

        GameOverState ( GameDataRef data , int score );

        void Init ( );
        void HandleInput ( );
        void Update ( float deltaTime );
        void Draw ( float deltaTime );

    private:

        GameDataRef _data;

        //sprites
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverBody;

        //texts
        sf::Text _playAgain;
        sf::Text _backToMainMenu;

        sf::Text _scoreText;
        sf::Text _bestText;

        //score variables
        int _score;
        int _best;   //for saving high score
  

};