#pragma once
#include <opencv2/core/mat.hpp>
using namespace cv;

class CDosaic
{
public:
	CDosaic(Mat& matD, Mat& matO);
private:
	Mat& mmatOrigin;
	Mat& mmatDosaic;
	void Dot(int type, int x, int y, int r);

	void SetPixel(int x, int y);
public:
	void Dosaic();
};


