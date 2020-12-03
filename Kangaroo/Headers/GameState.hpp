#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "State.hpp"
#include "Vehicle.hpp"
#include "Logs.hpp"
#include "Kangaroo.hpp"

class GameState : public State
{
public:
    GameState(GameDataRef);

    void Init();

    void HandleInput();
    void Update(float deltaTime);
    void Draw(float deltaTime);

private:
    GameDataRef _data;
    sf::Sprite _background;

    sf::Clock clock;
    sf::Clock clock2;

    Vehicle* vehicleLeft;
    Vehicle* vehicleRight;

    Logs* logsLeft;
    Logs* logsRight;

    Kangaroo* kangaroo;

};