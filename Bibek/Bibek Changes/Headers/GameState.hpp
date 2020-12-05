#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include "State.hpp"
#include "Vehicle.hpp"
#include "Logs.hpp"
#include "Kangaroo.hpp"
#include "Collision.hpp"

class GameState : public State
{
public:
    GameState(GameDataRef);

    void Init();

    void HandleInput();
    void Update(float deltaTime);
    void Draw(float deltaTime);
    void DetectCollision ( float deltaTime ); 
    void addScore ( );

private:
    GameDataRef _data;
    sf::Sprite _background;

    sf::Clock clock;
    sf::Clock clock2;   // to control log spawn 
    sf::Clock clock3;   // to quantize kangaroo movement

    Vehicle* vehicleLeft;
    Vehicle* vehicleRight;

    Logs* logsLeft;
    Logs* logsRight;

    Kangaroo* kangaroo;

    Collision collision;

    sf::SoundBuffer _killSoundBuffer;
    sf::Sound _killSound;

    int _gameState;

    //scoring assets
    sf::Text scoreText;
    sf::Font font;
    int _score;
    float initialYPosition; // Initial y position of kangaroo
    

};