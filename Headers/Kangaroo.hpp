#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITION.hpp"
#include "Game.hpp"

class Kangaroo
{
public:
	Kangaroo(GameDataRef data);
	~Kangaroo();

	
	void update(float deltaTime);
	void drawKangaroo();

private:
	GameDataRef _data;
	
	sf::Sprite _kangarooSprite;
	




};