#include "Game.h"
#include "Player.h"
#include <random>
#include "Block.h"

Player player;
std::vector<Block> blocks;




void Game::initVariables()
{
	this->window = nullptr;
	this->isLost = false;

	if (!this - buffer.loadFromFile("collide.wav"))
	{
		std::cout << "something went wrong" << std::endl;
	}
	if (!this - buffer2.loadFromFile("playerCollide.wav"))
	{
		std::cout << "something went wrong" << std::endl;
	}
	this->sound.setBuffer(buffer);
	this->sound2.setBuffer(buffer2);
	this->ballPos = sf::Vector2f(200, 200);
	this->ball.setRadius(10);
	this->ball.setPosition(sf::Vector2f(50, 50));
	this->ball.setFillColor(sf::Color::White);
	this->ball.setOutlineThickness(1);
	this->ball.setOutlineColor(sf::Color::Black);
}

void Game::CreateBlocks()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Block block(80 * i + 10, 30 * j + 20);
			blocks.push_back(block);
		}
	}
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
	this->CreateBlocks();
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
			this->isLost = true;
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
			this->ballPos.x = 200;
		}
	}

	if (this->isLost == true)
	{
		//this->isLost = false;
		this->ball.setPosition(sf::Vector2f(2000, 2000));
	}

	if (player.playerPlatform.getGlobalBounds().contains(sf::Vector2f(this->ball.getPosition().x + 20, this->ball.getPosition().y + 20)))
	{
		this->ballPos.y = -200;
		this->sound2.play();
	}
	this->ball.move(this->ballPos.x * dt, this->ballPos.y * dt * 2);
}

void Game::UpdateBlocks()
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i].blockTexture.getGlobalBounds().contains(sf::Vector2f(this->ball.getPosition().x + 10, this->ball.getPosition().y)))
		{
			blocks.erase(blocks.begin() + i);
			this->ballPos.y = 200;
			this->sound.play();
		}
	}
}

void Game::Update()
{
	this->dt = this->dt_clock.restart().asSeconds();
	this->pollEvents();
	this->Contorllers();
	this->updateBall();
	this->UpdateBlocks();
}


void Game::Contorllers()
{
	if (this->isLost == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (player.playerPlatform.getPosition().x < 0)
			{
				player.playerPlatform.move(380 * dt, 0);
			}
			player.playerPlatform.move(-380 * dt, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (player.playerPlatform.getPosition().x + 100 > 800)
			{
				player.playerPlatform.move(-380 * dt, 0);
			}
			player.playerPlatform.move(380 * dt, 0);
		}
	}
	else {

	}


}

void Game::render()
{
	this->window->clear();


	this->window->draw(player.playerPlatform);

	this->window->draw(this->ball);


	for (auto& block : blocks)
	{
		this->window->draw(block.blockTexture);
	}


	this->window->display();
}








