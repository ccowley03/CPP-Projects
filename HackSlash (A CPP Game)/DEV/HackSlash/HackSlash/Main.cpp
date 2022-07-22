#include "SDL.h"
#include "Game.h"



int main(int argc, char* argv[])
{
	
	const int FPS = 60;
	const int Delay = 1000 / FPS;

	Uint32 frameStart;
	int frametime;

	Game* game = new Game();


	while (game->running())
	{
		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - frameStart;
		if (Delay > frametime)
		{
			SDL_Delay(Delay - frametime);
		}
	}

	game->clean();



	return 0;
}