#ifndef __Over_H__
#define __Over_H__

class Over : public Chap
{
public:
	Over();
	~Over();

	HWND hWnd;
	//CSound* Sound1;
	Sprite loadimg;

	float speed;
	float alpha;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};



#endif