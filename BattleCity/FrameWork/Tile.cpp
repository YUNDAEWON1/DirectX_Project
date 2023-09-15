#include "Include.h"

void Tile::Update() {
	//if (TileType == tile_pop/* && isPop == TRUE*/) {
	//	if (GetTickCount64() - popTimer > 100) {
	//		if (popAniFrame == 5) {
	//			if (item.itemType > countUp) {
	//				TileType = background;
	//			}
	//			else {
	//				TileType = item;
	//				SetItemSprite();
	//			}
	//			//isPop = FALSE;
	//			popAniFrame = 0;
	//			popTimer = GetTickCount64();
	//			return;
	//		}
	//		popAniFrame++;
	//		popTimer = GetTickCount64();
	//		return;
	//	}
	//}
	if (TileType == bg_pop/* && isPop == TRUE*/) {
		if (GetTickCount64() - popTimer > 100) {
			if (popAniFrame == 5) {
				TileType = background;
				//isPop = FALSE;
				popAniFrame = 0;
				popTimer = GetTickCount64();
				return;
			}
			popAniFrame++;
			popTimer = GetTickCount64();
			return;
		}
	}
	else if (TileType == item) {
		if (GetTickCount64() - popTimer > 500) {
			popAniFrame++;
			popAniFrame %= 2;
			popTimer = GetTickCount64();
			return;
		}
	}
}

/*void Block::SetItemSprite() {
	switch (item.itemType)
	{
	case powerUp:
		blockSprite.Create("./resource/Img/item/potion.bmp", TRUE, RGB(255, 0, 255));
		break;
	case speedUp:
		blockSprite.Create("./resource/Img/item/skate.bmp", TRUE, RGB(255, 0, 255));
		break;
	case countUp:
		blockSprite.Create("./resource/Img/item/balloon.bmp", TRUE, RGB(255, 0, 255));
		break;
	}
}*/