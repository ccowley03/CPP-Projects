#pragma once
#include "Game.h"
class TextureManager
{
public:
	static SDL_Texture* TextureLoad(const char* texture, SDL_Renderer* render);

};

