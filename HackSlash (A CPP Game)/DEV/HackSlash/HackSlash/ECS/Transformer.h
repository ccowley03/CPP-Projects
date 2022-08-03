#pragma once

#include "Components.h"
#include "../Vector2D.h"
class Transformer :public Component
{

public:
	Vector2D pos;

	Vector2D velocity;

	int height = 32;
	int width = 32;

	int scale = 1;

	int speed = 3;
	
	Transformer()
	{
		pos.Zero();

	}
	Transformer(int sc)
	{
		pos.Zero();
		scale = sc;
	}
	Transformer(float x, float y)
	{
		setPos(x, y);
	}
	Transformer(float x, float y,int h ,int w, int scl)
	{
		setPos(x, y);
		height = h;
		width = w;
		scale = scl;
	}
	
	void init()override
	{
		velocity.Zero();
	}
	
	void update()override
	{
		pos.x += velocity.x * speed;
		pos.y += velocity.y * speed;
	

	}

	void setPos(float x, float y)
	{
		pos.x = x; pos.y = y;
	}

};