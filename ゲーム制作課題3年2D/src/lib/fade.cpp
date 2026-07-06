#include "fade.h"

// フェード各種状態
enum tagFadeState
{
	FADE_NON,		// フェードなし
	FADE_IN,		// フェードイン中
	FADE_OUT,		// フェードアウト中（徐々に画面が消える）
	FADE_OUT_WAIT,	// フェードアウト後の真っ暗状態
};

typedef struct
{
	tagFadeState m_state;	//現在のフェード状況
	int  m_count;			//フェード時間のカウント
}FADE_DATA;

FADE_DATA g_fade;

//	フェード初期化
void InitFade()
{
	g_fade.m_state = FADE_NON;
	g_fade.m_count = 0;
}

//フェード処理更新
void StepFade()
{
	//状態に合わせて行動変化
	//実際に処理をするのは下記の二つだけ
	switch (g_fade.m_state)
	{
	case FADE_IN:
		//徐々に明るくするので、数値は減らす
		g_fade.m_count -= FADE_SPD;
		//０まで来たらフェードイン修了
		if (g_fade.m_count <= 0)
		{
			g_fade.m_count = 0;			//安全策
			g_fade.m_state = FADE_NON;
		}
		break;
	case FADE_OUT:
		//徐々に暗くするので、数値は増やす
		g_fade.m_count += FADE_SPD;
		//２５５まで来たらフェードアウト終了
		if (g_fade.m_count >= 255)
		{
			g_fade.m_count = 255;		//安全策
			g_fade.m_state = FADE_OUT_WAIT;
		}
		break;
	}
}

//フェード用の画像描画
void DrawFade()
{
	//黒画像を描画
	switch (g_fade.m_state)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		//アルファ値を調整する
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_fade.m_count);

		//フェード用の黒い四角を表示
		DrawBox(0, 0, FADE_SIZE_X, FADE_SIZE_Y,
			GetColor(0, 0, 0), TRUE);

		//使い終わったら元に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}

//フェードイン呼び出し
void RequestFadeIn()
{
	g_fade.m_count = 255;
	g_fade.m_state = FADE_IN;
}

//フェードアウト呼び出し
void RequestFadeOut()
{
	g_fade.m_count = 0;
	g_fade.m_state = FADE_OUT;
}

//フェードインが終了しているか
bool IsEndFadeIn()
{
	if (g_fade.m_state == FADE_IN)
	{
		return false;
	}
	else
		return true;
}

//フェードアウトが終了しているか
bool IsEndFadeOut()
{
	if (g_fade.m_state == FADE_OUT)
	{
		return false;
	}
	else
		return true;
}

