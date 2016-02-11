// BasicShape.cpp: implementation of the CBasicShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flowchart_test.h"
#include "BasicShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBasicShape::CBasicShape()		  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
{
	tag=0;
	m_title="";
	m_clr=RGB(0,0,0);
    logFont.lfHeight = -round( 12.0 * 1.0 );
    logFont.lfWidth   = 0;
    logFont.lfEscapement = 0;
    logFont.lfOrientation = 0;
    logFont.lfWeight = FW_NORMAL;
    logFont.lfItalic = 0;
    logFont.lfUnderline = 0;
    logFont.lfStrikeOut = 0;
    logFont.lfCharSet = 0;
    logFont.lfOutPrecision = 0;
    logFont.lfClipPrecision = 0;
    logFont.lfQuality = 0;
    logFont.lfPitchAndFamily=0;
    strcpy (logFont.lfFaceName, _T( "Courier New" ));
    m_font.CreateFontIndirect(&logFont);
	R_tag1=0;
	R_tag2=0;
	R_tag3=0;
	tag1=0;
	tag2=0;
	k=1;
	intag1=0;
	intag2=0;
	intag3=0;
	outtag1=0;
	outtag2=0;
	outtag3=0;
}

CBasicShape::~CBasicShape()
{

}

void CBasicShape::SetTag(int mid_tag)
{
	tag=mid_tag;
}
int CBasicShape::GetTag()
{
	return(tag);
}
void CBasicShape::Draw(CDC* pDC)
{

}
void CBasicShape::SetPoint(CPoint m_point1,CPoint m_point2)
{
	point1=m_point1;
	point2=m_point2;
}

void CBasicShape::Serialize(CArchive& ar)
{
}

