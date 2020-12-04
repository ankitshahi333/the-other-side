#include "../Headers/Kangaroo.hpp"

Kangaroo::Kangaroo(GameDataRef data) : _data(data)
{
	_kangarooSprite.setTexture(_data->assets.GetTexture("Kangaroo Sprite"));
	_kangarooSprite.setScale(0.35f, 0.225f);
	_kangarooSprite.setPosition((_data->window.getSize().x / 2), (_data->window.getSize().y - _kangarooSprite.getGlobalBounds().height));

}
Kangaroo::~Kangaroo()
{

}

void Kangaroo::update(float deltaTime)
{
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _kangarooSprite.getPosition().x >0)
	{
		float velocity = -KANGAROO_SPEED * deltaTime;
		_kangarooSprite.move(velocity, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _kangarooSprite.getPosition().x + _kangarooSprite.getGlobalBounds().width<WINDOW_WIDTH)
	{
		float velocity = KANGAROO_SPEED * deltaTime;
		_kangarooSprite.move(velocity, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _kangarooSprite.getPosition().y > 0)
	{
		float velocity= -KANGAROO_SPEED * deltaTime;
		_kangarooSprite.move(0, velocity);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _kangarooSprite.getPosition().y + _kangarooSprite.getGlobalBounds().height < WINDOW_HEIGHT)
	{
		float velocity = KANGAROO_SPEED * deltaTime;
		_kangarooSprite.move(0, velocity);
	}
	
}

void Kangaroo::drawKangaroo()
{
	_data->window.draw(_kangarooSprite);
}