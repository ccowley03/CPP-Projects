#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	bool IsRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int count;


};

