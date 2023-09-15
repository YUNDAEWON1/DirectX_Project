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
				if (enemy[i].pos == LEFT && enemy[i].life == true)		// �����ʿ��� �������� ����!  x�� - ���Ѿ���
				{
					enemy[i].init_x -= enemy[i].speed; enemy[i].dx -= enemy[i].speed;
				}
				else if (enemy[i].pos == RIGHT && enemy[i].life == true)
				{
					enemy[i].init_x += enemy[i].speed;  enemy[i].dx += enemy[i].speed;
				}

				FishMoveTime = GetTickCount64();
			}




			//ȭ�� ������ ������ �ٽñ׸��� �����
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

	�⺻ �浹ó��

	= �簢�� �⵿ ���� ó��
	�÷��̾���� �浹 ���� ��ǥ�� (ML, MT) ~ (MR, MB), ź�� �浹 ���� ��ǥ�� (BL, BT) ~ (BR, BB)��� �غ���.
	(ML, MT), (BL, BT)�� ������ �簢���� ���� �� ��ǥ�̰� (MR. MB), (BR, BB)�� �簢���� ������ �Ʒ� ��ǥ�̴�.
	�� ���, �÷��̾�⿡ ź�� �浹 ������ ������ ����.
	* ML < BR && BL < MR && MT < BB && BT < MB

	= ���� �̿��� �浹 ���� ó��
	���� �̿��� �浹 ���� ó���� ������ ����.
	�÷��̾���� �߽���ǥ�� (MX, MY), ź�� �߽���ǥ�� (BX, BY)��� �ϰ�, �÷��̾���� �浹 ���� �ݰ��� MR,
	ź�� �浹 ���� �ݰ��� BR�̶�� ����. �̶� �÷��̾��� ź�� �浹 ������ �Ʒ��� ����.
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

