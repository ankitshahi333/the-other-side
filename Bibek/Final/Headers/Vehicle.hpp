#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITION.hpp"
#include "Game.hpp"
#include <vector>

class Vehicle
{

public:
    Vehicle(GameDataRef data);

    void spawnVehicleLeft ( float Lane );
    void spawnVehicleRight ( float Lane );
    void moveVehicleLeft ( float deltaTime );
    void moveVehicleRight ( float deltaTime );
    void drawVehicle ( );

    const std::vector< sf::Sprite > &getVehicleSprite( ) const;

private:
    GameDataRef _data;

    std::vector<sf::Sprite> _vehicleSprites;

};