// TRANS.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "TRANS.h"
#include "afxdialogex.h"


// TRANS �Ի���

IMPLEMENT_DYNAMIC(TRANS, CDialogEx)

TRANS::TRANS(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRANS, pParent)
	, m_Rotate_Angle(0)
	, m_Cut_X(0)
	, m_Cut_Y(0)
	, m_Cut_W(0)
	, m_Cut_H(0)
	, m_Rsize_Rotate_Angle(0)
{

}

TRANS::~TRANS()
{
}

void TRANS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ROTATE_ANGLE, m_Rotate_Angle);
	DDX_Control(pDX, IDC_FLIP_METHOD, m_Flip_Method);
	DDX_Text(pDX, IDC_CUT_X, m_Cut_X);
	DDX_Text(pDX, IDC_CUT_Y, m_Cut_Y);
	DDX_Text(pDX, IDC_CUT_W, m_Cut_W);
	DDX_Text(pDX, IDC_CUT_H, m_Cut_H);
	DDX_Text(pDX, IDC_RESIZE_ROTATE_ANGLE, m_Rsize_Rotate_Angle);
}


BEGIN_MESSAGE_MAP(TRANS, CDialogEx)
	ON_BN_CLICKED(IDC_CONFIG, &TRANS::OnBnClickedConfig)
	ON_BN_CLICKED(IDOK, &TRANS::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &TRANS::OnBnClickedCancel)
END_MESSAGE_MAP()


// TRANS ��Ϣ�������


void TRANS::OnBnClickedConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_trans.m_Rotate_Angle = m_Rotate_Angle;
	m_trans.m_Filp_flag = m_Flip_Method.GetCurSel() - 1;
	m_trans.m_Cut_Size.x = m_Cut_X;
	m_trans.m_Cut_Size.y = m_Cut_Y;
	m_trans.m_Cut_Size.width = m_Cut_W;
	m_trans.m_Cut_Size.height = m_Cut_H;
	m_trans.m_Resize_Rotate_Angle = m_Rsize_Rotate_Angle;
	m_trans.SaveXML();
}


BOOL TRANS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void TRANS::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedConfig();
	CDialogEx::OnOK();
}


void TRANS::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void TRANS::LoadXML()
{
	m_trans.LoadXML();
	m_Rotate_Angle = m_trans.m_Rotate_Angle;
	if (m_trans.m_Filp_flag < 0)
		m_Flip_Method.SetCurSel(0);
	else if(m_trans.m_Filp_flag == 0)
		m_Flip_Method.SetCurSel(1);
	else
		m_Flip_Method.SetCurSel(2);
	m_Cut_X = m_trans.m_Cut_Size.x;
	m_Cut_Y = m_trans.m_Cut_Size.y;
	m_Cut_W = m_trans.m_Cut_Size.width;
	m_Cut_H = m_trans.m_Cut_Size.height;
	m_Rsize_Rotate_Angle = m_trans.m_Resize_Rotate_Angle;
	UpdateData(false);
}
