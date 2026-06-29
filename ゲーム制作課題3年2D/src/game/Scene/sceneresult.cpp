#include "sceneresult.h"


SceneResult::SceneResult()
{
	SceneResult::Init();
}

SceneResult::~SceneResult()
{
	Exit();
}



int SceneResult::Loop() 
{
	int result = -1;

	switch (m_state)
	{
	case SceneResult::INIT:
		Init();
		m_state = SceneResult::LOAD;
		break;
	case SceneResult::LOAD:
		Load();
		m_sound.RequestSound(Sound::BGM_TITLE, DX_PLAYTYPE_LOOP);
		// フェードイン開始
		RequestFadeIn();
		m_state = SceneResult::STARTWAIT;
		break;
	case SceneResult::STARTWAIT:
		Step();
		if (IsEndFadeIn())
		{
			m_state = SceneResult::MAIN;
		}
		break;
	case SceneResult::MAIN:
		Step();
		if (IsInputTrg(KEY_SHOT))
		{
			RequestFadeOut();
			m_state = SceneResult::ENDWAIT;
		}
		break;
	case SceneResult::ENDWAIT:
		if (IsEndFadeOut())
		{
			m_state = SceneResult::END;
		}
		break;
	case SceneResult::END:
		Exit();
		// 破棄
		m_sound.StopAllSound();
		m_state = SceneResult::INIT;
		result = 0;
		break;
	}

	return result;
}

void SceneResult::Draw() {
	switch (m_state)
	{
	case SceneResult::STARTWAIT:
	case SceneResult::MAIN:
	case SceneResult::ENDWAIT:
		DrawFormatString(20, 20, WHITE, "次のシーンへ(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 1.3),
			(int)WINDOW_SIZE_Y / 1.3, 1.0f, 0.0f, m_hdl, TRUE);
		break;
	}
}

void SceneResult::Init()
{
	m_state = INIT;
	m_hdl = -1;
}

void SceneResult::Load()
{
	if (m_hdl == -1)
	{
		m_hdl = LoadGraph("data/game/RESULT.png");
	}
}

void SceneResult::Step()
{

}

void SceneResult::Exit()
{
	if (m_hdl != -1)
	{
		DeleteGraph(m_hdl);
		m_hdl = -1;
	}
}