#include "scenegame.h"



// 初期化処理
void Scene::Init() {
	m_state = INIT;
	m_endWaitCount = END_WAIT;
}

// デストラクタ
Scene::~Scene()
{
	Exit();
}

// 実行処理
int Scene::Loop()
{
	switch (m_state)
	{
	case INIT:
		m_stage.Init();
		m_player.Init();
		m_state = LOAD;
		break;
	case LOAD:
		m_stage.Load();
		m_player.Load();
		m_fade.RequestFadeIn();
		m_state = MAIN;
		break;
	case STARTWAIT:
		if (m_fade.IsEndFadeIn())
		{
			m_state = MAIN;
		}
		break;
	case MAIN:
		m_stage.Update();
		m_player.Update();
		//HitCheckPlayerToStage();
		break;
	case ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}

		break;
	case END:
		m_stage.Exit();
		m_player.Exit();
		m_state = INIT;
		return m_res;
		break;
	}

	return 0;
}

// ロード
void Scene::Load()
{
	m_player.Load();
	m_stage.Load();
}

// メイン処理
void Scene::Step()
{

}

// 終了前処理
void Scene::Exit()
{
	m_player.Exit();
	m_stage.Exit();
}

// 描画処理
void Scene::Draw()
{
	m_player.Draw();
	m_stage.Draw();
}

