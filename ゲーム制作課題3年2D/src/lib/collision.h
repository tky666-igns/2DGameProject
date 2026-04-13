#pragma once

#include <DxLib.h>

//		点と四角のあたり判定
//	dotPos		:	点の座標
//	squarePos	:	四角形の中心位置
//	sizeX,Y	:	四角形の縦と横のサイズ(中心からの距離)
//	@return		:	0=ヒットなし、1=ヒット
int		ChenkHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
								int sizeX, int sizeY);

//		矩形同士のあたり判定
//	squarePos	:	各矩形の中心位置
//	sizeX,Y		:	各矩形の縦と横のサイズ(中心からの距離)
//	@return		:	0=ヒットなし、1=ヒット
int		ChenkHitSquareToSquare(VECTOR squarePos1, VECTOR squarePos2,
								int sizeX1, int sizeY1, int sizeX2, int sizeY2);

//		円同士のあたり判定
//	circlePos	:	各円の中心位置
//	radius		:	各円の半径
//	@return		:	0=ヒットなし、1=ヒット
int		ChenkHitCircleToCircle(VECTOR circlePos1, VECTOR circlePos2,
								int radius1, int radius2);
