// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "dosaic.h"
#include "CDosaic.h"

// DLL internal state variables:
//static unsigned long long previous_;  // Previous value, if any


void dosaic(wchar_t* file)
{
	CDosaic* pDos = new CDosaic(file);
	pDos->ReadImage();
	pDos->Dosaic();
	pDos->Save();
	delete pDos;
}

