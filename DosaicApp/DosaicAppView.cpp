
// DosaicAppView.cpp : implementation of the CDosaicAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DosaicApp.h"
#endif

#include "DosaicAppDoc.h"
#include "DosaicAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDosaicAppView

IMPLEMENT_DYNCREATE(CDosaicAppView, CView)

BEGIN_MESSAGE_MAP(CDosaicAppView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDosaicAppView construction/destruction

CDosaicAppView::CDosaicAppView() noexcept
{
	// TODO: add construction code here

}

CDosaicAppView::~CDosaicAppView()
{
}

BOOL CDosaicAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDosaicAppView drawing

void CDosaicAppView::OnDraw(CDC* pDC)
{
	CDosaicAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc)
	{
		pDoc->Draw(pDC);
	}
		return;

	// TODO: add draw code for native data here
}

void CDosaicAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDosaicAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDosaicAppView diagnostics

#ifdef _DEBUG
void CDosaicAppView::AssertValid() const
{
	CView::AssertValid();
}

void CDosaicAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDosaicAppDoc* CDosaicAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDosaicAppDoc)));
	return (CDosaicAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CDosaicAppView message handlers
