
// ImgProcessDlg.h : ͷ�ļ�
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

// CImgProcessDlg �Ի���
class CImgProcessDlg : public CDialogEx
{
// ����
public:
	CImgProcessDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMGPROCESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	ROI m_roi;//--ROI����(���������͵��ú���)--
	Blob m_blob;//--Blob����--
	PixProcess m_pix;//--PixProcess����--
	Shape m_shape;//--Shape����--
	Distance m_dist;//--Distance����--
	Transformation m_trans;//--Transformation����--
	cv::Mat m_src;//--�洢ԭʼͼ��--
	std::vector<cv::Mat> m_dsts;//--�洢������ͼ��--
	int m_step;//--ָ��ǰִ�е��Ĳ���--
	CRect m_rect;//--�洢�ؼ��ߴ�--
	void InterfaceInit();//--��ʼ��--
	void Show_Image(cv::Mat src, int nIDDlgItem);//--��ʾͼ�񵽿ؼ���--
	afx_msg void OnBnClickedLoadImg();//--����ͼ��--
	CComboBox m_select_roi;//--ROIѡ���������--
	CComboBox m_select_blob;//--����ѡ���������--
	CComboBox m_select_pix;//--���ش���ѡ���������--
	CComboBox m_select_shape;//--��״���ѡ���������--
	CComboBox m_select_dist;//--�������ѡ���������--
	CListBox m_MsgList;//--�洢ִ�еĲ���--
	afx_msg void OnBnClickedDoRoi();//--ִ��ROI--
	afx_msg void OnBnClickedDoBlob();//--ִ����������--
	afx_msg void OnBnClickedDoPix();//--ִ�����ش���--
	afx_msg void OnBnClickedDoShape();//--ִ����״���--
	afx_msg void OnBnClickedDoDist();//--ִ�м������--
	afx_msg void OnBnClickedBefore();//--����һ��--
	afx_msg void OnBnClickedParamRoi();//--����ROI�Ĳ���--
	afx_msg void OnBnClickedParamBlob();//--������������Ĳ���--
	afx_msg void OnBnClickedParamPix();//--�������ش���Ĳ���--
	afx_msg void OnBnClickedParamShape();//--������״���Ĳ���--
	afx_msg void OnBnClickedParamDist();//--���ü������Ĳ���--
	afx_msg void OnBnClickedReset();//--����--
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
