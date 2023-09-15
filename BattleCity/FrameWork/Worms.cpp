#include "Include.h"


Player P1;

Player::Player()
{

}

Player::~Player()
{
}

void Player::Reset() 
{

}

void Player::Init()
{
	nowx = 219;
	nowy = 603;

	isDead = FALSE;
	speed = 2.f;
	playerState = STATE::start;
	AniFlame = 0;
	AniTime = GetTickCount64();
	DieTime = GetTickCount64();

	char Filename[256];

	sprintf_s(Filename, "./resource/Img/BATTLECITY/player_idle.png");
	player[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
	colider.Create("./resource/Img/BATTLECITY/colider.png", true, RGB(255, 255, 255));

	SetRect(&playerColider, nowx, nowy, nowx + 43, nowy + 43);

}


void Player::Update()
{
	Kill();
	if (isDead) playerState = die;

	switch (playerState)
	{
	case start:
		playerState = STATE::idle;
		AniFlame = 0;
		break;
	case left:
		if (GetTickCount64() - AniTime > 500) {
			AniFlame++;
			AniFlame %= 2;
			AniTime = GetTickCount64();
		}
		break;
	case left_idle:
		char Filename[256];
		sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_left01.png");
		player[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
		break;
	case right:
		if (GetTickCount64() - AniTime > 500) {
			AniFlame++;
			if (AniFlame > 1) AniFlame = 0;
			AniTime = GetTickCount64();
		}
		break;
	case right_idle:
		sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_right01.png");
		player[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
		break;
	case up:
		if (GetTickCount64() - AniTime > 500) {
			AniFlame++;
			if (AniFlame > 1) AniFlame= 0;
			AniTime = GetTickCount64();
		}
		break;
	case up_idle:
		sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_up01.png");
		player[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
		break;
	case down:
		if (GetTickCount64() - AniTime > 500) {
			AniFlame++;
			if (AniFlame > 1) AniFlame = 0;
			AniTime = GetTickCount64();
		}
		break;
	case down_idle:
		sprintf_s(Filename, "./resource/Img/BATTLECITY/1player_down01.png");
		player[0].Create(Filename, true, D3DCOLOR_XRGB(0, 128, 128));
		break;
	case alive:
		speed = 0;
		if (GetTickCount64() - AniTime > 200) {
			if (AniFlame >= 1) {
				speed = nowSpeed;
				playerState = idle;
				AniFlame = 0;
				AniTime = GetTickCount64();
			}
			AniFlame++;
			AniTime = GetTickCount64();
		}
		break;
	}
}

void Player::Draw()
{
	player[AniFlame].Render(nowx, nowy, 0, 3, 3);

	if (Gmanager.m_Collision == true)
	{
		colider.Render(nowx, nowy, 0, 1, 1);
	}
	
	
	if (Gmanager.m_Collision1== true)
	{
		for (int row = 0; row < 26; row++) {
			for (int col = 0; col < 26; col++) {
				if (map.map[row][col] != 0)
				{
					dv_font.Fonts->DrawTextA(NULL, "■", -1, &map.TileRect[row][col], DT_CENTER, D3DCOLOR_ARGB(255, 255, 255, 255));
				}
			}
		}
	}
}

void Player::SetPlayerAlive() {
	isDead = FALSE;
}


void Player::Move(double up, double down, double left, double right) {
	// 현재 위치를 저장
	RECT prevColider = playerColider;

	// 이동하려는 위치 계산
	double next_left = nowx - left * speed;
	double next_right = nowx + 43 + right * speed;
	double next_top = nowy - up * speed;
	double next_bottom = nowy + 43 + down * speed;

	// 이동하려는 위치가 유효한지 검사
	if (next_left < 24 || next_right > 651 || next_top < 29 || next_bottom > 650) {
		// 유효한 위치가 아니면 이동하지 않음
		return;
	}

	// 타일 충돌 검사
	for (int row = 0; row < 26; row++) {
		for (int col = 0; col < 26; col++) {
			if (map.map[row][col] != 0) {
				// 타일 충돌 영역 계산
				SetRect(&map.TileRect[row][col], 24 + col * 24, 28 + row * 24, 24 + col * 24 + 24, 28 + row * 24 + 24);

				// 이동한 위치와 충돌하는지 검사
				RECT nextColider;
				SetRect(&nextColider, next_left, next_top, next_right, next_bottom);
				RECT intersection;
				if (IntersectRect(&intersection, &nextColider, &map.TileRect[row][col])) {
					// 충돌 발생, 이동하지 않음
					return;
				}
			}
		}
	}

	// 모든 검사를 통과한 경우 이동 가능
	nowy -= up * speed;
	nowy += down * speed;
	nowx += right * speed;
	nowx -= left * speed;
	SetRect(&playerColider, nowx, nowy, nowx + 43, nowy + 43);


	if (playerColider.left < eTank1.enemy1Colider.right &&
		playerColider.right > eTank1.enemy1Colider.left &&
		playerColider.top < eTank1.enemy1Colider.bottom &&
		playerColider.bottom > eTank1.enemy1Colider.top)
	{
		sound.m_Explosion->Play(0);
		P1.isDead = TRUE;
	}
	else if (playerColider.left < eTank2.enemy2Colider.right &&
		playerColider.right > eTank2.enemy2Colider.left &&
		playerColider.top < eTank2.enemy2Colider.bottom &&
		playerColider.bottom > eTank2.enemy2Colider.top)
	{
		sound.m_Explosion->Play(0);
		P1.isDead = TRUE;
	}
}


float Player::GetNowX() {
	return nowx;
}

float Player::GetNowY() {
	return nowy;
}

void Player::Kill() {
}