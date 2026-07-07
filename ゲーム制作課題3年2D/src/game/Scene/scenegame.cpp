#include "scenegame.h"



Scene::Scene()
{
	m_state = INIT;
	Init();
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
		m_state = Scene::LOAD;
		break;
	case Scene::LOAD:
		Load();
		Sound::Play(Sound::BGMID_GAME, DX_PLAYTYPE_LOOP);
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

		if ( m_hit.HitCheckPlayerToTrap() == true || IsInputTrg(KEY_SHOT))
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
		Exit();
		Sound::AllStop();
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
		DrawFormatString(20, 20, WHITE, "GAME次のシーンへ(Z)");
		m_player.Draw();
		DrawStage();
		break;
	}
}

// 初期化
void Scene::Init()
{
	InitStage();
	m_player.Init();
	m_sound.Init();
	m_endWaitCount = 0;
	m_endWaitCount = END_WAIT;
}

// データロード
void Scene::Load()
{
	LoadStage();
	m_player.Load();
}

// メイン処理
void Scene::Step()
{
	UpdateStage();
	m_player.Update();
}

// 終了前処理
void Scene::Exit()
{
	ExitStage();
	m_player.Exit();
}

