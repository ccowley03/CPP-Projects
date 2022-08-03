#pragma once
#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class AIComponent : public Component
{
public:
	Transformer* transform;
	Sprite* sprite;

	void init() override
	{
		transform = &entity->getComponent<Transformer>();
		sprite = &entity->getComponent<Sprite>();

	}
};