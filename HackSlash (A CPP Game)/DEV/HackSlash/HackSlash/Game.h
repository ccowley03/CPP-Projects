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
	void AddPlayer(int numargs, const char* path, bool isanim);
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool IsRunning;
	SDL_Window* window;
	
	int count;


};

