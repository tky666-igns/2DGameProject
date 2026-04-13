#pragma once

#define KEY_UP		(0x01)	// 上
#define KEY_DOWN	(0x02)	// 下
#define KEY_RIGHT	(0x04)	// 右
#define KEY_LEFT	(0x08)	// 左
#define KEY_SHOT	(0x10)	// ショット

// キー入力更新
void UpdateKeyInput();
// キー入力判定(通常判定)
int IsKeyInputRep(unsigned int uKey);
// キー入力判定(トリガー判定)
int IsKeyInputTrg(unsigned int uKey);

