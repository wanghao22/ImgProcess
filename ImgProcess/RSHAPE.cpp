// RSHAPE.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "RSHAPE.h"
#include "afxdialogex.h"


// RSHAPE 对话框

IMPLEMENT_DYNAMIC(RSHAPE, CDialogEx)

RSHAPE::RSHAPE(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHAPE, pParent)
	, m_HouCir_Dp(0)
	, m_HouCir_Mindist(0)
	, m_HouCir_Thre(0)
	, m_HouCir_Vote(0)
	, m_HouCir_Minr(0)
	, m_HouCir_Maxr(0)
	, m_HouCir_Thickness(0)
	, m_MatCir_Cmin(0)
	, m_MatCir_Cmax(0)
	, m_MatCir_Degree(0)
	, m_MatCir_Thickness(0)
	, m_Ellipse_Cmin(0)
	, m_Ellipse_Cmax(0)
	, m_Ellipse_Scale(0)
	, m_Ellipse_Thickness(0)
	, m_HouLine_Cmin(0)
	, m_HouLine_Cmax(0)
	, m_HouLine_Rho(0)
	, m_HouLine_Theta(0)
	, m_HouLine_Thre(0)
	, m_HouLine_LineLen(0)
	, m_HouLine_LineGap(0)
	, m_HouLine_Thickness(0)
	, m_MatLine_Cmin(0)
	, m_MatLine_Cmax(0)
	, m_MatLine_Reps(0)
	, m_MatLine_Aeps(0)
	, m_MatLine_Thickness(0)
{

}

RSHAPE::~RSHAPE()
{
}

void RSHAPE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HOUCIR_DP, m_HouCir_Dp);
	DDX_Text(pDX, IDC_HOUCIR_MINDIST, m_HouCir_Mindist);
	DDX_Text(pDX, IDC_HOUCIR_THRE, m_HouCir_Thre);
	DDX_Text(pDX, IDC_HOUCIR_VOTE, m_HouCir_Vote);
	DDX_Text(pDX, IDC_HOUCIR_RMIN, m_HouCir_Minr);
	DDX_Text(pDX, IDC_HOUCIR_RMAX, m_HouCir_Maxr);
	DDX_Control(pDX, IDC_HOUCIR_COLOR, m_HouCir_Color);
	DDX_Text(pDX, IDC_HOUCIR_THICKNESS, m_HouCir_Thickness);
	DDX_Text(pDX, IDC_MATCIR_CMIN, m_MatCir_Cmin);
	DDX_Text(pDX, IDC_MATCIR_CMAX, m_MatCir_Cmax);
	DDX_Text(pDX, IDC_MATCIR_DEGREE, m_MatCir_Degree);
	DDX_Control(pDX, IDC_MATCIR_COLOR, m_MatCir_Color);
	DDX_Text(pDX, IDC_MATCIR_THICKNESS, m_MatCir_Thickness);
	DDX_Text(pDX, IDC_ELLIPSED_CMIN, m_Ellipse_Cmin);
	DDX_Text(pDX, IDC_ELLIPSED_CMAX, m_Ellipse_Cmax);
	DDX_Text(pDX, IDC_ELLIPSED_DEGREE, m_Ellipse_Scale);
	DDX_Text(pDX, IDC_ELLIPSED_THICKNESS, m_Ellipse_Thickness);
	DDX_Control(pDX, IDC_ELLIPSED_COLOR, m_Ellipse_Color);
	DDX_Text(pDX, IDC_HOULINE_CMIN, m_HouLine_Cmin);
	DDX_Text(pDX, IDC_HOULINE_CMAX, m_HouLine_Cmax);
	DDX_Text(pDX, IDC_HOULINE_RHO, m_HouLine_Rho);
	DDX_Text(pDX, IDC_HOULINE_THETA, m_HouLine_Theta);
	DDX_Text(pDX, IDC_HOULINE_THRE, m_HouLine_Thre);
	DDX_Text(pDX, IDC_HOULINE_LINELEN, m_HouLine_LineLen);
	DDX_Text(pDX, IDC_HOULINE_LINEGAP, m_HouLine_LineGap);
	DDX_Text(pDX, IDC_HOULINE_THICKNESS, m_HouLine_Thickness);
	DDX_Control(pDX, IDC_HOULINE_COLOR, m_HouLine_Color);
	DDX_Control(pDX, IDC_HOULINE_PFLAG, m_HouLine_Pflag);
	DDX_Text(pDX, IDC_MATLINE_CMIN, m_MatLine_Cmin);
	DDX_Text(pDX, IDC_MATLINE_CMAX, m_MatLine_Cmax);
	DDX_Text(pDX, IDC_MATLINE_REPS, m_MatLine_Reps);
	DDX_Text(pDX, IDC_MATLINE_AEPS, m_MatLine_Aeps);
	DDX_Text(pDX, IDC_MATLINE_THICKNESS, m_MatLine_Thickness);
	DDX_Control(pDX, IDC_MATLINE_COLOR, m_MatLine_Color);
}


