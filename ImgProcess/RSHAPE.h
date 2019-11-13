#pragma once
#include <Shape.h>
#include "afxcolorbutton.h"
#include "afxwin.h"

// RSHAPE �Ի���

class RSHAPE : public CDialogEx
{
	DECLARE_DYNAMIC(RSHAPE)

public:
	RSHAPE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RSHAPE();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_HouCir_Dp;//--����Բ���--�ۼ���--
	double m_HouCir_Mindist;//--����Բ���--Բ����С���--
	double m_HouCir_Thre;//--����Բ���--��ֵ--
	double m_HouCir_Vote;//--����Բ���--ͶƱ��--
	int m_HouCir_Minr;//--����Բ���--�뾶��Сֵ--
	int m_HouCir_Maxr;//--����Բ���--�뾶���ֵ--
	CMFCColorButton m_HouCir_Color;//--����Բ���--������ɫ--
	int m_HouCir_Thickness;//--����Բ���--�߿�--
	int m_MatCir_Cmin;//--���Բ���--Canny��ֵ����--
	int m_MatCir_Cmax;//--���Բ���--Canny��ֵ����--
	double m_MatCir_Degree;//--���Բ���--��϶�--
	CMFCColorButton m_MatCir_Color;//--���Բ���--������ɫ--
	int m_MatCir_Thickness;//--���Բ���--�߿�--
	int m_Ellipse_Cmin;//--��Բ���--Canny��ֵ����--
	int m_Ellipse_Cmax;//--��Բ���--Canny��ֵ����--
	int m_Ellipse_Scale;//--��Բ���--����ȣ�������������ᱻ�ж�λ��Բ��--
	int m_Ellipse_Thickness;//--��Բ���--�߿�--
	CMFCColorButton m_Ellipse_Color;//--��Բ���--������ɫ--
	int m_HouLine_Cmin;//--����ֱ�߼��--Canny��ֵ����--
	int m_HouLine_Cmax;//--����ֱ�߼��--Canny��ֵ����--
	double m_HouLine_Rho;//--����ֱ�߼��--����--
	double m_HouLine_Theta;//--����ֱ�߼��--����--
	int m_HouLine_Thre;//--����ֱ�߼��--ֱ����ֵ--
	double m_HouLine_LineLen;//--����ֱ�߼��--�߶γ���--
	double m_HouLine_LineGap;//--����ֱ�߼��--�����϶--
	int m_HouLine_Thickness;//--����ֱ�߼��--�߿�--
	CMFCColorButton m_HouLine_Color;//--����ֱ�߼��--������ɫ--
	CButton m_HouLine_Pflag;//--����ֱ�߼��--�Ƿ�ʹ�ø���ѧ���ֱ��--
	int m_MatLine_Cmin;//--���ֱ�߼��--Canny��ֵ����--
	int m_MatLine_Cmax;//--���ֱ�߼��--Canny��ֵ����--
	double m_MatLine_Reps;//--���ֱ�߼��--���뾫��--
	double m_MatLine_Aeps;//--���ֱ�߼��--�ǶȾ���--
	int m_MatLine_Thickness;//--���ֱ�߼��--�߿�--
	CMFCColorButton m_MatLine_Color;//--���ֱ�߼��--������ɫ--
	Shape m_shape;//--�洢Shape����
	virtual BOOL OnInitDialog();//--�����ʼ��--
	void LoadXML();//--���ز���--
	afx_msg void OnBnClickedChangeShape();//--�޸Ĳ���--
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
