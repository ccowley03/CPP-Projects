#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
	static ComponentID prevID = 0;
	return prevID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
	static ComponentID typeID = getComponentID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;
	virtual void init() {

	}
	virtual void update()
	{

	}
	virtual void draw()
	{

	}
	virtual ~Component() {

	}
};

class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;

	ComponentBitSet componentBitSet;
public:
	void update()
	{
		for (auto& comp : components)
		{
			comp->update();
		}
		
	}
	void draw()
	{
		for (auto& comp : components)
		{
			comp->draw();
		}
	}
	bool isActive()const
	{
		return active;
	}
	void destroy()
	{
		active = false;
	}
	template <typename T> bool hasComp() const
	{
		return componentBitSet[ getComponentID<T>()];
	}
	template<typename T, typename... TArguments>
	T& addComponent(TArguments&&... mArguments)
	{
		T* c(new T(std::forward < TArguments>(mArguments)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentID<T>()] = c;

		componentBitSet[getComponentID<T>()] = true;

		c->init();

		return *c;
	}
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentID<T>()]);
		return *static_cast<T*>(ptr);

	}
	
};

class Management
{
private:
	std::vector<std::unique_ptr<Entity>>entities;

public:
	void update()
	{
		for (auto &e : entities)
		{
			e->update();
		}
	}
	void draw()
	{
		for (auto& e : entities)
		{
			e->draw();
		}
	}
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}),
			std::end(entities));
	}
	Entity& addEntity()
	{
		Entity* ent = new Entity();
		std::unique_ptr<Entity> uPtr{ ent };
		entities.emplace_back(std::move(uPtr));
		return *ent;
	}
};