BEGIN_MESSAGE_MAP(RSHAPE, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGE_SHAPE, &RSHAPE::OnBnClickedChangeShape)
	ON_BN_CLICKED(IDOK, &RSHAPE::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RSHAPE::OnBnClickedCancel)
END_MESSAGE_MAP()


// RSHAPE 消息处理程序

//--界面初始化--
BOOL RSHAPE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//--加载参数--
void RSHAPE::LoadXML()
{
	m_shape.LoadXML();
	m_HouCir_Dp = m_shape.m_HouCir_Dp;
	m_HouCir_Mindist = m_shape.m_HouCir_Mindist;
	m_HouCir_Thre = m_shape.m_HouCir_Thre;
	m_HouCir_Vote = m_shape.m_HouCir_Vote;
	m_HouCir_Minr = m_shape.m_HouCir_Minr;
	m_HouCir_Maxr = m_shape.m_HouCir_Maxr;
	m_HouCir_Color.SetColor(RGB(m_shape.m_HouCir_Color[2],
		m_shape.m_HouCir_Color[1], m_shape.m_HouCir_Color[0]));
	m_HouCir_Thickness = m_shape.m_HouCir_Thickness;
	m_MatCir_Cmin = m_shape.m_MatCir_Cmin;
	m_MatCir_Cmax = m_shape.m_MatCir_Cmax;
	m_MatCir_Degree = m_shape.m_MatCir_Degree;
	m_MatCir_Color.SetColor(RGB(m_shape.m_MatCir_Color[2],
		m_shape.m_MatCir_Color[1], m_shape.m_MatCir_Color[0]));
	m_MatCir_Thickness = m_shape.m_MatCir_Thickness;
	m_Ellipse_Cmin = m_shape.m_Ellipse_Cmin;
	m_Ellipse_Cmax = m_shape.m_Ellipse_Cmax;
	m_Ellipse_Scale = m_shape.m_Ellipse_Scale;
	m_Ellipse_Thickness = m_shape.m_Ellipse_Thickness;
	m_Ellipse_Color.SetColor(RGB(m_shape.m_Ellipse_Color[2],
		m_shape.m_Ellipse_Color[1], m_shape.m_Ellipse_Color[0]));
	m_HouLine_Cmin = m_shape.m_HouLine_Cmin;
	m_HouLine_Cmax = m_shape.m_HouLine_Cmax;
	m_HouLine_Rho = m_shape.m_HouLine_Rho;
	m_HouLine_Theta = m_shape.m_HouLine_Theta;
	m_HouLine_Thre = m_shape.m_HouLine_Thre;
	m_HouLine_LineLen = m_shape.m_HouLine_LineLen;
	m_HouLine_LineGap = m_shape.m_HouLine_LineGap;
	m_HouLine_Thickness = m_shape.m_HouLine_Thickness;
	m_HouLine_Color.SetColor(RGB(m_shape.m_HouLine_Color[2],
		m_shape.m_HouLine_Color[1], m_shape.m_HouLine_Color[0]));
	m_HouLine_Pflag.SetCheck(m_shape.m_HouLine_P);
	m_MatLine_Cmin = m_shape.m_MatLine_Cmin;
	m_MatLine_Cmax = m_shape.m_MatLine_Cmax;
	m_MatLine_Reps = m_shape.m_MatLine_Reps;
	m_MatLine_Aeps = m_shape.m_MatLine_Aeps;
	m_MatLine_Thickness = m_shape.m_MatLine_Thickness;
	m_MatLine_Color.SetColor(RGB(m_shape.m_MatLine_Color[2],
		m_shape.m_MatLine_Color[1], m_shape.m_MatLine_Color[0]));
	UpdateData(false);
}

