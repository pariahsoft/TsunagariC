/******************************
** Tsunagari Tile Engine     **
** window.h - Window         **
** Copyright 2011 OmegaSDG   **
******************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>
#include <Gosu/Gosu.hpp>
#include <json/json.h>

//#include "resourcer.h"
#include "world.h"

class Entity;
class World;

class GameWindow : public Gosu::Window
{
public:
	GameWindow(uint x, uint y, bool fullscreen);
	virtual ~GameWindow();

	void buttonDown(Gosu::Button btn);
	void draw();
	bool needsRedraw();
	void update();

private:
//	string get_datadir();
	World* world;
};

#endif

