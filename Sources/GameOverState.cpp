#include <iostream>
#include <fstream>

#include "../Headers/GameOverState.hpp"
#include "../Headers/GameState.hpp"
#include "../Headers/DEFINITION.hpp"
#include "../Headers/MainMenuState.hpp"

GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)     //assigns value of data to _data when constructor is called
{

}

void GameOverState::Init()
{
    //best score check
    std::ifstream readFile;
    readFile.open(BEST_SCORE_FILEPATH);
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> _best;
        }
    }
    readFile.close();

    std::ofstream writeFile(BEST_SCORE_FILEPATH);
    if (writeFile.is_open())
    {
        if (_score > _best)
            _best = _score;

        writeFile << _best;
    }
    writeFile.close();

    //Texture loading section
    _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
    _data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

    //FONT loading section
    _data->assets.LoadFont("Game Over", GAME_OVER_TEXT_FILEPATH);

    //Setting texture for sprites
    _background.setTexture(_data->assets.GetTexture("Game Over Background"));
    _gameOverTitle.setTexture(_data->assets.GetTexture("Game Over Title"));
    _gameOverBody.setTexture(_data->assets.GetTexture("Game Over Body"));


    //gameOver assets
    _gameOverTitle.setPosition(WINDOW_WIDTH / 2 - _gameOverTitle.getGlobalBounds().width / 2,
        WINDOW_HEIGHT / 2 - _gameOverTitle.getGlobalBounds().height * 4);

    _gameOverBody.setPosition(WINDOW_WIDTH / 2 - _gameOverTitle.getGlobalBounds().width / 2,
        WINDOW_HEIGHT / 2 - _gameOverBody.getGlobalBounds().height);


    //Setting font for gameoverstate texts
    _playAgain.setFont(_data->assets.GetFont("Game Over"));
    _backToMainMenu.setFont(_data->assets.GetFont("Game Over"));
    _scoreText.setFont(_data->assets.GetFont("Game Over"));
    _bestText.setFont(_data->assets.GetFont("Game Over"));


    _playAgain.setCharacterSize(28);
    _playAgain.setFillColor(sf::Color::Red);
    _playAgain.setString("Press SPACE to play again");
    _playAgain.setPosition(WINDOW_WIDTH / 2 - _gameOverTitle.getGlobalBounds().width / 1.5, 360);

    _backToMainMenu.setCharacterSize(28);
    _backToMainMenu.setFillColor(sf::Color::Red);
    _backToMainMenu.setString("Press ESC to go back to MAIN MENU");
    _backToMainMenu.setPosition(WINDOW_WIDTH / 2 - _gameOverTitle.getGlobalBounds().width, 450);

    _scoreText.setCharacterSize(48);
    _scoreText.setFillColor(sf::Color::Red);
    _scoreText.setString(std::to_string(_score));
    _scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 - 110);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

    _bestText.setCharacterSize(48);
    _bestText.setFillColor(sf::Color::Red);
    _bestText.setString(std::to_string(_best));
    _bestText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 - 45);
    _bestText.setOrigin(_bestText.getGlobalBounds().width / 2, _bestText.getGlobalBounds().height / 2);
}

void GameOverState::HandleInput()
{
    sf::Event event;

    while (_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
            _data->window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        _data->machine.AddState(StateRef(new GameState(_data)), true);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _data->machine.AddState(StateRef(new MainMenuState(_data)), true);

}

void GameOverState::Update(float deltaTime)
{

}

void GameOverState::Draw(float deltaTime)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_gameOverTitle);
    _data->window.draw(_gameOverBody);
    _data->window.draw(_playAgain);
    _data->window.draw(_backToMainMenu);
    _data->window.draw(_scoreText);
    _data->window.draw(_bestText);
    _data->window.display();
}
