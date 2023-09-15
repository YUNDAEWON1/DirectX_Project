#include "Include.h"


Monster monster;



Monster::Monster(void)
{
	LifeTime = GetTickCount64();
	FishCountTime = GetTickCount64();
	FishMoveTime = GetTickCount64();
}

Monster::~Monster(void)
{
}

void Monster::Init()
{

	char FileName[256];

	for(int i = 0; i<2; i++ )
	{
		sprintf_s(FileName, "./resource/Img/enemy/enemy1_%02d.png", i);
		enemy1[i].Create(FileName,true,D3DCOLOR_XRGB(0,128,128));
	}
	for(int i = 0; i<2; i++ )
	{
		sprintf_s(FileName, "./resource/Img/enemy/enemy2_%02d.png", i);
		enemy2[i].Create(FileName,true,D3DCOLOR_XRGB(0,128,128));
	}
	for (int i = 0; i < 2; i++)
	{
		sprintf_s(FileName, "./resource/Img/enemy/enemy3_%02d.png", i);
		enemy3[i].Create(FileName, true, D3DCOLOR_XRGB(0, 128, 128));
	}
	for (int i = 0; i <2; i++)
	{
		sprintf_s(FileName, "./resource/Img/enemy/enemy4_%02d.png", i);
		enemy4[i].Create(FileName, true, D3DCOLOR_XRGB(0, 128, 128));
	}
	sprintf_s(FileName, "./resource/Img/BATTLECITY/boomImg.png");
	Boomimg.Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
	

}
void Monster::GoodFunction(double init_x, double init_y, double x, 
						   double y, int score, double speed, 
						   double scale, int pos, double dx, double dy, 
						   double dz, double w, int enemykind, int num)
{
	enemy[num].init_x = init_x ;
	enemy[num].init_y = init_y;
	enemy[num].x = x;
	enemy[num].y = y;
	enemy[num].life = false;
	enemy[num].score = score;

	enemy[num].speed = speed;
	enemy[num].scale = 3;
	enemy[num].w = 0;
	enemy[num].pos = pos;

	enemy[num].dz = 0;
	enemy[num].enemykind = enemykind;

	enemy[num].drz = 0;
	enemy[num].Shot = true;
	enemy[num].bulletPX1 = -5;
	enemy[num].bulletPY1 = -11;
	enemy[num].bulletPX2 = 3;
	enemy[num].bulletPY2 = -2;

	if(enemy[num].enemykind == 0 && enemy[num].pos==RIGHT)
	{
		enemy[num].drx = enemy[num].dx = init_x - 62.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 30.0f;

	}
	else if(enemy[num].enemykind == 0 && enemy[num].pos==LEFT)
	{
		enemy[num].drx = enemy[num].dx = init_x + 37.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 30.0f;

	}

	else if(enemy[num].enemykind == 1 && enemy[num].pos==RIGHT)
	{
		enemy[num].drx = enemy[num].dx = init_x - 55.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 22.0f;

	}
	else if(enemy[num].enemykind == 1 && enemy[num].pos==LEFT)
	{
		enemy[num].drx = enemy[num].dx = init_x + 30.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 22.0f;

	}
	else if(enemy[num].enemykind == 2 && enemy[num].pos==RIGHT)
	{
		enemy[num].drx = enemy[num].dx = init_x - 62.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 35.0f;

	}
	else if(enemy[num].enemykind == 2 && enemy[num].pos==LEFT)
	{
		enemy[num].drx = enemy[num].dx = init_x + 37.0f ;
		enemy[num].dry = enemy[num].dy = init_y + 35.0f;
	}

}


