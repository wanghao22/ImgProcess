#pragma once
#include <ROI.h>

// PROI 对话框

class PROI : public CDialogEx
{
	DECLARE_DYNAMIC(PROI)

public:
	PROI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PROI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Circle_X;//--圆心X点--
	int m_Circle_Y;//--圆心Y点--
	int m_Circle_R;//--圆心半径--
	int m_Annulus_X;//--圆环X点--
	int m_Annulus_Y;//--圆环Y点--
	int m_Annulus_Rmax;//--圆环内圆半径--
	int m_Annulus_Rmin;//--圆环外圆半径--
	double m_Ellipse_A;//--椭圆旋转角度--
	int m_Ellipse_H;//--椭圆高度--
	int m_Ellipse_W;//--椭圆宽度--
	int m_Ellipse_X;//--椭圆中心X点--
	int m_Ellipse_Y;//--椭圆中心Y点--
	int m_Rect_H;//--矩形高度--
	int m_Rect_W;//--矩形宽度--
	int m_Rect_X;//--矩形左上角X点--
	int m_Rect_Y;//--矩形左上角Y点--
	int m_Ring_Hmin;//--小矩形高度--
	int m_Ring_Hmax;//--大矩形高度--
	int m_Ring_Wmin;//--小矩形宽度--
	int m_Ring_Wmax;//--大矩形宽度--
	int m_Ring_Xmin;//--小矩形左上角X点--
	int m_Ring_Xmax;//--大矩形左上角X点--
	int m_Ring_Ymin;//--小矩形左上角Y点--
	int m_Ring_Ymax;//--大矩形左上角Y点--
	double m_Rotate_A;//--旋转矩形角度--
	int m_Rotate_H;//--旋转矩形高度--
	int m_Rotate_W;//--旋转矩形宽度--
	int m_Rotate_X;//--旋转矩形中心X点--
	int m_Rotate_Y;//--旋转矩形中心Y点--
	ROI m_roi;//--存储当前ROI参数--
	void LoadXML();//--加载数据--
	afx_msg void OnBnClickedChangeRoi();//--修改参数--
	afx_msg void OnBnClickedOk();//--重载确定按钮--
	virtual BOOL OnInitDialog();//--界面初始化--
};
