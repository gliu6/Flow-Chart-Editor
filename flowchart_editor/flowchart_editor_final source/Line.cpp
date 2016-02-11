// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"					  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
#include "flowchart_test.h"
#include "Line.h"
#include "math.h"
IMPLEMENT_SERIAL(CLine,CObject,1);

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{
	width1=0;
	width2=0;
	mpoint1.x=mpoint2.x=mpoint3.x=mpoint4.x=0;
	mpoint1.y=mpoint2.y=mpoint3.y=mpoint4.y=0;
}

CLine::~CLine()
{

}

void CLine::SetTag(int mid_tag)
{
	tag=mid_tag;
}

void CLine::SetPoint(CPoint m_point1,CPoint m_point2)
{
	point1=m_point1;
	point2=m_point2;
}

void CLine::Draw(CDC* pDC)
{
	//重画以前图形为白色
	CPen pen(PS_SOLID,1,pDC->GetBkColor());  //白色实线画笔，决定画图的边线            
	CPen *pOldPen=pDC->SelectObject(&pen);  //画笔选入设备描述表
	if(tag2!=5&&tag1!=3)//结束点非直线，并且出发点非菱形
	{
		if(point1.y<point2.y)
		{
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x,(point1.y+point2.y)/2);
			pDC->LineTo(point1.x,(point1.y+point2.y)/2);
			pDC->LineTo(point1.x,point1.y);
		}
		if(point1.y>=point2.y&&point1.x!=point2.x)
		{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y+20);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y+20);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y+20);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
			
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y+20);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y+20);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
				}
			}
			pDC->LineTo(point2.x,point2.y);

		}
		    pDC->MoveTo(point2);
			pDC->LineTo(point2.x-5,point2.y-5);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x+5,point2.y-5);
        /*if(point1.y>point2.y&&point1.x==point2.x)
		{
            pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			pDC->LineTo(point1.x-100,point1.y+20);
			pDC->LineTo(point1.x-100,point2.y-20);
			pDC->LineTo(point2.x,point2.y-20);
			pDC->LineTo(point2.x,point2.y);
		}
		*/
	}
	else if(tag1==3&&tag2!=5)//结束点非直线，但出发点为菱形
	{
		if(R_tag2==2)//从下面的点出发
		{
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x-5,point2.y-5);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x+5,point2.y-5);
			if(point1.y<point2.y)
			{
				pDC->MoveTo(point2);
				pDC->LineTo(point2.x,(point1.y+point2.y)/2);
				pDC->LineTo(point1.x,(point1.y+point2.y)/2);
				pDC->LineTo(point1.x,point1.y);
			}
				if(point1.y>=point2.y&&point1.x!=point2.x)
		{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y+20);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y+20);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y+20);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
			
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y+20);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y+20);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
				}
			}
			pDC->LineTo(point2.x,point2.y);

		}
			/*if(point1.y>point2.y&&point1.x==point2.x)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x,point1.y+20);
				pDC->LineTo(point1.x-100,point1.y+20);
				pDC->LineTo(point1.x-100,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
				pDC->LineTo(point2.x,point2.y);
			}
			*/
		}
		if(R_tag1==1) //从右边的点出发
		{
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x-10,point2.y-10);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x+10,point2.y-10);
			if(point1.x<point2.x&&point1.y<point2.y)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point2.x,point1.y);
				pDC->LineTo(point2.x,point2.y);
			}
			if(point1.x>point2.x&&point1.y==point2.y)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x,point1.y+50);
				pDC->LineTo(point2.x,point1.y+50);
				pDC->LineTo(point2.x,point2.y);
			}
		/*	if(point1.x<point2.x&&point1.y>=point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
			}
		*/
			if(point1.x>=point2.x&&point1.y<point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
			}
		/*	if(point1.x>=point2.x&&point1.y>point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
			}
		*/
			if(point1.y>=point2.y&&point1.x!=point2.x)
			{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y);
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
			
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
				}
			}
			pDC->LineTo(point2.x,point2.y);
			}

		}
		
	}
	if(tag2==5)//结束点为直线
	{
            pDC->MoveTo(point1);
			pDC->LineTo(point1.x-150,point1.y);
			pDC->LineTo(point1.x-150,point2.y);
			pDC->LineTo(point2.x,point2.y);
			pDC->LineTo(point2.x-5,point2.y-5);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x-5,point2.y+5);
	}

	pDC->SelectObject(pOldPen);                
	//~重画白色

		//画文本
	CRect r1(point1.x+5,(point1.y+point2.y)/2-20,point2.x+50,(point1.y+point2.y)/2-1);
	CFont *pOldFont1=pDC->SelectObject(&m_font);
	pDC->SetTextColor(RGB(255,255,255));
    pDC->DrawText(GetTitle(),r1,DT_NOPREFIX | DT_WORDBREAK | DT_LEFT);
	pDC->SelectObject(pOldFont1);

	if(R_tag2==2)
		point1=LineFront->GetPoint11();
	else if(R_tag1==1)
		point1=LineFront->GetPoint12();
	else if(R_tag3==3)
		point1=LineFront->GetPoint13();

	point2=LineBehind->GetPoint2();
	
	width1=LineFront->GetWidth();
	width2=LineBehind->GetWidth();

	if(tag2!=5&&tag1!=3)//结束点非直线，并且出发点非菱形
	{
		if(point1.y<point2.y)
		{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,(point1.y+point2.y)/2);
			pDC->LineTo(point2.x,(point1.y+point2.y)/2);
			pDC->LineTo(point2.x,point2.y);
			//获取中间点
			mpoint1.x=point1.x;
			mpoint1.y=(point1.y+point2.y)/2;
			mpoint2.x=point2.x;
			mpoint2.y=(point1.y+point2.y)/2;
			mpoint3=mpoint2;
			mpoint4=mpoint3;
		}
		if(point1.y>=point2.y&&point1.x!=point2.x)
		{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			//
			mpoint1.x=point1.x;
			mpoint1.y=point1.y+20;
			//
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y+20);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
				//
				mpoint2.x=(point1.x+point2.x)/2;
				mpoint2.y=point1.y+20;
				mpoint3.x=(point1.x+point2.x)/2;
				mpoint3.y=point2.y-20;
				mpoint4.x=point2.x;
				mpoint4.y=point2.y-20;
				//
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y+20);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
						//
						mpoint2.x=point2.x+width1/2+15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x+width1/2+15;
						mpoint3.y=point2.y-20;
						//
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y+20);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
						mpoint2.x=point2.x+width2/2+15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x+width2/2+15;
						mpoint3.y=point2.y-20;
					}
					pDC->LineTo(point2.x,point2.y-20);
					mpoint4.x=point2.x;
					mpoint4.y=point2.y-20;
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y+20);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
						mpoint2.x=point2.x-width1/2-15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x-width1/2-15;
						mpoint3.y=point2.y-20;
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y+20);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
						mpoint2.x=point2.x-width2/2-15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x-width2/2-15;
						mpoint3.y=point2.y-20;
					}
					pDC->LineTo(point2.x,point2.y-20);
					mpoint4.x=point2.x;
					mpoint4.y=point2.y-20;
				}
			}
			pDC->LineTo(point2.x,point2.y);

		}
		    pDC->MoveTo(point2);
			pDC->LineTo(point2.x-5,point2.y-5);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x+5,point2.y-5);
       /* if(point1.y>point2.y&&point1.x==point2.x)
		{
            pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			pDC->LineTo(point1.x-100,point1.y+20);
			pDC->LineTo(point1.x-100,point2.y-20);
			pDC->LineTo(point2.x,point2.y-20);
			pDC->LineTo(point2.x,point2.y);
		}
		*/
	}
	else if(tag1==3&&tag2!=5)//结束点非直线，但出发点为菱形
	{
		pDC->MoveTo(point2);
		pDC->LineTo(point2.x-5,point2.y-5);
		pDC->MoveTo(point2);
		pDC->LineTo(point2.x+5,point2.y-5);
		if(R_tag2==2)//从下面的点出发
		{
			if(point1.y<point2.y)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x,(point1.y+point2.y)/2);
				pDC->LineTo(point2.x,(point1.y+point2.y)/2);
				pDC->LineTo(point2.x,point2.y);
				//
				mpoint1.x=point1.x;
				mpoint1.y=(point1.y+point2.y)/2;
				mpoint2.x=point2.x;
				mpoint2.y=(point1.y+point2.y)/2;
				mpoint3=mpoint2;
				mpoint4=mpoint3;
				//
			}
			if(point1.y>=point2.y&&point1.x!=point2.x)
			{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y+20);
			//
			mpoint1.x=point1.x;
			mpoint1.y=point1.y+20;
			//
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y+20);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
				//
				mpoint2.x=(point1.x+point2.x)/2;
				mpoint2.y=point1.y+20;
				mpoint3.x=(point1.x+point2.x)/2;
				mpoint3.y=point2.y-20;
				mpoint4.x=point2.x;
				mpoint4.y=point2.y-20;
				//
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y+20);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
						//
						mpoint2.x=point2.x+width1/2+15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x+width1/2+15;
						mpoint3.y=point2.y-20;
						//
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y+20);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
						//
						mpoint2.x=point2.x+width2/2+15;
						mpoint2.y=point1.y+20;
						mpoint3.x=point2.x+width2/2+15;
						mpoint3.y=point2.y-20;
						//
					}
					pDC->LineTo(point2.x,point2.y-20);
					mpoint4.x=point2.x;
					mpoint4.y=point2.y-20;
			
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y+20);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y+20);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
					}
					pDC->LineTo(point2.x,point2.y-20);
					mpoint4.x=point2.x;
		        	mpoint4.y=point2.y-20;
				}
			}
			pDC->LineTo(point2.x,point2.y);
			

			}
			/*if(point1.y>point2.y&&point1.x==point2.x)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x,point1.y+20);
				pDC->LineTo(point1.x-100,point1.y+20);
				pDC->LineTo(point1.x-100,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
				pDC->LineTo(point2.x,point2.y);
			}*/
		}
		if(R_tag1==1) //从右边的点出发
		{
			if(point1.x<point2.x&&point1.y<point2.y)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point2.x,point1.y);
				pDC->LineTo(point2.x,point2.y);
				mpoint1.x=point2.x;
				mpoint1.y=point1.y;
				mpoint2=mpoint1;
				mpoint3=mpoint2;
				mpoint4=mpoint3;
			}
			/*
			if(point1.x>point2.x&&point1.y==point2.y)
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point1.y-50);
				pDC->LineTo(point2.x,point1.y-50);
				pDC->LineTo(point2.x,point2.y);
				mpoint1.x=point1.x+10;
				mpoint1.y=point1.y;
				
			}
			*/
		/*	if(point1.x<point2.x&&point1.y>=point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
			}
		*/
			if(point1.x>=point2.x&&point1.y<point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
				mpoint1.x=point1.x+10;
				mpoint1.y=point1.y;
				mpoint2.x=point1.x+10;
				mpoint2.y=point2.y-10;
				mpoint3.x=point2.x;
				mpoint3.y=point2.y-10;
				mpoint4=mpoint3;
			}
		/*	if(point1.x>=point2.x&&point1.y>point2.y)//
			{
				pDC->MoveTo(point1);
				pDC->LineTo(point1.x+10,point1.y);
				pDC->LineTo(point1.x+10,point2.y-10);
				pDC->LineTo(point2.x,point2.y-10);
				pDC->LineTo(point2.x,point2.y);
			}
		*/
			if(point1.y>=point2.y&&point1.x!=point2.x)
			{
			pDC->MoveTo(point1);
			pDC->LineTo(point1.x,point1.y);
			if(((point2.x-point1.x)>=width1&&(point2.x-point1.x)>=width2)||((point1.x-point2.x)>=width1&&(point1.x-point2.x)>=width2))
			{
				pDC->LineTo((point1.x+point2.x)/2,point1.y);
				pDC->LineTo((point1.x+point2.x)/2,point2.y-20);
				pDC->LineTo(point2.x,point2.y-20);
				//
				mpoint1.x=(point1.x+point2.x)/2;
				mpoint1.y=point1.y;
				mpoint2.x=(point1.x+point2.x)/2;
				mpoint2.y=point2.y-20;
				mpoint3.x=point2.x;
				mpoint3.y=point2.y-20;
				//
			}
			else
			{
				if(point1.x<point2.x)
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x+width1/2+15,point1.y);
						pDC->LineTo(point2.x+width1/2+15,point2.y-20);
						//
						mpoint1.x=point2.x+width1/2+15;
						mpoint1.y=point1.y;
						mpoint2.x=point2.x+width1/2+15;
						mpoint2.y=point2.y-20;
						//
					}
					else		
					{
						pDC->LineTo(point2.x+width2/2+15,point1.y);
						pDC->LineTo(point2.x+width2/2+15,point2.y-20);
						//
						mpoint1.x=point2.x+width2/2+15;
						mpoint1.y=point1.y;
						mpoint2.x=point2.x+width2/2+15;
						mpoint2.y=point2.y-20;
						//
					}
					pDC->LineTo(point2.x,point2.y-20);
					//
					mpoint3.x=point2.x;
					mpoint3.y=point2.y-20;
					//
				}
				else
				{
					if(width1>width2)
					{
						pDC->LineTo(point2.x-width1/2-15,point1.y);
						pDC->LineTo(point2.x-width1/2-15,point2.y-20);
						//
						mpoint1.x=point2.x-width1/2-15;
						mpoint1.y=point1.y;
						mpoint2.x=point2.x-width1/2-15;
						mpoint2.y=point2.y-20;
						//
					}
					else		
					{
						pDC->LineTo(point2.x-width2/2-15,point1.y);
						pDC->LineTo(point2.x-width2/2-15,point2.y-20);
						//
						mpoint1.x=point2.x-width2/2-15;
						mpoint1.y=point1.y;
						mpoint2.x=point2.x-width2/2-15;
						mpoint2.y=point2.y-20;
						//
					}
					pDC->LineTo(point2.x,point2.y-20);
					//
					mpoint3.x=point2.x;
					mpoint3.y=point2.y-20;
					//
				}
			}
			pDC->LineTo(point2.x,point2.y);
			//
			mpoint4=mpoint3;
			}

		}
		
	}
	if(tag2==5)//结束为直线
	{
            pDC->MoveTo(point1);
			pDC->LineTo(point1.x-150,point1.y);
			pDC->LineTo(point1.x-150,point2.y);
			pDC->LineTo(point2.x,point2.y);
			pDC->LineTo(point2.x-5,point2.y-5);
			pDC->MoveTo(point2);
			pDC->LineTo(point2.x-5,point2.y+5);
			//
			mpoint1.x=point1.x-150;
			mpoint1.y=point1.y;
			mpoint2.x=point1.x-150;
			mpoint2.y=point2.y;
			mpoint3=mpoint2;
			mpoint4=mpoint3;
			//
	}
	//画文本


	CRect r(point1.x+5,(point1.y+point2.y)/2-20,point2.x+50,(point1.y+point2.y)/2-1);
	CFont *pOldFont=pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_clr);
    pDC->DrawText(GetTitle(),r,DT_NOPREFIX | DT_WORDBREAK | DT_LEFT);
	pDC->SelectObject(pOldFont);
}

