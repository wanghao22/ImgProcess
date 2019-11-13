#pragma once
#include <PixProcess.h>
#include "afxwin.h"
#include "afxcolorbutton.h"

// RPIX �Ի���

class RPIX : public CDialogEx
{
	DECLARE_DYNAMIC(RPIX)

public:
	RPIX(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RPIX();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Hmin;//--HSV��H����Сֵ--
	int m_Smin;//--HSV��S����Сֵ--
	int m_Vmin;//--HSV��V����Сֵ--
	int m_Hmax;//--HSV��H�����ֵ--
	int m_Smax;//--HSV��S�����ֵ--
	int m_Vmax;//--HSV��V�����ֵ--
	int m_Rmin;//--RGB��R����Сֵ--
	int m_Gmin;//--RGB��G����Сֵ--
	int m_Bmin;//--RGB��B����Сֵ--
	int m_Rmax;//--RGB��R�����ֵ--
	int m_Gmax;//--RGB��G�����ֵ--
	int m_Bmax;//--RGB��B�����ֵ--
	int m_Omin;//--��ͨ����Сֵ--
	int m_Omax;//--��ͨ�����ֵ--
	CComboBox m_Gray_Mode;//--��ͨ������ʽ--
	int m_Thre_Thre;//--��ֵ����ֵ--
	CComboBox m_Thre_Mode;//--��ֵ������--
	int m_Canny_Bsize;//--Canny�˲��˴�С--
	int m_Canny_Ksize;//--Canny�˴�С--
	int m_Canny_Cmin;//--Canny��ֵ����--
	int m_Canny_Cmax;//--Canny��ֵ����--
	CButton m_Canny_Gflag;//--�Ƿ�ʹ���ݶȼ���Canny--
	CComboBox m_Sobel_Depth;//--ͼ��λ��--
	CComboBox m_Sobel_Type;//--Sobel����--
	int m_Sobel_Dx;//--Sobel��X����ĵ���λ--
	int m_Sobel_Dy;//--Sobel��Y����ĵ���λ--
	int m_Sobel_Ksize;//--Sobel�˴�С--
	double m_Sobel_Scale;//--Sobel��������--
	CComboBox m_Laplace_Depth;//--ͼ��λ��--
	CComboBox m_Laplace_Type;//--Laplace����--
	int m_Laplace_Bsize;//--Laplace�˲��˴�С--
	int m_Laplace_Ksize;//--Laplace�˴�С--
	double m_Laplace_Scale;//--Laplace��������--
	int m_SubPix_Bsize;//--�������˲��˴�С--
	int m_SubPix_Ksize;//--�����غ˴�С--
	CMFCColorButton m_SubPix_Color;//--�����صĻ�����ɫ--
	PixProcess m_pix;//--�洢PIX����--
	void LoadXML();//--����PIX����--
	virtual BOOL OnInitDialog();//--�����ʼ��--
	afx_msg void OnBnClickedChangePix();//--�޸Ĳ���--
	afx_msg void OnBnClickedOk();//--����OK��ť--
};
