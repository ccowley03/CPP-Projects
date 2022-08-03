#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"
class Collider : public Component
{
public:
	SDL_Rect collider;
	std::string coltag;

	Transformer* transform;

	Collider(std::string t)
		:coltag(t)
	{

	}

	void init() override
	{
		if (!entity->hasComp<Transformer>())
		{
			entity->addComponent<Transformer>();
		}
		transform = &entity->getComponent<Transformer>();

	}

	void update() override
	{
		collider.x = static_cast<int> (transform->pos.x);
		collider.y = static_cast<int>(transform->pos.y);
		
		collider.w = transform->width *transform->scale;
		
		collider.h = transform->height * transform->scale;

	}
};