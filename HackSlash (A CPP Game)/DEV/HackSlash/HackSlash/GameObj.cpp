#include "GameObj.h"
#include "TextureManager.h"
GameObj::GameObj(const char* texture, SDL_Renderer* render,int x, int y)
{
	renderer = render;
	objTexture = TextureManager::TextureLoad(texture, render);
	xpos = x; ypos = y;
}

GameObj::~GameObj()
{
}

void GameObj::Update()
{
	xpos++;
	ypos++;

	srcRect.h= 32 ; srcRect.w = 32;
	srcRect.x, srcRect.y = 0;
	
	destRect.x = xpos;destRect.y = ypos;
	
	destRect.w = srcRect.w * 2; destRect.h = srcRect.h * 2;
}

void GameObj::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
