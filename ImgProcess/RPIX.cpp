// RPIX.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "RPIX.h"
#include "afxdialogex.h"


// RPIX 对话框

IMPLEMENT_DYNAMIC(RPIX, CDialogEx)

RPIX::RPIX(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PIX, pParent)
	, m_Hmin(0)
	, m_Smin(0)
	, m_Vmin(0)
	, m_Hmax(0)
	, m_Smax(0)
	, m_Vmax(0)
	, m_Rmin(0)
	, m_Gmin(0)
	, m_Bmin(0)
	, m_Rmax(0)
	, m_Gmax(0)
	, m_Bmax(0)
	, m_Omin(0)
	, m_Omax(0)
	, m_Thre_Thre(0)
	, m_Canny_Bsize(0)
	, m_Canny_Ksize(0)
	, m_Canny_Cmin(0)
	, m_Canny_Cmax(0)
	, m_Sobel_Dx(0)
	, m_Sobel_Dy(0)
	, m_Sobel_Ksize(0)
	, m_Sobel_Scale(0.0)
	, m_Laplace_Bsize(0)
	, m_Laplace_Ksize(0)
	, m_Laplace_Scale(0)
	, m_SubPix_Bsize(0)
	, m_SubPix_Ksize(0)
{

}

RPIX::~RPIX()
{
}

void RPIX::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MIN_H, m_Hmin);
	DDV_MinMaxInt(pDX, m_Hmin, 0, 255);
	DDX_Text(pDX, IDC_MIN_S, m_Smin);
	DDV_MinMaxInt(pDX, m_Smin, 0, 255);
	DDX_Text(pDX, IDC_MIN_V, m_Vmin);
	DDV_MinMaxInt(pDX, m_Vmin, 0, 255);
	DDX_Text(pDX, IDC_MAX_H, m_Hmax);
	DDV_MinMaxInt(pDX, m_Hmax, 0, 359);
	DDX_Text(pDX, IDC_MAX_S, m_Smax);
	DDV_MinMaxInt(pDX, m_Smax, 0, 255);
	DDX_Text(pDX, IDC_MAX_V, m_Vmax);
	DDV_MinMaxInt(pDX, m_Vmax, 0, 255);
	DDX_Text(pDX, IDC_MIN_R, m_Rmin);
	DDV_MinMaxInt(pDX, m_Rmin, 0, 255);
	DDX_Text(pDX, IDC_MIN_G, m_Gmin);
	DDV_MinMaxInt(pDX, m_Gmin, 0, 255);
	DDX_Text(pDX, IDC_MIN_B, m_Bmin);
	DDV_MinMaxInt(pDX, m_Bmin, 0, 255);
	DDX_Text(pDX, IDC_MAX_R, m_Rmax);
	DDV_MinMaxInt(pDX, m_Rmax, 0, 255);
	DDX_Text(pDX, IDC_MAX_G, m_Gmax);
	DDV_MinMaxInt(pDX, m_Gmax, 0, 255);
	DDX_Text(pDX, IDC_MAX_B, m_Bmax);
	DDV_MinMaxInt(pDX, m_Bmax, 0, 255);
	DDX_Text(pDX, IDC_MIN_O, m_Omin);
	DDV_MinMaxInt(pDX, m_Omin, 0, 255);
	DDX_Text(pDX, IDC_MAX_O, m_Omax);
	DDV_MinMaxInt(pDX, m_Omax, 0, 255);
	DDX_Control(pDX, IDC_GRAY_MODE, m_Gray_Mode);
	DDX_Text(pDX, IDC_THRE_THRE, m_Thre_Thre);
	DDX_Control(pDX, IDC_THRE_MODE, m_Thre_Mode);
	DDX_Text(pDX, IDC_CANNY_BKSIZE, m_Canny_Bsize);
	DDX_Text(pDX, IDC_CANNY_KSIZE, m_Canny_Ksize);
	DDX_Text(pDX, IDC_CANNY_CMIN, m_Canny_Cmin);
	DDX_Text(pDX, IDC_CANNY_CMAX, m_Canny_Cmax);
	DDX_Control(pDX, IDC_CANNY_GFLAG, m_Canny_Gflag);
	DDX_Control(pDX, IDC_SOBEL_DEPTH, m_Sobel_Depth);
	DDX_Control(pDX, IDC_SOBEL_TYPE, m_Sobel_Type);
	DDX_Text(pDX, IDC_SOBEL_DX, m_Sobel_Dx);
	DDV_MinMaxInt(pDX, m_Sobel_Dx, 0, 2);
	DDX_Text(pDX, IDC_SOBEL_DY, m_Sobel_Dy);
	DDV_MinMaxInt(pDX, m_Sobel_Dy, 0, 2);
	DDX_Text(pDX, IDC_SOBEL_KSIZE, m_Sobel_Ksize);
	DDX_Text(pDX, IDC_SOBEL_SCALE, m_Sobel_Scale);
	DDX_Control(pDX, IDC_LAPLACE_DEPTH, m_Laplace_Depth);
	DDX_Control(pDX, IDC_LAPLACE_TYPE, m_Laplace_Type);
	DDX_Text(pDX, IDC_LAPLACE__BKSIZE, m_Laplace_Bsize);
	DDX_Text(pDX, IDC_LAPLACE_KSIZE, m_Laplace_Ksize);
	DDX_Text(pDX, IDC_LAPLACE_SCALE, m_Laplace_Scale);
	DDX_Text(pDX, IDC_SUBPIX_BKSIZE, m_SubPix_Bsize);
	DDX_Text(pDX, IDC_SUBPIX_KSIZE, m_SubPix_Ksize);
	DDX_Control(pDX, IDC_SUBPIX_COLOR, m_SubPix_Color);
}

