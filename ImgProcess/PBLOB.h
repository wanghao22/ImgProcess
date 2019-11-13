#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"
#include <Blob.h>


// PBLOB 对话框

class PBLOB : public CDialogEx
{
	DECLARE_DYNAMIC(PBLOB)

public:
	PBLOB(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PBLOB();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLOB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Contour_Thre;//--轮廓阈值--
	int m_Contour_KSize;//--轮廓卷积大小--
	CMFCColorButton m_Contour_Color;//--轮廓线条颜色--
	CComboBox m_Contour_Mode;//--轮廓分析模式--
	int m_Contour_Thickness;//--轮廓线宽--
	int m_CvBox_Thre;//--轮廓外接矩形阈值--
	int m_CvBox_KSize;//--轮廓外接矩形卷积大小--
	CMFCColorButton m_CvBox_Color;//--轮廓外接矩形线条颜色--
	CComboBox m_CvBox_Mode;//--轮廓外接矩形分析模式--
	int m_CvBox_Thickness;//--轮廓外接矩形线宽--
	Blob m_blob;//--存储Blob参数--
	void LoadXML();//--读取Blob的XML参数--
	virtual BOOL OnInitDialog();//--窗口初始化--
	afx_msg void OnBnClickedChangeBlob();//--修改参数--
	afx_msg void OnBnClickedOk();//--重载确定按钮--
};
