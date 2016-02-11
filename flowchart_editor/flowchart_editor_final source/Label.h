// Label.h: interface for the CLabel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABEL_H__2CAD428E_A5EF_4012_90B6_010D6561C437__INCLUDED_)
#define AFX_LABEL_H__2CAD428E_A5EF_4012_90B6_010D6561C437__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicShape.h"				 //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！

class CLabel : public CBasicShape   //全部为虚函数在各类的具体体现，详见基类，用于添加标签
{
protected:
	DECLARE_SERIAL(CLabel)
		int x1,x2,y1,y2;
public:
	CLabel();
	virtual ~CLabel();
	void SetTag(int mid_tag);
    int GetTag();	
	void SetPoint(CPoint m_point1,CPoint m_point2);
	void Draw(CDC* pDC);
	void Serialize(CArchive &ar);
		void DrawTag(CClientDC* pDC);
	bool CheckRect(CPoint c_point);
	bool Check_Out_Rect(CPoint c_point1,CPoint c_point2);
	void MovePoint(CPoint m_point1,CPoint m_point2);
	bool in_hot_point(CPoint m_point);
	void Zoom(CPoint m_point1,CPoint m_point2);
	void In_Draw(CClientDC* pDC);
	void In_Draw_Point(CClientDC* pDC);
	void paste_change();
	CString OnSavesvg();

};

#endif // !defined(AFX_LABEL_H__2CAD428E_A5EF_4012_90B6_010D6561C437__INCLUDED_)
