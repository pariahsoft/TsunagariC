/******************************
** Tsunagari Tile Engine     **
** sprite.h                  **
** Copyright 2011 OmegaSDG   **
******************************/

#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <string>

#include <libxml/parser.h>

#include "common.h"

namespace Gosu {
	class Image;
}

class Resourcer;

/**
 * Sprite is an image model for displaying 2D video game entities.
 *
 * Each Sprite represents one 'thing' that will be rendered to the screen.
 * Sprite can handle animated images that cycle through their frames over time.
 * It also has the capacity to switch between a couple different images on
 * demand.
 *
 * For example, you might have a Sprite for a player character with animated
 * models for walking in each possible movement direction (up, down, left,
 * right) along with static standing-still images for each direction. This
 * would all be handled by one Sprite.
 */
class Sprite
{
public:
	//! Sprite Constructor
	Sprite(Resourcer* rc, const std::string descriptor);
	
	//! Sprite Destructor
	~Sprite();
	
	//! Sprite Initializer
	bool init();
	
	//! Gosu Callback
	void draw() const;
	
	coord_t getCoordsByPixel();
	coord_t getCoordsByTile();
	
	//! Gosu Callback
	void moveByPixel(coord_t deltac);
	void moveByTile(coord_t deltac);
	void setCoordsByPixel(coord_t c);
	void setCoordsByTile(coord_t c);

private:
	bool processDescriptor();
	bool processPhases(xmlNode* phases);
	bool processPhase(xmlNode* phase);

	Resourcer* rc;
	const Gosu::Image* img;
	coord_t c;

	const std::string descriptor;

	//! SpriteValues XML Storage Struct
	/*!
	  Main XML storage struct for Sprite.
	*/
	struct SpriteValues {
		std::string sheet;
		coord_t tilesize; // z-coord not used
		std::map<std::string, unsigned long> phases;
	} xml;
};

#endif