void Monster::Reset()
{


	GoodFunction(100, 30, 100, 30, 50, 5, 3, LEFT, 30.0f, 50.0f, 0, 0, A_, 0);
	GoodFunction(200, 30, 200, 30, 100, 5, 3, RIGHT, 40.0f, 30.0f, 0, 100.0f, B_, 1);
	GoodFunction(250, 30, 200, 30, 100, 5, 3, RIGHT, 40.0f, 30.0f, 0, 100.0f, C_, 2);
	GoodFunction(300, 30, 200, 30, 100, 5, 3, RIGHT, 40.0f, 30.0f, 0, 100.0f, D_, 3);

	m_FishLifeSelect = 0;

}
void Monster::Update()
{


	if (Gmanager.m_GameStart == true)
	{

		if (GetTickCount64() - LifeTime > 100)
		{
			for (m_FishLifeSelect = 0; m_FishLifeSelect < 2; m_FishLifeSelect++)
			{
				if (enemy[m_FishLifeSelect].life == false)
				{
					enemy[m_FishLifeSelect].life = true;

				}

			}
			m_FishLifeSelect = 0;
			LifeTime = GetTickCount64();
		}



		if (GetTickCount64() - FishMoveTime > 200)
		{
			for (int i = 0; i < 4; i++)
			{
				if (enemy[i].pos == LEFT && enemy[i].life == true)		// 오른쪽에서 왼쪽으로 가면!  x를 - 시켜야지
				{
					enemy[i].init_x -= enemy[i].speed; enemy[i].dx -= enemy[i].speed;
				}
				else if (enemy[i].pos == RIGHT && enemy[i].life == true)
				{
					enemy[i].init_x += enemy[i].speed;  enemy[i].dx += enemy[i].speed;
				}

				FishMoveTime = GetTickCount64();
			}




			//화면 밖으로 나가면 다시그리게 만들기
			for (int i = 0; i < 4; i++)
			{

				if (enemy[i].life == true)
				{
					if (enemy[i].pos == LEFT && enemy[i].init_x < 30)
					{
						enemy[i].life = false;
						enemy[i].init_x = enemy[i].x;
						enemy[i].init_y = enemy[i].y;

						enemy[i].dx = enemy[i].drx;
						enemy[i].dy = enemy[i].dry;

						enemy[i].Shot = true;
					}
					else if (enemy[i].pos == RIGHT && enemy[i].init_x > 823)
					{
						enemy[i].life = false;
						enemy[i].init_x = enemy[i].x;
						enemy[i].init_y = enemy[i].y;

						enemy[i].dx = enemy[i].drx;
						enemy[i].dy = enemy[i].dry;

						enemy[i].Shot = true;

					}
					else if (enemy[i].pos == UP && enemy[i].init_y < 50)
					{
						enemy[i].life = false;
						enemy[i].init_x = enemy[i].x;
						enemy[i].init_y = enemy[i].y;

						enemy[i].dx = enemy[i].drx;
						enemy[i].dy = enemy[i].dry;

						enemy[i].Shot = true;
					}
					else if (enemy[i].pos == DOWN && enemy[i].init_y > 683)
					{
						enemy[i].life = false;
						enemy[i].init_x = enemy[i].x;
						enemy[i].init_y = enemy[i].y;

						enemy[i].dx = enemy[i].drx;
						enemy[i].dy = enemy[i].dry;

						enemy[i].Shot = true;
					}
				}


			}
			if (GetTickCount64() - FishCountTime > 100)
			{
				m_Acount++;
				m_Bcount++;

				m_Bulletcount++;

				if (m_Acount > 1)  m_Acount = 0;
				if (m_Bcount > 1) m_Bcount = 0;

				if (m_Bulletcount > 20) m_Bulletcount = 0;
				FishCountTime = GetTickCount64();
			}

			Boom();


			if (m_Boom1 == true)
			{
				if (GetTickCount64() - BoomTime1 > 50)
				{
					m_BoomCount1++;
					if (m_BoomCount1 > 25) { m_BoomCount1 = 0; m_Boom1 = false; }
					BoomTime1 = GetTickCount64();
				}
			}


		}
	}
}


/*

	기본 충돌처리

	= 사각형 출동 판정 처리
	플레이어기의 충돌 판정 좌표를 (ML, MT) ~ (MR, MB), 탄의 충돌 판정 좌표를 (BL, BT) ~ (BR, BB)라고 해보자.
	(ML, MT), (BL, BT)는 각각의 사각형의 왼쪽 위 좌표이고 (MR. MB), (BR, BB)는 사각형의 오른쪽 아래 좌표이다.
	이 경우, 플레이어기에 탄의 충돌 조건은 다음과 같다.
	* ML < BR && BL < MR && MT < BB && BT < MB

	= 원을 이용한 충돌 판정 처리
	원을 이용한 충돌 판정 처리는 다음과 같다.
	플레이어기의 중심좌표를 (MX, MY), 탄의 중심좌표를 (BX, BY)라고 하고, 플레이어기의 충돌 판정 반경을 MR,
	탄의 충돌 판정 반경을 BR이라고 하자. 이때 플레이어기와 탄의 충돌 조건은 아래와 같다.
	* (MX-BX)*(MX-BX) + (MY-BY)*(MY-BY) < (MR+BR)*(MR+BR)

*/

void Monster::Boom()
{
	for(int i=0; i<2; i++)
	{
		if(enemy[i].life == true)
		{

			
		}
	}
		//if(target.m_Life == true)
		//target.m_Life = false;
}



void Monster::Draw()
{
	if (Gmanager.m_GameStart == true)
	{
		if (m_Boom1 == true)
		{
			Boomimg.Render(m_BoomX1, m_BoomY1, 0, 1.5, 1.5);

		}

		for (int i = 0; i < 2; i++)
		{
			if (enemy[i].life == true)
			{
				m_Left = enemy[i].dx;
				m_High = enemy[i].dy;

				if (enemy[i].pos == LEFT)
				{

					if (enemy[i].enemykind == A_) enemy1[m_Acount].Render(
						enemy[i].init_x, enemy[i].init_y, 0, -enemy[i].scale, enemy[i].scale);

					if (enemy[i].enemykind == B_) enemy2[m_Bcount].Render(
						enemy[i].init_x, enemy[i].init_y, 0, -enemy[i].scale, enemy[i].scale);

				}
				if (enemy[i].pos == RIGHT)
				{

					if (enemy[i].enemykind == A_) enemy1[m_Acount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, 0, enemy[i].scale, enemy[i].scale);

					if (enemy[i].enemykind == B_) enemy2[m_Bcount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, 0, enemy[i].scale, enemy[i].scale);

				}
				if(enemy[i].pos == UP)
				{

					if (enemy[i].enemykind == A_) enemy1[m_Acount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, 90, enemy[i].scale, enemy[i].scale);

					if (enemy[i].enemykind == B_) enemy2[m_Bcount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, 90, enemy[i].scale, enemy[i].scale);

				}
				if(enemy[i].pos == DOWN)
				{

					if (enemy[i].enemykind == A_) enemy1[m_Acount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, -90, enemy[i].scale, enemy[i].scale);

					if (enemy[i].enemykind == B_) enemy2[m_Bcount].Render(
						enemy[i].init_x + enemy[i].w, enemy[i].init_y, -90, enemy[i].scale, enemy[i].scale);
				}



			}



		}

	}
}

