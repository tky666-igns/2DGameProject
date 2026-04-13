#pragma once



class Scene
{
private:
	enum tagSceneGame {
		SCENEGAME_INIT,		// 初期化
		SCENEGAME_LOAD,		// データロード
		SCENEGAME_MAIN,		// メイン処理
		SCENEGAME_END,		// 終了処理

		SCENEGAME_NUM
	};
	tagSceneGame m_state;

public:
	void Step();
	void Draw();

};




//void StepGame();
//void DrawGame();

