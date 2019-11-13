#pragma once
#include <Transformation.h>
#include "afxwin.h"

// TRANS �Ի���

class TRANS : public CDialogEx
{
	DECLARE_DYNAMIC(TRANS)

public:
	TRANS(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TRANS();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfig();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void LoadXML();
	Transformation m_trans;
	int m_Rotate_Angle;
	CComboBox m_Flip_Method;
	int m_Cut_X;
	int m_Cut_Y;
	int m_Cut_W;
	int m_Cut_H;
	int m_Rsize_Rotate_Angle;
};
