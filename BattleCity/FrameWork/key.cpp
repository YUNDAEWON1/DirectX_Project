#include "Include.h"

Key key;

Key::Key(void)
{

	
}

Key::~Key(void)
{
}

void Key::Player1Move() {
	if (P1.isDead)return;
	if (P1.playerState == alive)return;

	if (KeyDown(VK_LEFT))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			P1.Move(0, 0, 1.0f, 0);
			KeyTime1 = GetTickCount64();

			char Filename[256];
			for (int i = 0; i < 2; i++) {
				sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_left%02d.png",i+1);
				P1.player[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
			}

			if (!LeftKeyInput) {
				P1.AniFlame = 0;
				P1.AniTime = GetTickCount64();

				LeftKeyInput = TRUE;
			}
			P1.playerState = STATE::left;
		}
	}
	else if (KeyDown(VK_RIGHT))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			P1.Move(0, 0, 0, 1.0f);
			KeyTime1 = GetTickCount64();

			char Filename[256];
			for (int i = 0; i < 2; i++) {
				sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_right%02d.png", i + 1);
				P1.player[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
			}

			if (!RightKeyInput) {
				P1.AniFlame = 0;
				P1.AniTime = GetTickCount64();

				RightKeyInput = TRUE;
			}
			P1.playerState = STATE::right;
		}
	}
	else if (KeyDown(VK_UP))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			P1.Move(1.0f, 0, 0, 0);
			KeyTime1 = GetTickCount64();

			char Filename[256];
			for (int i = 0; i < 2; i++) {
				sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_up%02d.png", i + 1);
				P1.player[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
			}

			if (!UpKeyInput) {
				P1.AniFlame = 0;
				P1.AniTime = GetTickCount64();

				UpKeyInput = TRUE;
			}
			P1.playerState = STATE::up;
		}
	}
	else if (KeyDown(VK_DOWN))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			P1.Move(0, 1.0f, 0, 0);
			KeyTime1 = GetTickCount64();

			char Filename[256];
			for (int i = 0; i < 2; i++) {
				sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_down%02d.png", i + 1);
				P1.player[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
			}

			if (!DownKeyInput) {
				P1.AniFlame = 0;
				P1.AniTime = GetTickCount64();

				DownKeyInput = TRUE;
			}
			P1.playerState = STATE::down;
		}
	}

	//////마지막방향+IDLE 상태

	if (KeyUp(VK_LEFT) && LeftKeyInput) {
		LeftKeyInput = FALSE;
		P1.playerState = STATE::left_idle;
		P1.AniFlame = 0;
		P1.AniTime = GetTickCount64();
	}
	if (KeyUp(VK_RIGHT) && RightKeyInput) {
		RightKeyInput = FALSE;
		P1.playerState = STATE::right_idle;
		P1.AniFlame = 0;
		P1.AniTime = GetTickCount64();
	}
	if (KeyUp(VK_UP) && UpKeyInput) {
		UpKeyInput = FALSE;
		P1.playerState = STATE::up_idle;
		P1.AniFlame = 0;
		P1.AniTime = GetTickCount64();
	}
	if (KeyUp(VK_DOWN) && DownKeyInput) {
		DownKeyInput = FALSE;
		P1.playerState = STATE::down_idle;
		P1.AniFlame = 0;
		P1.AniTime = GetTickCount64();
	}


}

void Key::Update()
{

	Player1Move();

	// 시스템에 따라...GetTickCount/GetTickCount64
	if(KeyDown('1'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			map.m_Stage = 1;
			KeyTime = GetTickCount64();
		}
	}

	if(KeyDown('2'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision = true;
			KeyTime = GetTickCount64();
		}
		
	}


	if (KeyDown('3'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision1 = true;
			KeyTime = GetTickCount64();
		}
	}
	
	
	if(KeyDown('4'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision = false;
			KeyTime = GetTickCount64();
		}
		
	}

	if(KeyDown('5'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			Gmanager.m_Collision1 = false;
			KeyTime = GetTickCount64();

		}
	
	}
	/*if (KeyDown(VK_SPACE))
	{

	}*/
	/*
	if(KeyDown('6'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}



	if(KeyDown('7'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
		
	}



	
	

	if(KeyDown('8'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

		}
		
	}

	if(KeyDown('9'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('0'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
		
	}






	if(KeyDown(VK_F1))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F2))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F3))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F4))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F5))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F6))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F7))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F8))
	{
		if(GetTickCount64() - KeyTime > 200)
		{		
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F9))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F10))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F11))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	
	}

	
	if(KeyDown(VK_F12))
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
	
	}

	


	if(KeyDown(VK_SPACE) ) 
	{
		
		
		if(GetTickCount64() - KeyTime2 > 300)
		{
			if(Gmanager.m_GameStart==true )
			{

			}
				
			KeyTime2 = GetTickCount64();
		}
		
	}



	if (KeyDown(VK_LEFT))
	{

		if (GetTickCount64() - KeyTime1 > 10)
		{
			if (player.m_x <= 0)
			{
				player.m_x = player.m_x;
			}
			else if (Gmanager.m_GameStart == true)
			{
				player.m_x -= 0.5;
			}
			KeyTime1 = GetTickCount64();
		}
	}
	if(KeyDown(VK_RIGHT))
	{
		if(GetTickCount64() - KeyTime1 > 10)
		{
			if(player.m_x>=1190)
			{
				player.m_x = player.m_x;
			}
			else if(Gmanager.m_GameStart==true)
			{
				player.m_x+=0.5;
			}
			KeyTime1 = GetTickCount64();
		}
	}


	
	if(KeyDown(VK_UP))
	{
		if(GetTickCount64() - KeyTime3 > 10)
		{	

			if(player.m_y<=0)
			{
				player.m_y = player.m_y;
	
			}
			else if(Gmanager.m_GameStart==true)
			{
				player.m_y-=0.5;
			}

			KeyTime3 = GetTickCount64();
		}
		
		
	}

	if(KeyDown(VK_DOWN))
	{

		if(GetTickCount64() - KeyTime3 > 10)
		{
			
			if (player.m_y>= 670)
			{
				player.m_y = player.m_y;
			}
			else if(Gmanager.m_GameStart==true)
			{
				player.m_y+=0.5;
				
			}

			KeyTime3 = GetTickCount64();
		}
		
	}


	if(KeyDown('C') )
	{
		if(GetTickCount64() - KeyTime1 > 200)
		{	
			KeyTime1 = GetTickCount64();
		}
	}




	
	if(KeyDown('N'))
	{
		
		if(GetTickCount64() - KeyTime > 200)
		{			
			KeyTime = GetTickCount64();
		}
	}

	
	if(KeyDown('A'))
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}
	}




	if(KeyDown('W') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount64();
		}

	}


	if(KeyDown('E')  )
	{
		if(GetTickCount64() - KeyTime > 200)
		{	
			KeyTime = GetTickCount64();
		}
		
	}


	if(KeyDown('R') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown('S') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
	
			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown('D') )
	{
		if(GetTickCount64() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount64();
		}
	}


	if(KeyDown(VK_RETURN) ) 
	{
		
		if(GetTickCount64() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount64();
		}
		
	}
*/

}