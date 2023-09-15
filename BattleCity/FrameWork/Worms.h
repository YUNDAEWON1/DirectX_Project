#pragma once
#include "Include.h"
#include <list>

enum STATE{
	start, idle, up ,down,left,right,alive,die,
up_idle,down_idle,left_idle,right_idle
};



static int playerstate = idle;

class Player
{
	double nowx, nowy;
	double speed;
	double nowSpeed;
public :
	BOOL isDead;

	

	DWORD AniTime;
	DWORD DieTime;
	Sprite player[20];
	int AniFlame;
	Sprite colider;
	RECT playerColider;

	int playerState;
	
	Player();
	~Player();


	void SetPlayerAlive();
	void Move(double up, double down, double left, double right);
	
	float GetNowX();
	float GetNowY();

	void Init();
	void Update();
	void Draw();
	void Reset();

	void Kill();
	

};

extern Player P1;