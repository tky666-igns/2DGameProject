#include <stdio.h>
#include "stage.h"

//-------------------------------
//		ステージ初期化
//-------------------------------
void Stage::Init()
{
	// ステージデータ関連
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			m_stageData[y][x].m_state = -1;
			m_stageData[y][x].m_pos.x = 
				(float)(OBJECT_SIZE_X / 2 + OBJECT_SIZE_X * x);
			m_stageData[y][x].m_pos.y = 
				(float)(OBJECT_SIZE_Y / 2 + OBJECT_SIZE_Y * y);
		}
	}

	// 画像関連
	for (int i = 0; i < STAGEID_NUM; i++)
	{
		m_graphHdl[i] = -1;
	}
}


//-------------------------------
//		ステージロード
//-------------------------------
void Stage::Load()
{
	// ステージデータ------------------------------------------
	FILE *fp;
	if (fopen_s(&fp, "stage/stage001.csv", "r") != 0) return;

	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if(fscanf_s(fp, "%d", &m_stageData[y][x].m_state) == 0)
			{
				m_stageData[y][x].m_state = -1;
			}
			fgetc(fp);
		}
	}

	fclose(fp);
	//---------------------------------------------------------

	// 画像関連------------------------------------------------
	char graphName[][64] = {
		"graph/01.png", "graph/02.png"
	};
	for (int i = 0; i < STAGEID_NUM; i++)
	{
		m_graphHdl[i] = LoadGraph(graphName[i]);
	}
	//---------------------------------------------------------
}


//-------------------------------
//		ステージ更新
//-------------------------------
void Stage::Update()
{
}


//-------------------------------
//		ステージ描画
//-------------------------------
void Stage::Draw()
{
	VECTOR offset = m_player.GetOffset();

	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if (m_stageData[y][x].m_state == -1) continue;
			int posX = (int)(m_stageData[y][x].m_pos.x - offset.x);
			int posY = (int)(m_stageData[y][x].m_pos.y - offset.y);
			DrawRotaGraph(posX, posY, 1.0, 0.0,
				m_graphHdl[m_stageData[y][x].m_state], TRUE);
		}
	}
}


//-------------------------------
//		ステージ破棄
//-------------------------------
void Stage::Exit()
{
	for (int i = 0; i < STAGEID_NUM; i++)
	{
		if (m_graphHdl[i] != -1)
		{
			DeleteGraph(m_graphHdl[i]);
		}
	}
}