#pragma once
#include "SFML/Graphics.hpp"

class Object
{
public:
	sf::Vector2f position;
	sf::RectangleShape objectTexture;

	void inIt(float posX, float posY);
};





