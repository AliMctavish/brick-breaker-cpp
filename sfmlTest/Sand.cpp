#include "Sand.h"

void Sand::init()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(-1.f,1.f);
	this->velocity = dist(rd);
}

Sand::Sand(float& posX, float& posY)
{
	this->isGrounded = false;
	this->sandTexutre.setPosition(posX, posY);
	this->sandTexutre.setFillColor(sf::Color::Green);
	this->sandTexutre.setSize(sf::Vector2f(6,6));
	this->sandTexutre.setOutlineColor(sf::Color::White);
	this->sandTexutre.setOutlineThickness(0.f);
	this->sandPos = sf::Vector2f(posX, posY);
}

void Sand::update()
{
	this->sandTexutre.move(0.f, 3.f);
}

void Sand::ground()
{
	this->sandTexutre.move(0, -1.f);
}