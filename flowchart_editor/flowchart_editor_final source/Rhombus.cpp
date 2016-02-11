// Rhombus.cpp: implementation of the CRhombus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flowchart_test.h"
#include "Rhombus.h"
IMPLEMENT_SERIAL(CRhombus,CObject,1);

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRhombus::CRhombus()
{

}

CRhombus::~CRhombus()
{

}
void CRhombus::SetTag(int mid_tag)
{
	tag=mid_tag;
}
int CRhombus::GetTag()
{
	return(tag);
}

void CRhombus::SetPoint(CPoint m_point1,CPoint m_point2)
{
	point1=m_point1;
	point2=m_point2;
}
void CRhombus::Draw(CDC* pDC)
{
	pDC->SelectStockObject( BLACK_PEN );
	pDC->SelectStockObject( WHITE_BRUSH );

	// 画图形
	CPoint pt[4];

	pt[0].x = point1.x;
	pt[0].y = (point1.y+point2.y)/2;

	pt[1].x = (point1.x+point2.x)/2;
	pt[1].y = point1.y;

	pt[2].x = point2.x;
	pt[2].y = (point1.y+point2.y)/2;

	pt[3].x = (point1.x+point2.x)/2;
	pt[3].y = point2.y;

	pDC->Polygon( pt, 4 );

	// 画文本	
	CRect rect(point1,point2);
	int qwidth = rect.Width() / 4;
	int qheight = rect.Height() / 4;
	CRect r( point1.x + qwidth, point1.y + qheight, point2.x - qwidth, point2.y - qheight );
	CFont *pOldFont=pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_clr);
    pDC->DrawText(GetTitle(),r,DT_NOPREFIX | DT_WORDBREAK | DT_CENTER);
	pDC->SelectObject(pOldFont);
}
void CRhombus::Serialize(CArchive &ar)
{
	CBasicShape::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<tag<<point1<<point2<<m_title<<outtag1<<outtag2<<outtag3<<intag1<<intag2<<intag3;
	}
	else
	{
		ar>>tag>>point1>>point2>>m_title;
	}
}

void CRhombus::DrawTag(CClientDC* pDC)
{	
	CPoint t_point1;
	CPoint t_point2;
	CBrush brushBlue(RGB(0, 255, 0));
   CBrush* pOldBrush = pDC->SelectObject(&brushBlue);
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	pDC->SelectObject(pOldBrush);
}
void CRhombus::MovePoint(CPoint m_point1,CPoint m_point2)
{
	point1.x=m_point2.x-m_point1.x+point1.x;
	point1.y=m_point2.y-m_point1.y+point1.y;
	point2.x=m_point2.x-m_point1.x+point2.x;
	point2.y=m_point2.y-m_point1.y+point2.y;
	
}
void CRhombus::Zoom(CPoint m_point1, CPoint m_point2)
{
	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y-10;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect1(t_point1,t_point2);
	if(crect1.PtInRect(m_point1)) 
	{
		point1.y=m_point2.y;
		return;
	}
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x-10;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect2(t_point1,t_point2);
	if(crect2.PtInRect(m_point1)) 
	{
		point1.x=m_point2.x;
		return;
	}
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect3(t_point1,t_point2);
	if(crect3.PtInRect(m_point1)) 
	{
		point2.x=m_point2.x;
		return;
	}
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect4(t_point1,t_point2);
	if(crect4.PtInRect(m_point1)) 
	{
		point2.y=m_point2.y;
		return;
	}
}
bool CRhombus::in_hot_point(CPoint m_point)
{
	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y-10;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect1(t_point1,t_point2);
	if(crect1.PtInRect(m_point)) return true;
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x-10;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect2(t_point1,t_point2);
	if(crect2.PtInRect(m_point)) return true;
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect3(t_point1,t_point2);
	if(crect3.PtInRect(m_point)) return true;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect4(t_point1,t_point2);
	if(crect4.PtInRect(m_point)) return true;
	return false;
}
bool CRhombus::CheckRect(CPoint c_point)
{
	CRect crect1(point1,point2);
	CRect crect2(point2,point1);
	if(crect1.PtInRect(c_point)||crect2.PtInRect(c_point))
		return TRUE;
	else 
		return FALSE;
}
bool CRhombus::Check_Out_Rect(CPoint c_point1,CPoint c_point2)
{
	CRect crect1(c_point1,c_point2);
	CRect crect2(point1,point2);
	if((crect1.PtInRect(point1)&&crect1.PtInRect(point2))||crect2.PtInRect(c_point1))
		return TRUE;
	else
		return FALSE;
}
void CRhombus::In_Draw(CClientDC* pDC)
{
	CPen pen(PS_SOLID,1,pDC->GetBkColor()); 


CPen *pOldPen=pDC->SelectObject(&pen);//画笔选入设备描述表

	pDC->MoveTo(point1.x,(point1.y+point2.y)/2);
	pDC->LineTo((point1.x+point2.x)/2,point1.y);
	pDC->LineTo(point2.x,(point1.y+point2.y)/2);
	pDC->LineTo((point1.x+point2.x)/2,point2.y);
	pDC->LineTo(point1.x,(point1.y+point2.y)/2);
	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	CBrush brushBlue(pDC->GetBkColor());
   CBrush* pOldBrush = pDC->SelectObject(&brushBlue);
	pDC->Rectangle(CRect(point1,point2));
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));


