#pragma once
#include "Game.h"
#include "Maths.h""
class GameObj
{
public:
	GameObj(const char* texture,Vector2f p_pos);
	~GameObj();
	Vector2f& getpos();
	void Update();
	void Render();
	
private:

	
	Vector2f pos;
	

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


};

