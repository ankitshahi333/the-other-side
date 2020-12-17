#include "../Headers/Logs.hpp"

int LogslaneSelect(int lane);

Logs::Logs(GameDataRef data) : _data(data)
{

}

void Logs::spawnLogsLeft(float Lane)
{
    int SelectedLane = LogslaneSelect(Lane);
    sf::Sprite log(_data->assets.GetTexture("Log Sprite"));
    //log.setScale ( 0.65f , 0.35f );
    log.setPosition(0 - log.getGlobalBounds().width, SelectedLane);
    _LogsSprites.push_back(log);
}

void Logs::spawnLogsRight(float Lane)
{
    int SelectedLane = LogslaneSelect(Lane);
    sf::Sprite log(_data->assets.GetTexture("Log Sprite"));
    //log.setScale ( 0.65f , 0.35f );
    log.setPosition(WINDOW_WIDTH + log.getGlobalBounds().width, SelectedLane);
    _LogsSprites.push_back(log);
}

//select Lane
int LogslaneSelect(int Lane) {

    switch (Lane)
    {
    case 0:
        return 45;
    case 3:
        return 90;
    case 1:
        return 135;
    case 4:
        return 180;
    default:
        return 90;
    }

}


void Logs::moveLogsLeft(float deltaTime)
{
    for (unsigned short int i = 0; i < _LogsSprites.size(); i++)
    {
        //delete object after it crosses the screen border
        float LogsXcor = _LogsSprites.at(i).getPosition().x;
        float leftbound = WINDOW_WIDTH + _LogsSprites.at(i).getGlobalBounds().width;
        if (LogsXcor > leftbound) {
            _LogsSprites.erase(_LogsSprites.begin() + i);
        }
        //if not crossed the screen, move Logs
        else
        {
            float movement = 100 * deltaTime;
            _LogsSprites.at(i).move(movement, 0);
            XlogVelocity = movement;
        }
    }
}

void Logs::moveLogsRight(float deltaTime)
{
    for (unsigned short int i = 0; i < _LogsSprites.size(); i++) {

        //delete object after it crosses the screen border
        float LogsXcor = _LogsSprites.at(i).getPosition().x;
        float rightbound = -_LogsSprites.at(i).getGlobalBounds().width;

        if (LogsXcor < rightbound) {
            _LogsSprites.erase(_LogsSprites.begin() + i);
        }
        //if not crossed the screen, move Logs
        else
        {
            float movement = 100 * deltaTime;
            _LogsSprites.at(i).move(-movement, 0);
            XlogVelocity = movement;
        }

    }
}

int Logs::getXvelocity()
{
    return XlogVelocity;
}

void Logs::drawLogs()
{
    for (unsigned short int i = 0; i < _LogsSprites.size(); i++)
    {
        _data->window.draw(_LogsSprites.at(i));
    }
}

//returns LogsSprite properties to check collision
const std::vector<sf::Sprite>& Logs::getLogsSprite() const
{
    return _LogsSprites;
}