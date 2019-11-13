// RDIST.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "RDIST.h"
#include "afxdialogex.h"


// RDIST 对话框

IMPLEMENT_DYNAMIC(RDIST, CDialogEx)

RDIST::RDIST(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIST, pParent)
	, m_pt2pt_ptSx(0)
	, m_pt2pt_ptSy(0)
	, m_pt2pt_ptEx(0)
	, m_pt2pt_ptEy(0)
	, m_pt2pt_Angle(0)
	, m_pt2ln_ptSx(0)
	, m_pt2ln_ptSy(0)
	, m_pt2ln_lnSx(0)
	, m_pt2ln_lnSy(0)
	, m_pt2ln_lnEx(0)
	, m_pt2ln_lnEy(0)
	, m_pt2ln_Angle(0)
	, m_ln2ln_lnSSx(0)
	, m_ln2ln_lnSSy(0)
	, m_ln2ln_lnSEx(0)
	, m_ln2ln_lnSEy(0)
	, m_ln2ln_lnESx(0)
	, m_ln2ln_lnESy(0)
	, m_ln2ln_lnEEx(0)
	, m_ln2ln_lnEEy(0)
	, m_ln2ln_Gap(0)
{

}

RDIST::~RDIST()
{
}

void RDIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PT2PT_SX, m_pt2pt_ptSx);
	DDX_Text(pDX, IDC_PT2PT_SY, m_pt2pt_ptSy);
	DDX_Text(pDX, IDC_PT2PT_EX, m_pt2pt_ptEx);
	DDX_Text(pDX, IDC_PT2PT_EY, m_pt2pt_ptEy);
	DDX_Control(pDX, IDC_PT2PT_AFLAG, m_pt2pt_AFlag);
	DDX_Text(pDX, IDC_PT2PT_ANGLE, m_pt2pt_Angle);
	DDX_Text(pDX, IDC_PT2LN_PTX, m_pt2ln_ptSx);
	DDX_Text(pDX, IDC_PT2LN_PTY, m_pt2ln_ptSy);
	DDX_Text(pDX, IDC_PT2LN_LNSX, m_pt2ln_lnSx);
	DDX_Text(pDX, IDC_PT2LN_LNSY, m_pt2ln_lnSy);
	DDX_Text(pDX, IDC_PT2LN_LNEX, m_pt2ln_lnEx);
	DDX_Text(pDX, IDC_PT2LN_LNEY, m_pt2ln_lnEy);
	DDX_Control(pDX, IDC_PT2LN_ALFAG, m_pt2ln_AFlag);
	DDX_Text(pDX, IDC_PT2LN_ANGLE, m_pt2ln_Angle);
	DDX_Text(pDX, IDC_LN2LN_SSX, m_ln2ln_lnSSx);
	DDX_Text(pDX, IDC_LN2LN_SSY, m_ln2ln_lnSSy);
	DDX_Text(pDX, IDC_LN2LN_SEX, m_ln2ln_lnSEx);
	DDX_Text(pDX, IDC_LN2LN_SEY, m_ln2ln_lnSEy);
	DDX_Text(pDX, IDC_LN2LN_ESX, m_ln2ln_lnESx);
	DDX_Text(pDX, IDC_LN2LN_ESY, m_ln2ln_lnESy);
	DDX_Text(pDX, IDC_LN2LN_EEX, m_ln2ln_lnEEx);
	DDX_Text(pDX, IDC_LN2LN_EEY, m_ln2ln_lnEEy);
	DDX_Text(pDX, IDC_LN2LN_THRE, m_ln2ln_Gap);
}


BEGIN_MESSAGE_MAP(RDIST, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGE_DIST, &RDIST::OnBnClickedChangeDist)
	ON_BN_CLICKED(IDOK, &RDIST::OnBnClickedOk)
END_MESSAGE_MAP()


// RDIST 消息处理程序

