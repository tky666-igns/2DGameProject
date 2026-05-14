#include <DxLib.h>
#include "input.h"



//キー入力情報の初期化----------------
void Input::InitInput()
{
	m_nowKey = m_preKey = 0;
	m_nowKey = 0;


	if (CheckHitKey(KEY_INPUT_UP)) m_nowKey |= KEY_UP;

}

//	キー入力更新
void Input::UpdateInput()
{
	// 前回のデータ更新
	m_preKey = m_nowKey;
	// 一度データを0にする
	m_nowKey = 0;

	// 上を押した
	if(CheckHitKey(KEY_INPUT_UP)) m_nowKey |= KEY_UP;
	// 下を押した
	if(CheckHitKey(KEY_INPUT_DOWN)) m_nowKey |= KEY_DOWN;
	// 右を押した
	if(CheckHitKey(KEY_INPUT_RIGHT)) m_nowKey |= KEY_RIGHT;
	// 左を押した
	if(CheckHitKey(KEY_INPUT_LEFT)) m_nowKey |= KEY_LEFT;
	// Zを押した
	if(CheckHitKey(KEY_INPUT_Z)) m_nowKey |= KEY_SHOT;
}


//	キー入力判定(通常判定)
bool Input::IsInputRep(unsigned int key)
{
	if ((m_nowKey & key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//	キー入力判定(トリガー判定)
bool Input::IsInputTrg(unsigned int key)
{
	if ((m_nowKey & key) != 0
		&& !(m_preKey & key) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
