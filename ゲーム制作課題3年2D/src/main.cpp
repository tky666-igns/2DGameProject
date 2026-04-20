#include <DxLib.h>
#include "game/scenegame.h"
#include "lib/input.h"
#include "lib/debug.h"


// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// 一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);
	SetTransColor(255, 0, 255);	// 透過色指定

	Scene g_game;

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		ClearDrawScreen();

		// 計算処理
		UpdateKeyInput();
		g_game.Step();
		// 描画処理
		g_game.Draw();

		ScreenFlip();

	}

	// 終了前処理
	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