//--加载PIX参数--
void RPIX::LoadXML()
{
	m_pix.LoadXML();
	UpdateData(true);
	m_Thre_Thre = m_pix.m_Threshold_Thre;
	m_Thre_Mode.SetCurSel(m_pix.m_Threshold_Mode);
	m_Canny_Bsize = m_pix.m_Canny_BlurSize;
	m_Canny_Ksize = m_pix.m_Canny_Ksize;
	m_Canny_Cmin = m_pix.m_Canny_Min;
	m_Canny_Cmax = m_pix.m_Canny_Max;
	m_Canny_Gflag.SetCheck(m_pix.m_Canny_Gradient);
	m_Sobel_Depth.SetCurSel(m_pix.m_SobelDepth);
	if (cv::BORDER_ISOLATED == m_pix.m_SobelType)
		m_Sobel_Type.SetCurSel(6);
	else
		m_Sobel_Type.SetCurSel(m_pix.m_SobelType);
	m_Sobel_Dx = m_pix.m_SobelDx;
	m_Sobel_Dy = m_pix.m_SobelDy;
	m_Sobel_Ksize = m_pix.m_SobelKsize;
	m_Sobel_Scale = m_pix.m_SobelScale;
	m_Laplace_Depth.SetCurSel(m_pix.m_LaplaceDepth);
	if (cv::BORDER_ISOLATED == m_pix.m_LaplaceType)
		m_Laplace_Type.SetCurSel(6);
	else
		m_Laplace_Type.SetCurSel(m_pix.m_LaplaceType);
	m_Laplace_Bsize = m_pix.m_LaplaceGusize;
	m_Laplace_Ksize = m_pix.m_LaplaceKsize;
	m_Laplace_Scale = m_pix.m_LaplaceScale;
	m_SubPix_Bsize = m_pix.m_SubAutoThreKsize;
	m_SubPix_Ksize = m_pix.m_SubPixSize;
	m_SubPix_Color.SetColor(RGB(m_pix.m_SubPixColor[2], 
		m_pix.m_SubPixColor[1], m_pix.m_SubPixColor[0]));
	m_Hmin = m_pix.m_H_min;
	m_Hmax = m_pix.m_H_max;
	m_Smin = m_pix.m_S_min;
	m_Smax = m_pix.m_S_max;
	m_Vmin = m_pix.m_V_min;
	m_Vmax = m_pix.m_V_max;
	m_Rmin = m_pix.m_R_min;
	m_Rmax = m_pix.m_R_max;
	m_Gmin = m_pix.m_G_min;
	m_Gmax = m_pix.m_G_max;
	m_Bmin = m_pix.m_B_min;
	m_Bmax = m_pix.m_B_max;
	m_Omin = m_pix.m_Gray_Min;
	m_Omax = m_pix.m_Gray_Max;
	m_Gray_Mode.SetCurSel(m_pix.m_Gray_Case);
	UpdateData(false);
}


