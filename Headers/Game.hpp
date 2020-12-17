#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>
#include "DEFINITION.hpp"
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
    Game(int width, int height, std::string title);

private:

    const float deltaTime = 1.0f / GAME_FRAME_RATE;
    sf::Clock _clock;

    GameDataRef _data = std::make_shared< GameData >();

    void Run();

};