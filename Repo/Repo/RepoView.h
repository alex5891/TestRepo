
// RepoView.h : interface of the CRepoView class
//

#pragma once


class CRepoView : public CListView
{
protected: // create from serialization only
	CRepoView();
	DECLARE_DYNCREATE(CRepoView)

// Attributes
public:
	CRepoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CRepoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RepoView.cpp
inline CRepoDoc* CRepoView::GetDocument() const
   { return reinterpret_cast<CRepoDoc*>(m_pDocument); }
#endif

