#include "TextureManager.h"



SDL_Texture* TextureManager::TextureLoad(const char* texture, SDL_Renderer* render)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* Texture = SDL_CreateTextureFromSurface(render, tempSurface);
	SDL_FreeSurface(tempSurface);

	return Texture;
}
