#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()
{
	char FileName[255];

	sprintf_s(FileName, "./resource/Img/BATTLECITY/UI.png");
	UI.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));


	for (int i = 0; i < 7; i++)
	{
		sprintf_s(FileName, "./resource/Img/BATTLECITY/Tile_%02d.png", i);
		Tile[i].Create(FileName, true, D3DCOLOR_XRGB(0, 0, 0));
	}

}

void Map::Update(double frame)
{

	if (GetTickCount64() - m_MapImg1_1_ani1 > frame)
	{
		if (m_Stage == 1)
		{
			m_MapImg1_1_ani1Count++;
			if (m_MapImg1_1_ani1Count >1) m_MapImg1_1_ani1Count = 0;
			
		}
		
		m_MapImg1_1_ani1 = GetTickCount64();
	}

}

void Map::Draw()
{
	UI.Render(0, 0, 0, 1, 1);
	if (m_Stage == 1)
	{

		for (int row = 0; row < 26; row++) // 행
		{ 
			for (int col = 0; col < 26; col++) // 열
			{
				switch (map[row][col])
				{
				case 0:
					Tile[0].Render(24+col * 24, 26 + row * 24, 0, 3, 3);
					
					break;
				case 1:
					Tile[1].Render(26 + col * 24, 26 + row * 24, 0, 3, 3);
					break;
				case 2:
					Tile[2].Render(26 + col * 24,26 + row * 24, 0, 3, 3);
					break;
				case 3:
					Tile[3].Render(26 + col * 24, 26 + row * 24, 0, 3, 3);
					break;
				case 4:
					Tile[4].Render(26 + col * 24, 26 + row * 24, 0, 3, 3);
					break;
				case 5:
					Tile[5].Render(26 + col * 24, 26 + row * 24, 0, 3, 3);
					break;
				case 6:
					Tile[6].Render(26 + col * 24, 26 + row * 24, 0, 3, 3);
					break;
				}
				
			
			
			}
		}
		
	}

	if (Gmanager.m_Collision == true)
	{
		for (int row = 0; row < 26; row++) // 행
		{
			for (int col = 0; col < 26; col++) // 열
			{
				switch (map[row][col])
				{
				case 0:
					dv_font.DrawString("0", 27 + col * 24, 26 + row * 24);
					break;
				case 1:
					dv_font.DrawString("1", 27 + col * 24, 26 + row * 24);
					break;
				case 2:
					dv_font.DrawString("2", 27 + col * 24, 26 + row * 24);
					break;
				case 3:
					dv_font.DrawString("3", 27 + col * 24, 26+ row * 24);
					break;
				case 4:
					dv_font.DrawString("4", 27 + col * 24, 26+ row * 24);
					break;
				case 5:
					dv_font.DrawString("5", 27+ col * 24, 26 + row * 24);
					break;
				case 6:
					dv_font.DrawString("6", 27 + col * 24, 26 + row * 24);
					break;
				}
			}
		}
	}
}

