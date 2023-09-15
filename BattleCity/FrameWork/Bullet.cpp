#include "Include.h"

Bullet bullet;

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	
	isShoot = FALSE;


	char Filename[256];

	for (int i = 0; i < 4; i++)
	{
		sprintf_s(Filename, "./resource/Img/BATTLECITY/bullet_%02d.png", i);
		bulletImg[i].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
	}
	
	sprintf_s(Filename, "./resource/Img/BATTLECITY/boomImg.png");
	boomImg.Create(Filename, true, D3DCOLOR_XRGB(0, 127, 127));

}


void Bullet::Draw()
{

	if (isShoot == TRUE)
	{
		if (shootDirection == right || shootDirection == right_idle)
		{
			bulletImg[3].Render(b_nowx, b_nowy, 0, -3, 3);
		}
		else if (shootDirection == left || shootDirection == left_idle)
		{
			bulletImg[0].Render(b_nowx, b_nowy, 0, 3, 3);
		}
		else if (shootDirection == up || shootDirection == up_idle)
		{
			bulletImg[2].Render(b_nowx, b_nowy, 0, 3, 3);
		}
		else if (shootDirection == down || shootDirection == down_idle)
		{
			bulletImg[1].Render(b_nowx, b_nowy, 0, 3, 3);
		}

	}

	if (Gmanager.m_Collision == true)
	{
		dv_font.Fonts->DrawTextA(NULL, "ㅁ", -1, &rcBullet, DT_CENTER, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}

void Bullet::Update()
{
	char Filename[256];

	if (KeyDown(VK_SPACE) && !isShoot)
	{
			isShoot = TRUE;
			bSpeed = 0.f;
			shootDirection = P1.playerState;
			sound.m_Shot->Play(0);
	}


	if (isShoot == TRUE)
	{
		bSpeed += 0.3f;
		if (shootDirection == right || shootDirection == right_idle)
		{
			b_nowx += bSpeed;
		}
		else if (shootDirection == left || shootDirection == left_idle)
		{
			b_nowx -= bSpeed;
		}
		else if (shootDirection == up || shootDirection == up_idle)
		{
			b_nowy -= bSpeed;
		}
		else if (shootDirection == down || shootDirection == down_idle)
		{
			b_nowy += bSpeed;
		}
		SetRect(&rcBullet, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);

		if (b_nowx >= 651 || b_nowx <= 24 || b_nowy >= 650 || b_nowy <= 29)
		{
			isShoot = FALSE;
			bSpeed = 0.f;
		}
	}
	else if (isShoot == FALSE)
	{
		if (P1.playerState == right || P1.playerState == right_idle)
		{
			b_nowx = P1.playerColider.right;
			b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
		}
		else if (P1.playerState == left || P1.playerState == left_idle)
		{
			b_nowx = P1.playerColider.left;
			b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
		}
		else if (P1.playerState == up || P1.playerState == up_idle)
		{
			b_nowy = P1.playerColider.top;
			b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f -5.f;
		}
		else if (P1.playerState == down || P1.playerState == down_idle)
		{
			b_nowy = P1.playerColider.bottom;
			b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f -5.f;
		}

		SetRect(&rcBullet, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
	}
}

BOOL Bullet::collison()
{
	EnemyCollison();
	if (isShoot == TRUE)
	{
		for (int row = 0; row < 26; row++) {
			for (int col = 0; col < 26; col++) {
				if (bullet.rcBullet.left<map.TileRect[row][col].right &&
					bullet.rcBullet.right>map.TileRect[row][col].left &&
					bullet.rcBullet.top<map.TileRect[row][col].bottom &&
					bullet.rcBullet.bottom>map.TileRect[row][col].top)
				{
					if (map.map[row][col] == 1)
					{
						map.map[row][col] = 0;
						sound.m_Explosion->Play(0);

						// 충돌한 타일의 위치에 BoomImg 출력
						boomImg.Render(map.TileRect[row][col].left, map.TileRect[row][col].top, 0, 3, 3);
						isShoot = FALSE;
						if (P1.playerState == right || P1.playerState == right_idle)
						{
							b_nowx = P1.playerColider.right;
							b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
						}
						else if (P1.playerState == left || P1.playerState == left_idle)
						{
							b_nowx = P1.playerColider.left;
							b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
						}
						else if (P1.playerState == up || P1.playerState == up_idle)
						{
							b_nowy = P1.playerColider.top;
							b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f - 5.f;
						}
						else if (P1.playerState == down || P1.playerState == down_idle)
						{
							b_nowy = P1.playerColider.bottom;
							b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
						return 1;
					}
					else if (map.map[row][col] == 2)
					{
						isShoot = FALSE;
						sound.m_Explosion->Play(0);
						if (P1.playerState == right || P1.playerState == right_idle)
						{
							b_nowx = P1.playerColider.right;
							b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
						}
						else if (P1.playerState == left || P1.playerState == left_idle)
						{
							b_nowx = P1.playerColider.left;
							b_nowy = (P1.playerColider.top + P1.playerColider.bottom) / 2.f - 5.f;
						}
						else if (P1.playerState == up || P1.playerState == up_idle)
						{
							b_nowy = P1.playerColider.top;
							b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f - 5.f;
						}
						else if (P1.playerState == down || P1.playerState == down_idle)
						{
							b_nowy = P1.playerColider.bottom;
							b_nowx = (P1.playerColider.left + P1.playerColider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
						
						return 2;
					}
					else if (map.map[row][col] == 3 ||
						map.map[row][col] == 4 || map.map[row][col] == 5 ||
						map.map[row][col] == 6)
					{
						sound.m_Explosion->Play(0);
						 P1.isDead = true;
					}
				}

			}

		}
	}
	return 0;
}

BOOL Bullet::EnemyCollison()
{
	if (isShoot == TRUE)
	{
		if (bullet.rcBullet.left<eTank1.enemy1Colider.right &&
			bullet.rcBullet.right>eTank1.enemy1Colider.left &&
			bullet.rcBullet.top<eTank1.enemy1Colider.bottom &&
			bullet.rcBullet.bottom>eTank1.enemy1Colider.top)
		{
			// 적과 충돌한 경우
			isShoot = FALSE;
			sound.m_Explosion->Play(0);
			eTank1.isDead = TRUE; // 적 상태 변경
			return TRUE;
		}
		else if (bullet.rcBullet.left<eTank2.enemy2Colider.right &&
			bullet.rcBullet.right>eTank2.enemy2Colider.left &&
			bullet.rcBullet.top<eTank2.enemy2Colider.bottom &&
			bullet.rcBullet.bottom>eTank2.enemy2Colider.top)
		{
			// 적과 충돌한 경우
			isShoot = FALSE;
			sound.m_Explosion->Play(0);
			eTank2.isDead = TRUE; // 적 상태 변경
			return TRUE;
		}


		if (bullet.rcBullet.left<eBullet.rcBullet1.right &&
			bullet.rcBullet.right>eBullet.rcBullet1.left &&
			bullet.rcBullet.top<eBullet.rcBullet1.bottom &&
			bullet.rcBullet.bottom>eBullet.rcBullet1.top)
		{
			sound.m_Explosion->Play(0);
			isShoot = FALSE;
			eBullet.isShoot = FALSE;
		}
		else if (bullet.rcBullet.left<eBullet.rcBullet2.right &&
			bullet.rcBullet.right>eBullet.rcBullet2.left &&
			bullet.rcBullet.top<eBullet.rcBullet2.bottom &&
			bullet.rcBullet.bottom>eBullet.rcBullet2.top)
		{
			sound.m_Explosion->Play(0);
			isShoot = FALSE;
			eBullet.isShoot2 = FALSE;
		}
	}

	if (eTank1.isDead)
	{
		eTank1.enemy1Colider.right = 0;
		eTank1.enemy1Colider.bottom = 0;
		eTank1.RemoveEnemy1();
	}

	if (eTank2.isDead)
	{
		eTank2.enemy2Colider.right = 0;
		eTank2.enemy2Colider.bottom = 0;
		eTank2.RemoveEnemy2();
	}
	return FALSE;
}
