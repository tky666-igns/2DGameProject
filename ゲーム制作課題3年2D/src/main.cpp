#include <DxLib.h>
#include "game/Scene/scene.h"
#include "lib/input.h"
#include "lib/debug.h"


// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);
#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// 一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);
	SetTransColor(255, 0, 255);	// 透過色指定

	SceneMana g_sm;
	Fps g_fps;
	FADE g_fade;
	g_fade.Init();
	g_fps.Init();

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		if (!g_fps.IsNextFrame())continue;
		// 描画した画像をすべて消す
		ClearDrawScreen();

		// ゲーム本体の命令はこれより下に書く
		// 計算処理
		g_sm.Step();
		g_fps.Step();
		// 描画処理
		g_sm.Draw();
		g_fps.Print();

		ScreenFlip();

	}
	// 終了前処理
	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
