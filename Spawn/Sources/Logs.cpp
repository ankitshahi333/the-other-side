#include "../Headers/Logs.hpp"

int LogslaneSelect ( int lane );

Logs::Logs ( GameDataRef data ) : _data ( data )
{

}

void Logs::spawnLogsLeft ( float Lane)
{
    int SelectedLane =  LogslaneSelect ( Lane );
    sf::Sprite log( _data->assets.GetTexture ( "Car Sprite" ) ) ;
    log.setScale ( 5 , 1.0 );
    log.setPosition ( -100 , SelectedLane );
    _LogsSprites.push_back ( log ); 
}

void Logs::spawnLogsRight ( float Lane ) 
{
    int SelectedLane =  LogslaneSelect ( Lane );
    sf::Sprite log( _data->assets.GetTexture ( "Car Sprite" ) ) ;
    log.setScale ( 5 , 1.0 );
    log.setPosition ( WINDOW_WIDTH , SelectedLane );
    _LogsSprites.push_back ( log ); 
}

//select Lane
int LogslaneSelect (int Lane){

    switch ( Lane )
    {
    case 0:
        return 55;
    case 3:
        return 100;
    case 1:
        return 145;
    case 4:
        return 190;
    default:
        return 100;
    }

}

void Logs::moveLogsLeft ( float deltaTime )
{
    for(unsigned short int i = 0; i < _LogsSprites.size(); i++){
        
        //delete object after it crosses the screen border
        float LogsXcor = _LogsSprites.at( i ).getPosition().x;
        float leftbound = WINDOW_WIDTH + _LogsSprites.at(i).getGlobalBounds( ).width;
        if( LogsXcor > leftbound ){
            _LogsSprites.erase( _LogsSprites.begin() + i);
        }
        //if not crossed the screen, move Logs
        else
        {
            float movement = 100 * deltaTime;
            _LogsSprites.at(i).move (movement, 0);
        }
        
    }
}

void Logs::moveLogsRight ( float deltaTime )
{
    for(unsigned short int i = 0; i < _LogsSprites.size(); i++){
        
        //delete object after it crosses the screen border
        float LogsXcor = _LogsSprites.at( i ).getPosition().x;
        float rightbound = -_LogsSprites.at(i).getGlobalBounds( ).width;

        if( LogsXcor < rightbound ){
            _LogsSprites.erase( _LogsSprites.begin() + i);
        }
        //if not crossed the screen, move Logs
        else
        {
            float movement = 100 * deltaTime;
            _LogsSprites.at(i).move (-movement, 0);
        }
        
    }
}

void Logs::drawLogs ( )
{
    for(unsigned short int i = 0; i < _LogsSprites.size(); i++){
        _data->window.draw ( _LogsSprites.at( i ) );
    }
}

//returns LogsSprite properties to check collision
const std::vector<sf::Sprite> &Logs::getLogsSprite ( ) const{
    return _LogsSprites;
}