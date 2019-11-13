// PROI.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "PROI.h"
#include "afxdialogex.h"


// PROI 对话框

IMPLEMENT_DYNAMIC(PROI, CDialogEx)

PROI::PROI(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ROI, pParent)
	, m_Circle_X(0)
	, m_Circle_Y(0)
	, m_Circle_R(0)
	, m_Annulus_X(0)
	, m_Annulus_Y(0)
	, m_Annulus_Rmax(0)
	, m_Annulus_Rmin(0)
	, m_Ellipse_A(0)
	, m_Ellipse_H(0)
	, m_Ellipse_W(0)
	, m_Ellipse_X(0)
	, m_Ellipse_Y(0)
	, m_Rect_H(0)
	, m_Rect_W(0)
	, m_Rect_X(0)
	, m_Rect_Y(0)
	, m_Ring_Hmin(0)
	, m_Ring_Hmax(0)
	, m_Ring_Wmin(0)
	, m_Ring_Wmax(0)
	, m_Ring_Xmin(0)
	, m_Ring_Xmax(0)
	, m_Ring_Ymin(0)
	, m_Ring_Ymax(0)
	, m_Rotate_A(0)
	, m_Rotate_H(0)
	, m_Rotate_W(0)
	, m_Rotate_X(0)
	, m_Rotate_Y(0)
{
}

PROI::~PROI()
{
}

void PROI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CIRCLE_CENTER_X, m_Circle_X);
	DDX_Text(pDX, IDC_CIRCLE_CENTER_Y, m_Circle_Y);
	DDX_Text(pDX, IDC_CIRCLE_RADIUS, m_Circle_R);
	DDX_Text(pDX, IDC_ANNULUS_CENTER_X, m_Annulus_X);
	DDX_Text(pDX, IDC_ANNULUS_CENTER_Y, m_Annulus_Y);
	DDX_Text(pDX, IDC_ANNULUS_RMAX, m_Annulus_Rmax);
	DDX_Text(pDX, IDC_ANNULUS_RMIN, m_Annulus_Rmin);
	DDX_Text(pDX, IDC_ELLIPSE_A, m_Ellipse_A);
	DDX_Text(pDX, IDC_ELLIPSE_H, m_Ellipse_H);
	DDX_Text(pDX, IDC_ELLIPSE_W, m_Ellipse_W);
	DDX_Text(pDX, IDC_ELLIPSE_X, m_Ellipse_X);
	DDX_Text(pDX, IDC_ELLIPSE_Y, m_Ellipse_Y);
	DDX_Text(pDX, IDC_RECT_H, m_Rect_H);
	DDX_Text(pDX, IDC_RECT_W, m_Rect_W);
	DDX_Text(pDX, IDC_RECT_X, m_Rect_X);
	DDX_Text(pDX, IDC_RECT_Y, m_Rect_Y);
	DDX_Text(pDX, IDC_RECT_HB, m_Ring_Hmin);
	DDX_Text(pDX, IDC_RECT_HT, m_Ring_Hmax);
	DDX_Text(pDX, IDC_RECT_WB, m_Ring_Wmin);
	DDX_Text(pDX, IDC_RECT_WT, m_Ring_Wmax);
	DDX_Text(pDX, IDC_RECT_XB, m_Ring_Xmin);
	DDX_Text(pDX, IDC_RECT_XT, m_Ring_Xmax);
	DDX_Text(pDX, IDC_RECT_YB, m_Ring_Ymin);
	DDX_Text(pDX, IDC_RECT_YT, m_Ring_Ymax);
	DDX_Text(pDX, IDC_ROTATE_A, m_Rotate_A);
	DDX_Text(pDX, IDC_ROTATE_H, m_Rotate_H);
	DDX_Text(pDX, IDC_ROTATE_W, m_Rotate_W);
	DDX_Text(pDX, IDC_ROTATE_X, m_Rotate_X);
	DDX_Text(pDX, IDC_ROTATE_Y, m_Rotate_Y);
}

