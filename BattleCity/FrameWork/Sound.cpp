#include "Include.h"

Sound sound;



Sound::Sound(void)
{
	//g_pSoundManager = NULL; 사용 안했다
}

Sound::~Sound(void)
{
}

void Sound::Init()
{
	g_pSoundManager->Create( &m_Bk1, (LPWSTR)L"./resource/Sound/background.wav", 0, GUID_NULL ) ;
	g_pSoundManager->Create( &m_Shot, (LPWSTR)L"./resource/Sound/fire.wav", 0, GUID_NULL ) ;
	g_pSoundManager->Create( &m_Start, (LPWSTR)L"./resource/Sound/gamestart.wav", 0, GUID_NULL ) ;
	g_pSoundManager->Create( &m_Explosion, (LPWSTR)L"./resource/Sound/explosion.wav", 0, GUID_NULL ) ;
	g_pSoundManager->Create( &m_Over, (LPWSTR)L"./resource/Sound/gameover.wav", 0, GUID_NULL ) ;
}