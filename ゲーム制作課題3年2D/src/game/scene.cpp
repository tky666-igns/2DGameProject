#include "scene.h"

// 初期化処理
void SceneMana::Init() {
	m_sceneID = SCENE_TITLE;
	m_title.Init();
	m_game.Init();
	m_resualt.Init();
	m_fade.Init();
	m_sound.Init();
	m_sound.Load();
}

// デストラクタ
SceneMana::~SceneMana()
{
	Sound::Exit;
}

// 実行処理
int SceneMana::Loop()
{
	int result = -1;
	// ゲームが終了したか外部に伝えるため
	switch (m_sceneID)
	{
	case SceneMana::SCENE_TITLE:
		if (m_title.Loop() != -1)
		{
			m_sceneID = SceneMana::SCENE_GAME;
		}
		break;
	case SceneMana::SCENE_GAME:
		if (m_game.Step() != -1)
		{
			m_sceneID = SceneMana::SCENE_RESULT;
		}
		break;
	case SceneMana::SCENE_RESULT:
		if (m_resualt.Loop() != -1)
		{
			m_sceneID = SceneMana::SCENE_TITLE;


		}
		break;
	}
	// フェード処理の更新
	m_fade.Step();
	// 本編が終了したのか伝える
	return 0;
}

// 描画処理
void SceneMana::Draw()
{
	switch (m_sceneID)
	{
	case SceneMana::SCENE_TITLE:
		m_title.Draw();
		break;
	case SceneMana::SCENE_GAME:
		m_game.Draw();
		break;
	case SceneMana::SCENE_RESULT:
		m_resualt.Draw();
		break;
	}
	m_fade.Draw();

}



