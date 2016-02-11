// PropertyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "flowchart_test.h"
#include "PropertyDialog.h"
#include "flowchart_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertyDialog dialog


CPropertyDialog::CPropertyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPropertyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropertyDialog)
	m_text = _T("");
	//}}AFX_DATA_INIT
}


void CPropertyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertyDialog)
	DDX_Text(pDX, IDC_EDIT1, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertyDialog, CDialog)
	//{{AFX_MSG_MAP(CPropertyDialog)
	ON_BN_CLICKED(IDC_BUTTONFONT, OnButtonfont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyDialog message handlers

void CPropertyDialog::OnOK() 
{
	// TODO: Add extra validation here
    UpdateData(TRUE);
	m_shape->SetTitle( m_text );
    m_redrawWnd->RedrawWindow();
	CDialog::OnOK();
} 

//DEL CBasicShape*  CPropertyDialog::GetShape() const
//DEL {
//DEL     return m_shape;
//DEL }

//DEL CBasicShape* CPropertyDialog::GetShape() const
//DEL {
//DEL return m_shape;
//DEL }



void CPropertyDialog::SetRedrawWnd(Cflowchart_testView *wnd)
{
     m_redrawWnd=wnd;
}

void CPropertyDialog::OnButtonfont() 
{
	// TODO: Add your control notification handler code here
	CFontDialog dlg;
	dlg.m_cf.rgbColors=(m_shape->GetClr());
    dlg.m_cf.lpLogFont->lfHeight = m_shape->GetlogFont()->lfHeight;
    dlg.m_cf.lpLogFont->lfWidth   = m_shape->GetlogFont()->lfWidth;
    dlg.m_cf.lpLogFont->lfEscapement = m_shape->GetlogFont()->lfEscapement;
    dlg.m_cf.lpLogFont->lfOrientation = m_shape->GetlogFont()->lfOrientation;
    dlg.m_cf.lpLogFont->lfWeight = m_shape->GetlogFont()->lfWeight;
    dlg.m_cf.lpLogFont->lfItalic = m_shape->GetlogFont()->lfItalic;
    dlg.m_cf.lpLogFont->lfUnderline = m_shape->GetlogFont()->lfUnderline;
    dlg.m_cf.lpLogFont->lfStrikeOut = m_shape->GetlogFont()->lfStrikeOut;
    dlg.m_cf.lpLogFont->lfCharSet = m_shape->GetlogFont()->lfCharSet;
    dlg.m_cf.lpLogFont->lfOutPrecision = m_shape->GetlogFont()->lfOutPrecision;
    dlg.m_cf.lpLogFont->lfClipPrecision = m_shape->GetlogFont()->lfClipPrecision;
    dlg.m_cf.lpLogFont->lfQuality = m_shape->GetlogFont()->lfQuality;
    dlg.m_cf.lpLogFont->lfPitchAndFamily=m_shape->GetlogFont()->lfPitchAndFamily;
    strcpy (dlg.m_cf.lpLogFont->lfFaceName, m_shape->GetlogFont()->lfFaceName);
	if(IDOK==dlg.DoModal())
	{
		if((m_shape->GetFont())->m_hObject)
			(m_shape->GetFont())->DeleteObject();
		//将在字体对话框中设置的字体、颜色保存在相对应的图形对象中
		(m_shape->GetFont())->CreateFontIndirect(dlg.m_cf.lpLogFont);
        m_shape->SetClr(dlg.m_cf.rgbColors);
		m_shape->SetlogFont(dlg.m_cf.lpLogFont);
		Invalidate();
	}
}
