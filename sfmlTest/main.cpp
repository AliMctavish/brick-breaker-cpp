#include <iostream>
#include "Game.h"

int main()
{
	Game game;
	while (game.running())
	{
		//Update
		game.Update();

		//Render
		game.render();
	}

}