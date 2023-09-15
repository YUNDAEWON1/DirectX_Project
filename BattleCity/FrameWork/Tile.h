#pragma once
#include "Include.h"

enum { background, brick, steel, life1, life2, life3, life4, item, bg_pop,tile_pop };

class Tile {
public:
	RECT TileRect;
	int TileType;
	Sprite TileSprite;
	BOOL isPop;
	/*Item item;*/
	DWORD popTimer;
	int popAniFrame;
	int planter;

	void Update();
	void SetItemSprite();
};

extern Tile tile;