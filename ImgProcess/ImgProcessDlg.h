
// ImgProcessDlg.h : 头文件
//

#pragma once
#include "PROI.h"
#include "PBLOB.h"
#include "RPIX.h"
#include "RSHAPE.h"
#include "RDIST.h"
#include "TRANS.h"
#include "afxwin.h"
#include "putText.h"

// CImgProcessDlg 对话框
class CImgProcessDlg : public CDialogEx
{
// 构造
public:
	CImgProcessDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMGPROCESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	ROI m_roi;//--ROI操作(包括参数和调用函数)--
	Blob m_blob;//--Blob操作--
	PixProcess m_pix;//--PixProcess操作--
	Shape m_shape;//--Shape操作--
	Distance m_dist;//--Distance操作--
	Transformation m_trans;//--Transformation操作--
	cv::Mat m_src;//--存储原始图像--
	std::vector<cv::Mat> m_dsts;//--存储处理后的图像--
	int m_step;//--指向当前执行到的步骤--
	CRect m_rect;//--存储控件尺寸--
	void InterfaceInit();//--初始化--
	void Show_Image(cv::Mat src, int nIDDlgItem);//--显示图像到控件上--
	afx_msg void OnBnClickedLoadImg();//--加载图像--
	CComboBox m_select_roi;//--ROI选项的下拉框--
	CComboBox m_select_blob;//--轮廓选项的下拉框--
	CComboBox m_select_pix;//--像素处理选项的下拉框--
	CComboBox m_select_shape;//--形状检测选项的下拉框--
	CComboBox m_select_dist;//--计算距离选项的下拉框--
	CListBox m_MsgList;//--存储执行的操作--
	afx_msg void OnBnClickedDoRoi();//--执行ROI--
	afx_msg void OnBnClickedDoBlob();//--执行轮廓处理--
	afx_msg void OnBnClickedDoPix();//--执行像素处理--
	afx_msg void OnBnClickedDoShape();//--执行形状检测--
	afx_msg void OnBnClickedDoDist();//--执行计算距离--
	afx_msg void OnBnClickedBefore();//--回退一步--
	afx_msg void OnBnClickedParamRoi();//--设置ROI的参数--
	afx_msg void OnBnClickedParamBlob();//--设置轮廓处理的参数--
	afx_msg void OnBnClickedParamPix();//--设置像素处理的参数--
	afx_msg void OnBnClickedParamShape();//--设置形状检测的参数--
	afx_msg void OnBnClickedParamDist();//--设置计算距离的参数--
	afx_msg void OnBnClickedReset();//--重置--
	void showresult(int rc);
	afx_msg void OnBnClickedDoTrans();
	afx_msg void OnBnClickedParamTrans();
	CComboBox m_select_trans;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedSaveImg();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRect m_wndRect;
	int WriteInToXML(std::string xmlfile, cv::Mat src);
	int ReadFromXML(std::string xmlfile, cv::Mat &dst);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	bool init_flag;
};
