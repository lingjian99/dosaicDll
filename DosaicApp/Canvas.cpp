// Canvas.cpp : implementation file
//

#include "pch.h"
#include "dosaicDllTest.h"
#include "Canvas.h"
#include "Data.h"


// Canvas

IMPLEMENT_DYNAMIC(Canvas, CWnd)

Canvas::Canvas() : mpData(nullptr)
{

}

Canvas::~Canvas()
{
}


BEGIN_MESSAGE_MAP(Canvas, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// Canvas message handlers




BOOL Canvas::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
		
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void Canvas::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages

	mpData->Draw(dc.GetSafeHdc());
	POINT pnt;
	pnt.x = 20;
	pnt.y = 20;
	dc.MoveTo(pnt);
	pnt.x = 200;
	dc.LineTo(pnt);

}


void Canvas::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CStatic::OnLButtonDown(nFlags, point);
}


void Canvas::setData(CData* pData)
{
	mpData = pData;	// TODO: Add your implementation code here.
}
