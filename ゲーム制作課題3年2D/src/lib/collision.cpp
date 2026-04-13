#include <DxLib.h>


//-------------------------------
//		点と四角のあたり判定
//-------------------------------
int	ChenkHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
	int sizeX, int sizeY)
{
	int ret = 0;
	if (dotPos.x > squarePos.x - sizeX		// 四角の左端チェック
		&& dotPos.x < squarePos.x + sizeX	// 四角の右端チェック
		&& dotPos.y > squarePos.y - sizeY	// 四角の上端チェック
		&& dotPos.y < squarePos.y + sizeY)	// 四角の下端チェック
	{
		ret = 1;
	}
	return ret;
}


//-------------------------------
//		矩形同士のあたり判定
//-------------------------------
int	ChenkHitSquareToSquare(VECTOR squarePos1, VECTOR squarePos2,
	int sizeX1, int sizeY1, int sizeX2, int sizeY2)
{
	int ret = 0;
	if (squarePos1.x - sizeX1 < squarePos2.x + sizeX2		// 四角の左端チェック
		&& squarePos1.x + sizeX1 > squarePos2.x - sizeX2	// 四角の右端チェック
		&& squarePos1.y - sizeY1 < squarePos2.y + sizeY2	// 四角の上端チェック
		&& squarePos1.y + sizeY1 > squarePos2.y - sizeY2)	// 四角の下端チェック
	{
		ret = 1;
	}
	return ret;
}


//-------------------------------
//		円同士のあたり判定
//-------------------------------
int	ChenkHitCircleToCircle(VECTOR circlePos1, VECTOR circlePos2, int radius1, int radius2)
{
	int ret = 0;
	float lenX = circlePos1.x - circlePos2.x;
	float lenY = circlePos1.y - circlePos2.y;
	float radLen = (float)(radius1 + radius2);
	if (lenX * lenX + lenY * lenY < radLen * radLen)
	{
		ret = 1;
	}
	return ret;
}