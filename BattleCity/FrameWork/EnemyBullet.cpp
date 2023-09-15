#include "Include.h"

EnemyBullet eBullet;

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Init()
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


void EnemyBullet::Draw()
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

	if (isShoot2 == TRUE)
	{
		if (shootDirection2 == right || shootDirection2 == right_idle)
		{
			bulletImg[3].Render(b_nowx2, b_nowy2, 0, -3, 3);
		}
		else if (shootDirection2 == left || shootDirection2 == left_idle)
		{
			bulletImg[0].Render(b_nowx2, b_nowy2, 0, 3, 3);
		}
		else if (shootDirection2 == up || shootDirection2 == up_idle)
		{
			bulletImg[2].Render(b_nowx2, b_nowy2, 0, 3, 3);
		}
		else if (shootDirection2 == down || shootDirection2 == down_idle)
		{
			bulletImg[1].Render(b_nowx2, b_nowy2, 0, 3, 3);
		}

	}

	if (Gmanager.m_Collision == true)
	{
		dv_font.Fonts->DrawTextA(NULL, "ㅁ", -1, &rcBullet1, DT_CENTER, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}

void EnemyBullet::Update()
{
	

	if (!isShoot)
	{
		static clock_t lastShotTime = clock(); // 마지막 총알 발사 시간
		const int SHOT_INTERVAL = 1500; // 1.5초(밀리초 단위)
		
		// 일정 간격으로 총알 발사하기
		if (clock() - lastShotTime > SHOT_INTERVAL)
		{
			isShoot = true;
			sound.m_Shot->Play(0);
			bSpeed = 0.f;
			shootDirection = eTank1.enemyState;
			lastShotTime = clock(); // 마지막 총알 발사 시간 갱신
		}
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
		SetRect(&rcBullet1, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);

		if (b_nowx >= 651 || b_nowx <= 24 || b_nowy >= 650 || b_nowy <= 29)
		{
			isShoot = FALSE;
			bSpeed = 0.f;
		}
	}
	else if (isShoot == FALSE)
	{
		if (eTank1.enemyState == right || eTank1.enemyState == right_idle)
		{
			b_nowx = eTank1.enemy1Colider.right;
			b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
		}
		else if (eTank1.enemyState == left || eTank1.enemyState == left_idle)
		{
			b_nowx = eTank1.enemy1Colider.left;
			b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
		}
		else if (eTank1.enemyState == up || eTank1.enemyState == up_idle)
		{
			b_nowy = eTank1.enemy1Colider.top;
			b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
		}
		else if (eTank1.enemyState == down || eTank1.enemyState == down_idle)
		{
			b_nowy = eTank1.enemy1Colider.bottom;
			b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
		}
		SetRect(&rcBullet1, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
	}


	///eTank2
	if (!isShoot2)
	{

		static clock_t lastShotTime1 = clock(); // 마지막 총알 발사 시간
		const int SHOT_INTERVAL1 = 1500; // 1초(밀리초 단위)

		// 일정 간격으로 총알 발사하기
		if (clock() - lastShotTime1 > SHOT_INTERVAL1)
		{
			isShoot2 = true;
			sound.m_Shot->Play(0);
			bSpeed2 = 0.f;
			shootDirection2 = eTank2.enemyState;
			lastShotTime1 = clock(); // 마지막 총알 발사 시간 갱신
		}
	}

	if (isShoot2 == TRUE)
	{
		bSpeed2 += 0.3f;
		if (shootDirection2 == right || shootDirection2 == right_idle)
		{
			b_nowx2 += bSpeed2;
		}
		else if (shootDirection2 == left || shootDirection2 == left_idle)
		{
			b_nowx2 -= bSpeed2;
		}
		else if (shootDirection2 == up || shootDirection2 == up_idle)
		{
			b_nowy2 -= bSpeed2;
		}
		else if (shootDirection2 == down || shootDirection2 == down_idle)
		{
			b_nowy2 += bSpeed2;
		}
		SetRect(&rcBullet2, b_nowx2 - 3, b_nowy2, b_nowx2 + 9, b_nowy2 + 9);

		if (b_nowx2 >= 651 || b_nowx2 <= 24 || b_nowy2 >= 650 || b_nowy2 <= 29)
		{
			isShoot2 = FALSE;
			bSpeed2 = 0.f;
		}
	}
	else if (isShoot2 == FALSE)
	{
		if (eTank2.enemyState == right || eTank2.enemyState == right_idle)
		{
			b_nowx2 = eTank2.enemy2Colider.right;
			b_nowy2 = (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
		}
		else if (eTank2.enemyState == left || eTank2.enemyState == left_idle)
		{
			b_nowx2 = eTank2.enemy2Colider.left;
			b_nowy2= (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
		}
		else if (eTank2.enemyState == up || eTank2.enemyState == up_idle)
		{
			b_nowy2 = eTank2.enemy2Colider.top;
			b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
		}
		else if (eTank2.enemyState == down || eTank2.enemyState == down_idle)
		{
			b_nowy2 = eTank2.enemy2Colider.bottom;
			b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
		}
		SetRect(&rcBullet2, b_nowx2 - 3, b_nowy2, b_nowx2 + 9, b_nowy2 + 9);
	}
}

BOOL EnemyBullet::collison()
{
	EnemyCollison();
	if (isShoot == TRUE)
	{
		for (int row = 0; row < 26; row++) {
			for (int col = 0; col < 26; col++) {
				if (eBullet.rcBullet1.left<map.TileRect[row][col].right &&
					eBullet.rcBullet1.right>map.TileRect[row][col].left &&
					eBullet.rcBullet1.top<map.TileRect[row][col].bottom &&
					eBullet.rcBullet1.bottom>map.TileRect[row][col].top)
				{
					if (map.map[row][col] == 1)
					{
						map.map[row][col] = 0;
						sound.m_Explosion->Play(0);
						isShoot = FALSE;
						if (eTank1.enemyState == right || eTank1.enemyState == right_idle)
						{
							b_nowx = eTank1.enemy1Colider.right;
							b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == left || eTank1.enemyState == left_idle)
						{
							b_nowx = eTank1.enemy1Colider.left;
							b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == up || eTank1.enemyState == up_idle)
						{
							b_nowy = eTank1.enemy1Colider.top;
							b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == down || eTank1.enemyState == down_idle)
						{
							b_nowy = eTank1.enemy1Colider.bottom;
							b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet1, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
						return 1;
					}
					else if (map.map[row][col] == 2)
					{
						sound.m_Explosion->Play(0);
						isShoot = FALSE;

						if (eTank1.enemyState == right || eTank1.enemyState == right_idle)
						{
							b_nowx = eTank1.enemy1Colider.right;
							b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == left || eTank1.enemyState == left_idle)
						{
							b_nowx = eTank1.enemy1Colider.left;
							b_nowy = (eTank1.enemy1Colider.top + eTank1.enemy1Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == up || eTank1.enemyState == up_idle)
						{
							b_nowy = eTank1.enemy1Colider.top;
							b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
						}
						else if (eTank1.enemyState == down || eTank1.enemyState == down_idle)
						{
							b_nowy = eTank1.enemy1Colider.bottom;
							b_nowx = (eTank1.enemy1Colider.left + eTank1.enemy1Colider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet1, b_nowx - 3, b_nowy, b_nowx + 9, b_nowy + 9);
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


	if (isShoot2 == TRUE)
	{
		for (int row = 0; row < 26; row++) {
			for (int col = 0; col < 26; col++) {
				if (eBullet.rcBullet2.left<map.TileRect[row][col].right &&
					eBullet.rcBullet2.right>map.TileRect[row][col].left &&
					eBullet.rcBullet2.top<map.TileRect[row][col].bottom &&
					eBullet.rcBullet2.bottom>map.TileRect[row][col].top)
				{
					if (map.map[row][col] == 1 )
					{
						sound.m_Explosion->Play(0);
						map.map[row][col] = 0;

						// 충돌한 타일의 위치에 BoomImg 출력
						boomImg.Render(map.TileRect[row][col].left, map.TileRect[row][col].top, 0, 3, 3);
						isShoot2 = FALSE;
						if (eTank2.enemyState == right || eTank2.enemyState == right_idle)
						{
							b_nowx2 = eTank2.enemy2Colider.right;
							b_nowy2 = (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == left || eTank2.enemyState == left_idle)
						{
							b_nowx2 = eTank2.enemy2Colider.left;
							b_nowy2 = (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == up || eTank2.enemyState == up_idle)
						{
							b_nowy2 = eTank2.enemy2Colider.top;
							b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == down || eTank2.enemyState == down_idle)
						{
							b_nowy2 = eTank2.enemy2Colider.bottom;
							b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet2, b_nowx2 - 3, b_nowy2, b_nowx2 + 9, b_nowy2 + 9);
						return 1;
					}
					else if (map.map[row][col] == 2)
					{
						sound.m_Explosion->Play(0);
						isShoot2 = FALSE;

						if (eTank2.enemyState == right || eTank2.enemyState == right_idle)
						{
							b_nowx2 = eTank2.enemy2Colider.right;
							b_nowy2 = (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == left || eTank2.enemyState == left_idle)
						{
							b_nowx2 = eTank2.enemy2Colider.left;
							b_nowy2 = (eTank2.enemy2Colider.top + eTank2.enemy2Colider.bottom) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == up || eTank2.enemyState == up_idle)
						{
							b_nowy2 = eTank2.enemy2Colider.top;
							b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
						}
						else if (eTank2.enemyState == down || eTank2.enemyState == down_idle)
						{
							b_nowy2 = eTank2.enemy2Colider.bottom;
							b_nowx2 = (eTank2.enemy2Colider.left + eTank2.enemy2Colider.right) / 2.f - 5.f;
						}
						SetRect(&rcBullet2, b_nowx2 - 3, b_nowy2, b_nowx2 + 9, b_nowy2 + 9);
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

BOOL EnemyBullet::EnemyCollison()
{
	if (isShoot == TRUE)
	{
		if (eBullet.rcBullet1.left<P1.playerColider.right &&
			eBullet.rcBullet1.right>P1.playerColider.left &&
			eBullet.rcBullet1.top<P1.playerColider.bottom &&
			eBullet.rcBullet1.bottom>P1.playerColider.top)
		{
			// 적과 충돌한 경우
			isShoot = FALSE;
			sound.m_Explosion->Play(0);
			P1.isDead = TRUE; 
			return TRUE;
		}
		
	}

	if (isShoot2 == TRUE)
	{
		if (eBullet.rcBullet2.left<P1.playerColider.right &&
			eBullet.rcBullet2.right>P1.playerColider.left &&
			eBullet.rcBullet2.top<P1.playerColider.bottom &&
			eBullet.rcBullet2.bottom>P1.playerColider.top)
		{
			// 적과 충돌한 경우
			isShoot2 = FALSE;
			sound.m_Explosion->Play(0);
			P1.isDead = TRUE; 
			return TRUE;
		}

	}
	return FALSE;
}