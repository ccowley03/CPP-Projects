#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"
class CollisionComponent : public Component
{
public:
	SDL_Rect collider;
	std::string coltag;

	TransformComponent* transform;

	CollisionComponent(std::string t)
		:coltag(t)
	{

	}

	void init() override
	{
		if (!entity->hasComp<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

	}

	void update() override
	{
		collider.x = static_cast<int> (transform->pos.x);
		collider.y = static_cast<int>(transform->pos.y);
		
		collider.w = transform->width *transform->scale;
		
		collider.h = transform->height * transform->scale;

	}
};