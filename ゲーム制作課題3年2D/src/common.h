#pragma once

// ウィンドウのサイズ
#define WINDOW_SIZE_X (640)		
#define WINDOW_SIZE_Y (480)

// ゲーム中の重力
#define GRAVITY	(0.1f)

// ステージの縦横の数
#define STAGE_X	(40)
#define STAGE_Y	(15)

// ステージのタイプ
enum tagStageID{
	STAGEID_BLOCK,		// 床・壁
	STAGEID_BOX,		// 宝箱

	STAGEID_NUM
};

// プレイヤーのサイズ
#define PLAYER_SIZE_X (32)		
#define PLAYER_SIZE_Y (32)

// ステージに配置する物体のサイズ
#define OBJECT_SIZE_X		(32)
#define OBJECT_SIZE_Y		(32)