//--加载数据--
void PROI::LoadXML()
{
	m_roi.LoadXML();
	//UpdateData(true);
	m_Circle_X = m_roi.m_Circle_Center.x;
	m_Circle_Y = m_roi.m_Circle_Center.y;
	m_Circle_R = m_roi.m_Circle_Radius;
	m_Annulus_X = m_roi.m_Annulus_Center.x;
	m_Annulus_Y = m_roi.m_Annulus_Center.y;
	m_Annulus_Rmin = m_roi.m_Annulus_Radius_Min;
	m_Annulus_Rmax = m_roi.m_Annulus_Radius_Max;
	m_Rect_X = m_roi.m_Rectangl_Rect.x;
	m_Rect_Y = m_roi.m_Rectangl_Rect.y;
	m_Rect_W = m_roi.m_Rectangl_Rect.width;
	m_Rect_H = m_roi.m_Rectangl_Rect.height;
	m_Ring_Xmin = m_roi.m_Ring_Rect_Min.x;
	m_Ring_Ymin = m_roi.m_Ring_Rect_Min.y;
	m_Ring_Wmin = m_roi.m_Ring_Rect_Min.width;
	m_Ring_Hmin = m_roi.m_Ring_Rect_Min.height;
	m_Ring_Xmax = m_roi.m_Ring_Rect_Max.x;
	m_Ring_Ymax = m_roi.m_Ring_Rect_Max.y;
	m_Ring_Wmax = m_roi.m_Ring_Rect_Max.width;
	m_Ring_Hmax = m_roi.m_Ring_Rect_Max.height;
	m_Ellipse_X = m_roi.m_Ellipse.center.x;
	m_Ellipse_Y = m_roi.m_Ellipse.center.y;
	m_Ellipse_W = m_roi.m_Ellipse.size.width;
	m_Ellipse_H = m_roi.m_Ellipse.size.height;
	m_Ellipse_A = m_roi.m_Ellipse.angle;
	m_Rotate_X = m_roi.m_RotateRect.center.x;
	m_Rotate_Y = m_roi.m_RotateRect.center.y;
	m_Rotate_W = m_roi.m_RotateRect.size.width;
	m_Rotate_H = m_roi.m_RotateRect.size.height;
	m_Rotate_A = m_roi.m_RotateRect.angle;
	UpdateData(false);
}


BEGIN_MESSAGE_MAP(PROI, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGE_ROI, &PROI::OnBnClickedChangeRoi)
	ON_BN_CLICKED(IDOK, &PROI::OnBnClickedOk)
END_MESSAGE_MAP()


// PROI 消息处理程序

//--修改参数--
void PROI::OnBnClickedChangeRoi()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_roi.m_Circle_Center.x = m_Circle_X;
	m_roi.m_Circle_Center.y = m_Circle_Y;
	m_roi.m_Circle_Radius = m_Circle_R;
	m_roi.m_Annulus_Center.x = m_Annulus_X;
	m_roi.m_Annulus_Center.y = m_Annulus_Y;
	m_roi.m_Annulus_Radius_Min = m_Annulus_Rmin;
	m_roi.m_Annulus_Radius_Max = m_Annulus_Rmax;
	m_roi.m_Rectangl_Rect.x = m_Rect_X;
	m_roi.m_Rectangl_Rect.y = m_Rect_Y;
	m_roi.m_Rectangl_Rect.width = m_Rect_W;
	m_roi.m_Rectangl_Rect.height = m_Rect_H;
	m_roi.m_Ring_Rect_Min.x = m_Ring_Xmin;
	m_roi.m_Ring_Rect_Min.y = m_Ring_Ymin;
	m_roi.m_Ring_Rect_Min.width = m_Ring_Wmin;
	m_roi.m_Ring_Rect_Min.height = m_Ring_Hmin;
	m_roi.m_Ring_Rect_Max.x = m_Ring_Xmax;
	m_roi.m_Ring_Rect_Max.y = m_Ring_Ymax;
	m_roi.m_Ring_Rect_Max.width = m_Ring_Wmax;
	m_roi.m_Ring_Rect_Max.height = m_Ring_Hmax;
	m_roi.m_Ellipse.center.x = m_Ellipse_X;
	m_roi.m_Ellipse.center.y = m_Ellipse_Y;
	m_roi.m_Ellipse.size.width = m_Ellipse_W;
	m_roi.m_Ellipse.size.height = m_Ellipse_H;
	m_roi.m_Ellipse.angle = m_Ellipse_A;
	m_roi.m_RotateRect.center.x = m_Rotate_X;
	m_roi.m_RotateRect.center.y = m_Rotate_Y;
	m_roi.m_RotateRect.size.width = m_Rotate_W;
	m_roi.m_RotateRect.size.height = m_Rotate_H;
	m_roi.m_RotateRect.angle = m_Rotate_A;
	//UpdateData(false);
	m_roi.SaveXML();
}

//--重载确定按钮--
void PROI::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangeRoi();
	CDialogEx::OnOK();
}

//--界面初始化--
BOOL PROI::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
