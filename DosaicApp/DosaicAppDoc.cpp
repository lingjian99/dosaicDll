
// DosaicAppDoc.cpp : implementation of the CDosaicAppDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DosaicApp.h"
#endif

#include "DosaicAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "DosaicAppView.h"
// CDosaicAppDoc

IMPLEMENT_DYNCREATE(CDosaicAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CDosaicAppDoc, CDocument)
	ON_COMMAND(ID_EDIT_INSERTIMAGE, &CDosaicAppDoc::OnEditInsertimage)
	ON_COMMAND(ID_EDIT_DOSAIC, &CDosaicAppDoc::OnEditDosaic)
END_MESSAGE_MAP()


// CDosaicAppDoc construction/destruction

CDosaicAppDoc::CDosaicAppDoc() noexcept
{
	// TODO: add one-time construction code here
	mpData = new CData();
}

CDosaicAppDoc::~CDosaicAppDoc()
{
	if (mpData != nullptr)
		delete mpData;
}

BOOL CDosaicAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


// CDosaicAppDoc serialization

void CDosaicAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDosaicAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CDosaicAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDosaicAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDosaicAppDoc diagnostics

#ifdef _DEBUG
void CDosaicAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDosaicAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDosaicAppDoc commands


void CDosaicAppDoc::OnEditInsertimage()
{
	// TODO: Add your command handler code here
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = L"";	//默认打开的文件路径
	CString fileName = L"";			//默认打开的文件名
	CString filter = L"File (*.jpg; *.png; *.bmp)|*.jpg;*.png;*.doc||";	//文件过虑的类型

	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);

	INT_PTR result = openFileDlg.DoModal();

	if (result == IDOK) {
		CString filePath = openFileDlg.GetPathName();
		mpData->CreateImageObject(filePath);
		UpdateAllViews(nullptr);
	}
}


void CDosaicAppDoc::Draw(CDC* pDC)
{
	// TODO: Add your implementation code here.
	mpData->Draw(pDC->GetSafeHdc());

	
}

/// <summary>
/// there is only one view. 
/// </summary>
/// <returns></returns>
CDosaicAppView* CDosaicAppDoc::GetView()
{
	// TODO: Add your implementation code here.
	POSITION pos;
	pos = this->GetFirstViewPosition();
	return (CDosaicAppView*)this->GetNextView(pos);
}


void CDosaicAppDoc::OnEditDosaic()
{
	
}
