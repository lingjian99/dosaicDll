
// DosaicAppView.h : interface of the CDosaicAppView class
//

#pragma once


class CDosaicAppView : public CView
{
protected: // create from serialization only
	CDosaicAppView() noexcept;
	DECLARE_DYNCREATE(CDosaicAppView)

// Attributes
public:
	CDosaicAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDosaicAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DosaicAppView.cpp
inline CDosaicAppDoc* CDosaicAppView::GetDocument() const
   { return reinterpret_cast<CDosaicAppDoc*>(m_pDocument); }
#endif

