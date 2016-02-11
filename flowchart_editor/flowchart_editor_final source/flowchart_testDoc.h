// flowchart_testDoc.h : interface of the Cflowchart_testDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "BasicShape.h"
#if !defined(AFX_flowchart_testDOC_H__2DD7B033_F2A1_4CD0_B086_43C1B80A3325__INCLUDED_)
#define AFX_flowchart_testDOC_H__2DD7B033_F2A1_4CD0_B086_43C1B80A3325__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Cflowchart_testDoc : public CDocument			  //������֪��������Ϣ�뵽�����ĵ�Ŀ¼�µġ�ע�ͽ���˵�����ڲ鿴����
{
protected: // create from serialization only
	Cflowchart_testDoc();
	DECLARE_DYNCREATE(Cflowchart_testDoc)

// Attributes
public:
	CPoint m_point1;
	CPoint m_point2;
	CRect rect;
	int move_ok;								 //�϶�ʱtag��once��ǲ���
	int once;
	int num;
	int m_up;                       //������up
    int tag;                 //��ÿ�ε��ֻ����һ��ͼ��
	CBasicShape *m_BasicShape;
	CPtrArray m_ptrArray;
	int m_ptrArray_sessible[1000];//��¼��ǰѡ��ͼԪ���
	int m_ptrArray_sessible_size;//��¼��ǰѡ�ж���ͼԪ
	bool cursor_replaced;//�Ƿ�����Ϊʮ�ֹ�꣬Ŀǰû��
	bool cursor_flag;	//ͬ��
	CPtrArray cut;
	CPtrArray cut1;//DELETE��
	bool cut_flag;
	int l_tag;     //�������ֱ�ߺ������ڱ���.
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

