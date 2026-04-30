#include "Sound.h"

static const char* SOUND_PATH[Sound::tagSound::SOUND_NUM] = {
	"data/sound/title.mp3",
	"data/sound/bgm01.mp3",
	"data/sound/se_explore.mp3",
};



//データを初期化
void Sound::Init()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_hndl[i] = -1;
	}
}

//音楽データをロード

void Sound::Load()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_hndl[i] == -1)
		{
			m_hndl[i] = LoadSoundMem(SOUND_PATH[i]);
		}
	}
}

//終了前に行う
void Sound::Exit()
{
	//すでに音がロードされていたら-1ではなくなっている
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_hndl[i] != -1)
		{
			DeleteSoundMem(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}

//音の再生要請
void Sound::RequestSound(int soundID, int type)
{
	PlaySoundMem(m_hndl[soundID], type);
}

//音の停止要請
void Sound::StopSound(int soundID)
{
	StopSoundMem(m_hndl[soundID]);
}

//すべての音の停止要請
void Sound::StopAllSound()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		StopSound(i);
	}
}

