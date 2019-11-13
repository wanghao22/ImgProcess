#pragma once
#include <Distance.h>
#include "afxwin.h"

// RDIST 对话框

class RDIST : public CDialogEx
{
	DECLARE_DYNAMIC(RDIST)

public:
	RDIST(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RDIST();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_pt2pt_ptSx;//--点到点--点A的X坐标--
	int m_pt2pt_ptSy;//--点到点--点A的Y坐标--
	int m_pt2pt_ptEx;//--点到点--点B的X坐标--
	int m_pt2pt_ptEy;//--点到点--点B的Y坐标--
	CButton m_pt2pt_AFlag;//--点到点--是否计算角度--
	double m_pt2pt_Angle;//--点到点--角度--
	int m_pt2ln_ptSx;//--点到线--点A的X坐标--
	int m_pt2ln_ptSy;//--点到线--点A的Y坐标--
	int m_pt2ln_lnSx;//--点到线--线段起点的X坐标--
	int m_pt2ln_lnSy;//--点到线--线段起点的Y坐标--
	int m_pt2ln_lnEx;//--点到线--线段终点的X坐标--
	int m_pt2ln_lnEy;//--点到线--线段终点的Y坐标--
	CButton m_pt2ln_AFlag;//--点到线--是否计算角度--
	double m_pt2ln_Angle;//--点到线--角度--
	int m_ln2ln_lnSSx;//--线到线--线段1起点的X坐标--
	int m_ln2ln_lnSSy;//--线到线--线段1起点的Y坐标--
	int m_ln2ln_lnSEx;//--线到线--线段1终点的X坐标--
	int m_ln2ln_lnSEy;//--线到线--线段1终点的Y坐标--
	int m_ln2ln_lnESx;//--线到线--线段2起点的X坐标--
	int m_ln2ln_lnESy;//--线到线--线段2起点的Y坐标--
	int m_ln2ln_lnEEx;//--线到线--线段2终点的X坐标--
	int m_ln2ln_lnEEy;//--线到线--线段2终点的Y坐标--
	double m_ln2ln_Gap;//--线到线--如果计算出来的差异值大于这个数，则判定这两直线相交，距离为0--
	Distance m_dist;//--存储Dist参数
	virtual BOOL OnInitDialog();//--界面初始化--
	void LoadXML();//--加载参数--
	afx_msg void OnBnClickedChangeDist();//--修改参数--
	afx_msg void OnBnClickedOk();//--重载确定按钮--
};
