#include "pch.h"
#include "Data.h"


CData::~CData()
{
    for (auto pObj : mObjects) {
        delete pObj;
    }
}
// save data in specificated file
void CData::fileSave()
{
    // TODO: Add your implementation code here.
}


void CData::openFile(CString file)
{
    // TODO: Add your implementation code here.
    return;
}


void CData::setFile(CString file)
{
    
    // TODO: Add your implementation code here.
}


CString CData::getFile()
{
    // TODO: Add your implementation code here.
    return mFile;
}

void CData::CreateImageObject(CString file)
{

    CObjImage* obj = new CObjImage();
    obj->setFileName(file);
    int i = mObjects.size();

    mObjects.push_back((IObject*)obj);
}


void CData::Draw(HDC hDC)
{
    // TODO: Add your implementation code here.
    for (auto pObj : mObjects) {
        if (pObj == nullptr)
            return;
        pObj->Draw(hDC);
    }
}