//--修改参数--
void RSHAPE::OnBnClickedChangeShape()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_shape.m_HouCir_Dp = m_HouCir_Dp;
	m_shape.m_HouCir_Mindist = m_HouCir_Mindist;
	m_shape.m_HouCir_Thre = m_HouCir_Thre;
	m_shape.m_HouCir_Vote = m_HouCir_Vote;
	m_shape.m_HouCir_Minr = m_HouCir_Minr;
	m_shape.m_HouCir_Maxr = m_HouCir_Maxr;
	COLORREF color = m_HouCir_Color.GetColor();
	m_shape.m_HouCir_Color[2] = BYTE(color);
	m_shape.m_HouCir_Color[1] = BYTE(color >> 8);
	m_shape.m_HouCir_Color[0] = BYTE(color >> 16);
	m_shape.m_HouCir_Thickness = m_HouCir_Thickness;
	m_shape.m_MatCir_Cmin = m_MatCir_Cmin;
	m_shape.m_MatCir_Cmax = m_MatCir_Cmax;
	m_shape.m_MatCir_Degree = m_MatCir_Degree;
	color = m_MatCir_Color.GetColor();
	m_shape.m_MatCir_Color[2] = BYTE(color);
	m_shape.m_MatCir_Color[1] = BYTE(color >> 8);
	m_shape.m_MatCir_Color[0] = BYTE(color >> 16);
	m_shape.m_MatCir_Thickness = m_MatCir_Thickness;
	m_shape.m_Ellipse_Cmin = m_Ellipse_Cmin;
	m_shape.m_Ellipse_Cmax = m_Ellipse_Cmax;
	m_shape.m_Ellipse_Scale = m_Ellipse_Scale;
	m_shape.m_Ellipse_Thickness = m_Ellipse_Thickness;
	color = m_Ellipse_Color.GetColor();
	m_shape.m_Ellipse_Color[2] = BYTE(color);
	m_shape.m_Ellipse_Color[1] = BYTE(color >> 8);
	m_shape.m_Ellipse_Color[0] = BYTE(color >> 16);
	m_shape.m_HouLine_Cmin = m_HouLine_Cmin;
	m_shape.m_HouLine_Cmax = m_HouLine_Cmax;
	m_shape.m_HouLine_Rho = m_HouLine_Rho;
	m_shape.m_HouLine_Theta = m_HouLine_Theta;
	m_shape.m_HouLine_Thre = m_HouLine_Thre;
	m_shape.m_HouLine_LineLen = m_HouLine_LineLen;
	m_shape.m_HouLine_LineGap = m_HouLine_LineGap;
	m_shape.m_HouLine_Thickness = m_HouLine_Thickness;
	color = m_HouLine_Color.GetColor();
	m_shape.m_HouLine_Color[2] = BYTE(color);
	m_shape.m_HouLine_Color[1] = BYTE(color >> 8);
	m_shape.m_HouLine_Color[0] = BYTE(color >> 16);
	m_shape.m_HouLine_P = m_HouLine_Pflag.GetCheck();
	m_shape.m_MatLine_Cmin = m_MatLine_Cmin;
	m_shape.m_MatLine_Cmax = m_MatLine_Cmax;
	m_shape.m_MatLine_Reps = m_MatLine_Reps;
	m_shape.m_MatLine_Aeps = m_MatLine_Aeps;
	m_shape.m_MatLine_Thickness = m_MatLine_Thickness;
	color = m_MatLine_Color.GetColor();
	m_shape.m_MatLine_Color[2] = BYTE(color);
	m_shape.m_MatLine_Color[1] = BYTE(color >> 8);
	m_shape.m_MatLine_Color[0] = BYTE(color >> 16);
	m_shape.SaveXML();
}


void RSHAPE::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangeShape();
	CDialogEx::OnOK();
}


void RSHAPE::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
