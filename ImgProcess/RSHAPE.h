#pragma once
#include <Shape.h>
#include "afxcolorbutton.h"
#include "afxwin.h"

// RSHAPE 对话框

class RSHAPE : public CDialogEx
{
	DECLARE_DYNAMIC(RSHAPE)

public:
	RSHAPE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RSHAPE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_HouCir_Dp;//--霍夫圆检测--累加器--
	double m_HouCir_Mindist;//--霍夫圆检测--圆心最小间距--
	double m_HouCir_Thre;//--霍夫圆检测--阈值--
	double m_HouCir_Vote;//--霍夫圆检测--投票数--
	int m_HouCir_Minr;//--霍夫圆检测--半径最小值--
	int m_HouCir_Maxr;//--霍夫圆检测--半径最大值--
	CMFCColorButton m_HouCir_Color;//--霍夫圆检测--绘制颜色--
	int m_HouCir_Thickness;//--霍夫圆检测--线宽--
	int m_MatCir_Cmin;//--拟合圆检测--Canny阈值下限--
	int m_MatCir_Cmax;//--拟合圆检测--Canny阈值上限--
	double m_MatCir_Degree;//--拟合圆检测--拟合度--
	CMFCColorButton m_MatCir_Color;//--拟合圆检测--绘制颜色--
	int m_MatCir_Thickness;//--拟合圆检测--线宽--
	int m_Ellipse_Cmin;//--椭圆检测--Canny阈值下限--
	int m_Ellipse_Cmax;//--椭圆检测--Canny阈值上限--
	int m_Ellipse_Scale;//--椭圆检测--长宽比（大于这个数不会被判定位椭圆）--
	int m_Ellipse_Thickness;//--椭圆检测--线宽--
	CMFCColorButton m_Ellipse_Color;//--椭圆检测--绘制颜色--
	int m_HouLine_Cmin;//--霍夫直线检测--Canny阈值下限--
	int m_HouLine_Cmax;//--霍夫直线检测--Canny阈值上限--
	double m_HouLine_Rho;//--霍夫直线检测--极径--
	double m_HouLine_Theta;//--霍夫直线检测--极角--
	int m_HouLine_Thre;//--霍夫直线检测--直线阈值--
	double m_HouLine_LineLen;//--霍夫直线检测--线段长度--
	double m_HouLine_LineGap;//--霍夫直线检测--两点间隙--
	int m_HouLine_Thickness;//--霍夫直线检测--线宽--
	CMFCColorButton m_HouLine_Color;//--霍夫直线检测--绘制颜色--
	CButton m_HouLine_Pflag;//--霍夫直线检测--是否使用概率学检测直线--
	int m_MatLine_Cmin;//--拟合直线检测--Canny阈值下限--
	int m_MatLine_Cmax;//--拟合直线检测--Canny阈值上限--
	double m_MatLine_Reps;//--拟合直线检测--距离精度--
	double m_MatLine_Aeps;//--拟合直线检测--角度精度--
	int m_MatLine_Thickness;//--拟合直线检测--线宽--
	CMFCColorButton m_MatLine_Color;//--拟合直线检测--绘制颜色--
	Shape m_shape;//--存储Shape参数
	virtual BOOL OnInitDialog();//--界面初始化--
	void LoadXML();//--加载参数--
	afx_msg void OnBnClickedChangeShape();//--修改参数--
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
