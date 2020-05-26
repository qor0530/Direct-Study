#include "GameSystem.h"
void GameSystem::Init(HWND hWnd) //
{
	D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory);
	// Obtain the size of the drawing area.
	RECT rc;
	GetClientRect(hWnd, &rc);

	// Create a Direct2D render target			
		pD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
				rc.right - rc.left,
				rc.bottom - rc.top)
		),
		&pRT 
	);

		CoCreateInstance(CLSID_WICImagingFactory, 
	NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pIWICFactory)); //비트맵 받을 준비

		pIWICFactory->CreateDecoderFromFilename(
			L"1.png",
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnLoad,
			&pDecoder
		);

		pDecoder->GetFrame(0, &pSource);
		pIWICFactory->CreateFormatConverter(&pConverter);
		pConverter->Initialize(
			pSource,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.f,
			WICBitmapPaletteTypeMedianCut
		);
		pRT->CreateBitmapFromWicBitmap(
			pConverter,
			NULL,
			&cBitmap
		);
		pRT->CreateBitmapBrush(cBitmap,
			&m_pBitmapBrush);

		pRT->BeginDraw(); //그리기 시작 
		pRT->FillRectangle(
			D2D1::RectF(
				rc.left + 100.0f,
				rc.top + 100.0f,
				rc.right - 100.0f,
				rc.bottom - 100.0f),
			m_pBitmapBrush);
		pRT->EndDraw(); //그리기 끝
}

void GameSystem::Update()
{
}

void GameSystem::Render()
{
}

void GameSystem::Release()
{
}
