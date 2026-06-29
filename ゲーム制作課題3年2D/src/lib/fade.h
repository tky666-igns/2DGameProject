#pragma once
#include <DxLib.h>
#include "../common.h"


//フェードの初期化
void InitFade();
//フェードの処理更新
void StepFade();
//フェードの描画管理
void DrawFade();
//フェードインリクエスト
void RequestFadeIn();
//フェードアウトリクエスト
void RequestFadeOut();
//フェードインが終了したか
bool IsEndFadeIn();
//フェードアウトが終了したか
bool IsEndFadeOut();


