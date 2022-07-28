#pragma once
#include "Game.h"

class GameObj
{
public:
	GameObj(const char* texture);
	~GameObj();
	
	void Update();
	void Render();
	
private:

	
	
	

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


};

