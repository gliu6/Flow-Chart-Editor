// Label.cpp: implementation of the CLabel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"					  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
#include "flowchart_test.h"
#include "Label.h"
IMPLEMENT_SERIAL(CLabel,CObject,1);

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLabel::CLabel()
{
	m_title="Lable";

}

CLabel::~CLabel()
{

}

void CLabel::SetTag(int mid_tag)
{
	tag=mid_tag;
}
int CLabel::GetTag()
{
	return(tag);
}
void CLabel::SetPoint(CPoint m_point1,CPoint m_point2)
{
	point1=m_point1;
	point2=m_point2;
}

void CLabel::Draw(CDC* pDC)
{
//画文本
    int cut = round( ( double ) 10 * 1.0);
	CRect r( point1.x + cut, point1.y + cut / 2, point2.x - cut, point2.y - cut / 2 );
	CFont *pOldFont=pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_clr);
    pDC->DrawText( GetTitle(), r, DT_NOPREFIX | DT_WORDBREAK | DT_CENTER );
	pDC->SelectObject(pOldFont);
}

void CLabel::Serialize(CArchive &ar)
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
void CLabel::DrawTag(CClientDC* pDC)
{	
	CPoint t_point1;
	CPoint t_point2;
	// create and select a solid blue brush
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
void CLabel::MovePoint(CPoint m_point1,CPoint m_point2)
{
	point1.x=m_point2.x-m_point1.x+point1.x;
	point1.y=m_point2.y-m_point1.y+point1.y;
	point2.x=m_point2.x-m_point1.x+point2.x;
	point2.y=m_point2.y-m_point1.y+point2.y;
	
}
void CLabel::Zoom(CPoint m_point1, CPoint m_point2)
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
bool CLabel::in_hot_point(CPoint m_point)
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
bool CLabel::CheckRect(CPoint c_point)
{
	CRect crect1(point1,point2);
	CRect crect2(point2,point1);
	if(crect1.PtInRect(c_point)||crect2.PtInRect(c_point))
		return TRUE;
	else 
		return FALSE;
}
bool CLabel::Check_Out_Rect(CPoint c_point1,CPoint c_point2)
{
	CRect crect1(c_point1,c_point2);
	CRect crect2(point1,point2);
	if((crect1.PtInRect(point1)&&crect1.PtInRect(point2))||crect2.PtInRect(c_point1))
		return TRUE;
	else
		return FALSE;
}
void CLabel::In_Draw(CClientDC* pDC)
{
	CPen pen(PS_SOLID,1,RGB(255,255,255)); //白色实线画笔，决定画图的边线


CPen *pOldPen=pDC->SelectObject(&pen);//画笔选入设备描述表

	pDC->MoveTo(point1.x,point1.y);
	pDC->LineTo(point1.x,point2.y);
	pDC->LineTo(point2.x,point2.y);
	pDC->LineTo(point2.x,point1.y);
	pDC->LineTo(point1.x,point1.y);
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
CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH));

                                                              //创建空画刷，防止遮挡内容


CBrush *pOldBrush=pDC->SelectObject(pBrush);//选择画刷


pDC->Rectangle(CRect(point1,point2)); //画矩形
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
void CLabel::In_Draw_Point(CClientDC* pDC)
{
	CPen pen(PS_SOLID,1,RGB(255,255,255)); //白色实线画笔，决定画图的边线


	CPen *pOldPen=pDC->SelectObject(&pen);//画笔选入设备描述表
	pDC->MoveTo(point1.x,point1.y);
	pDC->LineTo(point1.x,point2.y);
	pDC->LineTo(point2.x,point2.y);
	pDC->LineTo(point2.x,point1.y);
	pDC->LineTo(point1.x,point1.y);
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
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH));

                                                              //创建空画刷，防止遮挡内容


CBrush *pOldBrush=pDC->SelectObject(pBrush);//选择画刷

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
void CLabel::paste_change()
{
	point1.x=point1.x+20;
	point1.y=point1.y+20;
	point2.x=point2.x+20;
	point2.y=point2.y+20;
}

////////////////////////////////////////////////////
// OnSavesvg 文字标签内SVG保存函数
////////////////////////////////////////////////////
CString CLabel::OnSavesvg()
{
	HDC hDC = CreateCompatibleDC(NULL);
	int cut = round( ( double ) 10 * 1.0);
    
	CString text_Temp;//text_Temp保存绘制文字的变量
	
	CString isItalic,isUnderline;   // isItalic和isUnderline分别为是否斜体和下划线
	if(logFont.lfItalic == true)
		isItalic="Italic";
	else
		isItalic="Normal";
	if(logFont.lfUnderline == true)
		isUnderline="Underline";
	else
		isUnderline="none";
	
	text_Temp.Format("<text x=\"%d\" y=\"%d\" style=\"fill:RGB(%d,%d,%d); text-anchor: middle; font-size:%dpt; font-weight:%d; font-family:%s; font-style:%s; text-decoration:%s\">%s</text>\r\n", (point1.x + point2.x) / 2,point1.y + cut / 2 + abs(logFont.lfHeight),GetRValue(GetClr()),GetGValue(GetClr()),GetBValue(GetClr()),(int)(-(float)logFont.lfHeight * 72.0 / GetDeviceCaps(hDC, LOGPIXELSY) + 0.5),logFont.lfWeight,logFont.lfFaceName,(LPCTSTR)isItalic,(LPCTSTR)isUnderline,GetTitle());
	
	return text_Temp;   //return 向flowchart_testDoc中返回该字符串
}
