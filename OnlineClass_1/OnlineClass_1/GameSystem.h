#pragma once
#include <d2d1.h>
#include <wincodec.h>
class GameSystem
{
private:
	ID2D1Factory* pD2DFactory = NULL; //다이렉트 2d를 사용하기시작
	ID2D1HwndRenderTarget* pRT = NULL; //도화지 
	ID2D1SolidColorBrush* pBlackBrush = NULL; //도구 (도장)

	IWICBitmapDecoder *pDecoder = NULL;
	IWICBitmapFrameDecode *pSource = NULL;
	IWICStream *pStream = NULL;
	IWICFormatConverter *pConverter = NULL;
	IWICBitmapScaler *pScaler = NULL;
	IWICImagingFactory *pIWICFactory;
	ID2D1Bitmap *cBitmap;
	ID2D1BitmapBrush *m_pBitmapBrush;
public:
	void Init(HWND hWnd);
	void Update();
	void Render();
	void Release();
};