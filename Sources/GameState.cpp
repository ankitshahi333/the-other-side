#include "../Headers/GameState.hpp"
#include "../Headers/DEFINITION.hpp"
#include <iostream>
#include <sstream>

GameState::GameState(GameDataRef data) : _data(data)      //assigns value of data to _data when constructor is called
{

}

void GameState::Init()
{

    //Texture loading section
    _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Raft Sprite", RAFT_SPRITE_FILEPATH);
    _data->assets.LoadTexture("LSCar Sprite", LEFT_SPAWN_CAR_FILEPATH);
    _data->assets.LoadTexture("RSCar Sprite", RIGHT_SPAWN_CAR_FILEPATH);
    _data->assets.LoadTexture("Kangaroo Sprite", KANGAROO_FILEPATH);

    //Adding the score text
    if (!font.loadFromFile(FONT_FILEPATH)) {
        std::cout << "Error opening font.";
    }
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setPosition(5, 2);


    //Setting texture for sprites
    _background.setTexture(_data->assets.GetTexture("Game Background"));

    //object creation section
    vehicleLeft = new Vehicle(_data);
    vehicleRight = new Vehicle(_data);
    logsLeft = new Logs(_data);
    logsRight = new Logs(_data);
    kangaroo = new Kangaroo(_data);

    //Initial position of kangaroo
    initialYPosition = kangaroo->getPosition();
}

void GameState::HandleInput()
{

    sf::Event event;

    while (_data->window.pollEvent(event)) {

        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }

    }

}

void GameState::Update(float deltaTime)
{
    //Checking the y position of the kangaroo
    float yPositionOfKangaroo = kangaroo->getPosition();
    if (yPositionOfKangaroo <= 0) {
        addScore();
    }

    vehicleLeft->moveVehicleLeft(deltaTime);
    vehicleRight->moveVehicleRight(deltaTime);

    logsLeft->moveLogsLeft(deltaTime);
    logsRight->moveLogsRight(deltaTime);
    kangaroo->update(deltaTime);

    if (clock.getElapsedTime().asSeconds() > CAR_SPAWN_FREQUENCY) {

        int LRlane = rand() % 3;       //LRLane :  choose Left Random Lane
        vehicleLeft->spawnVehicleLeft(LRlane);

        int RRLane = 3 + rand() % 2;   //RRLane :  choose Right Random Lane
        vehicleRight->spawnVehicleRight(RRLane);
        clock.restart();
    }

    if (clock2.getElapsedTime().asSeconds() > 4.0f) {

        int LLRlane = rand() % 2;       //LRLane :  choose Left Random Lane
        logsLeft->spawnLogsLeft(LLRlane);

        int LRRLane = 3 + rand() % 2;   //RRLane :  choose Right Random Lane
        logsRight->spawnLogsRight(LRRLane);
        clock2.restart();
    }


}

void GameState::Draw(float deltaTime)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(scoreText);
    kangaroo->drawKangaroo();
    vehicleLeft->drawVehicle();
    vehicleRight->drawVehicle();
    logsLeft->drawLogs();
    logsRight->drawLogs();
    _data->window.display();
}

void GameState::addScore()
{
    //Updating score
    _score++;
    std::string newScore = "Score: " + std::to_string(_score);
    scoreText.setString(newScore);

    //Replace Kangaroo
    kangaroo->setPosition(initialYPosition);
}


