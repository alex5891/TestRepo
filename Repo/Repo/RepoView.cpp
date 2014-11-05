
// RepoView.cpp : implementation of the CRepoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Repo.h"
#endif

#include "RepoDoc.h"
#include "RepoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRepoView

IMPLEMENT_DYNCREATE(CRepoView, CListView)

BEGIN_MESSAGE_MAP(CRepoView, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRepoView construction/destruction

CRepoView::CRepoView()
{
	// TODO: add construction code here

}

CRepoView::~CRepoView()
{
}

BOOL CRepoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

void CRepoView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

void CRepoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRepoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRepoView diagnostics

#ifdef _DEBUG
void CRepoView::AssertValid() const
{
	CListView::AssertValid();
}

void CRepoView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CRepoDoc* CRepoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRepoDoc)));
	return (CRepoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRepoView message handlers
void CRepoView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
