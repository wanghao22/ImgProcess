#pragma once
#include <Distance.h>
#include "afxwin.h"

// RDIST �Ի���

class RDIST : public CDialogEx
{
	DECLARE_DYNAMIC(RDIST)

public:
	RDIST(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RDIST();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_pt2pt_ptSx;//--�㵽��--��A��X����--
	int m_pt2pt_ptSy;//--�㵽��--��A��Y����--
	int m_pt2pt_ptEx;//--�㵽��--��B��X����--
	int m_pt2pt_ptEy;//--�㵽��--��B��Y����--
	CButton m_pt2pt_AFlag;//--�㵽��--�Ƿ����Ƕ�--
	double m_pt2pt_Angle;//--�㵽��--�Ƕ�--
	int m_pt2ln_ptSx;//--�㵽��--��A��X����--
	int m_pt2ln_ptSy;//--�㵽��--��A��Y����--
	int m_pt2ln_lnSx;//--�㵽��--�߶�����X����--
	int m_pt2ln_lnSy;//--�㵽��--�߶�����Y����--
	int m_pt2ln_lnEx;//--�㵽��--�߶��յ��X����--
	int m_pt2ln_lnEy;//--�㵽��--�߶��յ��Y����--
	CButton m_pt2ln_AFlag;//--�㵽��--�Ƿ����Ƕ�--
	double m_pt2ln_Angle;//--�㵽��--�Ƕ�--
	int m_ln2ln_lnSSx;//--�ߵ���--�߶�1����X����--
	int m_ln2ln_lnSSy;//--�ߵ���--�߶�1����Y����--
	int m_ln2ln_lnSEx;//--�ߵ���--�߶�1�յ��X����--
	int m_ln2ln_lnSEy;//--�ߵ���--�߶�1�յ��Y����--
	int m_ln2ln_lnESx;//--�ߵ���--�߶�2����X����--
	int m_ln2ln_lnESy;//--�ߵ���--�߶�2����Y����--
	int m_ln2ln_lnEEx;//--�ߵ���--�߶�2�յ��X����--
	int m_ln2ln_lnEEy;//--�ߵ���--�߶�2�յ��Y����--
	double m_ln2ln_Gap;//--�ߵ���--�����������Ĳ���ֵ��������������ж�����ֱ���ཻ������Ϊ0--
	Distance m_dist;//--�洢Dist����
	virtual BOOL OnInitDialog();//--�����ʼ��--
	void LoadXML();//--���ز���--
	afx_msg void OnBnClickedChangeDist();//--�޸Ĳ���--
	afx_msg void OnBnClickedOk();//--����ȷ����ť--
};
