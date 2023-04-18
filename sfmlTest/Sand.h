#pragma once
#include "SFML/Graphics.hpp"
#include <random>


class Sand {
public :
	//SAND CTOR
	Sand(float& posX , float& posY);

	//INIT VARIALBES
	float velocity;
	sf::RectangleShape sandTexutre;
	sf::Vector2f sandPos;
	bool isGrounded;

	void init();

	void ground();

	//UPDATE SAND POSITION 
	void update();

};
