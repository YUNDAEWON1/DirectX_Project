#include "Include.h"
#include <cstdlib>
#include <ctime>

Field field;

void Field::Init() {

	second = 180;
	minute = second / 60;
	gameTimer = 0;

	for (int row = 0; row < 13; row++) {
		for (int col = 0; col < 15; col++) {

			tile[row][col].TileRect.left = 20 + col * 40;
			tile[row][col].TileRect.right = 20 + col * 40 + 40;
			tile[row][col].TileRect.top = 40 + row * 40;
			tile[row][col].TileRect.bottom = 40 + row * 40 + 40;

			//if (block[row][col].blockType != 1) {
			//	block[row][col].blockType = rand() % 2+1;
			//	//block[row][col].blockType = _background;
			//}
			//block[10][10].blockType = _unblock;
			tile[row][col].TileType = map[row][col];

			switch (tile[row][col].TileType) {
			case background:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_00.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			case brick:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_01.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			case steel:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_02.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			}
		}
	}
}

void Field::Reset() {
	second = 180;
	minute = second / 60;
	gameTimer = 0;

	for (int row = 0; row < 13; row++) {
		for (int col = 0; col < 15; col++) {

			tile[row][col].TileRect.left = 20 + col * 40;
			tile[row][col].TileRect.right = 20 + col * 40 + 40;
			tile[row][col].TileRect.top = 40 + row * 40;
			tile[row][col].TileRect.bottom = 40 + row * 40 + 40;

			//if (block[row][col].blockType != 1) {
			//	block[row][col].blockType = rand() % 2+1;
			//	//block[row][col].blockType = _background;
			//}
			//block[10][10].blockType = _unblock;
			tile[row][col].TileType = map[row][col];

			switch (tile[row][col].TileType) {
			case background:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_00.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			case brick:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_01.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			case steel:
				tile[row][col].TileSprite.Create("./resource/Img/BATTLECITY/Tile_02.png", false, D3DCOLOR_XRGB(255, 255, 255));
				break;
			}
		}
	}
}

void Field::Update() {
	for (int row = 0; row < 13; row++) {
		for (int col = 0; col < 15; col++) {
			tile[row][col].Update();
		}
	}
	/*if (!Gmanager.isGameStart) {
		gameTimer = GetTickCount64();
	}*/
	if (1000 < GetTickCount64() - gameTimer) {
		second -= 1;
		minute = second / 60;
		gameTimer = GetTickCount64();
	}

	/*if (second < 0) {
		BGStop();
		EffectPlay(sound.gameOver);
		Sleep(1000);
		EffectPlay(sound.draw);
		Gmanager.gameResult = draw;
		g_Mng.n_Chap = OVER;
	}*/
}

void Field::Draw() {
	for (int row = 0; row < 26; row++)
	{
		for (int col = 0; col < 26; col++)
		{
			if (tile[row][col].TileType == brick) {
				tile[row][col].TileSprite.Draw(20 + col * 24, 80 + row * 24 - tile[row][col].TileSprite.imagesinfo.Height);
			}
			if (tile[row][col].TileType == steel) {
				tile[row][col].TileSprite.Draw(20 + col * 24, 80 + row * 24 - tile[row][col].TileSprite.imagesinfo.Height);
			}
			else if (tile[row][col].TileType == tile_pop) {
				tile[row][col].TileSprite.Draw(20 + col * 24, 80 + row * 24 - tile[row][col].TileSprite.imagesinfo.Height,
					24 * tile[row][col].popAniFrame, 0, 40 + tile[row][col].popAniFrame * 24, 49);
			}
			else if (tile[row][col].TileType == bg_pop) {
				tile[row][col].TileSprite.Draw(20 + col * 24, 80 + row * 24 - tile[row][col].TileSprite.imagesinfo.Height,
					24 * tile[row][col].popAniFrame, 0, 40 + tile[row][col].popAniFrame * 24, 40);
			}
			else if (tile[row][col].TileType == item) {
				tile[row][col].TileSprite.Draw(20 + col * 24, 80 + row * 24 - tile[row][col].TileSprite.imagesinfo.Height,
					24 * tile[row][col].popAniFrame, 0, 35 + tile[row][col].popAniFrame * 24, 40);
			}
		}
	}
}