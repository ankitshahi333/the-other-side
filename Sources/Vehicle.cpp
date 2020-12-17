#include "../Headers/Vehicle.hpp"

int laneSelect(int lane);

Vehicle::Vehicle(GameDataRef data) : _data(data)
{

}

void Vehicle::spawnVehicleLeft(float Lane)
{
    int SelectedLane = laneSelect(Lane);
    sf::Sprite car(_data->assets.GetTexture("LSCar Sprite"));
    car.setScale(0.65f, 0.732f);
    car.setPosition(0 - car.getGlobalBounds().width, SelectedLane);
    _vehicleSprites.push_back(car);
}

void Vehicle::spawnVehicleRight(float Lane)
{
    int SelectedLane = laneSelect(Lane);
    sf::Sprite car(_data->assets.GetTexture("RSCar Sprite"));
    car.setScale(0.65f, 0.65f);
    car.setPosition(WINDOW_WIDTH + car.getGlobalBounds().width, SelectedLane);
    _vehicleSprites.push_back(car);
}

//select Lane
int laneSelect(int Lane) {

    switch (Lane)
    {
    case 0:
        return 455;
    case 3:
        return 410;
    case 1:
        return 365;
    case 4:
        return 320;
    case 2:
        return 275;
    default:
        return 455;
    }

}

void Vehicle::moveVehicleLeft(float deltaTime)
{
    for (unsigned short int i = 0; i < _vehicleSprites.size(); i++) {

        //delete object after it crosses the screen border
        float vehicleXcor = _vehicleSprites.at(i).getPosition().x;
        float leftbound = WINDOW_WIDTH + _vehicleSprites.at(i).getGlobalBounds().width;
        if (vehicleXcor > leftbound)
            _vehicleSprites.erase(_vehicleSprites.begin() + i);

        //if not crossed the screen, move vehicle
        else
        {
            float movement = 100 * deltaTime;
            _vehicleSprites.at(i).move(movement, 0);
        }
    }
}

void Vehicle::moveVehicleRight(float deltaTime)
{
    for (unsigned short int i = 0; i < _vehicleSprites.size(); i++)
    {
        //delete object after it crosses the screen border
        float vehicleXcor = _vehicleSprites.at(i).getPosition().x;
        float rightbound = 0 - _vehicleSprites.at(i).getGlobalBounds().width;

        if (vehicleXcor < rightbound)
            _vehicleSprites.erase(_vehicleSprites.begin() + i);

        //if not crossed the screen, move vehicle
        else
        {
            float movement = 100 * deltaTime;
            _vehicleSprites.at(i).move(-movement, 0);
        }
    }
}

void Vehicle::drawVehicle()
{
    for (unsigned short int i = 0; i < _vehicleSprites.size(); i++)
    {
        _data->window.draw(_vehicleSprites.at(i));
    }
}

//returns vehiclesprite properties to check collision
const std::vector<sf::Sprite>& Vehicle::getVehicleSprite() const
{
    return _vehicleSprites;
}