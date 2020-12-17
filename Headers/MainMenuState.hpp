#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public State
{
public:
    MainMenuState(GameDataRef data);

    void Init();
    void HandleInput();
    void Update(float deltaTime);
    void Draw(float deltaTime);

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _title;

    //main screen buttons
    sf::Text _playText;
    sf::Text _quitText;

    //button click sound
    sf::SoundBuffer _clickSoundBuffer;
    sf::Sound _clickSound;

};