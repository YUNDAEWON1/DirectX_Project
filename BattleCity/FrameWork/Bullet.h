#pragma once
#include "Include.h"


class Bullet
{
public:

	Sprite bulletImg[4];
	Sprite bulCollider;
	Sprite boomImg;
	RECT rcBullet;


	float b_x, b_y;
	float b_nowx, b_nowy;
	float bSpeed = 0.05f;
	int shootDirection;

	BOOL isShoot;



	Bullet();
	~Bullet();
	void Init();
	void Update();
	void Draw();

	BOOL collison();
	BOOL EnemyCollison();
};

extern Bullet bullet;