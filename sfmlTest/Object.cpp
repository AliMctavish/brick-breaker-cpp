#include "Object.h"


void Object::inIt(float posX, float posY)
{
	this->objectTexture.setPosition(posX,posY);
	this->objectTexture.setSize(sf::Vector2f(80, 30));
	this->objectTexture.setFillColor(sf::Color(107, 84, 40));
	this->objectTexture.setOutlineColor(sf::Color::White);
	//this->objectTexture.setOutlineThickness(1);
	this->position.x = posX;
	this->position.y = posY;
}














