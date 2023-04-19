#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

class Game
{
public:
	sf::RenderWindow* window;

	void initVariables();

	sf::Sound sound;
	sf::Sound sound2;
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer2;


	sf::VideoMode videoMode;
	sf::Event ev; 
	sf::CircleShape ball;
	sf::Vector2f ballPos;
	float dt;
	bool isLost;
	sf::Clock dt_clock;
	void initWindow();


	void updateBall();	


	void Contorllers();


	void UpdateBlocks();


	void CreateBlocks();


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

