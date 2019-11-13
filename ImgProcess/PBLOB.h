#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"
#include <Blob.h>


// PBLOB �Ի���

class PBLOB : public CDialogEx
{
	DECLARE_DYNAMIC(PBLOB)

public:
	PBLOB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PBLOB();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLOB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Contour_Thre;//--������ֵ--
	int m_Contour_KSize;//--���������С--
	CMFCColorButton m_Contour_Color;//--����������ɫ--
	CComboBox m_Contour_Mode;//--��������ģʽ--
	int m_Contour_Thickness;//--�����߿�--
	int m_CvBox_Thre;//--������Ӿ�����ֵ--
	int m_CvBox_KSize;//--������Ӿ��ξ����С--
	CMFCColorButton m_CvBox_Color;//--������Ӿ���������ɫ--
	CComboBox m_CvBox_Mode;//--������Ӿ��η���ģʽ--
	int m_CvBox_Thickness;//--������Ӿ����߿�--
	Blob m_blob;//--�洢Blob����--
	void LoadXML();//--��ȡBlob��XML����--
	virtual BOOL OnInitDialog();//--���ڳ�ʼ��--
	afx_msg void OnBnClickedChangeBlob();//--�޸Ĳ���--
	afx_msg void OnBnClickedOk();//--����ȷ����ť--
};
