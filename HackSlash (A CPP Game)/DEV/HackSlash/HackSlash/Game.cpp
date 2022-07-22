#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObj.h"
SDL_Texture *playertexture;
SDL_Rect srcRec, DestRec;

GameObj* player = nullptr;

Game::Game()
{
	init("HackSlash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;

	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SubSys initialised..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Works!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Window Works" << std::endl;
		}
		IsRunning = true;
	}
	else
	{
		IsRunning = false;

	}

	player = new GameObj("assets/player.png", renderer,0,0);

}

void Game::handleEvents()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;
	default:
		break;

	}

}

void Game::update()
{
	player->Update();

}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playertexture, NULL, &DestRec);
	player->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Stopped" << std::endl;

}

bool Game::running()
{
	return IsRunning;
}