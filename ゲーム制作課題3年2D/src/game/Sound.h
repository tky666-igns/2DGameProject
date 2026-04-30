#pragma once
#include <DxLib.h>

class Sound
{
public:
	enum tagSound
	{
		BGM_TITLE,
		BGMID_GAME,
		BGMID_RESULT,
		SEID_EXPLOSION,

		SOUND_NUM
	};
	int m_hndl[SOUND_NUM];
	//データを初期化
	void Init();

	//音楽データをロード

	void Load();

	//終了前に行う
	void Exit();

	//音の再生要請
	void RequestSound(int soundID, int type);

	//音の停止要請
	void StopSound(int soundID);

	//すべての音の停止要請
	void StopAllSound();
};