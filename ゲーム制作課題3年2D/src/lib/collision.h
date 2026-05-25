#pragma once

#include <DxLib.h>

//		点と四角のあたり判定
//	dotPos		:	点の座標
//	squarePos	:	四角形の中心位置
//	sizeX,Y	:	四角形の縦と横のサイズ(中心からの距離)
//	@return		:	0=ヒットなし、1=ヒット
bool CheckHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
	int width, int height);

//		矩形同士のあたり判定
//	squarePos	:	各矩形の中心位置
//	sizeX,Y		:	各矩形の縦と横のサイズ(中心からの距離)
//	@return		:	0=ヒットなし、1=ヒット
bool CheckHitSquareToSquare(VECTOR squarePos1, int width1, int height1,
	VECTOR squarePos2, int width2, int height2);

//		円同士のあたり判定
//	circlePos	:	各円の中心位置
//	radius		:	各円の半径
//	@return		:	0=ヒットなし、1=ヒット
bool CheckHitCircleToCircle(VECTOR circlePos1, int radius1,
	VECTOR circlePos2, int radius2);
