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
	LOGFONT logFont;   //��������                           //������֪��������Ϣ�뵽�����ĵ�Ŀ¼�µġ�ע�ͽ���˵�����ڲ鿴����
	CFont m_font;      //��������
	COLORREF m_clr;    //������ɫ
	int tag;           //���ͼ�α�ǣ��������1����Բ��2
	
	CString m_title;                    //��ͼ���ڲ���ӵ��ı�
	                 
public:
	CBasicShape* LineFront;			//�������õ�ָ�룬����ֻ�����ӵ�ͼ��
	CBasicShape* LineBehind;		//ͬ��
	int tag1;
	int tag2;
	int R_tag1;   //������ε��������߳��ڵ�
	int	R_tag2;
	int R_tag3; 
	int k;    //���ڱ�����εĳ����
	int intag1;   //�����ڵ�
	int intag2;
	int intag3;
	int outtag1;
	int outtag2;
	int outtag3;
	CPoint point1;                  //�洢���α߿��������
	CPoint point2;
public:
	void SetlogFont(LOGFONT *lf);//��������
	void SetClr(COLORREF clr);//������ɫ
	LOGFONT* GetlogFont();//�õ�����
	CFont* GetFont();//�õ�����
	COLORREF GetClr();//�õ���ɫ
	void SetTitle( CString title );//�����ı�����
	CString GetTitle() const;//�õ��ı�����
	CBasicShape();
	virtual ~CBasicShape();
	virtual void SetTag(int mid_tag);             //����ͼ�α��
	virtual int GetTag();						  //���ͼ�α��
	virtual void SetPoint(CPoint m_point1,CPoint m_point2);   //���ò�����
	virtual void Draw(CDC* pDC);					//��д��draw������
	virtual void Serialize(CArchive& ar);         //��д�����л����溯��
	virtual CString OnSavesvg();					//svg��ʽ���溯��
	virtual bool CheckRect(CPoint c_point);//����������Ƿ�����ͼԪ�ڣ���ѡ��
	virtual bool Check_Out_Rect(CPoint c_point1,CPoint c_point2);//�������Ƿ��ѡͼԪ�������ѡ��
	virtual void DrawTag(CClientDC* pDC);//�����ȵ�С����
	virtual void MovePoint(CPoint m_point1,CPoint m_point2);//�ı�ͼԪ����
	virtual bool in_hot_point(CPoint m_point);//����Ƿ����ȵ㷽����
	virtual void Zoom(CPoint m_point1,CPoint m_point2);//��������
	virtual void In_Draw(CClientDC* pDC);//�ػ�ͼԪ
	virtual void In_Draw_Point(CClientDC* pDC);//��ȥ�ȵ�
    void SetCharacter(CString mid_title);       //���ڴ洢���ֵĺ����������ĵ���serializa����
	CPoint GetPoint11();						//����ȡ���εĲ�ͬ�ĵ�
	CPoint GetPoint12();						//ͬ��
	CPoint GetPoint13();						//ͬ��
	CPoint GetPoint2();
	CBasicShape* GetLine_ptr1();				//������ߵ�ָ��
	CBasicShape* GetLine_ptr2();
	void AddTag();								//����ͼ�α��
	int Get_k();								//����ͼ�α�ǣ����ڱ�����γ�����
	virtual void paste_change();				//�������
	void Reduce_k();							//��get_k()���ý���෴
	int GetWidth();								//���ͼ�ο�ȣ����������Զ�����
	bool EntryCheck();    //�����б���ڵ��Ƿ��ѱ�ѡ��.
	void Set_in_out_tag(int i_tag1,int i_tag2,int i_tag3,int o_tag1,int o_tag2,int o_tag3);//���������ļ���Ĳ���
	void SetRTag(int tag11,int tag22,int R_tag11,int R_tag22,int R_tag33);      //ͬ��
	void Setintag(int i_tag);													//ͬ��
private:

};

#endif // !defined(AFX_BASICSHAPE_H__325AE13C_402A_4977_B3DF_D85BCE06387B__INCLUDED_)
