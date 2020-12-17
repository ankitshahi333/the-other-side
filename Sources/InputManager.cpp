#include "../Headers/InputManager.hpp"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(button)) {

        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
            object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (tempRect.contains(GetMousePosition(window)))
            return true;
    }
    return false;
}

bool InputManager::IsHovered(sf::Sprite object, sf::RenderWindow& window)
{
    sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
        object.getGlobalBounds().width, object.getGlobalBounds().height);

    if (tempRect.contains(GetMousePosition(window)))
        return true;
    else
        return false;

}

bool InputManager::IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::Vector2f position = object.getPosition();
        sf::Vector2f Size = sf::Vector2f(object.getGlobalBounds().width, object.getGlobalBounds().height);
        sf::IntRect tempRect(position.x - Size.x / 2, position.y - Size.y / 2, Size.x, Size.y);
        if (tempRect.contains(GetMousePosition(window)))
            return true;
    }

    return false;
}

bool InputManager::IsTextHovered(sf::Text object, sf::RenderWindow& window)
{
    sf::Vector2f position = object.getPosition();
    sf::Vector2f Size = sf::Vector2f(object.getGlobalBounds().width, object.getGlobalBounds().height);
    sf::IntRect tempRect(position.x - Size.x / 2, position.y - Size.y / 2, Size.x, Size.y);
    if (tempRect.contains(GetMousePosition(window)))
        return true;
    else
        return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}