#pragma once
#include "IObject.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

class CObjImage : public IObject
{
private:
	cv::String mFile;
	Mat mcvImage;
	Mat mcvDosaic;
	POINT pntStart;



public:
	CObjImage();
	~CObjImage();
	CString getFileName();

	void setFileName(CString file);
	virtual void Draw(HDC hdc);	
	void doDosaic();
protected:
	void cleanup(); 
	void DrawDosaic(HDC hDC);
	void DrawOrigin(HDC hDC);
	void FillBitmapInfo(BITMAPINFO& bmi, int width, int height, int bpp);

};

