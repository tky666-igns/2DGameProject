#pragma once

// ゲームで使うボタン
#define KEY_UP			(0b1)		//上ボタン
#define KEY_DOWN		(0b10)		//下ボタン
#define KEY_RIGHT		(0b100)		//右ボタン
#define KEY_LEFT		(0b1000)	//左ボタン
#define KEY_SHOT		(0b10000)	//弾発射ボタン


//キー入力情報の初期化
void InitInput();
//キー入力情報を更新
void UpdateInput();
//キーを押したか（通常判定）
bool IsInputRep(unsigned int key);
//キーを押したか（トリガー判定）
bool IsInputTrg(unsigned int key);
