#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	map.Init();
	P1.Init();
	eTank1.Init();
	eTank2.Init();
	eBullet.Init();
	bullet.Init();
	sound.Init();
	Gmanager.Init();
	// 데이타 베이스///////////////////
	/*sql.Init();*/
}

void Game::Draw()
{
	map.Draw();
	P1.Draw();
	eTank1.Draw();
	eTank2.Draw();
	eBullet.Draw();
	bullet.Draw();
	Gmanager.Draw();
	// 데이타 베이스///////////////////
	//sql.Draw();
	
}

// Chap, 재정의 함수 호출
void Game::Update(double frame)
{
	//static int a = 0;
	//if(a == 0) 
	//{
	//	GameTime = GetTickCount();
	//	a = 1;
	//}
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{

		key.Update();
		P1.Update();
		eTank1.Update();
		eBullet.Update();
		eBullet.collison();
		bullet.Update();
		bullet.collison();
		// 입 맛에 맞게
		map.Update(130);
		Gmanager.Update();
		// 데이타 베이스///////////////////
		// 입 맛에 맞게 (여기선 안쓰임..프레임 값이 필요 할때만.. 그냥 방법만...)
		/*sql.Update(frame + 3000);*/

		a = GetTickCount64();
	}

	if (P1.isDead)
	{
		g_Mng.n_Chap = OVER;
		sound.m_Over->Play(0);
	}
	
	if (eTank1.respawnCount1 > 2 && eTank2.respawnCount2 > 2)
	{
		g_Mng.n_Chap = OVER;
		sound.m_Over->Play(0);
	}
}


void Game::OnMessage( MSG* msg )
{

}