// flowchart_test.h : main header file for the flowchart_test application
//

#if !defined(AFX_flowchart_test_H__DE3D5A55_9EB0_42AC_90F3_FA9E28738CD8__INCLUDED_)
#define AFX_flowchart_test_H__DE3D5A55_9EB0_42AC_90F3_FA9E28738CD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testApp:
// See flowchart_test.cpp for the implementation of this class
//

class Cflowchart_testApp : public CWinApp
{
public:
	Cflowchart_testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cflowchart_testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(Cflowchart_testApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_flowchart_test_H__DE3D5A55_9EB0_42AC_90F3_FA9E28738CD8__INCLUDED_)