pDC->SelectObject(pOldBrush);

pDC->SelectObject(pOldPen);
 

}
void CRhombus::In_Draw_Point(CClientDC* pDC)
{
	CPen pen(PS_SOLID,1,pDC->GetBkColor()); 


CPen *pOldPen=pDC->SelectObject(&pen);//画笔选入设备描述表

	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->MoveTo(t_point1.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point2.y);
	pDC->LineTo(t_point2.x,t_point1.y);
	pDC->LineTo(t_point1.x,t_point1.y);
	CBrush brush(pDC->GetBkColor());
   CBrush* pOldBrush = pDC->SelectObject(&brush);

	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point2.x;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point2.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
pDC->Rectangle(CRect(t_point1,t_point2));


pDC->SelectObject(pOldBrush);

	pDC->SelectObject(pOldPen);
}
void CRhombus::paste_change()
{
	point1.x=point1.x+20;
	point1.y=point1.y+20;
	point2.x=point2.x+20;
	point2.y=point2.y+20;
}

////////////////////////////////////////////////////
// OnSavesvg 菱形内SVG保存函数
////////////////////////////////////////////////////
CString CRhombus::OnSavesvg()
{
	CPoint pt[4];   //pt[4] 计算并存储菱形四端点坐标

	pt[0].x = point1.x;
	pt[0].y = (point1.y+point2.y)/2;

	pt[1].x = (point1.x+point2.x)/2;
	pt[1].y = point1.y;

	pt[2].x = point2.x;
	pt[2].y = (point1.y+point2.y)/2;

	pt[3].x = (point1.x+point2.x)/2;
	pt[3].y = point2.y;
	
	HDC hDC = CreateCompatibleDC(NULL);
	
	CString rho_Temp,text_Temp;   //rho_Temp保存绘制形状的路径 text_Temp保存绘制文字的变量
	rho_Temp.Format("<polygon points=\"%d,%d %d,%d %d,%d %d,%d\" style=\"fill:rgb(255,255,255);stroke-width:1;stroke:rgb(0,0,0)\"/>\r\n",pt[0].x,pt[0].y,pt[1].x,pt[1].y,pt[2].x,pt[2].y,pt[3].x,pt[3].y);
	
	CString isItalic,isUnderline;   //isItalic和isUnderline分别为是否斜体和下划线
	CRect rect(point1,point2);
	int qheight = rect.Height() / 4;
	if(logFont.lfItalic == true)
		isItalic="Italic";
	else
		isItalic="Normal";
	if(logFont.lfUnderline == true)
		isUnderline="Underline";
	else
		isUnderline="none";
	
	text_Temp.Format("<text x=\"%d\" y=\"%d\" style=\"fill:RGB(%d,%d,%d); text-anchor: middle; font-size:%dpt; font-weight:%d; font-family:%s; font-style:%s; text-decoration:%s\">%s</text>\r\n", (point1.x + point2.x) / 2,point1.y + qheight + abs(logFont.lfHeight),GetRValue(GetClr()),GetGValue(GetClr()),GetBValue(GetClr()),(int)(-(float)logFont.lfHeight * 72.0 / GetDeviceCaps(hDC, LOGPIXELSY) + 0.5),logFont.lfWeight,logFont.lfFaceName,(LPCTSTR)isItalic,(LPCTSTR)isUnderline,GetTitle());
	
	return rho_Temp+text_Temp;   //return 向flowchart_testDoc中返回上述两字符串
}