#pragma once
#include "SFML/Graphics.hpp"


class Player {


public: 

	Player();

	void init();


	sf::Vector2f size;
	sf::RectangleShape playerPlatform;
	sf::Vector2f playerPos;

};
