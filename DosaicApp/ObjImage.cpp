#include "pch.h"
#include "ObjImage.h"
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc.hpp>
#include "CDosaic.h"
using namespace cv;

CObjImage::CObjImage()
{
	pntStart.x = pntStart.y = 0;
}
CObjImage::~CObjImage()
{
	cleanup();
}

void CObjImage::setFileName(const CString file)
{
	cleanup();

	USES_CONVERSION;
	if (!file.IsEmpty())
	{
		double ratio;
		Mat mat;
		mFile = W2A(file);
		mat = imread(mFile);
		if (!mat.empty())
		{
			ratio = ((double)1280) / mat.cols;
			resize(mat, mcvImage, Size(), ratio, ratio);
			mat.release();
			mcvDosaic.create(mcvImage.rows, mcvImage.cols / 8 * 8, CV_8UC3);
		}
		
		doDosaic();
	}
}

void CObjImage::Draw(HDC hDC)
{
	DrawOrigin(hDC);
	DrawDosaic(hDC);

}

void CObjImage::cleanup()
{
	if (!mcvImage.empty())
	{
		mcvImage.release();
	}

	if (!mcvDosaic.empty())
	{
		mcvDosaic.release();
	}
}
CString CObjImage::getFileName()
{

	USES_CONVERSION;
	std::string str = mFile;
	return A2W(str.c_str());
}

void  CObjImage::FillBitmapInfo(BITMAPINFO& bmi, int width, int height, int bpp)
{


	BITMAPINFOHEADER* bmih = &(bmi.bmiHeader);

	memset(bmih, 0, sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = width;
	bmih->biHeight = -abs(height);
	bmih->biPlanes = 1;
	bmih->biBitCount = bpp;
	bmih->biCompression = BI_RGB;

	if (bpp == 8)  // 8bit bitmap, it is rare now.
	{
		RGBQUAD* palette = bmi.bmiColors;
		int i;
		for (i = 0; i < 256; i++)
		{
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
}


void CObjImage::DrawDosaic(HDC hDC)
{
	BITMAPINFO bmi;

	FillBitmapInfo(bmi, mcvImage.cols, mcvImage.rows, mcvImage.channels() * 8);

	CRect drect;
	drect.left = pntStart.x;
	drect.top = pntStart.y;
	drect.bottom = drect.top + mcvImage.rows;
	drect.right = drect.left + mcvImage.cols;

	SetStretchBltMode(hDC, COLORONCOLOR);
	StretchDIBits(hDC,
		1280,
		0,
		drect.right,  //显示窗口宽度
		drect.bottom,  //显示窗口高度
		0,
		0,
		drect.Width(),     //图像宽度
		drect.Height(),     //图像高度
		mcvImage.data,
		&bmi,
		DIB_RGB_COLORS,
		SRCCOPY);
	return;
}


void CObjImage::doDosaic()
{
	// TODO: Add your implementation code here.
	if (mcvImage.empty())
		return;

	CDosaic* dos = new CDosaic(mcvImage, mcvDosaic);
	dos->Dosaic();
}




void CObjImage::DrawOrigin(HDC hDC)
{
	BITMAPINFO bmi;

	FillBitmapInfo(bmi, mcvDosaic.cols, mcvDosaic.rows, mcvDosaic.channels() * 8);

	CRect drect;
	drect.left = pntStart.x;
	drect.top = pntStart.y;
	drect.bottom = drect.top + mcvDosaic.rows;
	drect.right = drect.left + mcvDosaic.cols;

	SetStretchBltMode(hDC, COLORONCOLOR);
	StretchDIBits(hDC,
		0,
		0,
		drect.right,  //显示窗口宽度
		drect.bottom,
		0,
		0,
		drect.Width(),
		drect.Height(),
		mcvDosaic.data,
		&bmi,
		DIB_RGB_COLORS,
		SRCCOPY);
	return;
}
