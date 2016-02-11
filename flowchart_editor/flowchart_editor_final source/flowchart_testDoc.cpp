// flowchart_testDoc.cpp : implementation of the Cflowchart_testDoc class
//

#include "stdafx.h"							  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
#include "flowchart_test.h"
#include "BasicShape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Rhombus.h"
#include "Quadrangle.h"
#include "Line.h"
#include "Label.h"
#include "Cunchu.h"

#include "flowchart_testDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testDoc

IMPLEMENT_DYNCREATE(Cflowchart_testDoc, CDocument)

BEGIN_MESSAGE_MAP(Cflowchart_testDoc, CDocument)
	//{{AFX_MSG_MAP(Cflowchart_testDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
	ON_COMMAND(ID_SaveSVG, Cflowchart_testDoc::OnSavesvg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testDoc construction/destruction

Cflowchart_testDoc::Cflowchart_testDoc()
{
	m_up=0;
	tag=0;
	m_ptrArray_sessible_size=0;
	cursor_replaced=false;
	cursor_flag=false;
	l_tag=0;
	
	//m_BasicShape=new CRectangle();                    //需要修改
}

Cflowchart_testDoc::~Cflowchart_testDoc()
{
}

BOOL Cflowchart_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testDoc serialization

void Cflowchart_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int nCount=m_ptrArray.GetSize();
		ar<<nCount;
		for(int i=0;i<nCount;i++)
		((CBasicShape*)m_ptrArray.GetAt(i))->Serialize(ar);
	}
	else
	{
		/*
		int nCount;
		ar>>nCount;
		for(int i=0;i<nCount;i++)
		((CBasicShape*)m_ptrArray.GetAt(i))->Serialize(ar);
		*/

		int nCount;
		int tag;
		int o_tag1;
		int o_tag2;
		int o_tag3;
		int i_tag1;
		int i_tag2;
		int i_tag3;
		CPoint p1;
		CPoint p2;
		CString title;
		int flag=1;                   //标记折线号
		CBasicShape *p_BasicShape;
		int tag11;
		int tag22;
		int R_tag11;
		int R_tag22;
		int R_tag33;
		ar>>nCount;
		for(int i=0;i<nCount;i++)
		{
			ar>>tag;
			if(tag==1)
			{
				ar>>p1>>p2;
				ar>>title;
				ar>>o_tag1>>o_tag2>>o_tag3>>i_tag1>>i_tag2>>i_tag3;
				p_BasicShape=new CRectangle;
			}
			if(tag==2)
			{
				ar>>p1>>p2;
				ar>>title;
				ar>>o_tag1>>o_tag2>>o_tag3>>i_tag1>>i_tag2>>i_tag3;
				p_BasicShape=new CEllipse;
			}			
			if(tag==3)
			{
				ar>>p1>>p2;
				ar>>title;
				ar>>o_tag1>>o_tag2>>o_tag3>>i_tag1>>i_tag2>>i_tag3;
				p_BasicShape=new CRhombus;
			}
			if(tag==4)
			{
				ar>>p1>>p2;
				ar>>title;
				ar>>o_tag1>>o_tag2>>o_tag3>>i_tag1>>i_tag2>>i_tag3;
				p_BasicShape=new CQuadrangle;
			}
			if(tag==6)
			{
				ar>>p1>>p2;
				ar>>title;
				ar>>o_tag1>>o_tag2>>o_tag3>>i_tag1>>i_tag2>>i_tag3;
				p_BasicShape=new CLabel;	
			}
			if(tag==5)
			{
				int ok=0;
				//l_tag++;
				ar>>title>>p1>>p2>>i_tag1>>i_tag2>>i_tag3;
				for(;ok==0;)
				{
					l_tag++;
					for(int j=0;j<i;j++)
					{
						if(((CBasicShape*)m_ptrArray.GetAt(j))->outtag1==flag||((CBasicShape*)m_ptrArray.GetAt(j))->outtag2==flag||((CBasicShape*)m_ptrArray.GetAt(j))->outtag3==flag)
						{
							p_BasicShape=new CLine;
							ok=1;
							p_BasicShape->LineFront=((CBasicShape*)m_ptrArray.GetAt(j));
							for(int w=0;w<i;w++)
							{
								if(((CBasicShape*)m_ptrArray.GetAt(w))->intag1==flag||((CBasicShape*)m_ptrArray.GetAt(w))->intag2==flag||((CBasicShape*)m_ptrArray.GetAt(w))->intag3==flag)
								{
									p_BasicShape->LineBehind=((CBasicShape*)m_ptrArray.GetAt(w));
									break;
								}
							}
						}
					}
				flag++;
				}
			}
			p_BasicShape->SetTag(tag);
			p_BasicShape->SetCharacter(title);
			if(tag!=5)
			{
				p_BasicShape->SetPoint(p1,p2);
				p_BasicShape->Set_in_out_tag(i_tag1,i_tag2,i_tag3,o_tag1,o_tag2,o_tag3);
			}
			if(tag==5)
			{
				ar>>tag11>>tag22>>R_tag11>>R_tag22>>R_tag33;
				p_BasicShape->SetPoint(p1,p2);
				p_BasicShape->Setintag(i_tag1);
				p_BasicShape->SetRTag(tag11,tag22,R_tag11,R_tag22,R_tag33);
			}
			m_ptrArray.Add(p_BasicShape);
			
		} 

	} 

}

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testDoc diagnostics

#ifdef _DEBUG
void Cflowchart_testDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cflowchart_testDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testDoc commands

/////////////////////////////////////////////////////////////////////////////
// 按键响应函数 SVG存储函数
/////////////////////////////////////////////////////////////////////////////
void Cflowchart_testDoc::OnSavesvg()
{
	CFileDialog fileDlg(FALSE);   //开启对话框
	fileDlg.m_ofn.lpstrTitle="SVG保存";   
	fileDlg.m_ofn.lpstrFilter="SVG Files(*.svg)\0*.svg\0All Files(*.*)\0*.*\0\0";
	fileDlg.m_ofn.lpstrDefExt="svg";   //对话框属性设置
	if(IDOK==fileDlg.DoModal())
	{
		CFile file(fileDlg.GetPathName(),CFile::modeReadWrite|CFile::modeCreate);

		CString head_Temp("<\?xml version=\"1.0\" encoding=\"iso-8859-1\"\?>\r\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 20000303 Stylable//EN\"\r\n\"http://www.w3.org/TR/2000/03/WD-SVG-20000303/DTD/svg-20000303-stylable.dtd\">\r\n\r\n<svg width=\"100%\" height=\"100%\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\r\n\r\n");
		file.Write(head_Temp,head_Temp.GetLength());   //SVG 头文件写入

		int nCount=m_ptrArray.GetSize();   //取内存中各图形元数据
		for(int i=0;i<nCount;i++)
		{
			CString shape_Temp(((CBasicShape*)m_ptrArray.GetAt(i))->OnSavesvg());
			file.SeekToEnd();
			file.Write(shape_Temp,shape_Temp.GetLength());   //写入
		}
		CString tail_Temp("\r\n</svg>");   //写尾文件
		file.SeekToEnd();
		file.Write(tail_Temp,tail_Temp.GetLength());
		file.Close();
	}
}
