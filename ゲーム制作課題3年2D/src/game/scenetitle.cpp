#include "scenetitle.h"


// コンストラクタ
SceneTitle::SceneTitle()
{
	m_state = INIT;
	m_hdl = -1;
}
// デストラクタ
SceneTitle::~SceneTitle()
{

}

// 実行処理
int SceneTitle::Loop() 
{

	switch (m_state)
	{
	case SceneTitle::INIT:
		// 初期化関連
		//m_hdl = -1;
		m_state = SceneTitle::LOAD;
		break;
	case SceneTitle::LOAD:
		if (m_hdl == -1)
		{
			m_hdl = LoadGraph("data/game/TITLE.png");
		}
		// BGM鳴らす
		m_sound.RequestSound(m_sound.BGM_TITLE, DX_PLAYTYPE_LOOP);
		// フェードイン開始
		m_fade.RequestFadeIn();
		m_state = SceneTitle::STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		if (m_fade.IsEndFadeIn()) 
		{
			m_state = SceneTitle::MAIN;
		}
		break;
	case SceneTitle::MAIN:
		// Zキーで次の場面へ
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// フェードアウト開始
			m_fade.RequestFadeOut();
			m_state = SceneTitle::ENDWAIT;
		}
		break;
	case SceneTitle::ENDWAIT:
		if (m_fade.IsEndFadeOut())
		{
			m_state = SceneTitle::END;
		}
		break;
	case SceneTitle::END:
		// 音楽止めて次へ
		m_sound.StopAllSound();
		if (m_hdl != -1) 
		{
			DeleteGraph(m_hdl);
			m_hdl = -1;
		}
		m_state = SceneTitle::INIT;
		break;
	}

	return 0;
}

// 描画処理
void SceneTitle::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		// タイトル画面描画
		DrawFormatString(20, 20, WHITE, "タイトルシーン(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 2),
			(int)WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_hdl, TRUE);
		break;
	}
}

