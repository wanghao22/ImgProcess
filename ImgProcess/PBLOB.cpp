// PBLOB.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "PBLOB.h"
#include "afxdialogex.h"


// PBLOB 对话框

IMPLEMENT_DYNAMIC(PBLOB, CDialogEx)

PBLOB::PBLOB(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BLOB, pParent)
	, m_Contour_Thre(0)
	, m_Contour_KSize(0)
	, m_Contour_Thickness(0)
	, m_CvBox_Thre(0)
	, m_CvBox_KSize(0)
	, m_CvBox_Thickness(0)
{
	
}

PBLOB::~PBLOB()
{
}

void PBLOB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTOUR_THRE, m_Contour_Thre);
	DDX_Text(pDX, IDC_CONTOUR_KSIZE, m_Contour_KSize);
	DDX_Control(pDX, IDC_CONTOUR_COLOR, m_Contour_Color);
	DDX_Control(pDX, IDC_CONTOUR_MODE, m_Contour_Mode);
	DDX_Text(pDX, IDC_CONTOUR_THICKNESS, m_Contour_Thickness);
	DDX_Text(pDX, IDC_CVBOX_THRE, m_CvBox_Thre);
	DDX_Text(pDX, IDC_CVBOX_KSIZE, m_CvBox_KSize);
	DDX_Control(pDX, IDC_CVBOX_COLOR, m_CvBox_Color);
	DDX_Control(pDX, IDC_CVBOX_MODE, m_CvBox_Mode);
	DDX_Text(pDX, IDC_CVBOX_THICKNESS, m_CvBox_Thickness);
}

//--读取Blob的XML参数--
void PBLOB::LoadXML()
{
	m_blob.LoadXML();//xml->m_bolb
	//UpdateData(true);
	m_Contour_Thre = m_blob.m_Contour_Thre;
	m_Contour_KSize = m_blob.m_Contour_BlurSize;
	m_Contour_Color.SetColor(RGB(m_blob.m_Contour_Color[2], 
		m_blob.m_Contour_Color[1], m_blob.m_Contour_Color[0]));
	m_Contour_Mode.SetCurSel(m_blob.m_Contour_Mode);
	m_Contour_Thickness = m_blob.m_Contour_Thickness;
	m_CvBox_Thre = m_blob.m_CvBox_Thre;
	m_CvBox_KSize = m_blob.m_CvBox_BlurSize;
	m_CvBox_Color.SetColor(RGB(m_blob.m_CvBox_Color[2],
		m_blob.m_CvBox_Color[1], m_blob.m_CvBox_Color[0]));
	m_CvBox_Mode.SetCurSel(m_blob.m_CvBox_Mode);
	m_CvBox_Thickness = m_blob.m_CvBox_Thickness;//m_bolb->PBLOB
	UpdateData(false);//PBLOB->控件
}


BEGIN_MESSAGE_MAP(PBLOB, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGE_BLOB, &PBLOB::OnBnClickedChangeBlob)
	ON_BN_CLICKED(IDOK, &PBLOB::OnBnClickedOk)
END_MESSAGE_MAP()


// PBLOB 消息处理程序

//--窗口初始化--
BOOL PBLOB::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//--修改参数--
void PBLOB::OnBnClickedChangeBlob()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);//控件->PBLOB
	m_blob.m_Contour_Thre = m_Contour_Thre;
	m_blob.m_Contour_BlurSize = m_Contour_KSize;
	COLORREF color = m_Contour_Color.GetColor();
	m_blob.m_Contour_Color[2] = BYTE(color);
	m_blob.m_Contour_Color[1] = BYTE(color >> 8);
	m_blob.m_Contour_Color[0] = BYTE(color >> 16);
	m_blob.m_Contour_Mode = m_Contour_Mode.GetCurSel();
	m_blob.m_Contour_Thickness = m_Contour_Thickness;
	m_blob.m_CvBox_Thre = m_CvBox_Thre;
	m_blob.m_CvBox_BlurSize = m_CvBox_KSize;
	color = m_CvBox_Color.GetColor();
	m_blob.m_CvBox_Color[2] = BYTE(color);
	m_blob.m_CvBox_Color[1] = BYTE(color >> 8);
	m_blob.m_CvBox_Color[0] = BYTE(color >> 16);
	m_blob.m_CvBox_Mode = m_CvBox_Mode.GetCurSel();
	m_blob.m_CvBox_Thickness = m_CvBox_Thickness;//PBLOB->m_blob
	//UpdateData(false);
	m_blob.SaveXML();//m_blob->xml
}

//--重载确定按钮--
void PBLOB::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangeBlob();
	CDialogEx::OnOK();
}
