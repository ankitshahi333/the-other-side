//This header includes all the constants used in the program and filepath for different resources
#pragma once

//Game Window Properties
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

//Game Frame Rate
#define GAME_FRAME_RATE 60

//Splash State Properties
#define SPLASH_STATE_DURATION 3.0f
#define SPLASH_STATE_BACKGROUND_FILEPATH    "Assets/Graphics/SplashBackground.png"

//Main Menu State Properties
#define MAIN_MENU_BACKGROUND_FILEPATH       "Assets/Graphics/MainBackground.png"
#define MAIN_MENU_TITLE_FILEPATH            "Assets/Graphics/Title.png"
#define PLAY_BUTTON_FILEPATH                "Assets/Graphics/PlayButton.png"
#define PLAY_BUTTON_HOVER_FILEPATH          "Assets/Graphics/PlayButtonHover.png"
#define QUIT_BUTTON_FILEPATH                "Assets/Graphics/QuitButton.png"
#define QUIT_BUTTON_HOVER_FILEPATH          "Assets/Graphics/QuitButtonHover.png"

//Font properties
#define FONT_FILEPATH                       "Assets/Fonts/MarkerFelt.ttf"
#define GAME_OVER_TEXT_FILEPATH             "Assets/Fonts/MATURASC.TTF"

//Game State Properties
#define GAME_BACKGROUND_FILEPATH            "Assets/Graphics/Background.png"
#define LOG_SPRITE_FILEPATH                 "Assets/Graphics/Log.png"
#define LEFT_SPAWN_CAR_FILEPATH             "Assets/Graphics/LSCar.png"
#define RIGHT_SPAWN_CAR_FILEPATH            "Assets/Graphics/RSCar.png"
#define CAR_SPAWN_FREQUENCY 1.5f

//Game Over State Properties
#define GAME_OVER_BACKGROUND_FILEPATH       "Assets/Graphics/Background.png"
#define GAME_OVER_TITLE_FILEPATH            "Assets/Graphics/GameOverTitle.png"
#define GAME_OVER_BODY_FILEPATH             "Assets/Graphics/GameOverBody.png"

//Kangaroo Properties
#define KANGAROO_FILEPATH                   "Assets/Graphics/kangaroo.png"
#define KANGAROO_SPEED 45.f
#define KANGAROO_MOVE_TIME_DELAY 0.100f

//Sound files
#define INTRO_SOUND_FILEPATH                "Assets/Audio/intro.wav"
#define BACKGROUND_SOUND_FILEPATH           "Assets/Audio/background.wav"
#define CLICK_SOUND_FILEPATH                "Assets/Audio/click.wav"
#define KILL_SOUND_FILEPATH                 "Assets/Audio/kill.wav"
#define SPLASH_SOUND_FILEPATH               "Assets/Audio/splash.wav"
#define JUMP_SOUND_FILEPATH                 "Assets/Audio/jump.wav"

//BestScore 
#define BEST_SCORE_FILEPATH                 "Assets/best.txt"

//gameStates enum
enum eGameState{
    eplaying, eGameOver, eReady
};