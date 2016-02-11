// flowchart_testView.cpp : implementation of the Cflowchart_testView class
//

#include "stdafx.h"					  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
#include "flowchart_test.h"

#include "flowchart_testDoc.h"
#include "flowchart_testView.h"
#include "BasicShape.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Rhombus.h"
#include "Quadrangle.h"
#include "Cunchu.h"
#include "propertydialog.h"
#include "Line.h"
#include "Label.h"
#include <GdiPlus.h>   //PNG将用到GDI+库
using namespace Gdiplus;
#pragma comment(lib,"gdiplus.lib")   //开启GDI+ 


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView

IMPLEMENT_DYNCREATE(Cflowchart_testView, CView)

BEGIN_MESSAGE_MAP(Cflowchart_testView, CView)
	//{{AFX_MSG_MAP(Cflowchart_testView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENUITEM32781, OnMenuitem32781)
	ON_WM_RBUTTONDOWN()
	ON_WM_CANCELMODE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_TEXT, OnText)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DELETE, OnDelete)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_BUTTON32775,SetRectangle)
	ON_COMMAND(ID_BUTTON32778,SetCircle)
	ON_COMMAND(ID_BUTTON32776,SetLingxing)
	ON_COMMAND(ID_BUTTON32777,Setpingxing)
	ON_COMMAND(ID_BUTTON32782,SetLine)
	ON_COMMAND(ID_BUTTON32790,SetLabel)	
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_SavePNG, &Cflowchart_testView::OnSavepng)
	ON_COMMAND(ID_HELP_FINDER, &Cflowchart_testView::OnHelpFinder)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView construction/destruction

Cflowchart_testView::Cflowchart_testView()
{

}

Cflowchart_testView::~Cflowchart_testView()
{
}

BOOL Cflowchart_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView drawing

