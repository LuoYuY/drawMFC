// termprjView.h : interface of the CTermprjView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMPRJVIEW_H__6EB0EDDE_191E_4D45_A97B_963A826D9896__INCLUDED_)
#define AFX_TERMPRJVIEW_H__6EB0EDDE_191E_4D45_A97B_963A826D9896__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <stdlib.h>   
#include <vector>

class CTermprjView : public CView
{
protected: // create from serialization only
	CTermprjView();
	DECLARE_DYNCREATE(CTermprjView)

// Attributes
public:
	CTermprjDoc* GetDocument();
	bool m_drawline;  //是否在画直线状态
	bool m_drawarc;  //是否在画圆弧状态
	bool m_capture;   //
	bool m_inrect; //在区域内
	POINT beginPt;  //起点
	POINT endPt; //终点
	std::vector<CRect> rects;  //所有光标发生变化的区域
	CRect temp;  //光标在区域内，保存检测到的rect
	int num;//rect的数量
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTermprjView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTermprjView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTermprjView)
	afx_msg void OnDrawline();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in termprjView.cpp
inline CTermprjDoc* CTermprjView::GetDocument()
   { return (CTermprjDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMPRJVIEW_H__6EB0EDDE_191E_4D45_A97B_963A826D9896__INCLUDED_)
