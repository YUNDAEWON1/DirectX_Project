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
	// ����Ÿ ���̽�///////////////////
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
	// ����Ÿ ���̽�///////////////////
	//sql.Draw();
	
}

// Chap, ������ �Լ� ȣ��
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
		// �� ���� �°�
		map.Update(130);
		Gmanager.Update();
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
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