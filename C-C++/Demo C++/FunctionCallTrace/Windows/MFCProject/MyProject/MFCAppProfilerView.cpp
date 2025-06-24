
// MFCAppProfilerView.cpp : implementation of the CMFCAppProfilerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCAppProfiler.h"
#endif

#include "MFCAppProfilerDoc.h"
#include "MFCAppProfilerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppProfilerView

IMPLEMENT_DYNCREATE(CMFCAppProfilerView, CView)

BEGIN_MESSAGE_MAP(CMFCAppProfilerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCAppProfilerView construction/destruction

CMFCAppProfilerView::CMFCAppProfilerView()
{
	// TODO: add construction code here

}

CMFCAppProfilerView::~CMFCAppProfilerView()
{
}

BOOL CMFCAppProfilerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCAppProfilerView drawing

void CMFCAppProfilerView::OnDraw(CDC* /*pDC*/)
{
	CMFCAppProfilerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCAppProfilerView printing

BOOL CMFCAppProfilerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCAppProfilerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCAppProfilerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCAppProfilerView diagnostics

#ifdef _DEBUG
void CMFCAppProfilerView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppProfilerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppProfilerDoc* CMFCAppProfilerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppProfilerDoc)));
	return (CMFCAppProfilerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppProfilerView message handlers

void CMFCAppProfilerView::DrawCircle( CPoint point )
{
	CClientDC* pDC = new CClientDC(this);
	CRect rc;
	rc.left = point.x;
	rc.top  = point.y;
	rc.right = rc.left + 50;
	rc.bottom = rc.top + 50;
	pDC->Ellipse(&rc);
}

void CMFCAppProfilerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	DrawCircle( point );
	CView::OnLButtonDown(nFlags, point);
}

void Call1( )
{
	::MessageBox( NULL, TEXT("Hello"),TEXT("Sample"),MB_OK);
}

void Call2( )
{
	Call1();
}
void Call3( )
{
	Call2();
}


void CMFCAppProfilerView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	Call3();
	CView::OnRButtonDown(nFlags, point);
}
