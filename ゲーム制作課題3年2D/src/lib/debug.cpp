#include <DxLib.h>

// FPS表示用構造体
typedef struct{
	double m_fps;		// 実際のfps
	int m_nowTime;		// 現在のPC時間
	int m_prevTime;	// 1秒前のPC時間
	int m_count;		// カウント用
}FpsData;
static FpsData g_fps = { 0.0 };



//-------------------------------
//		FPS表示関数
//-------------------------------
void PrintFps(void)
{
	// 一定カウントが溜まったら計算開始
	if (g_fps.m_count == 59)
	{
		// 現在時間と1秒前の時間を更新
		g_fps.m_prevTime = g_fps.m_nowTime;
		g_fps.m_nowTime = GetNowCount();
		// FPS計算
		int time = g_fps.m_nowTime - g_fps.m_prevTime;
		g_fps.m_fps = 1000.0 / (time / 60.0);
		// カウントは0に戻す
		g_fps.m_count = 0;
	}
	else g_fps.m_count++;

	// FPSは常に表示を続ける
	DrawFormatString(16, 16, GetColor(255, 255, 255),
		"FPS:%.1lf", g_fps.m_fps);
}