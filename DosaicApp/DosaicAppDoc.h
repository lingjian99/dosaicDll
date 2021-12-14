
// DosaicAppDoc.h : interface of the CDosaicAppDoc class
//


#pragma once

#include "Data.h"
class CDosaicAppView;

class CDosaicAppDoc : public CDocument
{
protected: // create from serialization only
	CDosaicAppDoc() noexcept;
	DECLARE_DYNCREATE(CDosaicAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CDosaicAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CData* mpData;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditInsertimage();
	void Draw(CDC* pDC);
protected:
	CDosaicAppView* GetView();
public:
	afx_msg void OnEditDosaic();
};
