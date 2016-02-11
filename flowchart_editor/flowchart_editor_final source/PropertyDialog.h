#if !defined(AFX_PROPERTYDIALOG_H__37EED6C7_11DD_4F8F_9448_C542910A76AB__INCLUDED_)
#define AFX_PROPERTYDIALOG_H__37EED6C7_11DD_4F8F_9448_C542910A76AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertyDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyDialog dialog
#include "BasicShape.h"
#include "flowchart_testView.h"
class CPropertyDialog : public CDialog
{
// Construction
public:
	void SetRedrawWnd(Cflowchart_testView* wnd);
	
	CBasicShape* m_shape;//对话框对应的图形对象指针
	CPropertyDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPropertyDialog)
	enum { IDD = IDD_DIALOG1 };
	CString	m_text;//在编辑框内输入的文本
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertyDialog)
	virtual void OnOK();
	afx_msg void OnButtonfont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	
private:
	Cflowchart_testView* m_redrawWnd;//指向对话框父类的指针
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYDIALOG_H__37EED6C7_11DD_4F8F_9448_C542910A76AB__INCLUDED_)
