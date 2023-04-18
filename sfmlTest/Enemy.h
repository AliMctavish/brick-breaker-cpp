#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>



class Enemy {
public :
	sf::Vector2f enemyPosition;
	sf::RectangleShape enemyTexture;
	float size = 1;
	int velocity = 1;

	Enemy();


	void Update();

	void ground();

	void Render(float& posX , float& posY);
};






