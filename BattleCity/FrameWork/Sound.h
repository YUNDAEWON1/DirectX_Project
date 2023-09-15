#pragma once

class Sound
{
	
public:
	Sound(void);
	~Sound(void);

	
CSoundManager* g_pSoundManager;
CSound*		m_Bk1;
CSound*		m_Shot;
CSound* m_Start;
CSound* m_Explosion;
CSound* m_Over;

int m_Select;

	

	void Init();
	
	
};

extern Sound sound;