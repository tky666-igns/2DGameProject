#include <DxLib.h>
#include "input.h"


typedef struct {
	unsigned int m_nowKey;
	unsigned int m_PrevKey;
}INPUT_DATA;
static INPUT_DATA g_input;


//キー入力情報の初期化----------------
void InitInput()
{
	g_input.m_nowKey = g_input.m_PrevKey = 0;


	//if (CheckHitKey(KEY_INPUT_UP)) g_input.m_nowKey |= KEY_UP;

}

//	キー入力更新
void UpdateInput()
{
	// 前回のデータ更新
	g_input.m_PrevKey = g_input.m_nowKey;
	// 一度データを0にする
	g_input.m_nowKey = 0;

	// 上を押した
	if(CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) g_input.m_nowKey |= KEY_UP;
	// 下を押した
	if(CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) g_input.m_nowKey |= KEY_DOWN;
	// 右を押した
	if(CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) g_input.m_nowKey |= KEY_RIGHT;
	// 左を押した
	if(CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) g_input.m_nowKey |= KEY_LEFT;
	// Zを押した
	if(CheckHitKey(KEY_INPUT_Z)) g_input.m_nowKey |= KEY_SHOT;
}


//	キー入力判定(通常判定)
bool IsInputRep(unsigned int key)
{
	if ((g_input.m_nowKey & key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//	キー入力判定(トリガー判定)
bool IsInputTrg(unsigned int key)
{
	if ((g_input.m_nowKey & key) != 0
		&& !(g_input.m_PrevKey & key) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
