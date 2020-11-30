#include "PlayState.h"
#include "Headers/DEFINITION.hpp"

PlayState::PlayState(GameDataRef data) : _data(data)
{
    printf("Entered play state");
    srand(time(NULL));
}

void PlayState::Init()
{
	_data->assets.LoadTexture("Play State Background", PLAY_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.GetTexture("Play State Background"));
}

void PlayState::HandleInput()
{
    sf::Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _data->window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.KeyPressed == sf::Keyboard::Up) {
                //Move forward
            }
            else if (event.KeyPressed == sf::Keyboard::Down) {
                //Move Backward
            } 
            else if(event.KeyPressed == sf::Keyboard::Right) {
                //Move to the right
            }
            else if(event.KeyPressed == sf::Keyboard::Left) {
                //Move to the left
            }
            
        }
    }

}

void PlayState::Update(float deltaTime)
{
    if (_clock.getElapsedTime().asSeconds() > 1) {
        Spawn();
    }
}

void PlayState::Draw(float deltaTime)
{
    _data->window.clear();
    //draw here
    _data->window.draw(_background);

    _data->window.display();
}

void Spawn() {
    int row = rand() % 5 + 1;
    printf("%d\n", row);
}