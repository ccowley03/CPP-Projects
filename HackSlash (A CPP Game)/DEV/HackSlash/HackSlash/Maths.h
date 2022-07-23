#pragma once

#include <iostream>
struct Vector2f
{
	Vector2f()
	:x(0.0f), y(0.0f)
	{}
	Vector2f(float x_val,float y_val)
		:x(x_val), y(y_val)
	{}
	
	void output()
	{
		std::cout << x << ", " << y << std::endl;
	}
	float x, y;

};


