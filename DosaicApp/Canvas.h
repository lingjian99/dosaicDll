#pragma once

class CData;
// Canvas

class Canvas : public CStatic
{
	DECLARE_DYNAMIC(Canvas)

public:
	Canvas();
	virtual ~Canvas();
private:
	CData* mpData;
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void setData(CData* pData);
};


