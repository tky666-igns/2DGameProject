#include <stdio.h>
#include "stage.h"
#include "../common.h"
#include "player.h"

STAGE_DATA g_stage = { 0 };


//-------------------------------
//		ステージ初期化
//-------------------------------
void InitStage()
{
	// ステージデータ関連
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			g_stage.m_stageData[y][x].m_state = -1;
			g_stage.m_stageData[y][x].m_pos.x = (float)(OBJECT_SIZE_X / 2 + OBJECT_SIZE_X * x);
			g_stage.m_stageData[y][x].m_pos.y = (float)(OBJECT_SIZE_Y / 2 + OBJECT_SIZE_Y * y);
		}
	}

	// 画像関連
	for (int i = 0; i < STAGEID_NUM; i++)
	{
		g_stage.m_graphHndl[i] = -1;
	}
}


//-------------------------------
//		ステージロード
//-------------------------------
void LoadStage()
{
	// ステージデータ------------------------------------------
	FILE *fp;
	if (fopen_s(&fp, "stage/stage001.csv", "r") != 0) return;

	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if(fscanf_s(fp, "%d", &g_stage.m_stageData[y][x].m_state) == 0)
			{
				g_stage.m_stageData[y][x].m_state = -1;
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
		g_stage.m_graphHndl[i] = LoadGraph(graphName[i]);
	}
	//---------------------------------------------------------
}


//-------------------------------
//		ステージ更新
//-------------------------------
void UpdateStage()
{
}


//-------------------------------
//		ステージ描画
//-------------------------------
void DrawStage()
{
	VECTOR offset = GetOffset();

	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if (g_stage.m_stageData[y][x].m_state == -1) continue;
			int posX = (int)(g_stage.m_stageData[y][x].m_pos.x - offset.x);
			int posY = (int)(g_stage.m_stageData[y][x].m_pos.y - offset.y);
			DrawRotaGraph(posX, posY, 1.0, 0.0,
				g_stage.m_graphHndl[g_stage.m_stageData[y][x].m_state], TRUE);
		}
	}
}


//-------------------------------
//		ステージ破棄
//-------------------------------
void ExitStage()
{
	for (int i = 0; i < STAGEID_NUM; i++)
	{
		if (g_stage.m_graphHndl[i] != -1)
		{
			DeleteGraph(g_stage.m_graphHndl[i]);
		}
	}
}