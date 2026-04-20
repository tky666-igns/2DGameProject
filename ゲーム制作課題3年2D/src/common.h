#pragma once

// ウィンドウのサイズ
static const int WINDOW_SIZE_X = 640;
static const int WINDOW_SIZE_Y = 480;

// ゲーム中の重力
static const float GRAVITY = 0.1f;

// ステージの縦横の数
static const int STAGE_X	= 40;
static const int STAGE_Y	= 15;

// ステージのタイプ
enum tagStageID{
	STAGEID_BLOCK,		// 床・壁
	STAGEID_BOX,		// 宝箱

	STAGEID_NUM
};

// プレイヤーのサイズ
static const int PLAYER_SIZE_X = 32;
static const int PLAYER_SIZE_Y = 32;

// ステージに配置する物体のサイズ
static const int OBJECT_SIZE_X = 32;
static const int OBJECT_SIZE_Y = 32;


static const int RED = GetColor(255, 0, 0);
static const int BLUE = GetColor(0, 0, 255);
static const int GREEN = GetColor(0, 255, 0);
static const int WHITE = GetColor(255, 255, 255);