BEGIN_MESSAGE_MAP(RPIX, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGE_PIX, &RPIX::OnBnClickedChangePix)
	ON_BN_CLICKED(IDOK, &RPIX::OnBnClickedOk)
END_MESSAGE_MAP()


// RPIX 消息处理程序

//--界面初始化--
BOOL RPIX::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//--修改参数--
void RPIX::OnBnClickedChangePix()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_Sobel_Dx = MAX(m_Sobel_Dx, 0);
	m_Sobel_Dx = MIN(m_Sobel_Dx, 2);
	m_Sobel_Dy = MAX(m_Sobel_Dy, 0);
	m_Sobel_Dy = MIN(m_Sobel_Dy, 2);
	m_pix.m_Threshold_Thre = m_Thre_Thre;
	m_pix.m_Threshold_Mode = m_Thre_Mode.GetCurSel();
	m_pix.m_Canny_BlurSize = m_Canny_Bsize;
	m_pix.m_Canny_Ksize = m_Canny_Ksize;
	m_pix.m_Canny_Min = m_Canny_Cmin;
	m_pix.m_Canny_Max = m_Canny_Cmax;
	m_pix.m_Canny_Gradient = m_Canny_Gflag.GetCheck();
	m_pix.m_SobelDepth = m_Sobel_Depth.GetCurSel();
	int temp = m_Sobel_Type.GetCurSel();
	if (temp > 5)
		m_pix.m_SobelType = cv::BORDER_ISOLATED;
	else
		m_pix.m_SobelType = temp;
	m_pix.m_SobelDx = m_Sobel_Dx;
	m_pix.m_SobelDy = m_Sobel_Dy;
	m_pix.m_SobelKsize = m_Sobel_Ksize;
	m_pix.m_SobelScale = m_Sobel_Scale;
	m_pix.m_LaplaceDepth = m_Laplace_Depth.GetCurSel();
	temp = m_Laplace_Type.GetCurSel();
	if (temp > 5)
		m_pix.m_LaplaceType = cv::BORDER_ISOLATED;
	else
		m_pix.m_LaplaceType = temp;
	m_pix.m_LaplaceGusize = m_Laplace_Bsize;
	m_pix.m_LaplaceKsize = m_Laplace_Ksize;
	m_pix.m_LaplaceScale = m_Laplace_Scale;
	m_pix.m_SubAutoThreKsize = m_SubPix_Bsize;
	m_pix.m_SubPixSize = m_SubPix_Ksize;
	COLORREF color = m_SubPix_Color.GetColor();
	m_pix.m_SubPixColor[2] = BYTE(color);
	m_pix.m_SubPixColor[1] = BYTE(color >> 8);
	m_pix.m_SubPixColor[0] = BYTE(color >> 16);
	m_pix.m_H_min = m_Hmin;
	m_pix.m_H_max = m_Hmax;
	m_pix.m_S_min = m_Smin;
	m_pix.m_S_max = m_Smax;
	m_pix.m_V_min = m_Vmin;
	m_pix.m_V_max = m_Vmax;
	m_pix.m_R_min = m_Rmin;
	m_pix.m_R_max = m_Rmax;
	m_pix.m_G_min = m_Gmin;
	m_pix.m_G_max = m_Gmax;
	m_pix.m_B_min = m_Bmin;
	m_pix.m_B_max = m_Bmax;
	m_pix.m_Gray_Min = m_Omin;
	m_pix.m_Gray_Max = m_Omax;
	m_pix.m_Gray_Case = m_Gray_Mode.GetCurSel();
	UpdateData(false);
	m_pix.SaveXML();
}

//--重载OK按钮--
void RPIX::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangePix();
	CDialogEx::OnOK();
}