//--界面初始化--
BOOL RDIST::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LoadXML();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
//--加载参数--
void RDIST::LoadXML()
{
	m_dist.LoadXML();
	UpdateData(true);
	m_pt2pt_ptSx = m_dist.m_pt2pt_ptS.x;
	m_pt2pt_ptSy = m_dist.m_pt2pt_ptS.y;
	m_pt2pt_ptEx = m_dist.m_pt2pt_ptE.x;
	m_pt2pt_ptEy = m_dist.m_pt2pt_ptE.y;
	m_pt2pt_AFlag.SetCheck(m_dist.m_pt2pt_AFlag);
	m_pt2pt_Angle = m_dist.m_pt2pt_Angle;
	m_pt2ln_ptSx = m_dist.m_pt2ln_ptS.x;
	m_pt2ln_ptSy = m_dist.m_pt2ln_ptS.y;
	m_pt2ln_lnSx = m_dist.m_pt2ln_lnS.x;
	m_pt2ln_lnSy = m_dist.m_pt2ln_lnS.y;
	m_pt2ln_lnEx = m_dist.m_pt2ln_lnE.x;
	m_pt2ln_lnEy = m_dist.m_pt2ln_lnE.y;
	m_pt2ln_AFlag.SetCheck(m_dist.m_pt2ln_AFlag);
	m_pt2ln_Angle = m_dist.m_pt2ln_Angle;
	m_ln2ln_lnSSx = m_dist.m_ln2ln_lnSS.x;
	m_ln2ln_lnSSy = m_dist.m_ln2ln_lnSS.y;
	m_ln2ln_lnSEx = m_dist.m_ln2ln_lnSE.x;
	m_ln2ln_lnSEy = m_dist.m_ln2ln_lnSE.y;
	m_ln2ln_lnESx = m_dist.m_ln2ln_lnES.x;
	m_ln2ln_lnESy = m_dist.m_ln2ln_lnES.y;
	m_ln2ln_lnEEx = m_dist.m_ln2ln_lnEE.x;
	m_ln2ln_lnEEy = m_dist.m_ln2ln_lnEE.y;
	m_ln2ln_Gap = m_dist.m_ln2ln_Gap;
	UpdateData(false);
}

//--修改参数--
void RDIST::OnBnClickedChangeDist()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_dist.m_pt2pt_ptS.x = m_pt2pt_ptSx;
	m_dist.m_pt2pt_ptS.y = m_pt2pt_ptSy;
	m_dist.m_pt2pt_ptE.x = m_pt2pt_ptEx;
	m_dist.m_pt2pt_ptE.y = m_pt2pt_ptEy;
	m_dist.m_pt2pt_AFlag = m_pt2pt_AFlag.GetCheck();
	m_dist.m_pt2pt_Angle = m_pt2pt_Angle;
	m_dist.m_pt2ln_ptS.x = m_pt2ln_ptSx;
	m_dist.m_pt2ln_ptS.y = m_pt2ln_ptSy;
	m_dist.m_pt2ln_lnS.x = m_pt2ln_lnSx;
	m_dist.m_pt2ln_lnS.y = m_pt2ln_lnSy;
	m_dist.m_pt2ln_lnE.x = m_pt2ln_lnEx;
	m_dist.m_pt2ln_lnE.y = m_pt2ln_lnEy;
	m_dist.m_pt2ln_AFlag = m_pt2ln_AFlag.GetCheck();
	m_dist.m_pt2ln_Angle = m_pt2ln_Angle;
	m_dist.m_ln2ln_lnSS.x = m_ln2ln_lnSSx;
	m_dist.m_ln2ln_lnSS.y = m_ln2ln_lnSSy;
	m_dist.m_ln2ln_lnSE.x = m_ln2ln_lnSEx;
	m_dist.m_ln2ln_lnSE.y = m_ln2ln_lnSEy;
	m_dist.m_ln2ln_lnES.x = m_ln2ln_lnESx;
	m_dist.m_ln2ln_lnES.y = m_ln2ln_lnESy;
	m_dist.m_ln2ln_lnEE.x = m_ln2ln_lnEEx;
	m_dist.m_ln2ln_lnEE.y = m_ln2ln_lnEEy;
	m_dist.m_ln2ln_Gap = m_ln2ln_Gap;
	UpdateData(false);
	m_dist.SaveXML();
}

//--重载确定按钮--
void RDIST::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangeDist();
	CDialogEx::OnOK();
}
