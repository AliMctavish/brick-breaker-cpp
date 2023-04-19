#pragma once
#include "SFML/Graphics.hpp"


class Block {
public :
	Block(float posX , float posY);
	sf::RectangleShape blockTexture;
private:
	sf::Vector2f position;


};
