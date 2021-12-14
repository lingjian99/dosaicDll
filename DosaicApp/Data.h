#pragma once

#include <vector>
#include <memory>
#include "ObjImage.h"
using namespace std;

class CData
{
private:
	CWnd mView;
	CString mFile;
	vector<IObject*>  mObjects;
public:


	~CData();
	// save data in specificated file
	void fileSave();
	void openFile(CString file);
	void setFile(CString file);
	CString getFile();
	void CreateImageObject(CString file);

	void Draw(HDC hDC);
};
