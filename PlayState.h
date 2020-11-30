#pragma once

#include <SFML/Graphics.hpp>
#include "Headers/Game.hpp"
#include "Headers/State.hpp"

class PlayState :
    public State
{
public:
    PlayState(GameDataRef data);

    void Init();

    void HandleInput();
    void Update(float deltaTime);
    void Draw(float deltaTime);

private:

    GameDataRef _data;
    std::vector<sf::Sprite> _vehicles;
    sf::Sprite _background;
    sf::Clock _clock;
    sf::Text _score;
};

