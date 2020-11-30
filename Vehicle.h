#pragma once

#include <SFML/Graphics.hpp>
#include "Headers/AssetManager.hpp"

class Vehicle
{
public:
	Vehicle() {}
	~Vehicle() {}

	sf::Sprite GetSprite() {
	}
	void Update(float deltaTime) {}
	void Init() {}

	AssetManager textureAsset;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _speed;
	bool _isRight;
	
};

