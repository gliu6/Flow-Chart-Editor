// flowchart_testView.h : interface of the Cflowchart_testView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_flowchart_testVIEW_H__B4CE80DC_B3F1_4E91_856C_1704E08DFC7C__INCLUDED_)
#define AFX_flowchart_testVIEW_H__B4CE80DC_B3F1_4E91_856C_1704E08DFC7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "flowchart_testDoc.h"
class Cflowchart_testView : public CView			  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
{
protected: // create from serialization only
	Cflowchart_testView();
	DECLARE_DYNCREATE(Cflowchart_testView)
	afx_msg void SetRectangle();
    afx_msg void SetCircle();
	afx_msg void SetLingxing();
	afx_msg void Setpingxing();
	afx_msg void SetLine();
	afx_msg void SetLabel();
// Attributes
public:
	Cflowchart_testDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cflowchart_testView)
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
	virtual ~Cflowchart_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Generated message map functions
protected:
	//{{AFX_MSG(Cflowchart_testView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuitem32781();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);//右键响应
	afx_msg void OnCancelMode();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);//双击弹出添加文本对话框
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnText();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);//右键弹出快捷菜单
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

public:
	afx_msg void OnSavepng();
	afx_msg void OnHelpFinder();
};

#ifndef _DEBUG  // debug version in flowchart_testView.cpp
inline Cflowchart_testDoc* Cflowchart_testView::GetDocument()
   { return (Cflowchart_testDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_flowchart_testVIEW_H__B4CE80DC_B3F1_4E91_856C_1704E08DFC7C__INCLUDED_)
