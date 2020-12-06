#include "../Headers/GameState.hpp"
#include "../Headers/DEFINITION.hpp"
#include <iostream>
#include <sstream>

GameState::GameState(GameDataRef data) : _data(data)      //assigns value of data to _data when constructor is called
{

}

void GameState::Init()
{
    //Audio Loading section

    if ( !_killSoundBuffer.loadFromFile ( KILL_SOUND_FILEPATH ) ){
        std::cout << "Kill sound not found." << std::endl;
    }
    _killSound.setBuffer ( _killSoundBuffer );

    //Texture loading section
    _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Log Sprite", LOG_SPRITE_FILEPATH);
    _data->assets.LoadTexture("LSCar Sprite", LEFT_SPAWN_CAR_FILEPATH);
    _data->assets.LoadTexture("RSCar Sprite", RIGHT_SPAWN_CAR_FILEPATH);
    _data->assets.LoadTexture("Kangaroo Sprite", KANGAROO_FILEPATH);


    //Adding the score text
    if (!font.loadFromFile(FONT_FILEPATH)) {
        std::cout << "Error opening font.";
    }
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    //scoreText.setOrigin ( scoreText.getGlobalBounds ().width / 2 , scoreText.getGlobalBounds ().height / 2 ) ;
    scoreText.setPosition(5, 2);


    //Setting texture for sprites
    _background.setTexture(_data->assets.GetTexture("Game Background"));


    //object creation section
    vehicleLeft = new Vehicle(_data);
    vehicleRight = new Vehicle(_data);
    logsLeft = new Logs(_data);
    logsRight = new Logs(_data);
    kangaroo = new Kangaroo(_data);

    _gameState = eGameState::eplaying;

     //Initial position of kangaroo
    initialYPosition = kangaroo->getPosition();
    _score = 0;


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
    if (yPositionOfKangaroo <= 0){
        addScore();
    }

    
    vehicleLeft->moveVehicleLeft(deltaTime);
    vehicleRight->moveVehicleRight(deltaTime);

    logsLeft->moveLogsLeft(deltaTime);
    logsRight->moveLogsRight(deltaTime);

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


    if ( _gameState == eGameState::eplaying ) {

        if( clock3.getElapsedTime () .asSeconds () > KANGAROO_MOVE_TIME_DELAY )  {
            kangaroo->update( deltaTime ) ;
            clock3.restart();
        }

        //passes control to collision detection section
        DetectCollision ( deltaTime ); 
    }

}

void GameState::DetectCollision( float deltaTime ){

    //collision detection
    
    //collision with vehicle spawning from right
    std::vector<sf::Sprite> VLeftSprites = vehicleLeft->getVehicleSprite() ;
    for ( int i = 0 ; i < VLeftSprites.size () ; i ++)
    {
        if ( collision.CheckSpriteCollision ( kangaroo->GetSprite ( ) , VLeftSprites.at ( i )  ) ) 
        {
            _killSound.play();
            std::cout << "Collision with VLEFT" << std::endl;
            //_gameState = eGameState::eGameOver;
        }
    }

    //collision with vehicle spawning from right
    std::vector<sf::Sprite> VRightSprites = vehicleRight->getVehicleSprite() ;
    for ( int i = 0 ; i < VRightSprites.size () ; i ++)
    {
        if ( collision.CheckSpriteCollision ( kangaroo->GetSprite ( ) , VRightSprites.at ( i ) ) ) 
        {
            _killSound.play();
            std::cout << "Collision with VRIGHT" << std::endl;
            //_gameState = eGameState::eGameOver;
        }

    }

    //river area
    bool inRiver = false;
    if ( kangaroo->getPosition() >= 45 and kangaroo->getPosition() < 225 ){
        inRiver = true;
    }

    //collision with logsLeft
    std::vector<sf::Sprite> LogLeftSprites = logsLeft->getLogsSprite() ;
    for ( int i = 0 ; i < LogLeftSprites.size () ; i ++)
    {
        bool collides = collision.CheckSpriteCollision (  kangaroo->GetSprite ( ) , LogLeftSprites.at ( i ) );
        if ( collides )
        {
            std::cout << "Collision with logs Left" << std::endl;
            kangaroo->Attach ( logsLeft->getXvelocity ( ) * 1.67 ) ;
            clock4.restart();
        }

        if ( !inRiver )
        {
            clock4.restart();
        }

        else if ( inRiver ) {
            if ( clock4.getElapsedTime().asSeconds ( ) > 0.5 ) 
            { 
                std::cout << "Out" << std::endl;
                clock4.restart();
            }
        }

    }

    //collision with logsRight
    std::vector<sf::Sprite> LogRightSprites = logsRight->getLogsSprite() ;
    for ( int i = 0 ; i < LogRightSprites.size () ; i ++)
    {
        bool collides = collision.CheckSpriteCollision (  kangaroo->GetSprite ( ) , LogRightSprites.at ( i ) );
        if ( collides )
        {
            std::cout << "Collision with logs Right" << std::endl;
            kangaroo->Attach ( - logsRight->getXvelocity ( ) * 1.67 );
            clock4.restart();
        }

        if ( !inRiver )
        {
            clock4.restart();
        }

        else if ( inRiver ) {
            if ( clock4.getElapsedTime().asSeconds ( ) > 0.5 ) 
            { 
                std::cout << "Out" << std::endl;
                clock4.restart();
            }
        }
    }


}

void GameState::Draw(float deltaTime)
{
    _data->window.clear();
    _data->window.draw(_background);

    logsLeft->drawLogs();
    logsRight->drawLogs();

    kangaroo->drawKangaroo();

    vehicleLeft->drawVehicle();
    vehicleRight->drawVehicle();

    _data->window.draw ( scoreText );
    
    _data->window.display();
}

void GameState::addScore()
{
    //Updating score
    _score += 25 ;
    std::string newScore = "Score: " + std::to_string(_score);
    scoreText.setString(newScore);

    //Replace Kangaroo
    kangaroo->setPosition ( initialYPosition );
}
