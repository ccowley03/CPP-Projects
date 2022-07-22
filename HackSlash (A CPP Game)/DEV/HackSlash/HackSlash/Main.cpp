#include "SDL.h"
#include "Game.h"



int main(int argc, char* argv[])
{
	Game* game = new Game();



	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();



	return 0;
}