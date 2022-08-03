#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "Anim.h"
#include <map>

class Sprite : public Component
{
private:
	Transformer* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	std::map<const char*, Anim> animations;
	std::vector<Anim> anims;
	bool animation = false;

	int frames = 0;
	int speed = 100;


public:
	
	int animInd = 0;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	
	
	Sprite() = default;
	Sprite(const char * path)
	{
		setTexture(path);

	}
	Sprite(const char* path,bool isAnim)
	{
		animation = isAnim;
		
		
	
		

		anims.push_back(Anim(0, 3, 200));
		anims.push_back(Anim(1, 3, 200));
		anims.push_back(Anim(2, 3, 200));
		anims.push_back(Anim(3, 3, 200));
		
		animations.emplace("Idle", anims.at(0));
		animations.emplace("Walkleft", anims.at(1));
		animations.emplace("Walkright", anims.at(2));
		animations.emplace("Walkup", anims.at(3));

		
		play("Idle");
		setTexture(path);

	

	}
	~Sprite()
	{
		SDL_DestroyTexture(texture);
	}
	void setTexture(const char* path)
	{
		texture = TextureManager::TextureLoad(path);
	}
	void init()override
	{
		transform = &entity->getComponent<Transformer>();
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		
		

	}
	void update()override
	{
		
		
		if (animation)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animInd * transform->height;

		destRect.x = static_cast<int>(transform->pos.x);
		
		destRect.y =static_cast<int> (transform->pos.y);

		destRect.w = transform->width * transform->scale;
		
		destRect.h = transform->width * transform->scale;

	}
	void draw()override
	{
		TextureManager::Draw(texture, srcRect, destRect,spriteFlip);
	}

	void play(const char* animname)
	{
		frames = animations[animname].frameNum;
		animInd = animations[animname].index;
		speed = animations[animname].speed;

	}

};