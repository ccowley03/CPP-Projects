#pragma once
#include "Game.h"
class TextureManager
{
public:
	static SDL_Texture* TextureLoad(const char* texture);
	static void Draw(SDL_Texture *texture,SDL_Rect src, SDL_Rect dest,SDL_RendererFlip flip);
};

