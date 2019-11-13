#pragma once
#include <ROI.h>

// PROI �Ի���

class PROI : public CDialogEx
{
	DECLARE_DYNAMIC(PROI)

public:
	PROI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PROI();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Circle_X;//--Բ��X��--
	int m_Circle_Y;//--Բ��Y��--
	int m_Circle_R;//--Բ�İ뾶--
	int m_Annulus_X;//--Բ��X��--
	int m_Annulus_Y;//--Բ��Y��--
	int m_Annulus_Rmax;//--Բ����Բ�뾶--
	int m_Annulus_Rmin;//--Բ����Բ�뾶--
	double m_Ellipse_A;//--��Բ��ת�Ƕ�--
	int m_Ellipse_H;//--��Բ�߶�--
	int m_Ellipse_W;//--��Բ���--
	int m_Ellipse_X;//--��Բ����X��--
	int m_Ellipse_Y;//--��Բ����Y��--
	int m_Rect_H;//--���θ߶�--
	int m_Rect_W;//--���ο��--
	int m_Rect_X;//--�������Ͻ�X��--
	int m_Rect_Y;//--�������Ͻ�Y��--
	int m_Ring_Hmin;//--С���θ߶�--
	int m_Ring_Hmax;//--����θ߶�--
	int m_Ring_Wmin;//--С���ο��--
	int m_Ring_Wmax;//--����ο��--
	int m_Ring_Xmin;//--С�������Ͻ�X��--
	int m_Ring_Xmax;//--��������Ͻ�X��--
	int m_Ring_Ymin;//--С�������Ͻ�Y��--
	int m_Ring_Ymax;//--��������Ͻ�Y��--
	double m_Rotate_A;//--��ת���νǶ�--
	int m_Rotate_H;//--��ת���θ߶�--
	int m_Rotate_W;//--��ת���ο��--
	int m_Rotate_X;//--��ת��������X��--
	int m_Rotate_Y;//--��ת��������Y��--
	ROI m_roi;//--�洢��ǰROI����--
	void LoadXML();//--��������--
	afx_msg void OnBnClickedChangeRoi();//--�޸Ĳ���--
	afx_msg void OnBnClickedOk();//--����ȷ����ť--
	virtual BOOL OnInitDialog();//--�����ʼ��--
};
