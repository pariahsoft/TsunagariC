/******************************
** Tsunagari Tile Engine     **
** entity.cpp                **
** Copyright 2011 OmegaSDG   **
******************************/

#define TILE_SIZE 64

#include "entity.h"

Entity::Entity(Resourcer* rc,
               const std::string descriptor,
               const std::string spriteDescriptor)
	: sprite(NULL),
	  rc(rc),
	  redraw(true),
	  descriptor(descriptor),
	  spriteDescriptor(spriteDescriptor)
{
}

Entity::~Entity()
{
	delete sprite;
}

bool Entity::init()
{
	sprite = new Sprite(rc, spriteDescriptor);
	return sprite->init();
}

void Entity::draw()
{
	redraw = false;
	sprite->draw();
}

bool Entity::needsRedraw() const
{
	return redraw;
}

void Entity::moveByTile(coord_t delta)
{
	sprite->moveByTile(delta);
	redraw = true;
}

