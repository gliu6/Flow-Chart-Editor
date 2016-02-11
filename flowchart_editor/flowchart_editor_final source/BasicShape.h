// BasicShape.h: interface for the CBasicShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASICSHAPE_H__325AE13C_402A_4977_B3DF_D85BCE06387B__INCLUDED_)
#define AFX_BASICSHAPE_H__325AE13C_402A_4977_B3DF_D85BCE06387B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define round(a) ( int ) ( a + .5 )
class CBasicShape :public CObject
{
protected:
	LOGFONT logFont;   //设置字体                           //！！想知道编者信息请到帮助文档目录下的“注释解释说明”内查看！！
	CFont m_font;      //设置字体
	COLORREF m_clr;    //设置颜色
	int tag;           //标记图形标记，如矩形是1，椭圆是2
	
	CString m_title;                    //在图形内部添加的文本
	                 
public:
	CBasicShape* LineFront;			//折现内用的指针，用于只想连接的图形
	CBasicShape* LineBehind;		//同上
	int tag1;
	int tag2;
	int R_tag1;   //标记菱形的三个连线出口点
	int	R_tag2;
	int R_tag3; 
	int k;    //用于标记菱形的出入点
	int intag1;   //标记入口点
	int intag2;
	int intag3;
	int outtag1;
	int outtag2;
	int outtag3;
	CPoint point1;                  //存储矩形边框的两个点
	CPoint point2;
public:
	void SetlogFont(LOGFONT *lf);//设置字体
	void SetClr(COLORREF clr);//设置颜色
	LOGFONT* GetlogFont();//得到字体
	CFont* GetFont();//得到字体
	COLORREF GetClr();//得到颜色
	void SetTitle( CString title );//设置文本内容
	CString GetTitle() const;//得到文本内容
	CBasicShape();
	virtual ~CBasicShape();
	virtual void SetTag(int mid_tag);             //设置图形标记
	virtual int GetTag();						  //获得图形标记
	virtual void SetPoint(CPoint m_point1,CPoint m_point2);   //设置参数点
	virtual void Draw(CDC* pDC);					//重写的draw（）。
	virtual void Serialize(CArchive& ar);         //重写的序列化保存函数
	virtual CString OnSavesvg();					//svg格式保存函数
	virtual bool CheckRect(CPoint c_point);//检查鼠标左键是否点击在图元内，即选中
	virtual bool Check_Out_Rect(CPoint c_point1,CPoint c_point2);//检查鼠标是否框选图元，即多个选中
	virtual void DrawTag(CClientDC* pDC);//绘制热点小方块
	virtual void MovePoint(CPoint m_point1,CPoint m_point2);//改变图元数据
	virtual bool in_hot_point(CPoint m_point);//鼠标是否在热点方块内
	virtual void Zoom(CPoint m_point1,CPoint m_point2);//放缩功能
	virtual void In_Draw(CClientDC* pDC);//重绘图元
	virtual void In_Draw_Point(CClientDC* pDC);//擦去热点
    void SetCharacter(CString mid_title);       //用于存储文字的函数，用于文档类serializa函数
	CPoint GetPoint11();						//用于取菱形的不同的点
	CPoint GetPoint12();						//同上
	CPoint GetPoint13();						//同上
	CPoint GetPoint2();
	CBasicShape* GetLine_ptr1();				//获得折线的指针
	CBasicShape* GetLine_ptr2();
	void AddTag();								//设置图形标记
	int Get_k();								//设置图形标记，用于标记菱形出发点
	virtual void paste_change();				//黏贴函数
	void Reduce_k();							//与get_k()作用结果相反
	int GetWidth();								//获得图形宽度，用于折现自动绕行
	bool EntryCheck();    //用来判别入口点是否已被选中.
	void Set_in_out_tag(int i_tag1,int i_tag2,int i_tag3,int o_tag1,int o_tag2,int o_tag3);//用来传打开文件后的参数
	void SetRTag(int tag11,int tag22,int R_tag11,int R_tag22,int R_tag33);      //同上
	void Setintag(int i_tag);													//同上
private:

};

#endif // !defined(AFX_BASICSHAPE_H__325AE13C_402A_4977_B3DF_D85BCE06387B__INCLUDED_)
