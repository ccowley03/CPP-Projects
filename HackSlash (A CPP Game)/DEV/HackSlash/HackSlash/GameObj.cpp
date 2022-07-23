#include "GameObj.h"
#include "TextureManager.h"
GameObj::GameObj(const char* texture, Vector2f p_pos)
	:pos(p_pos)
{
	objTexture = TextureManager::TextureLoad(texture);
}

GameObj::~GameObj()
{
}

Vector2f& GameObj::getpos()
{
	return pos;
}

void GameObj::Update()
{
	

	srcRect.h= 32 ; srcRect.w = 32;
	srcRect.x, srcRect.y = 0;
	
	destRect.x = this->getpos().x; destRect.y = this->getpos().y;
	
	destRect.w = srcRect.w * 2; destRect.h = srcRect.h * 2;
}

void GameObj::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

