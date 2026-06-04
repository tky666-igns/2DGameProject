#include "TrapManager.h"
#include <math.h>

static const char TRAP_PATH[] = "graph/Ishi.png";


// 初期化
void TrapManager::Init()
{
	for(int i = 0; i < TRAP_MAX; i++)
	{
		m_trap[i].Init();
	}
}

// ロード
void TrapManager::Load()
{
	int THdl = LoadGraph(TRAP_PATH);

	for (int i = 0; i < TRAP_MAX; i++)
	{
		m_trap[i].Load(THdl);
	}
}

// 終了
void TrapManager::Exit()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		m_trap[i].Exit();
	}
}

// 
void TrapManager::Step(VECTOR playerPos)
{

}

// 描画
void TrapManager::Draw()
{
	for (int i = 0; i < TRAP_MAX; i++)
	{
		m_trap[i].Draw();
	}
}

// トラップをリクエスト
void TrapManager::Request()
{
	VECTOR TrapPos = { (float)GetRand(920) - 460.0f, 10.0f, (float)GetRand(920) - 460.0f };

	for (int i = 0; i < TRAP_MAX; i++)
	{
		if (m_trap[i].Request(TrapPos) == true)
		{
			
		}
	}
}