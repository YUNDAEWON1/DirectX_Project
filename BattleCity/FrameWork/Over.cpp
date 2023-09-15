#include "Include.h"



Over::Over()
{
}

Over::~Over()
{
}

void Over::Init()
{
	speed = 1000;
	alpha = 0;
	

	loadimg.Create("./resource/Img/BATTLECITY/OVER.png", false, D3DCOLOR_XRGB(0, 0, 0));
	
}

// Chap, 재정의 함수 호출
void Over::Update(double frame)
{
	alpha += speed * frame / 1000;
	if (alpha >= 255)
	{
		alpha = 255;
		speed = -speed;
		//Draw();
	}
	if (alpha <= 0) {
		g_Mng.n_Chap = MENU;
	}
}

void Over::Draw()
{
	loadimg.SetColor(255, 255, 255, alpha);  // 색상 변경
	loadimg.RenderDraw(150, 200, 0, 0, 244, 115, 0, 2, 2);

}

void Over::OnMessage( MSG* msg )
{

}