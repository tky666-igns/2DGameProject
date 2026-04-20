#pragma once



class Scene
{
private:
	enum tagSceneGame {
		SCENEGAME_INIT,		// 初期化
		SCENEGAME_LOAD,		// データロード
		SCENEGAME_STARTWAIT,
		SCENEGAME_MAIN,		// メイン処理
		SCENEGAME_ENDWAIT,
		SCENEGAME_END,		// 終了処理

		SCENEGAME_NUM
	};
	tagSceneGame m_state;
	int m_res;
public:
	void Init();
	int Step();
	void Draw();
	void HitCheck();
};




//void StepGame();
//void DrawGame();

