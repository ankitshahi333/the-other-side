#pragma once

#include <SFML/Graphics.hpp>

class InputManager
{
    public:

        InputManager( ) { }
        ~InputManager( ) { }

        bool IsTextHovered ( sf::Text object, sf::RenderWindow &window);
        bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window);
        
        bool IsHovered ( sf::Sprite object, sf::RenderWindow &window);
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

        sf::Vector2i GetMousePosition( sf::RenderWindow &window);

};