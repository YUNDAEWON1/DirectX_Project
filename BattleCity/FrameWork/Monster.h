#pragma once
#include "Include.h"


class Monster
{
	typedef struct Mon
	{
		double init_x, init_y;				// 첫 출현위치
		double x, y;						// 재출현
		int score;							// 이넘잡으면 먹는점수
		double speed; 
		double scale;
		bool life;							// 죽었니 살았니
		bool Death;
		int pos;							// 향하는 방향
		double dx, dy, dz, drx, dry, drz;	// 데미지존
		double w;
		bool ShotStart;
		bool Shot;
		double bulletX;
		double bulletY;
		double bulletPX1;
		double bulletPY1;
		double bulletPX2;
		double bulletPY2;
		double bdx, bdy;
		int enemykind;
	};

	
public:
	Monster(void);
	~Monster(void);
	Sprite enemy1[2], enemy2[2], enemy3[2], enemy4[2], Boomimg;

	Mon enemy[4];
	int m_Acount, m_Bcount,m_Ccount,m_Dcount, m_Bulletcount;

	 DWORD FishMoveTime;
	 DWORD FishCountTime;
	 DWORD LifeTime;

	 DWORD BoomTime1;
	 bool m_Boom1;
	 int m_BoomCount1;
	 double m_BoomX1;
	 double m_BoomY1;



	 RECT m_rc;
	 double m_Left;
	 double m_High;

	 int m_FishLifeSelect;

	void GoodFunction(double init_x, double init_y, double x, double y, int score, double speed, 
						   double scale, int pos, double dx, double dy, double dz, double w, int fishkind, int num);
	void Init();
	void Update();
	void Draw();
	void Boom();
	void Reset();

};

extern Monster monster;