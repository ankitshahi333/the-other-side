#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITION.hpp"
#include "Game.hpp"
#include <vector>

class Logs
{

    public:
        Logs ( GameDataRef data ); 

        void spawnLogsLeft ( float Lane ) ;
        void spawnLogsRight ( float Lane ) ;
        void moveLogsLeft ( float deltaTime ) ;
        void moveLogsRight ( float deltaTime ) ;
        int getXvelocity ( ) ; 
        void drawLogs ( ) ;

        const std::vector< sf::Sprite > &getLogsSprite ( ) const;
    
    private:
        GameDataRef _data;

        std::vector< sf::Sprite > _LogsSprites;
        int XlogVelocity;
};