////////////////////////////////////////////////////
// OnSavesvg 基类SVG保存函数 虚函数
////////////////////////////////////////////////////
CString CBasicShape::OnSavesvg()
{
    CString str;
	return str;
}
bool CBasicShape::CheckRect(CPoint c_point)
{
	CRect crect1(point1,point2);
	CRect crect2(point2,point1);
	if(crect1.PtInRect(c_point)||crect2.PtInRect(c_point))
		return TRUE;
	else 
		return FALSE;
}
bool CBasicShape::Check_Out_Rect(CPoint c_point1,CPoint c_point2)
{
	return false;
	
}
void CBasicShape::DrawTag(CClientDC* pDC)
{	

	/*CPoint t_point1;
	CPoint t_point2;
	t_point1.x=point1.x+point2.x;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	*/
}
void CBasicShape::MovePoint(CPoint m_point1,CPoint m_point2)
{
	point1.x=m_point2.x-m_point1.x+point1.x;
	point1.y=m_point2.y-m_point1.y+point1.y;
	point2.x=m_point2.x-m_point1.x+point2.x;
	point2.y=m_point2.y-m_point1.y+point2.y;
	
}
bool CBasicShape::in_hot_point(CPoint m_point)
{
	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	CRect crect1(t_point1,t_point2);
	if(crect1.PtInRect(m_point)) return true;
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
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
void CBasicShape::Zoom(CPoint m_point1, CPoint m_point2)
{
	CPoint t_point1;
	CPoint t_point2;
	t_point1.x=(point1.x+point2.x)/2-5;
	t_point1.y=point1.y;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y-10;
	CRect crect1(t_point1,t_point2);
	if(crect1.PtInRect(m_point1)) 
	{
		point1.y=m_point2.y;
		return;
	}
	t_point1.y=(point1.y+point2.y)/2-5;
	t_point1.x=point1.x;
	t_point2.x=t_point1.x-10;
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
void CBasicShape::In_Draw(CClientDC* pDC)
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
void CBasicShape::In_Draw_Point(CClientDC* pDC)
{
	CPen pen(PS_SOLID,1,RGB(255,255,255)); //白色实线画笔，决定画图的边线


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

	pDC->SelectObject(pOldPen);
}



//DEL CString CBasicShape::GetTitle() const
//DEL {
//DEL 
//DEL }



//DEL CString CBasicShape::GetTitle() const
//DEL {
//DEL 
//DEL }

CString CBasicShape::GetTitle() const
{
	return m_title;
}

void CBasicShape::SetTitle(CString title)
{
	m_title = title;
}

void CBasicShape::SetCharacter(CString mid_title)
{
	m_title=mid_title;
}

COLORREF CBasicShape::GetClr()
{
    return m_clr;
}

CFont* CBasicShape::GetFont()
{
    return &m_font;
}

LOGFONT* CBasicShape::GetlogFont()
{
    return &logFont;
}

void CBasicShape::SetClr(COLORREF clr)
{
    m_clr=clr;
}

void CBasicShape::SetlogFont(LOGFONT *lf)
{
    logFont.lfHeight = lf->lfHeight;
    logFont.lfWidth   = lf->lfWidth;
    logFont.lfEscapement = lf->lfEscapement;
    logFont.lfOrientation = lf->lfOrientation;
    logFont.lfWeight = lf->lfWeight;
    logFont.lfItalic = lf->lfItalic;
    logFont.lfUnderline = lf->lfUnderline;
    logFont.lfStrikeOut = lf->lfStrikeOut;
    logFont.lfCharSet = lf->lfCharSet;
    logFont.lfOutPrecision = lf->lfOutPrecision;
    logFont.lfClipPrecision = lf->lfClipPrecision;
    logFont.lfQuality = lf->lfQuality;
    logFont.lfPitchAndFamily=lf->lfPitchAndFamily;
    strcpy (logFont.lfFaceName, lf->lfFaceName);
}

CPoint CBasicShape::GetPoint11()           //用于四个基本图形
{

		CPoint mid_point1;
		mid_point1.x=(point1.x+point2.x)/2;
		mid_point1.y=point2.y;
		return mid_point1;
}

CPoint CBasicShape::GetPoint12()
{

	CPoint mid_point1;
	mid_point1.x=point2.x;
	mid_point1.y=(point1.y+point2.y)/2;
	return mid_point1;
}
CPoint CBasicShape::GetPoint13()
{
	      //*&&下一个直线* //下一个是直线由菱形第三出口出发
	CPoint mid_point1;
	mid_point1.x=point1.x;
	mid_point1.y=(point1.y+point2.y)/2;
	return mid_point1;
}
CPoint CBasicShape::GetPoint2()
{
	if(tag!=5)//非折线
	{
		CPoint mid_point2;
		mid_point2.x=(point1.x+point2.x)/2;
		mid_point2.y=point1.y;
		return mid_point2;
	}
	if(tag==5)
	{
		CPoint mid_point2;
		mid_point2.x=point1.x;
		mid_point2.y=(point1.y+point2.y)/2-10;
		return mid_point2;
	}
}
CBasicShape* CBasicShape::GetLine_ptr1()
{
	return LineFront;
}
CBasicShape* CBasicShape::GetLine_ptr2()
{
	return LineBehind;
}

void  CBasicShape::SetRTag(int tag11,int tag22,int R_tag11,int R_tag22,int R_tag33)
{
	tag1=tag11;
	tag2=tag22;
	R_tag1=R_tag11;
	R_tag2=R_tag22;
	R_tag3=R_tag33;
}


void CBasicShape::AddTag()
{
	k++;
}

int CBasicShape::Get_k()
{
	return k;
}

void CBasicShape::Reduce_k()
{
	k--;
}

void CBasicShape::paste_change()
{
	point1.x=point1.x+20;
	point1.y=point1.y+20;
	point2.x=point2.x+20;
	point2.y=point2.y+20;
}

int CBasicShape::GetWidth()
{
	int width;
	if(point1.x<point2.x)
		width=point2.x-point1.x;
	else
		width=point1.x-point2.x;
	return width;
}
bool CBasicShape::EntryCheck()
{
	if(intag1==1)
		return TRUE;
	else
		return FALSE;
}

void CBasicShape::Set_in_out_tag(int i_tag1,int i_tag2,int i_tag3,int o_tag1,int o_tag2,int o_tag3)
{
	outtag1=o_tag1;
	outtag2=o_tag2;
	outtag3=o_tag3;
	intag1=i_tag1;
	intag2=i_tag2;
	intag3=i_tag3;
}

void CBasicShape::Setintag(int i_tag1)
{
	intag1=i_tag1;
}