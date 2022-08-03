#pragma once
#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class AIComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();

	}
};