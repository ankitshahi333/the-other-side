#include <iostream>

#include "../Headers/Kangaroo.hpp"

Kangaroo::Kangaroo(GameDataRef data) : _data(data)
{
	if (!_jumpSoundBuffer.loadFromFile(JUMP_SOUND_FILEPATH)) {
		std::cout << "Jump sound not found." << std::endl;
	}

	_jumpSound.setBuffer(_jumpSoundBuffer);

	_kangarooSprite.setTexture(_data->assets.GetTexture("Kangaroo Sprite"));
	_kangarooSprite.setScale(0.255f, 0.2f);
	_kangarooSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - _kangarooSprite.getGlobalBounds().height);
}

Kangaroo::~Kangaroo()
{

}

float Kangaroo::getPosition()
{
	return _kangarooSprite.getPosition().y;
}

void Kangaroo::setPosition(float yPosition)
{
	float xPosition = _kangarooSprite.getPosition().x;
	this->_kangarooSprite.setPosition(xPosition, yPosition);
}

void Kangaroo::update(float deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _kangarooSprite.getPosition().x > 0)
	{
		_jumpSound.play();
		_kangarooSprite.move(-KANGAROO_SPEED, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _kangarooSprite.getPosition().x + _kangarooSprite.getGlobalBounds().width < WINDOW_WIDTH)
	{
		_jumpSound.play();
		_kangarooSprite.move(KANGAROO_SPEED, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _kangarooSprite.getPosition().y > 0)
	{
		_jumpSound.play();
		_kangarooSprite.move(0, -KANGAROO_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _kangarooSprite.getPosition().y + _kangarooSprite.getGlobalBounds().height < WINDOW_HEIGHT)
	{
		_jumpSound.play();
		_kangarooSprite.move(0, KANGAROO_SPEED);
	}

}

void Kangaroo::Attach(float Xvelocity)
{
	_kangarooSprite.move(Xvelocity, 0);
}

void Kangaroo::drawKangaroo()
{
	_data->window.draw(_kangarooSprite);
}

const sf::Sprite& Kangaroo::GetSprite() const
{
	return _kangarooSprite;
}