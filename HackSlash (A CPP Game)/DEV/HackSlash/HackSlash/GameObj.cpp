#include "GameObj.h"
#include "TextureManager.h"
GameObj::GameObj(const char* texture)
{
	objTexture = TextureManager::TextureLoad(texture);
}

GameObj::~GameObj()
{
}


void GameObj::Update()
{
	

	srcRect.h= 32 ; srcRect.w = 32;
	srcRect.x, srcRect.y = 0;
	
	
	destRect.w = srcRect.w * 2; destRect.h = srcRect.h * 2;
}

void GameObj::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

