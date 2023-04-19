#include "Block.h"



Block::Block(float posX , float posY)
{
	this->blockTexture.setFillColor(sf::Color::White);
	this->blockTexture.setPosition(posX, posY);
	this->blockTexture.setSize(sf::Vector2f(60,20));

}


