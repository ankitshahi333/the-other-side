#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.hpp"
#include "State.hpp"
#include "Vehicle.hpp"
#include "Logs.hpp"
#include "Kangaroo.hpp"
#include "Collision.hpp"
#include "GameOverState.hpp"

class GameState : public State
{
public:
    GameState ( GameDataRef );

    void Init ( );
    void HandleInput ( );
    void Update( float deltaTime );
    void Draw ( float deltaTime );
    void DetectCollision ( float deltaTime ); 
    void addScore ( );

private:
    GameDataRef _data;
    sf::Sprite _background;

    sf::Clock clock;
    sf::Clock clock2;   // to control log spawn 
    sf::Clock clock3;   // to quantize kangaroo movement
    sf::Clock clock4;   // for water collision
    sf::Clock clock5;   // for Initial Ready State

    //screen objects
    Vehicle* vehicleLeft;
    Vehicle* vehicleRight;

    Logs* logsLeft;
    Logs* logsRight;

    Kangaroo* kangaroo;

    // to detect collision
    Collision collision;


    //gameplay sounds
    sf::SoundBuffer _killSoundBuffer;
    sf::Sound _killSound;

    sf::SoundBuffer _splashSoundBuffer;
    sf::Sound _splashSound;

    //current gamestate ( playing or not playing )
    int _gameState;
    int ReadyTime = 0;

    //scoring assets
    sf::Text scoreText;
    sf::Font font;
    int _score;
    float initialYPosition; // Initial y position of kangaroo

    //lives assets
    sf::Text livesLeft;
    int _lives;  

};