#pragma once


//	フェードリセット
void ResetFade();
//	フェード更新
void UpdateFade();
//	フェード描画
void DrawFade();


//	フェードインリクエスト
void RequestFadeIn();
//	フェードアウトリクエスト
void RequestFadeOut();
//	フェードインが終了したか
int IsEndFadeIn();
//	フェードアウトが終了したか
int IsEndFadeOut();
