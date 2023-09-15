#include "Include.h"

class EnemyBullet
{
public:

	Sprite bulletImg[4];
	Sprite bulCollider;
	Sprite boomImg;




	RECT rcBullet1;
	RECT rcBullet2;



	float b_x, b_y;
	float b_nowx, b_nowy;
	float b_nowx2, b_nowy2;

	float bSpeed = 0.05f;
	float bSpeed2 = 0.05f;

	int shootDirection;
	int shootDirection2;

	BOOL isShoot;
	BOOL isShoot2;

	EnemyBullet();
	~EnemyBullet();
	void Init();
	void Update();
	void Draw();

	BOOL collison();
	BOOL EnemyCollison();
};

extern EnemyBullet eBullet;

