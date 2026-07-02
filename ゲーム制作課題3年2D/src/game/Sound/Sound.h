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
private:

	static int m_hdl[SOUND_NUM];

public:
	//データを初期化
	static void Init();

	//音楽データをロード
	static void Load();

	//終了前に行う
	static void Exit();

	//音の再生要請
	static bool Play(tagSound id, int type = DX_PLAYTYPE_BACK,
				bool isStart = true);

	//音の停止要請
	static void Stop(tagSound id);

	//すべての音の停止要請
	static void AllStop();

	// 再生中か
	static bool IsPlay(tagSound id);
};