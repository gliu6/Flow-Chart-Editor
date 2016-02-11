// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__182CA98A_44DD_4B53_AA6D_143DBFE3D6E4__INCLUDED_)
#define AFX_LINE_H__182CA98A_44DD_4B53_AA6D_143DBFE3D6E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicShape.h"			  //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！

class CLine : public CBasicShape   
{
protected:
	DECLARE_SERIAL(CLine)
public:
	CLine();									 //全部为虚函数在各类的具体体现，详见基类
	virtual ~CLine();
	void SetTag(int mid_tag);
	void SetPoint(CPoint m_point1,CPoint m_point2);
	void Draw(CDC* pDC);
    void Serialize(CArchive &ar);
	bool CheckRect(CPoint c_point);
	CString OnSavesvg();
	void DrawTag(CClientDC* pDC);
	void In_Draw_Point(CClientDC* pDC);
	bool in_hot_point(CPoint m_point);
	 bool Check_Out_Rect(CPoint c_point1,CPoint c_point2);
public:
	int width1;				//用于保存连接两个图形的宽度
	int width2;
	CPoint mpoint1;			//用于连线中间的拐点
	CPoint mpoint2;
	CPoint mpoint3;
	CPoint mpoint4;

};

#endif // !defined(AFX_LINE_H__182CA98A_44DD_4B53_AA6D_143DBFE3D6E4__INCLUDED_)
