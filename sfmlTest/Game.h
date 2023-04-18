#pragma once
#include "SFML/Graphics.hpp"



class Game
{
private:
	void initVariables();
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev; 
	sf::CircleShape ball;
	sf::Vector2f ballPos;
	float random;
	float dt;
	sf::Clock dt_clock;
	void initWindow();


	void updateBall();	


	void Contorllers();


public :
	//construct
	Game();
	//destruct
	virtual ~Game();


	






	//Accessors

	const bool running() const {
		return this->window->isOpen();
	};


	//functions
	void pollEvents();



	void Update();


	void render();

};

