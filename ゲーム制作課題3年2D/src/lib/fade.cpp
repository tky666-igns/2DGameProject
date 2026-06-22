#include "fade.h"




//	フェード初期化
void FADE::Init()
{
	m_state = FADE_NON;
	m_count = 0;
}

//	フェード更新
void FADE::Update()
{
	switch (m_state)
	{
	case FADE_IN:
		m_count -= FADE_SPD;
		if (m_count <= 0)
		{
			m_count = 0;
			m_state = FADE_NON;
		}
		break;
	case FADE_OUT:
		m_count += FADE_SPD;
		if (m_count >= 255)
		{
			m_count = 255;
			m_state = FADE_OUT_WAIT;
		}
		break;
	}
}

//	フェード描画
void FADE::Draw()
{
	switch (m_state)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		// ここでアルファ値をセットする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_count);
		// フェード用の黒い四角を表示
		DrawBox(0, 0, FADE_SIZE_X, FADE_SIZE_Y,
			GetColor(0, 0, 0), TRUE);
		// 他に影響を及ぼさないように、ここで設定を無効にする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}


//	フェードインリクエスト
void FADE::RequestFadeIn()
{
	// 徐々に明るくするので、最初はMAXに
	m_count = 255;
	m_state = FADE_IN;
}

//	フェードアウトリクエスト
void FADE::RequestFadeOut()
{
	m_count = 0;
	m_state = FADE_OUT;
}

//	フェードインが終了したか
bool FADE::IsEndFadeIn()
{
	if (m_state == FADE_IN)
	{
		return false;
	}
	else
		return true;
}

//	フェードアウトが終了したか
bool FADE::IsEndFadeOut()
{
	if (m_state == FADE_OUT)
	{
		return false;
	}
	else
		return true;
}