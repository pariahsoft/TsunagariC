/*********************************
** Tsunagari Tile Engine        **
** overlay.cpp                  **
** Copyright 2011-2012 OmegaSDG **
*********************************/

#include "area.h"
#include "overlay.h"

Overlay::Overlay()
	: Entity()
{
}

Overlay::~Overlay()
{
}

void Overlay::tick(unsigned long dt)
{
	runTickScript();
	switch (conf.moveMode) {
	case TURN:
		// Replace with MOVE_TO_DEST();
		tickTile(dt);
		break;
	case TILE:
		tickTile(dt);
		break;
	case NOTILE:
		tickNoTile(dt);
		break;
	}
}

void Overlay::teleport(int x, int y)
{
	r.x = x;
	r.y = y;
}

void Overlay::move(int x, int y)
{
	fromTile = NULL;
	destTile = NULL;

	// XXX: Find nearest facing.
	//setFacing(ivec2(x, y));

	// XXX: Hack for facing. Shouldn't need to set.
	setFacing(ivec2(0, 1));

	// Copied from Entity::preMove()
	destCoord = r + rcoord(x, y, 0);

	moving = true;

	// Start moving animation.
	//setPhase("moving " + getFacing());

	// Movement happens over time. See updateTile().
}

void Overlay::erase()
{
	area->erase(this);
}
