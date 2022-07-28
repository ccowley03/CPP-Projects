#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include <vector>
#include "Vector2D.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"
SDL_Texture *playertexture;
SDL_Rect srcRec, DestRec;

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Map * map;

Management manager;
auto& player(manager.addEntity());

auto& wall(manager.addEntity());

Game::Game()
{
	init("HackSlash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
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
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
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

	
	map = new Map();
	
	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/player.png");
	player.addComponent<KeyController>();

	player.addComponent<CollisionComponent>("player");
	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);

	wall.addComponent<SpriteComponent>("assets/dirt.png");

	wall.addComponent<CollisionComponent>("wall");
	
	

}

void Game::handleEvents()
{

	
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

	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<CollisionComponent>().collider,
		wall.getComponent<CollisionComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		
		player.getComponent<TransformComponent>().velocity * -1;
		std::cout << "Wall Hit" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playertexture, NULL, &DestRec);
	map->DrawMap();
	manager.draw();
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