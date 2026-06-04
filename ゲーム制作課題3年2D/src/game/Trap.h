#pragma once
#include <DxLib.h>

// １画面に出てくるトラップの数
static const int TRAP_MAX = 1;

class Trap
{
public:
	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();
private:
	VECTOR m_pos;		// 画面の表示位置
	int m_hdl;			// 画像ハンドル
	bool m_isActive;	// 生存フラグ
};
