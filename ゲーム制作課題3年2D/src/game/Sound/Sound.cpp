#include "Sound.h"

// 配列でやるときはstaticが必要
int Sound::m_hdl[SOUND_NUM];

//データを初期化
void Sound::Init()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_hdl[i] = -1;
	}
}

//音楽データをロード

void Sound::Load()
{
	// 配列でやる
	bool ret = true;

	const char* filePath[SOUND_NUM] = {
	"data/sound/title.mp3",
	"data/sound/bgm01.mp3",
	"data/sound/result.mp3",
	};

	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_hdl[i] = LoadSoundMem(filePath[i]);

		if (m_hdl[i] == -1)
		{
			ret = false;
		}
	}
	// 音量の変更
	ChangeVolumeSoundMem(100, m_hdl[0]);
}

//終了前に行う
void Sound::Exit()
{
	//すでに音がロードされていたら-1ではなくなっている
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_hdl[i] != -1)
		{
			DeleteSoundMem(m_hdl[i]);
			m_hdl[i] = -1;
		}
	}
}

//音の再生要請
bool Sound::Play(tagSound id, int type, bool isStart)
{
	int ret = PlaySoundMem(m_hdl[id], type, isStart);

	if (ret == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//音の停止要請
void Sound::Stop(tagSound id)
{
	// 音楽を停止
	StopSoundMem(m_hdl[id]);
}

//すべての音の停止要請
void Sound::AllStop()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		StopSoundMem(m_hdl[i]);
	}
}

// 音楽が再生中か
bool Sound::IsPlay(tagSound id)
{
	int result = CheckSoundMem(m_hdl[id]);
	// 1は再生中
	// return CheckSoundMem(m_hndl[id]) == 1 ? true : false; 満たしていたら左の結果(true)、以外だったら右の結果(false)
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

