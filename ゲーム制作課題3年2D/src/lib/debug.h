#pragma once

static const int FRAME_RATE(60);
static const int FRAME_RATE_MILI_SECOND(1000 / FRAME_RATE - 1);

class Fps
{
private:
	float m_frameRate;	// 実際のfps保存
	int m_nowTime;		// 現在のPC時間
	int m_prevTime;		// 1秒前のPC時間
	int m_prevDrawTime;	// 時間描画
	int m_count;		// カウント用

public:
	// 初期化
	void Init();
	// 次のフレーム
	bool IsNextFrame();
	// 実行
	void Step();
	// FPS表示関数
	void Print(void);
};




