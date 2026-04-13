#include <DxLib.h>
#include "input.h"

// キーボード入力構造体
typedef struct{
	unsigned int m_nowKey;	// 今回入力したキー
	unsigned int m_preKey;	// 前回入力したキー
}INPUT_DATA;

static INPUT_DATA g_inputData = { 0 };


//-------------------------------
//		キー入力更新
//-------------------------------
void UpdateKeyInput(void)
{
	// 前回のデータ更新
	g_inputData.m_preKey = g_inputData.m_nowKey;
	// 一度データを0にする
	g_inputData.m_nowKey = 0;

	// 上を押した
	if(CheckHitKey(KEY_INPUT_UP)) g_inputData.m_nowKey |= KEY_UP;
	// 下を押した
	if(CheckHitKey(KEY_INPUT_DOWN)) g_inputData.m_nowKey |= KEY_DOWN;
	// 右を押した
	if(CheckHitKey(KEY_INPUT_RIGHT)) g_inputData.m_nowKey |= KEY_RIGHT;
	// 左を押した
	if(CheckHitKey(KEY_INPUT_LEFT)) g_inputData.m_nowKey |= KEY_LEFT;
	// Zを押した
	if(CheckHitKey(KEY_INPUT_Z)) g_inputData.m_nowKey |= KEY_SHOT;
}


//-------------------------------
//		キー入力判定(通常判定)
//-------------------------------
int IsKeyInputRep(unsigned int uKey)
{
	if(g_inputData.m_nowKey & uKey) return 1;
	else return 0;
}


//-------------------------------
//		キー入力判定(トリガー判定)
//-------------------------------
int IsKeyInputTrg(unsigned int uKey)
{
	if((g_inputData.m_nowKey & uKey)
		&& !(g_inputData.m_preKey & uKey)) return 1;
	else return 0;
}
