#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "DEFINITION.hpp"
#include "Game.hpp"

class Kangaroo
{
public:
	Kangaroo(GameDataRef data);
	~Kangaroo();


	void update(float deltaTime);
	float getPosition();
	void setPosition(float yPosition);
	void drawKangaroo();
	void Attach(float Xvelocity);

	const sf::Sprite& GetSprite() const;

private:
	GameDataRef _data;
	sf::Sprite _kangarooSprite;

	//kangaroo jump sound
	sf::SoundBuffer _jumpSoundBuffer;
	sf::Sound _jumpSound;

};