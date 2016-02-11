// DiagramPropertyDlg.h: interface for the CDiagramPropertyDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIAGRAMPROPERTYDLG_H__87B03DF9_365B_4025_9136_D28659768F2E__INCLUDED_)
#define AFX_DIAGRAMPROPERTYDLG_H__87B03DF9_365B_4025_9136_D28659768F2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDiagramPropertyDlg : public CDialog  
{
public:
	BasicShape* m_shape;
	CDiagramPropertyDlg();
	virtual ~CDiagramPropertyDlg();

};

#endif // !defined(AFX_DIAGRAMPROPERTYDLG_H__87B03DF9_365B_4025_9136_D28659768F2E__INCLUDED_)
