#pragma once
#include "Include.h"

class Key
{

public:
	Key(void);
	~Key(void);
	
	DWORD KeyTime;
	// 동시 키 선택을 위함
	DWORD KeyTime1;
	DWORD KeyTime2;
	DWORD KeyTime3;

	BOOL WkeyInput;
	BOOL AkeyInput;
	BOOL SkeyInput;
	BOOL DkeyInput;

	BOOL LeftKeyInput;
	BOOL RightKeyInput;
	BOOL UpKeyInput;
	BOOL DownKeyInput;
	
	BOOL SpaceKeyInput;

	void Update();
	void Player1Move();

};

extern Key key;