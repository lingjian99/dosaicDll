#include "pch.h"
#include "CDosaic.h"
#include <comdef.h> 
#include <comdef.h> 
#include <opencv2/core/types_c.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

CDosaic::CDosaic(wchar_t* file)
{
	_bstr_t tmp(file);
	mFile = tmp;
}


void CDosaic::Dot(int type, int x, int y, int r)
{
	
	x += 3;
	y += 3;
	switch (7 - type)
	{

	case 7:
		SetPixel(x - 1, y - 3);
		SetPixel(x + 2, y - 3);
		SetPixel(x + 3, y - 2);
		SetPixel(x + 4, y - 1);
		SetPixel(x + 4, y + 2);
		SetPixel(x + 3, y + 3);
		SetPixel(x + 2, y + 4);
		SetPixel(x - 1, y + 4);
		SetPixel(x - 2, y + 3);
		SetPixel(x - 3, y + 2);
		SetPixel(x - 3, y - 1);
		SetPixel(x - 2, y - 2);
	case 6:
		SetPixel(x, y - 3);
		SetPixel(x + 1, y - 3);

		SetPixel(x + 4, y);
		SetPixel(x + 4, y + 1);

		SetPixel(x + 1, y + 4);
		SetPixel(x, y + 4);
		SetPixel(x - 3, y);
		SetPixel(x - 2, y - 1);
	case 5:
		SetPixel(x + 2, y - 2);
		SetPixel(x + 3, y - 1);

		SetPixel(x + 3, y + 2);
		SetPixel(x + 2, y + 3);

		SetPixel(x - 1, y + 3);
		SetPixel(x - 2, y + 2);
		SetPixel(x - 3, y + 1);
		SetPixel(x - 1, y - 2);


	case 4:

		SetPixel(x, y - 2);
		SetPixel(x + 1, y - 2);

		SetPixel(x + 3, y);
		SetPixel(x + 3, y + 1);

		SetPixel(x + 1, y + 3);
		SetPixel(x, y + 3);

		SetPixel(x - 2, y + 1);
		SetPixel(x - 2, y);

	case 3:	
		SetPixel(x + 2, y - 1);
		SetPixel(x + 2, y + 2);
		SetPixel(x - 1, y + 2);	
		SetPixel(x - 1, y - 1);	

	case 2:

		SetPixel(x, y - 1);
		SetPixel(x + 1, y - 1);
		SetPixel(x + 2, y);
		SetPixel(x + 2, y + 1);
	case 1:
		SetPixel(x + 1, y + 2);
		SetPixel(x, y + 2);
		SetPixel(x - 1, y + 1);
		SetPixel(x - 1, y);
	default:
		SetPixel(x, y);
		SetPixel(x, y + 1);
		SetPixel(x + 1, y);
		SetPixel(x + 1, y + 1);
		break;
	}

}

void CDosaic::ReadImage()
{
	if (!mFile.empty())
	{
		double ratio;
		Mat mat;
	
		mat = imread(mFile);
		if (!mat.empty())
		{
			ratio = ((double)1280) / mat.cols;
			resize(mat, mmatOrigin, Size(), ratio, ratio);
			mat.release();
			mmatDosaic.create(mmatOrigin.rows, mmatOrigin.cols / 8 * 8, CV_8UC3);
		}
	}
}

void CDosaic::Dosaic()
{
	// TODO: Add your implementation code here.
	int rate = 8; //mmatDosaic.rows * 8 / 1280; 

	Vec3b bgr;
	int sum;
	for (size_t row = 0; row < (int)mmatOrigin.rows - rate; row += rate)
	{
		for (size_t col = 0; col < (int)mmatOrigin.cols - rate; col += rate)
		{
			sum = 0;
			for (int ii = row; ii < row + rate; ii++)
			{
				for (int jj = col; jj < col + rate; jj++)
				{
					bgr = mmatOrigin.at<Vec3b>(ii, jj); //��Vec3bҲ��
					sum += bgr.val[0] + bgr.val[1] + bgr.val[2];

				}
			}
			//sum = col / 160;
			sum += rate * rate * 3 * 16;
			sum /= (rate * rate * 3 * 32);
			Dot(sum, row, col, 8);

		}
	}
}

void CDosaic::SetPixel(int x, int y)
{
	size_t start = (x * mmatDosaic.cols + y);
	mmatDosaic.at<Vec3b>(start).val[0] = 0;
	mmatDosaic.at<Vec3b>(start).val[1] = 0;
	mmatDosaic.at<Vec3b>(start).val[2] = 0;
}


void CDosaic::Save()
{
	// TODO: Add your implementation code here.
	if (!mmatDosaic.empty())
	{
		imwrite(mFile + ".jpg", mmatDosaic);  //͵����
	}
}
