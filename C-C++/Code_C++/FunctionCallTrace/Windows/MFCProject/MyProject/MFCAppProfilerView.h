
// MFCAppProfilerView.h : interface of the CMFCAppProfilerView class
//

#pragma once


class CMFCAppProfilerView : public CView
{
protected: // create from serialization only
	CMFCAppProfilerView();
	DECLARE_DYNCREATE(CMFCAppProfilerView)

// Attributes
public:
	CMFCAppProfilerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	void DrawCircle( CPoint point );
// Implementation
public:
	virtual ~CMFCAppProfilerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCAppProfilerView.cpp
inline CMFCAppProfilerDoc* CMFCAppProfilerView::GetDocument() const
   { return reinterpret_cast<CMFCAppProfilerDoc*>(m_pDocument); }
#endif

