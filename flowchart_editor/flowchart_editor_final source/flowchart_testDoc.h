// flowchart_testDoc.h : interface of the Cflowchart_testDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "BasicShape.h"
#if !defined(AFX_flowchart_testDOC_H__2DD7B033_F2A1_4CD0_B086_43C1B80A3325__INCLUDED_)
#define AFX_flowchart_testDOC_H__2DD7B033_F2A1_4CD0_B086_43C1B80A3325__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Cflowchart_testDoc : public CDocument			  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
{
protected: // create from serialization only
	Cflowchart_testDoc();
	DECLARE_DYNCREATE(Cflowchart_testDoc)

// Attributes
public:
	CPoint m_point1;
	CPoint m_point2;
	CRect rect;
	int move_ok;								 //拖动时tag和once标记不置
	int once;
	int num;
	int m_up;                       //标记鼠标up
    int tag;                 //是每次点击只出现一个图形
	CBasicShape *m_BasicShape;
	CPtrArray m_ptrArray;
	int m_ptrArray_sessible[1000];//记录当前选中图元编号
	int m_ptrArray_sessible_size;//记录当前选中多少图元
	bool cursor_replaced;//是否鼠标变为十字光标，目前没用
	bool cursor_flag;	//同上
	CPtrArray cut;
	CPtrArray cut1;//DELETE用
	bool cut_flag;
	int l_tag;     //用来标记直线号以用于保存.
	CBasicShape *mm_BasicShape;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cflowchart_testDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Cflowchart_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(Cflowchart_testDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSavesvg();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_flowchart_testDOC_H__2DD7B033_F2A1_4CD0_B086_43C1B80A3325__INCLUDED_)

