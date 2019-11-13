#pragma once
#include <PixProcess.h>
#include "afxwin.h"
#include "afxcolorbutton.h"

// RPIX 对话框

class RPIX : public CDialogEx
{
	DECLARE_DYNAMIC(RPIX)

public:
	RPIX(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RPIX();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Hmin;//--HSV中H的最小值--
	int m_Smin;//--HSV中S的最小值--
	int m_Vmin;//--HSV中V的最小值--
	int m_Hmax;//--HSV中H的最大值--
	int m_Smax;//--HSV中S的最大值--
	int m_Vmax;//--HSV中V的最大值--
	int m_Rmin;//--RGB中R的最小值--
	int m_Gmin;//--RGB中G的最小值--
	int m_Bmin;//--RGB中B的最小值--
	int m_Rmax;//--RGB中R的最大值--
	int m_Gmax;//--RGB中G的最大值--
	int m_Bmax;//--RGB中B的最大值--
	int m_Omin;//--单通道最小值--
	int m_Omax;//--单通道最大值--
	CComboBox m_Gray_Mode;//--单通道处理方式--
	int m_Thre_Thre;//--二值化阈值--
	CComboBox m_Thre_Mode;//--二值化方法--
	int m_Canny_Bsize;//--Canny滤波核大小--
	int m_Canny_Ksize;//--Canny核大小--
	int m_Canny_Cmin;//--Canny阈值下限--
	int m_Canny_Cmax;//--Canny阈值上限--
	CButton m_Canny_Gflag;//--是否使用梯度计算Canny--
	CComboBox m_Sobel_Depth;//--图像位数--
	CComboBox m_Sobel_Type;//--Sobel方法--
	int m_Sobel_Dx;//--Sobel在X方向的导数位--
	int m_Sobel_Dy;//--Sobel在Y方向的导数位--
	int m_Sobel_Ksize;//--Sobel核大小--
	double m_Sobel_Scale;//--Sobel缩放因子--
	CComboBox m_Laplace_Depth;//--图像位数--
	CComboBox m_Laplace_Type;//--Laplace方法--
	int m_Laplace_Bsize;//--Laplace滤波核大小--
	int m_Laplace_Ksize;//--Laplace核大小--
	double m_Laplace_Scale;//--Laplace缩放因子--
	int m_SubPix_Bsize;//--亚像素滤波核大小--
	int m_SubPix_Ksize;//--亚像素核大小--
	CMFCColorButton m_SubPix_Color;//--亚像素的绘制颜色--
	PixProcess m_pix;//--存储PIX参数--
	void LoadXML();//--加载PIX参数--
	virtual BOOL OnInitDialog();//--界面初始化--
	afx_msg void OnBnClickedChangePix();//--修改参数--
	afx_msg void OnBnClickedOk();//--重载OK按钮--
};