void Cflowchart_testView::OnDraw(CDC* pDC)
{
	Cflowchart_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	if(pDoc->tag!=0&&pDoc->m_up==1)
	{	
		pDoc->m_BasicShape->Draw(pDC);
		pDoc->tag=0;
		pDoc->m_up=0;
	}
	
	for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
	{
		((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->Draw(pDC);
	}


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView printing

BOOL Cflowchart_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cflowchart_testView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cflowchart_testView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView diagnostics

#ifdef _DEBUG
void Cflowchart_testView::AssertValid() const
{
	CView::AssertValid();
}

void Cflowchart_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cflowchart_testDoc* Cflowchart_testView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cflowchart_testDoc)));
	return (Cflowchart_testDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Cflowchart_testView message handlers

void Cflowchart_testView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Cflowchart_testDoc* pDoc = GetDocument();
	pDoc->m_point1=point;

	pDoc->rect.left=point.x;
	pDoc->rect.top=point.y;
	bool flag1=false;
	if(pDoc->tag==0)
	{
		for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{
			if(((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->CheckRect(point))
			{
					flag1=true;
					break;
			}
			if(pDoc->m_ptrArray_sessible_size==1&&(((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->in_hot_point(point)))
			{
				flag1=true;
			}
		}
	}
	if(pDoc->tag==5)                                               //用来连线传点的
	{
		int i;
		bool m_select;
		for(i=0;i<pDoc->m_ptrArray.GetSize();i++)
		{
			
			m_select = ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->CheckRect(point);
			if(m_select==TRUE)
				break;
		}
			if(m_select==TRUE)
			{	
				if(pDoc->tag==5)                           
				{
					pDoc->m_BasicShape=new CLine;
				    pDoc->m_BasicShape->LineFront=(CBasicShape*)pDoc->m_ptrArray.GetAt(i);
				//	if(pDoc->m_BasicShape->tag1==3)
				//	((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->SetRTag();

					pDoc->m_BasicShape->tag1=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetTag();
					int flag=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->Get_k();
					{	
						if(pDoc->m_BasicShape->tag1!=3)
						{
							if(flag==1)
							pDoc->m_point1=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetPoint11();
							pDoc->m_BasicShape->R_tag2=2;                   //用于直线类

						}
						else
						{
						if(flag==1&&((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->outtag1==0)
						{
							pDoc->m_point1=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetPoint11();
							pDoc->m_BasicShape->R_tag2=2;                   //用于直线类
						}
						if(flag==2&&((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->outtag2==0)
						{
							pDoc->m_point1=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetPoint12();
							pDoc->m_BasicShape->R_tag1=1;
						}
						if(flag==3)
						{
							pDoc->m_point1=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetPoint13();
							pDoc->m_BasicShape->R_tag3=3;
						}
						}
					}
					if(pDoc->m_BasicShape->tag1==3)
					((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->AddTag();
				}                           
			}
			else
			{
				pDoc->tag=0;
			}
		
	}                                                            //~用来连线的

	if(pDoc->tag==0&&flag1==false)
	{
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		bool if_any_select=false;
		int j=0;

		for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
		{
			
			bool m_select = ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->CheckRect(point);
			if(m_select==TRUE)
			{	
				for(int k=0;k<pDoc->m_ptrArray_sessible_size;k++)
				{
					((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[k]))->In_Draw_Point(&dc);
				}
				pDoc->m_ptrArray_sessible[j++]=i;
				pDoc->m_ptrArray_sessible_size=1;
				((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->DrawTag(&dc);
				if_any_select=true;
				break;
			}
		}
		if(if_any_select==false)
		{	
			for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
			{	
				((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw_Point(&dc);	
			}
			pDoc->m_ptrArray_sessible_size=0;
		}

	}

	CView::OnLButtonDown(nFlags, point);
}
	

void Cflowchart_testView::OnLButtonUp(UINT nFlags, CPoint point) //鼠标抬起响应。
{
	Cflowchart_testDoc* pDoc = GetDocument();
	pDoc->m_point2=point;
	pDoc->rect.right=point.x;
	pDoc->rect.bottom=point.y;
	CClientDC dc(this);	
	bool flag=true;
	if((pDoc->m_point2.x<=pDoc->m_point1.x||pDoc->m_point2.y<=pDoc->m_point1.y)&&pDoc->tag!=5)           //使图形只能从左上方画.
		pDoc->tag=0;
	if(pDoc->tag==1)
	{
		pDoc->m_BasicShape=new CRectangle;
    	pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
		pDoc->m_BasicShape->SetTag(1);
		pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
	}
	if(pDoc->tag==2)
	{
		pDoc->m_BasicShape=new CEllipse;
    	pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
		pDoc->m_BasicShape->SetTag(2);
		pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
	}
	if(pDoc->tag==3)
	{
		pDoc->m_BasicShape=new CRhombus;
    	pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
		pDoc->m_BasicShape->SetTag(3);
		pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
	}
	if(pDoc->tag==4)
	{
		pDoc->m_BasicShape=new CQuadrangle;
    	pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
		pDoc->m_BasicShape->SetTag(4);
		pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
	}
	if(pDoc->tag==6)
	{
		pDoc->m_BasicShape=new CLabel;
    	pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
		pDoc->m_BasicShape->SetTag(6);
		pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
		((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray.GetSize()-1))->DrawTag(&dc);
		pDoc->m_ptrArray_sessible[0]=pDoc->m_ptrArray.GetSize()-1;
		pDoc->m_ptrArray_sessible_size=1;
	}
	if(pDoc->tag==5)
	{
		int i;
		bool m_select;
		for(i=0;i<pDoc->m_ptrArray.GetSize();i++)
		{
			
				m_select = ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->CheckRect(point);
				if(m_select==TRUE)
				break;
		}
				if(m_select==TRUE)
				{	
					if(pDoc->tag==5)                            //用来连线的
					{
						pDoc->m_BasicShape->LineBehind=(CBasicShape*)pDoc->m_ptrArray.GetAt(i);
						pDoc->m_BasicShape->tag2=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetTag();
						pDoc->m_point2=((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->GetPoint2();

					//	((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->intag=1;      //入口点已有连线
						if(pDoc->m_BasicShape->tag2==5)
						{
							pDoc->m_point1=pDoc->m_BasicShape->LineFront->GetPoint13();
							pDoc->m_BasicShape->R_tag3=3;
							if(pDoc->m_BasicShape->R_tag2==2||pDoc->m_BasicShape->R_tag1==1)
							{
								pDoc->m_BasicShape->LineFront->Reduce_k();
								pDoc->m_BasicShape->R_tag2=0;
								pDoc->m_BasicShape->R_tag1=0;
							}
						}
					}
																		//~用来连线的
					pDoc->l_tag++;						//用于标记保存
					if((pDoc->m_BasicShape->LineFront->GetTag())!=3)
						pDoc->m_BasicShape->LineFront->outtag1=pDoc->l_tag;
					else
					{
						if(pDoc->m_BasicShape->LineFront->outtag1==0&&pDoc->m_BasicShape->R_tag2==2)
								pDoc->m_BasicShape->LineFront->outtag1=pDoc->l_tag;
						else if(pDoc->m_BasicShape->LineFront->outtag2==0&&pDoc->m_BasicShape->R_tag1==1)
								pDoc->m_BasicShape->LineFront->outtag2=pDoc->l_tag;
						else if(pDoc->m_BasicShape->LineFront->outtag3==0&&pDoc->m_BasicShape->R_tag3==3)
								pDoc->m_BasicShape->LineFront->outtag3=pDoc->l_tag;
					}
					if(pDoc->m_BasicShape->LineBehind->intag1==0)
						pDoc->m_BasicShape->LineBehind->intag1=pDoc->l_tag;
					else if(pDoc->m_BasicShape->LineBehind->intag2==0)
						pDoc->m_BasicShape->LineBehind->intag2=pDoc->l_tag;
					else if(pDoc->m_BasicShape->LineBehind->intag3==0)
						pDoc->m_BasicShape->LineBehind->intag3=pDoc->l_tag;
														//~标记保存
				pDoc->m_BasicShape->SetPoint(pDoc->m_point1,pDoc->m_point2);
				pDoc->m_BasicShape->SetTag(5);
				pDoc->m_ptrArray.Add(pDoc->m_BasicShape);
				}

				else
				{
					pDoc->tag=0;
					if(pDoc->m_BasicShape->tag1==3)
					pDoc->m_BasicShape->LineFront->Reduce_k();
					//delete pDoc->m_BasicShape;
				}

	}

	if(pDoc->tag!=0)
	{
		pDoc->m_up=1;
		pDoc->num++;
		for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{	
			((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw_Point(&dc);	
		}
		pDoc->m_ptrArray_sessible_size=0;
	}
	if(pDoc->tag==0&&pDoc->m_ptrArray_sessible_size!=0&&!(pDoc->m_ptrArray_sessible_size==1&&((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->in_hot_point(pDoc->m_point1)))
	{
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{	
			((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw(&dc);	
			((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->MovePoint(pDoc->m_point1,pDoc->m_point2);
			if(((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->CheckRect(point)==TRUE);
			else
			InvalidateRect(NULL,TRUE);
			((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->DrawTag(&dc);
		}
		for(int m=0;m<pDoc->m_ptrArray_sessible_size;m++)
			{	
				((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[m]))->In_Draw_Point(&dc);	
			}
			pDoc->m_ptrArray_sessible_size=0;

	}
	if(pDoc->tag==0)
	{
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		bool if_any_select=false;
		int j=0;
		bool flag=false;
		
		for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
		{
			
			bool m_select = ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->Check_Out_Rect(pDoc->m_point1,point);
			if(m_select==true)
			{	
			//	if(flag==false) pDoc->m_ptrArray_sessible_size=0;
				pDoc->m_ptrArray_sessible[j++]=i;
				pDoc->m_ptrArray_sessible_size++;
				((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->DrawTag(&dc);
				flag=true;
				if_any_select=true;
			}
		}
		if(if_any_select==false&&pDoc->m_ptrArray_sessible_size!=0&&!((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->in_hot_point(pDoc->m_point1))
		{	
			for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
			{	
				((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw_Point(&dc);	
			}
			pDoc->m_ptrArray_sessible_size=0;

		}
	}
	
	if(pDoc->tag==0)
		if(pDoc->m_ptrArray_sessible_size==1&&((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->in_hot_point(pDoc->m_point1))
	{
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->In_Draw(&dc);	
		((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->Zoom(pDoc->m_point1,pDoc->m_point2);
		((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->In_Draw_Point(&dc);
	}
	InvalidateRect(NULL,FALSE);
	
	CView::OnLButtonUp(nFlags, point);

}

void Cflowchart_testView::SetRectangle()					//设置标记，表明图形种类（下同）
{
	Cflowchart_testDoc* pDoc = GetDocument();

	pDoc->tag=1;



	
	InvalidateRect(NULL,FALSE);
}
void Cflowchart_testView::SetCircle()
{
	Cflowchart_testDoc* pDoc = GetDocument();
	pDoc->tag=2;



	InvalidateRect(NULL,FALSE);
}

void Cflowchart_testView::SetLingxing()
{
	Cflowchart_testDoc* pDoc = GetDocument();

	pDoc->tag=3;



	InvalidateRect(NULL,FALSE);
}

void Cflowchart_testView::Setpingxing()
{
	Cflowchart_testDoc* pDoc = GetDocument();

	pDoc->tag=4;
		


	InvalidateRect(NULL,FALSE);
}
void Cflowchart_testView::SetLine()
{
	Cflowchart_testDoc* pDoc = GetDocument();

	pDoc->tag=5;
		


	InvalidateRect(NULL,FALSE);
}

void Cflowchart_testView::SetLabel()
{
	Cflowchart_testDoc* pDoc = GetDocument();

	pDoc->tag=6;
		


	InvalidateRect(NULL,FALSE);
}

void Cflowchart_testView::OnMouseMove(UINT nFlags, CPoint point) 
{
	Cflowchart_testDoc* pDoc = GetDocument();
	pDoc->m_point2=point;
	pDoc->cursor_replaced=false;
	if(pDoc->m_up==0&&pDoc->move_ok!=0){
/*	if(pDoc->m_up==0&&pDoc->move_ok!=0)
	InvalidateRect(pDoc->rect,TRUE);
	pDoc->rect.right=point.x;
	pDoc->rect.bottom=point.y;
	pDoc->move_ok=1;
	if(pDoc->m_up==0&&pDoc->m_BasicShape->GetTag()!=0)
		pDoc->once=1;
	else
		pDoc->once=0;

	InvalidateRect(NULL,FALSE);
	
	CView::OnMouseMove(nFlags, point); 
*/
		if(pDoc->m_ptrArray_sessible_size==1&&pDoc->tag==0)
		{
			if(((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->in_hot_point(point)&&((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]))->GetTag()!=5)
			{	
				HCURSOR   hc;

				hc=LoadCursor(NULL,IDC_CROSS);

				SetCursor(hc);
				pDoc->cursor_replaced=true;
			}
		}
	}
	
	CView::OnMouseMove(nFlags, point); 
}

void Cflowchart_testView::OnMenuitem32781() 
{
	
}

void Cflowchart_testView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//按下右键，如果在图形内部且图形没有被选中，则选中图形
	Cflowchart_testDoc* pDoc = GetDocument();

	if( pDoc->m_ptrArray.GetSize()!=0 )
	{
		
		int count = 0;
		CBasicShape* obj;

		for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
		{
			obj = (CBasicShape*)pDoc->m_ptrArray.GetAt( i );
			if( obj->CheckRect( point ) )
			{
				if(pDoc->tag==0&&pDoc->m_ptrArray_sessible_size==0)
				{
					InvalidateRect(NULL,FALSE);
		            CClientDC dc(this);	
		            bool if_any_select=false;
		            int j=0;

		            for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
					{
						bool m_select = ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->CheckRect(point);
			            if(m_select==TRUE)
						{	
							for(int k=0;k<pDoc->m_ptrArray_sessible_size;k++)
							{
								((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[k]))->In_Draw_Point(&dc);
							}
							pDoc->m_ptrArray_sessible[j++]=i;
				            pDoc->m_ptrArray_sessible_size=1;
				            ((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->DrawTag(&dc);
				            if_any_select=true;
				            break;
						}
					}
					if(if_any_select==false)
					{	
						for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
						{	
							((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw_Point(&dc);	
						}
			            pDoc->m_ptrArray_sessible_size=0;
					}

				}

				
			}
		}

//		RedrawWindow();
	}

	
	CView::OnRButtonDown(nFlags, point);
}

void Cflowchart_testView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void Cflowchart_testView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//双击弹出添加文本对话框
	Cflowchart_testDoc* pDoc = GetDocument();
    for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
	{   
		if(((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->CheckRect(point))
        {    
			CPropertyDialog dlg;
            dlg.m_shape=((CBasicShape*)pDoc->m_ptrArray.GetAt(i));
			dlg.m_text=(dlg.m_shape->GetTitle());
			dlg.SetRedrawWnd(this);
            dlg.DoModal();
			
			break;
        }
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void Cflowchart_testView::OnEditCut()					//用于剪切
{
	// TODO: Add your command handler code here
	Cflowchart_testDoc* pDoc = GetDocument();
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
			pDoc->cut.RemoveAll();
	 	for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{
			for(int j=i;j<=i;j++)
				pDoc->m_ptrArray_sessible[j]-=i;
			/*if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==1)
				pDoc->mm_BasicShape=new CRectangle;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==2)
				pDoc->mm_BasicShape=new CEllipse;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==3)
				pDoc->mm_BasicShape=new CRhombus;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==4)
				pDoc->mm_BasicShape=new CQuadrangle;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==6)
				pDoc->mm_BasicShape=new CLabel;
			else
			{
				pDoc->m_ptrArray.RemoveAt(pDoc->m_ptrArray_sessible[i]);
				continue;
			}
			pDoc->mm_BasicShape->SetPoint(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->point1,((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->point2);			
			pDoc->mm_BasicShape->SetTag(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag());
			pDoc->mm_BasicShape->SetTitle(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTitle());
			*/
			if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()!=5)
			pDoc->cut.Add((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]]);
	 		((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->In_Draw(&dc);
	 		pDoc->m_ptrArray.RemoveAt(pDoc->m_ptrArray_sessible[i]);
			
			pDoc->cut_flag=true;
		
		}
		for(int m=0;m<pDoc->cut.GetSize();m++)
		{
			if(((CBasicShape*)pDoc->cut[m])->GetTag()!=5)
			{
				for(int t=0;t<pDoc->m_ptrArray.GetSize();t++)
				{
					if(((CBasicShape*)pDoc->m_ptrArray[t])->GetTag()==5)
					{
							if(((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind==(CBasicShape*)pDoc->cut[m]||((CBasicShape*)pDoc->m_ptrArray[t])->LineFront==((CBasicShape*)pDoc->cut[m]))
							{
								//pDoc->cut.Add((CBasicShape*)pDoc->m_ptrArray[t]);
	 							((CBasicShape*)pDoc->m_ptrArray[t])->In_Draw(&dc);
	 							pDoc->m_ptrArray.RemoveAt(t);
							}
					}
				}
			}
		}

		pDoc->m_ptrArray_sessible_size=0;
		/*for(int i=1;i<pDoc->m_ptrArray_sessible_size;i++)
		{
			((CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[i]))->In_Draw_Point(&dc);
		}*/
		InvalidateRect(NULL,TRUE);
}

void Cflowchart_testView::OnEditCopy()             //用于复制
{
	// TODO: Add your command handler code here
	Cflowchart_testDoc* pDoc = GetDocument();
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		pDoc->cut.RemoveAll();
		for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{
			if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==1)
				pDoc->mm_BasicShape=new CRectangle;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==2)
				pDoc->mm_BasicShape=new CEllipse;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==3)
				pDoc->mm_BasicShape=new CRhombus;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==4)
				pDoc->mm_BasicShape=new CQuadrangle;
			else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==6)
				pDoc->mm_BasicShape=new CLabel;
			else continue;
			pDoc->mm_BasicShape->SetPoint(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->point1,((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->point2);
			pDoc->mm_BasicShape->SetTag(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag());
			//if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==1)
			//{
			//	pDoc->mm_BasicShape=(CRectangle)pDoc->mm_BasicShape;
			//}
			pDoc->mm_BasicShape->SetTitle(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTitle());
			pDoc->cut.Add(pDoc->mm_BasicShape);
			
			((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->In_Draw_Point(&dc);
			
			pDoc->cut_flag=false;
		}
		pDoc->m_ptrArray_sessible_size=0;
		InvalidateRect(NULL,TRUE);
}

void Cflowchart_testView::OnEditPaste()           //用于黏贴
{
	// TODO: Add your command handler code here
	Cflowchart_testDoc* pDoc = GetDocument();
	InvalidateRect(NULL,FALSE);
	CClientDC dc(this);	
	if(pDoc->cut.GetSize()!=0&&pDoc->cut_flag==false)
	{
		for(int i=0;i<pDoc->cut.GetSize();i++)		
		{
			if(((CBasicShape*)pDoc->cut[i])->GetTag()!=5)
			{
				pDoc->m_ptrArray.InsertAt(0,((CBasicShape*)pDoc->cut[i]));
				((CBasicShape*)pDoc->m_ptrArray.GetAt(0))->paste_change();
			}
			
		}
		for(int j=0;j<pDoc->m_ptrArray.GetSize();j++)
			{
				((CBasicShape*)pDoc->m_ptrArray.GetAt(j))->Draw(&dc);
			}
	
	}
	else if(pDoc->cut.GetSize()!=0)
	{
		for(int i=0;i<pDoc->cut.GetSize();i++)		
		{
			
			pDoc->m_ptrArray.InsertAt(0,((CBasicShape*)pDoc->cut[i]));
			for(int i=0;i<pDoc->m_ptrArray.GetSize();i++)
			{
				((CBasicShape*)pDoc->m_ptrArray.GetAt(i))->Draw(&dc);
			}
		}
	}

	//RedrawWindow();

}


void Cflowchart_testView::OnText() 
{
	// TODO: Add your command handler code here
	Cflowchart_testDoc* pDoc = GetDocument(); 
			CPropertyDialog dlg;
            dlg.m_shape=(CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]);
			dlg.m_text=(dlg.m_shape->GetTitle());
			dlg.SetRedrawWnd(this);
            dlg.DoModal();
			
	
}

void Cflowchart_testView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint screen( point );
    CMenu menu2;
	menu2.LoadMenu(IDR_MENU2);
	CMenu*pPopup2=menu2.GetSubMenu(0);
	CMenu menu1;
	menu1.LoadMenu(IDR_MENU1);
	CMenu*pPopup1=menu1.GetSubMenu(0);
	ClientToScreen(&screen);
	Cflowchart_testDoc* pDoc = GetDocument();
	if( pDoc->m_ptrArray_sessible_size == 1 )//是否选中一个图形
	{
		CBasicShape* obj=(CBasicShape*)pDoc->m_ptrArray.GetAt(pDoc->m_ptrArray_sessible[0]);
		//如果点击图形内部则弹出快捷菜单1
		if( obj->CheckRect( point )  )
			pPopup1->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,screen.x,screen.y,this);
		//如果点击图形内部则弹出快捷菜单2
		else
			pPopup2->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,screen.x,screen.y,this);
	}
	//如果图形没有被选中，则弹出快捷菜单2
	else
		pPopup2->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,screen.x,screen.y,this);

	
	CView::OnRButtonUp(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
// 按键响应函数 PNG存储函数
/////////////////////////////////////////////////////////////////////////////

HANDLE MakeDib( HBITMAP hbitmap, UINT bits)   
{   
    HANDLE hdib;   
    HDC hdc;   
    BITMAP bitmap;   
    UINT wLineLen;   
    DWORD dwSize;   
    DWORD wColSize;   
    LPBITMAPINFOHEADER lpbi;   
    LPBYTE lpBits;   
    
	GetObject(hbitmap,sizeof(BITMAP),&bitmap)   ;
//   
//   DWORD   align   the   width   of   the   DIB   
//   Figure   out   the   size   of   the   colour   table   
//   Calculate   the   size   of   the   DIB   
//   
    wLineLen = (bitmap.bmWidth*bits+31)/32 * 4;
    wColSize = sizeof(RGBQUAD)*((bits <= 8) ? 1<<bits : 0);
    dwSize = sizeof(BITMAPINFOHEADER) + wColSize + (DWORD)(UINT)wLineLen*(DWORD)(UINT)bitmap.bmHeight;
//   
//   Allocate   room   for   a   DIB   and   set   the   LPBI   fields   
//   
    hdib = GlobalAlloc(GHND,dwSize);
    if (!hdib) return hdib;
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hdib);
	lpbi->biSize = sizeof(BITMAPINFOHEADER);
	lpbi->biWidth = bitmap.bmWidth;
	lpbi->biHeight = bitmap.bmHeight;
    lpbi->biPlanes = 1;
    lpbi->biBitCount = (WORD)bits;
    lpbi->biCompression = BI_RGB;
    lpbi->biSizeImage = dwSize - sizeof(BITMAPINFOHEADER) - wColSize;
    lpbi->biXPelsPerMeter =   0;
    lpbi->biYPelsPerMeter =   0;
    lpbi->biClrUsed = (bits <= 8) ? 1<<bits : 0;
    lpbi->biClrImportant = 0;
//   
//   Get   the   bits   from   the   bitmap   and   stuff   them   after   the   LPBI   
//   
    lpBits = (LPBYTE)(lpbi+1)+wColSize;
    hdc = CreateCompatibleDC(NULL);    
    GetDIBits(hdc,hbitmap,0,bitmap.bmHeight,lpBits,(LPBITMAPINFO)lpbi, DIB_RGB_COLORS);
//   Fix   this   if   GetDIBits   messed   it   up....   
    lpbi->biClrUsed = (bits <= 8) ? 1<<bits : 0;
    DeleteDC(hdc);   
    GlobalUnlock(hdib);  
    return hdib;   
}

#define DIB_HEADER_MARKER ((WORD)('M' << 8) | 'B')
#define WIDTHBYTES(bits) (((bits) + 31) / 32 * 4)
#define IS_WIN30_DIB(lpbi) ((*(LPDWORD)(lpbi)) == sizeof(BITMAPINFOHEADER))

WORD WINAPI DIBNumColors(LPSTR lpbi)
{   
    WORD wBitCount;
    if (IS_WIN30_DIB(lpbi))
    {   
        DWORD dwClrUsed;
		dwClrUsed = ((LPBITMAPINFOHEADER)lpbi)->biClrUsed;
		if (dwClrUsed   !=   0)
			return (WORD)dwClrUsed;
	}
	if (IS_WIN30_DIB(lpbi))
		wBitCount = ((LPBITMAPINFOHEADER)lpbi)->biBitCount;
	else
		wBitCount = ((LPBITMAPCOREHEADER)lpbi)->bcBitCount;
	switch (wBitCount)
	{
	    case 1: return 2;
	    case 4:	return 16;   
        case 8: return 256;
		default:return 0;
	}
}
WORD WINAPI PaletteSize(LPSTR lpbi)
{
	if (IS_WIN30_DIB (lpbi))
		return (WORD)(::DIBNumColors(lpbi) * sizeof(RGBQUAD));
	else
		return (WORD)(::DIBNumColors(lpbi) * sizeof(RGBTRIPLE));
}
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0;
	UINT size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;     //   Failure
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;     //   Failure
	GetImageEncoders (num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;     //   Success
		}
	}
	free(pImageCodecInfo);
	return -1;     //   Failure
}
void Cflowchart_testView::OnSavepng()
{
	CString strText;    //保存文件地址用变量
	LPWSTR lpszW = new WCHAR[255];    //转换文件地址用变量
	
	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle="PNG保存";
	fileDlg.m_ofn.lpstrFilter="PNG Files(*.png)\0*.png\0All Files(*.*)\0*.*\0\0";
	fileDlg.m_ofn.lpstrDefExt="png";
	//对话框预设置
	
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	HDC hdcMem = CreateCompatibleDC(pDC->GetSafeHdc());     //从已画完的PDC创建HDC
	HBITMAP hbitmap = CreateCompatibleBitmap(pDC->GetSafeHdc(),rect.right,rect.bottom);
	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hdcMem,hbitmap);
	StretchBlt(hdcMem,0,0,rect.right,rect.bottom,pDC->GetSafeHdc(),0,0,rect.right,rect.bottom,SRCCOPY);
	::SelectObject(hdcMem,hOldBmp);

	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken,&gdiplusStartupInput,NULL);
	//启动GDI+库

	Image* image = Bitmap::FromHBITMAP(hbitmap,0);

	CLSID pngClsid;
	GetEncoderClsid(L"image/png", &pngClsid);
    //载入GDI+库中PNG解码函数

	if(IDOK==fileDlg.DoModal())
	{
		strText = fileDlg.GetPathName();
        LPTSTR lpStr = strText.GetBuffer( strText.GetLength() );
        int nLen = MultiByteToWideChar(CP_ACP, 0,lpStr, -1, NULL, NULL);
        MultiByteToWideChar(CP_ACP, 0,  lpStr, -1, lpszW, nLen);
		image->Save(lpszW, &pngClsid, NULL);
	}
	//对话框确定后image存为PNG文件

    delete image;
	delete[] lpszW;
	GdiplusShutdown(gdiplusToken);
	//释放image 关闭GDI+
	::DeleteObject(hbitmap);
	::ReleaseDC(0,hdcMem);		
}

void Cflowchart_testView::OnDelete()              //删除功能
{
	//void Cflowchart_testView::OnDelete() 
	Cflowchart_testDoc* pDoc = GetDocument();
		InvalidateRect(NULL,FALSE);
		CClientDC dc(this);	
		pDoc->cut1.RemoveAll();	
	 	for(int i=0;i<pDoc->m_ptrArray_sessible_size;i++)
		{
			for(int j=i;j<=i;j++)
				pDoc->m_ptrArray_sessible[j]-=i;
			pDoc->cut1.Add((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]]);
	 		((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->In_Draw(&dc);
			//
			if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->GetTag()==5)
			{
				if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->GetTag()!=3)
				{	
					((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->outtag1=0;
				}
				else
				{
					if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->R_tag2==2)
					{
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->outtag1=0;
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->k=1;
					}
					else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->R_tag1==1)
					{
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->outtag2=0;
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->k=2;
					}
					else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->R_tag3==3)
					{
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->outtag3=0;
						((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineFront->k=3;
					}
				}
				if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag1!=0)
					((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag1=0;
				else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag2!=0)
					((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag2=0;
				else if(((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag3!=0)
					((CBasicShape*)pDoc->m_ptrArray[pDoc->m_ptrArray_sessible[i]])->LineBehind->intag3=0;
			}
			//
	 		pDoc->m_ptrArray.RemoveAt(pDoc->m_ptrArray_sessible[i]);
			
		
		}
		for(int m=0;m<pDoc->cut1.GetSize();m++)
		{
			if(((CBasicShape*)pDoc->cut1[m])->GetTag()!=5)
			{
				for(int t=0;t<pDoc->m_ptrArray.GetSize();t++)
				{
					if(((CBasicShape*)pDoc->m_ptrArray[t])->GetTag()==5)
					{
							if(((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind==(CBasicShape*)pDoc->cut1[m]||((CBasicShape*)pDoc->m_ptrArray[t])->LineFront==((CBasicShape*)pDoc->cut1[m]))
							{
								pDoc->cut1.Add((CBasicShape*)pDoc->m_ptrArray[t]);
								//
								if(((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->GetTag()!=3)
								{	
									((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->outtag1=0;
								}
								else
								{
									if(((CBasicShape*)pDoc->m_ptrArray[t])->R_tag2==2)
									{
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->outtag1=0;
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->k=1;
									}
									else if(((CBasicShape*)pDoc->m_ptrArray[t])->R_tag1==1)
									{
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->outtag2=0;
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->k=2;
									}
									else if(((CBasicShape*)pDoc->m_ptrArray[t])->R_tag3==3)
									{
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->outtag3=0;
										((CBasicShape*)pDoc->m_ptrArray[t])->LineFront->k=3;
									}
								}

						if(((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag1!=0)
							((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag1=0;
						else if(((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag2!=0)
							((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag2=0;
						else if(((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag3!=0)
							((CBasicShape*)pDoc->m_ptrArray[t])->LineBehind->intag3=0;
                                //
	 							((CBasicShape*)pDoc->m_ptrArray[t])->In_Draw(&dc);
	 							pDoc->m_ptrArray.RemoveAt(t);
							}
					}
				}
			}
		}
		pDoc->m_ptrArray_sessible_size=0;
		pDoc->cut1.RemoveAll();
		InvalidateRect(NULL,TRUE);

}


void Cflowchart_testView::OnHelpFinder()                    //内部代码为引用代码，用于打开帮助文档
{
	    char exeFullPath[MAX_PATH];
		CString strPath;
		GetModuleFileName(NULL,exeFullPath,MAX_PATH);

		strPath = CString(exeFullPath);
		strPath = strPath.Left(strPath.ReverseFind('\\'));
		strPath += "\\flowchart_editor_help.chm";
		CString hh;	
		hh.Format("hh.exe ");
		CString final=hh+strPath;
		char* line=(char*)(LPCTSTR)final;


WinExec(line,SW_SHOW);

}
