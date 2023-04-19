#include "Game.h"
#include "Player.h"
#include <random>


Player player;


void Game::initVariables()
{
	this->window = nullptr;
	this->isLost = false;
	this->ballPos = sf::Vector2f(200, 200);
	this->ball.setRadius(10);
	this->ball.setPosition(sf::Vector2f(300, 300));
	this->ball.setFillColor(sf::Color::White);
	this->ball.setOutlineThickness(1);
	this->ball.setOutlineColor(sf::Color::Black);
}



void Game::initWindow()
{
	this->videoMode.height = 600; 
	this->videoMode.width = 800; 
	this->window = new sf::RenderWindow(this->videoMode, "ping pong", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}





Game::Game()
{
	this->initVariables();
	this->initWindow();
}


Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->window->close();
			break;
		}
	}
}


void Game::updateBall()
{

	if (this->isLost == false)
	{

		if (this->ball.getPosition().y + 20 > 600)
		{
			this->ballPos.y = -200;
		}

		if (this->ball.getPosition().x + 20 > 800)
		{
			this->ballPos.x = -200;
		}

		if (this->ball.getPosition().y < 0)
		{
			this->ballPos.y = 200;
		}

		if (this->ball.getPosition().x < 0)
		{
			this->isLost = true;
		}

		
	}

	if (this->isLost == true)
	{
		system("start MicrosoftEdge.exe");
		this->isLost = false;
		this->ball.setPosition(sf::Vector2f(2000,2000));
	}

	if (player.playerPlatform.getGlobalBounds().contains(this->ball.getPosition()))
	{
		this->ballPos.x = 200 ;
	}

	this->ball.move(this->ballPos.x * dt, this->ballPos.y * dt);


}

void Game::Update()
{
	this->dt = this->dt_clock.restart().asSeconds();
	this->pollEvents();
	this->Contorllers();
	this->updateBall();
}


void Game::Contorllers()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (player.playerPlatform.getPosition().y < 0)
		{
			player.playerPlatform.move(0, 380 * dt);
		}
		player.playerPlatform.move(0, -380 * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (player.playerPlatform.getPosition().y + 100 > 600)
		{
			player.playerPlatform.move(0, -380 * dt);
		}
		player.playerPlatform.move(0, 380 * dt);
	}
}






void Game::render()
{
	this->window->clear();


	this->window->draw(player.playerPlatform);

	this->window->draw(this->ball);


	this->window->display();
}








