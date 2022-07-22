#pragma once
#include "Game.h"
class GameObj
{
public:
	GameObj(const char* texture, SDL_Renderer* render,int x ,int y);
	~GameObj();
	void Update();
	void Render();
private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

	SDL_Renderer* renderer;
};