bool CLine::CheckRect(CPoint c_point)
{
	CPoint t_point1,t_point2;
	if((pow((float)point1.x,2)+pow((float)point1.y,2))>(pow((float)mpoint1.x,2)+pow((float)mpoint1.y,2))) 
	{
		t_point1.x=mpoint1.x-10;
		t_point1.y=mpoint1.y-10;
		t_point2.x=point1.x+10;
		t_point2.y=point1.y;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	else if((pow((float)point1.x,2)+pow((float)point1.y,2))<(pow((float)mpoint1.x,2)+pow((float)mpoint1.y,2))) 
	{
		t_point2.x=mpoint1.x+10;
		t_point2.y=mpoint1.y+10;
		t_point1.x=point1.x-10;
		t_point1.y=point1.y;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	if((pow((float)mpoint2.x,2)+pow((float)mpoint2.y,2))>(pow((float)mpoint1.x,2)+pow((float)mpoint1.y,2))) 
	{
		t_point1.x=mpoint1.x-10;
		t_point1.y=mpoint1.y-10;
		t_point2.x=mpoint2.x+10;
		t_point2.y=mpoint2.y+10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	else if((pow((float)mpoint2.x,2)+pow((float)mpoint2.y,2))<(pow((float)mpoint1.x,2)+pow((float)mpoint1.y,2))) 
	{
		t_point2.x=mpoint1.x+10;
		t_point2.y=mpoint1.y+10;
		t_point1.x=mpoint2.x-10;
		t_point1.y=mpoint2.y-10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) 
			return true;
	}
	if((pow((float)mpoint2.x,2)+pow((float)mpoint2.y,2))>(pow((float)mpoint3.x,2)+pow((float)mpoint3.y,2))) 
	{
		t_point1.x=mpoint3.x-10;
		t_point1.y=mpoint3.y-10;
		t_point2.x=mpoint2.x+10;
		t_point2.y=mpoint2.y+10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) 
			return true;
	}
	else if((pow((float)mpoint2.x,2)+pow((float)mpoint2.y,2))<(pow((float)mpoint3.x,2)+pow((float)mpoint3.y,2))) 
	{
		t_point2.x=mpoint3.x+10;
		t_point2.y=mpoint3.y+10;
		t_point1.x=mpoint2.x-10;
		t_point1.y=mpoint2.y-10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) 
			return true;
	}
	if((pow((float)mpoint3.x,2)+pow((float)mpoint3.y,2))>(pow((float)mpoint4.x,2)+pow((float)mpoint4.y,2))) 
	{
		t_point1.x=mpoint4.x-10;
		t_point1.y=mpoint4.y-10;
		t_point2.x=mpoint3.x+10;
		t_point2.y=mpoint3.y+10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	else if((pow((float)mpoint3.x,2)+pow((float)mpoint3.y,2))<(pow((float)mpoint4.x,2)+pow((float)mpoint4.y,2))) 
	{
		t_point2.x=mpoint4.x+10;
		t_point2.y=mpoint4.y+10;
		t_point1.x=mpoint3.x-10;
		t_point1.y=mpoint3.y-10;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	if((pow((float)point2.x,2)+pow((float)point2.y,2))>(pow((float)mpoint4.x,2)+pow((float)mpoint4.y,2))) 
	{
		t_point1.x=mpoint4.x-10;
		t_point1.y=mpoint4.y-10;
		t_point2.x=point2.x+10;
		t_point2.y=point2.y;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	}
	else if((pow((float)point2.x,2)+pow((float)point2.y,2))<(pow((float)mpoint4.x,2)+pow((float)mpoint4.y,2))) 
	{
		t_point2.x=mpoint4.x+10;
		t_point2.y=mpoint4.y+10;
		t_point1.x=point2.x-10;
		t_point1.y=point2.y;
		CRect crect1(t_point1,t_point2);
		if(crect1.PtInRect(c_point)) return true;
	} 
		return FALSE;
}
void CLine::Serialize(CArchive &ar)
{
	CBasicShape::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<tag<<m_title<<point1<<point2<<intag1<<intag2<<intag3<<tag1<<tag2<<R_tag1<<R_tag2<<R_tag3;
	}
	else
	{
		ar>>tag>>m_title;
	}
}

////////////////////////////////////////////////////
// OnSavesvg 折线内SVG保存函数
////////////////////////////////////////////////////
CString CLine::OnSavesvg()
{
	HDC hDC = CreateCompatibleDC(NULL);
	
	CString lne_Temp,text_Temp,array_Temp;   //rec_Temp保存绘制形状的路径 text_Temp保存绘制文字的变量 array_Temp保存箭头绘制变量
	
	lne_Temp.Format("<polyline points=\"%d,%d %d,%d %d,%d %d,%d %d,%d %d,%d\" style=\"fill:rgb(255,255,255);fill-opacity:0;stroke-width:1;stroke:rgb(0,0,0)\"/>\r\n",point1.x,point1.y,mpoint1.x,mpoint1.y,mpoint2.x,mpoint2.y,mpoint3.x,mpoint3.y,mpoint4.x,mpoint4.y,point2.x,point2.y);
	
	if(mpoint4.x==point2.x)   //如果是向下的箭头
		array_Temp.Format("<polyline points=\"%d,%d %d,%d %d,%d\" style=\"fill:rgb(255,255,255);fill-opacity:0;stroke-width:1;stroke:rgb(0,0,0)\"/>\r\n",point2.x-5,point2.y-5,point2.x,point2.y,point2.x+5,point2.y-5);
	else if(mpoint4.y==point2.y)   //如果是向右的箭头
	    array_Temp.Format("<polyline points=\"%d,%d %d,%d %d,%d\" style=\"fill:rgb(255,255,255);fill-opacity:0;stroke-width:1;stroke:rgb(0,0,0)\"/>\r\n",point2.x-5,point2.y-5,point2.x,point2.y,point2.x-5,point2.y+5);
	
	CString isItalic,isUnderline;   // isItalic和isUnderline分别为是否斜体和下划线
	int cut = round( ( double ) 10 * 1.0 );
	
	if(logFont.lfItalic == true)
		isItalic="Italic";
	else
		isItalic="Normal";
	if(logFont.lfUnderline == true)
		isUnderline="Underline";
	else
		isUnderline="none";
	
	text_Temp.Format("<text x=\"%d\" y=\"%d\" style=\"fill:RGB(%d,%d,%d); text-anchor: middle; font-size:%dpt; font-weight:%d; font-family:%s; font-style:%s; text-decoration:%s\">%s</text>\r\n", (point1.x + point2.x) / 2,point1.y + (point2.x-point1.x) / 10 + abs(logFont.lfHeight),GetRValue(GetClr()),GetGValue(GetClr()),GetBValue(GetClr()),(int)(-(float)logFont.lfHeight * 72.0 / GetDeviceCaps(hDC, LOGPIXELSY) + 0.5),logFont.lfWeight,logFont.lfFaceName,(LPCTSTR)isItalic,(LPCTSTR)isUnderline,GetTitle());
	
	return lne_Temp+text_Temp+array_Temp;   //return 向flowchart_testDoc中返回上述三字符串

}
void CLine::DrawTag(CClientDC* pDC)
{	
	CPoint t_point1;
	CPoint t_point2;
	CBrush brushBlue(RGB(0, 255, 0));
   CBrush* pOldBrush = pDC->SelectObject(&brushBlue);
	t_point1.x=point1.x-5;
	t_point1.y=point1.y-5;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.x=+point2.x-5;
	t_point1.y=point2.y-5;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	pDC->SelectObject(pOldBrush);
}
void CLine::In_Draw_Point(CClientDC* pDC)
{
	CPoint t_point1;
	CPoint t_point2;
	CPen pen(PS_SOLID,1,pDC->GetBkColor()); 


	CPen *pOldPen=pDC->SelectObject(&pen);//
	CBrush brushBlue(pDC->GetBkColor());
   CBrush* pOldBrush = pDC->SelectObject(&brushBlue);
	t_point1.x=point1.x-5;
	t_point1.y=point1.y-5;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	t_point1.x=point2.x-5;
	t_point1.y=point2.y-5;
	t_point2.x=t_point1.x+10;
	t_point2.y=t_point1.y+10;
	pDC->Rectangle(CRect(t_point1,t_point2));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CLine::in_hot_point(CPoint m_point)
{
	return false;
}
bool CLine::Check_Out_Rect(CPoint c_point1,CPoint c_point2)
{
	CRect crect1(c_point1,c_point2);
	if((crect1.PtInRect(point1)&&crect1.PtInRect(point2))||CheckRect(c_point1))
		return TRUE;
	else
		return FALSE;
}