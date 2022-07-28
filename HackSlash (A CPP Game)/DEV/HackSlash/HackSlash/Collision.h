#pragma once
#include <SDL.h>

//Access-Aligned Bounding Box Collision (AABB)

class Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);

};