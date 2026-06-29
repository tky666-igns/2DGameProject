#include "scenegame.h"



Scene::Scene()
{
	m_state = INIT;
}

Scene::~Scene()
{
	Exit();
}


// 実行処理
int Scene::Loop()
{
	int result = -1;

	switch (m_state)
	{
	case Scene::INIT:
		Init();
		m_state = LOAD;
		break;
	case Scene::LOAD:
		Load();
		m_sound.RequestSound(Sound::BGMID_GAME, DX_PLAYTYPE_LOOP);
		RequestFadeIn();
		m_state = Scene::MAIN;
		break;
	case Scene::STARTWAIT:
		if (IsEndFadeIn())
		{
			m_state = Scene::MAIN;
		}
		break;
	case Scene::MAIN:
		Step();
		//当たり判定処理
		m_hit.HitCheckPlayerToStage();

		if ( m_hit.HitCheckPlayerToTrap() == true)
		{
			m_endWaitCount = END_WAIT;
			RequestFadeOut();
			m_state = Scene::ENDWAIT;
		}
		break;
	case Scene::ENDWAIT:
		if (IsEndFadeOut()) {
			m_state = Scene::END;
		}
		m_endWaitCount--;
		break;
	case Scene::END:
		m_state = Scene::INIT;
		result = 0;
		break;
	}

	return result;
}

// 描画処理
void Scene::Draw()
{
	switch (m_state)
	{
	case Scene::STARTWAIT:
	case Scene::MAIN:
	case Scene::ENDWAIT:
		m_player.Draw();
		m_stage.Draw();
		break;
	}
}

// 初期化
void Scene::Init()
{
	m_stage.Init();
	m_player.Init();
	m_endWaitCount = 0;
	m_endWaitCount = END_WAIT;
}

// データロード
void Scene::Load()
{
	m_stage.Load();
	m_player.Load();
}

// メイン処理
void Scene::Step()
{
	m_stage.Update();
	m_player.Update();
}

// 終了前処理
void Scene::Exit()
{
	m_stage.Exit();
	m_player.Exit();
}

