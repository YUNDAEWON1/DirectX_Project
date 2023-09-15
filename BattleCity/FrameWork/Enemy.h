#pragma once
#include "Include.h"

class Enemy {
	double nowx, nowy;
	double speed;
	double nowSpeed;

    double moveDirX; // Enemy 객체의 이동 방향 저장
    double moveDirY;


  

public:
	BOOL isDead;
	DWORD AniTime;
	DWORD DieTime;
    Sprite enemy1[2], enemy2[2];
    Sprite colider1, colider2;
	int AniFlame;
	RECT enemy1Colider;
	RECT enemy2Colider;

	int enemyState;

    int respawnCount1;
    int respawnCount2;

    Enemy();
    ~Enemy();

    void eTank1Move(double left, double right, double up, double down);
    void eTank2Move(double left, double right, double up, double down);
    void RemoveEnemy1();
    void RemoveEnemy2();
    float GetNowX();
    float GetNowY();

    void Init();
    void Update();
    void Draw();
    void Reset();
    
    
};

extern Enemy eTank1, eTank2;