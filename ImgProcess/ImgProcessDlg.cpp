
// ImgProcessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "ImgProcessDlg.h"
#include "afxdialogex.h"

using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CImgProcessDlg �Ի���



CImgProcessDlg::CImgProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IMGPROCESS_DIALOG, pParent)
	, init_flag(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImgProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECT_ROI, m_select_roi);
	DDX_Control(pDX, IDC_SELECT_BLOB, m_select_blob);
	DDX_Control(pDX, IDC_SELECT_PIX, m_select_pix);
	DDX_Control(pDX, IDC_SELECT_SHAPE, m_select_shape);
	DDX_Control(pDX, IDC_SELECT_DIST, m_select_dist);
	DDX_Control(pDX, IDC_OUTPUT, m_MsgList);
	DDX_Control(pDX, IDC_SELECT_TRANS, m_select_trans);
}

BEGIN_MESSAGE_MAP(CImgProcessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD_IMG, &CImgProcessDlg::OnBnClickedLoadImg)
//	ON_CBN_SELCHANGE(IDC_SELECT_ROI, &CImgProcessDlg::OnCbnSelchangeSelectRoi)
ON_BN_CLICKED(IDC_DO_ROI, &CImgProcessDlg::OnBnClickedDoRoi)
ON_BN_CLICKED(IDC_DO_BLOB, &CImgProcessDlg::OnBnClickedDoBlob)
ON_BN_CLICKED(IDC_DO_PIX, &CImgProcessDlg::OnBnClickedDoPix)
ON_BN_CLICKED(IDC_DO_SHAPE, &CImgProcessDlg::OnBnClickedDoShape)
ON_BN_CLICKED(IDC_DO_DIST, &CImgProcessDlg::OnBnClickedDoDist)
ON_BN_CLICKED(IDC_BEFORE, &CImgProcessDlg::OnBnClickedBefore)
ON_BN_CLICKED(IDC_PARAM_ROI, &CImgProcessDlg::OnBnClickedParamRoi)
ON_BN_CLICKED(IDC_PARAM_BLOB, &CImgProcessDlg::OnBnClickedParamBlob)
ON_BN_CLICKED(IDC_PARAM_PIX, &CImgProcessDlg::OnBnClickedParamPix)
ON_BN_CLICKED(IDC_PARAM_SHAPE, &CImgProcessDlg::OnBnClickedParamShape)
ON_BN_CLICKED(IDC_PARAM_DIST, &CImgProcessDlg::OnBnClickedParamDist)
ON_BN_CLICKED(IDC_RESET, &CImgProcessDlg::OnBnClickedReset)
ON_BN_CLICKED(IDC_DO_TRANS, &CImgProcessDlg::OnBnClickedDoTrans)
ON_BN_CLICKED(IDC_PARAM_TRANS, &CImgProcessDlg::OnBnClickedParamTrans)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_SAVE_IMG, &CImgProcessDlg::OnBnClickedSaveImg)
ON_WM_SIZE()
ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CImgProcessDlg ��Ϣ�������
//�����ʼ��
BOOL CImgProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InterfaceInit();
	init_flag = true;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CImgProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CImgProcessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CImgProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//--��ʼ��--
void CImgProcessDlg::InterfaceInit()
{
	//���ñ�����ɫ
	SetBackgroundColor(RGB(0x1e, 0x1e, 0x1e));
	///��������
	static CFont font;
	font.CreatePointFont(80, L"����");
	int dlgitem[] = { IDC_ROIS ,IDC_ROIS1 ,IDC_ROIS2 ,IDC_ROIS3 ,\
		IDC_ROIS4, IDC_ROIS5, IDC_ROIS6};
	for (int i = 0; i < 7; i++)
	{
		GetDlgItem(dlgitem[i])->SetFont(&font);
	}

	cv::namedWindow("view");
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_SHOW_IMG)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	
	m_select_roi.SetCurSel(0);
	m_select_blob.SetCurSel(0);
	m_select_pix.SetCurSel(0);
	m_select_shape.SetCurSel(0);
	m_select_dist.SetCurSel(0);
	m_select_trans.SetCurSel(0);

	m_roi.LoadXML();
	m_blob.LoadXML();
	m_pix.LoadXML();
	m_shape.LoadXML();
	m_dist.LoadXML();
	m_trans.LoadXML();
	m_step = -1;

	///���ɳ�ʼͼƬ
	/*Mat initmat(1000, 1000, CV_8UC3, Scalar(0xff, 0xff, 0xff));
	putText::putTextZH(initmat, "��ӭʹ������ͼ����ϵͳ", Point(50, 200), Scalar(0), 60, "����");
	putText::putTextZH(initmat, "�������½Ǽ���ͼ��", Point(100, 300), Scalar(0), 60, "����");
	putText::putTextZH(initmat, "���ͼƬ���в���", Point(150, 400), Scalar(0), 60, "����");
	imshow("view", initmat);*/

	//��ȡ�ܴ��ڴ�С
	GetClientRect(&m_wndRect);
}

//--��ʾͼ�񵽿ؼ���--
void CImgProcessDlg::Show_Image(cv::Mat src, int nIDDlgItem)
{
	//����Ӧ
	if (src.channels() == 1)
		cvtColor(src, src, CV_GRAY2BGR);
	//CV_BGR2GRAY 3->1;
	//CV_GRAY2BGR 1->3;
	//CV_BGR2HSV  3->3;
	cv::Mat temp;
	GetDlgItem(nIDDlgItem)->GetClientRect(&m_rect);
	CvSize window_size = cvSize(m_rect.Width(), m_rect.Height());
	double width = window_size.width;
	double scale = (double)src.rows / (double)src.cols;
	double height = width*scale;
	if (width > window_size.width || height > window_size.height)
	{
		height = window_size.height;
		scale = (double)src.cols / (double)src.rows;
		width = height*scale;
		if (width > window_size.width || height > window_size.height)
		{
			return;
		}
	}
	try
	{
		cv::resize(src, temp, cvSize((int)width, (int)height));
	}
	catch (Exception ex)
	{
		string str = ex.msg;
		AfxMessageBox(CString(str.c_str()));
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
		return;
	}
	cv::Mat dst = cv::Mat::Mat(window_size, CV_8UC3, cvScalarAll(0xff));
	int x = (dst.cols - temp.cols) / 2;
	int y = (dst.rows - temp.rows) / 2;
	cv::Mat roi = dst(cvRect(x, y, temp.cols, temp.rows));
	temp.copyTo(roi);
	cv::imshow("view", dst);
}

//--����ͼ��--
void CImgProcessDlg::OnBnClickedLoadImg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString picPath;   //����ͼƬ·������  
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"jpg file(*.jpg)|*.jpg|png file(*.png)|*.png|bmp \
		file(*.bmp)|*.bmp|xml file(*.xml)|*.xml|�����ļ�(*.*)|*.*||");   //ѡ���ļ��Ի���  
	if (dlg.DoModal() == IDOK)
	{
		picPath = dlg.GetPathName();  //��ȡͼƬ·��  
	}
	else
	{
		AfxMessageBox(L"��δѡȡͼ��");
		return;
	}
	string picpath = CW2A(picPath);
	string ext = picpath.substr(picpath.length() - 3, 3);
	if (ext == "xml")
		ReadFromXML(picpath, m_src);
	else
		m_src = imread(picpath, -1);
	//m_src = imread(picpath, -1);
	Show_Image(m_src, IDC_SHOW_IMG);
	m_dsts.clear();
	while (m_MsgList.GetCount() != 0)
	{
		m_MsgList.DeleteString(0);
	}
	m_step = -1;
}

//--ִ��ROI--
void CImgProcessDlg::OnBnClickedDoRoi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int status = 0;
	if (m_step == -1)
	{
		try
		{
			status = m_roi.Excute_(m_src, dst, m_select_roi.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			status = m_roi.Excute_(m_dsts[m_step], dst, m_select_roi.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (status != 0)
	{
		showresult(status);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"�ɹ�");
	m_step++;

	CString temp;//CString:L"";   string:"";
	GetDlgItemTextW(IDC_SELECT_ROI, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--ִ����������--
void CImgProcessDlg::OnBnClickedDoBlob()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int rc = 0;
	if (m_step == -1)
	{
		try
		{
			rc = m_blob.Excute_(m_src, dst, m_select_blob.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			rc = m_blob.Excute_(m_dsts[m_step], dst, m_select_blob.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (rc != 0)
	{
		showresult(rc);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"�ɹ�");
	m_step++;

	CString temp;
	GetDlgItemTextW(IDC_SELECT_BLOB, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--ִ�����ش���--
void CImgProcessDlg::OnBnClickedDoPix()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int rc = 0;//״ֵ̬
	if (m_step == -1)
	{
		try
		{
			rc = m_pix.Excute_(m_src, dst, m_select_pix.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			rc = m_pix.Excute_(m_dsts[m_step], dst, m_select_pix.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (rc != 0)
	{
		showresult(rc);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"�ɹ�");
	m_step++;

	CString temp;
	GetDlgItemTextW(IDC_SELECT_PIX, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--ִ����״���--
void CImgProcessDlg::OnBnClickedDoShape()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int rc = 0;
	if (m_step == -1)
	{
		try
		{
			rc = m_shape.Excute_(m_src, dst, m_select_shape.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			rc = m_shape.Excute_(m_dsts[m_step], dst, m_select_shape.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (rc != 0)
	{
		showresult(rc);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"�ɹ�");
	m_step++;

	CString temp;
	GetDlgItemTextW(IDC_SELECT_SHAPE, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--ִ�м������--
void CImgProcessDlg::OnBnClickedDoDist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int rc = 0;
	int subtype = m_select_dist.GetCurSel();
	if (m_step == -1)
	{
		try
		{
			rc = m_dist.Excute_(m_src, dst, m_select_dist.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			rc = m_dist.Excute_(m_dsts[m_step], dst, m_select_dist.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (rc != 0)
	{
		showresult(rc);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	CString result;
	if (POINT_2_POINT == subtype)
		result.Format(L"�ɹ�������=%.2f", m_dist.m_pt2pt_Result);
	else if (POINT_2_LINE == subtype)
		result.Format(L"�ɹ�������=%.2f", m_dist.m_pt2ln_Result);
	else if (LINE_2_LINE == subtype)
		result.Format(L"�ɹ�������=%.2f", m_dist.m_ln2ln_Result);
	else
		result.Format(L"ʧ��");
	GetDlgItem(IDC_RESULT)->SetWindowTextW(result);
	m_step++;

	CString temp;
	GetDlgItemTextW(IDC_SELECT_DIST, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--����һ��--
void CImgProcessDlg::OnBnClickedBefore()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_step == -1)
		return;
	else if (m_step == 0)
	{
		m_dsts.pop_back();
		m_step--;
		Show_Image(m_src, IDC_SHOW_IMG);
	}
	else
	{
		m_dsts.pop_back();
		m_step--;
		Show_Image(m_dsts[m_step], IDC_SHOW_IMG);
	}
	int l = m_MsgList.GetCount();
	m_MsgList.DeleteString(l - 1);
	m_MsgList.SetCurSel(l - 2);
}

//--����ROI�Ĳ���--
void CImgProcessDlg::OnBnClickedParamRoi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PROI rwnd;
	rwnd.DoModal();
	m_roi.LoadXML();
}

//--������������Ĳ���--
void CImgProcessDlg::OnBnClickedParamBlob()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PBLOB rwnd;
	rwnd.DoModal();
	m_blob.LoadXML();
}

//--�������ش���Ĳ���--
void CImgProcessDlg::OnBnClickedParamPix()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	RPIX rwnd;
	rwnd.DoModal();
	m_pix.LoadXML();
}

//--������״���Ĳ���--
void CImgProcessDlg::OnBnClickedParamShape()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	RSHAPE rwnd;
	rwnd.DoModal();
	m_shape.LoadXML();
}

//--���ü������Ĳ���--
void CImgProcessDlg::OnBnClickedParamDist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	RDIST rwnd;
	rwnd.DoModal();
	m_dist.LoadXML();
}

//--����--
void CImgProcessDlg::OnBnClickedReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	while (m_MsgList.GetCount() != 0)
	{
		m_MsgList.DeleteString(0);
	}
	if (!m_src.empty())
		Show_Image(m_src, IDC_SHOW_IMG);
	m_dsts.clear();
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"���óɹ�");
	m_step = -1;
}

//--��ʾ����Ľ��--
void CImgProcessDlg::showresult(int rc)
{
	if (rc == _NO_IMAGE_)
	{
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ�ܣ�û�м���ͼ��");
	}
	else if (rc == _PARAM_ERROR_)
	{
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ�ܣ���������");
	}
	else if (rc == _ROI_OVERTOP_)
	{
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ�ܣ�ROI������Χ");
	}
	else if (rc == _NO_DECTION_)
	{
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ�ܣ�û�м�⵽");
	}
	else
	{
		GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ�ܣ�����ԭ��");
	}
}

//--ִ��ͼ��任--
void CImgProcessDlg::OnBnClickedDoTrans()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat dst;
	int rc = 0;
	if (m_step == -1)
	{
		try
		{
			rc = m_trans.Excute_(m_src, dst, m_select_trans.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	else
	{
		try
		{
			rc = m_trans.Excute_(m_dsts[m_step], dst, m_select_trans.GetCurSel());
		}
		catch (Exception ex)
		{
			string str = ex.msg;
			AfxMessageBox(CString(str.c_str()));
			GetDlgItem(IDC_RESULT)->SetWindowTextW(L"ʧ��");
			return;
		}
	}
	if (rc != 0)
	{
		showresult(rc);
		return;
	}
	Show_Image(dst, IDC_SHOW_IMG);
	m_dsts.push_back(dst);
	GetDlgItem(IDC_RESULT)->SetWindowTextW(L"�ɹ�");
	m_step++;

	CString temp;
	GetDlgItemTextW(IDC_SELECT_TRANS, temp);
	m_MsgList.AddString(temp);
	int l = m_MsgList.GetCount();
	m_MsgList.SetCurSel(l - 1);
}

//--����ͼ��任�Ĳ���--
void CImgProcessDlg::OnBnClickedParamTrans()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRANS twnd;
	twnd.DoModal();
	m_trans.LoadXML();
}

//--��ɫ����--
HBRUSH CImgProcessDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	int dlgitem[] = { IDC_ROIS ,IDC_ROIS1 ,IDC_ROIS2 ,IDC_ROIS3 ,\
		IDC_ROIS4, IDC_ROIS5, IDC_ROIS6 };
	for (int i = 0; i < 7; i++)
	{
		if (pWnd->GetDlgCtrlID() == dlgitem[i])
		{
			pDC->SetTextColor(RGB(0xdc, 0xdc, 0xdc));
		}
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

//--����ͼ��--
void CImgProcessDlg::OnBnClickedSaveImg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat save;
	if (m_src.empty())
	{
		AfxMessageBox(L"û�п��Դ洢��ͼ��");
		return;
	}
	if (m_dsts.size() < 1)
		save = m_src.clone();
	else
	{
		int index = static_cast<int>(m_dsts.size() - 1);
		save = m_dsts[index].clone();
	}
	CString picPath;
	TCHAR szFilter[] = __T("jpg file(*.jpg)|*.jpg|png file(*.png)|*.png|bmp \
		file(*.bmp)|*.bmp|xml file(*.xml)|*.xml|�����ļ�(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, __T("jpg"), __T("name"), OFN_HIDEREADONLY | \
		OFN_OVERWRITEPROMPT, szFilter, this);
	fileDlg.m_ofn.lpstrTitle = __T("����ͼƬ");
	CString imgpath;
	if (IDOK == fileDlg.DoModal())
	{
		imgpath = fileDlg.GetPathName();
	}
	else
	{
		MessageBox(__TEXT("��ȡ���˱��棡"), __T("��ʾ"), MB_ICONINFORMATION);
		return;
	}
	string path2 = CW2A(imgpath);
	string ext = path2.substr(path2.length() - 3, 3);
	try
	{
		if (ext == "xml")
			WriteInToXML(path2, save);
		else
			imwrite(path2, save);
	}
	catch (cv::Exception ex)
	{
		AfxMessageBox(L"����·������");
	}
	catch (const std::exception& ex)
	{
		AfxMessageBox(CString(ex.what()));
		//AfxMessageBox(L"��������������ĵ���Ϣ");
	}
	catch (...)
	{
		AfxMessageBox(L"��������");
	}
	save.release();
}

//--����Ӧ��󻯺ͻ�ԭ--
void CImgProcessDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	//TODO: �ڴ˴������Ϣ����������
	for (int i = 1000; i <1126; i++)//��Ϊ�Ƕ���ؼ���������������ѭ��
	{
		CWnd *pWnd = GetDlgItem(i);
		//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
		if (pWnd && nType != 1 && m_wndRect.Width() && m_wndRect.Height())
		{
			CRect rect;   //��ȡ�ؼ��仯ǰ�Ĵ�С 
			pWnd->GetWindowRect(&rect);
			ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
			rect.left = rect.left*cx / m_wndRect.Width();//�����ؼ���С
			rect.right = rect.right*cx / m_wndRect.Width();
			rect.top = rect.top*cy / m_wndRect.Height();
			rect.bottom = rect.bottom*cy / m_wndRect.Height();
			pWnd->MoveWindow(rect);//���ÿؼ���С 
		}
	}
	GetClientRect(&m_wndRect);
	if (init_flag && !m_src.empty())
	{
		int index = static_cast<int>(m_dsts.size() - 1);
		if (index >= 0)
			Show_Image(m_dsts[index], IDC_SHOW_IMG);
		else
			Show_Image(m_src, IDC_SHOW_IMG);
	}
}

int CImgProcessDlg::WriteInToXML(string xmlfile, Mat src)
{
	FileStorage fs(xmlfile, FileStorage::WRITE);
	if (!fs.isOpened())
		return -1;
	fs << "rows" << src.rows;
	fs << "cols" << src.cols;
	fs << "type" << src.type();
	int chaneel = src.channels();
	fs << "data" << "[";
	for (int i = 0; i<src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			if (chaneel == 1)
			{
				int t = src.at<uchar>(i, j);
				fs << t;
			}
			else if (chaneel == 3)
			{
				Vec3b p = src.at<Vec3b>(i, j);
				int t = p[0]; fs << t;
				t = p[1]; fs << t;
				t = p[2]; fs << t;
			}
			else if (chaneel == 4)
			{
				Vec4b p = src.at<Vec4b>(i, j);
				int t = p[0]; fs << t;
				t = p[1]; fs << t;
				t = p[2]; fs << t;
				t = p[3]; fs << t;
			}
			else
				return -2;
		}
	}
	fs << "]";
	fs.release();
	return 0;
}

int CImgProcessDlg::ReadFromXML(string xmlfile, Mat & dst)
{
	FileStorage fs(xmlfile, FileStorage::READ);
	if (!fs.isOpened())
		return -1;
	int row, col, type;
	fs["rows"] >> row;
	fs["cols"] >> col;
	fs["type"] >> type;
	if (row <= 0 || col <= 0)
		return -2;
	dst = Mat::zeros(row, col, type);
	vector<int> MatData;
	int chaneel = dst.channels();
	FileNode DataNode = fs["data"];
	for (FileNodeIterator it = DataNode.begin(); it != DataNode.end(); it++)
	{
		MatData.push_back(*it);
	}
	if (MatData.size() != row*col*chaneel)
		return -2;
	int idx = 0;
	for (int i = 0; i<dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			if (chaneel == 1)
			{
				dst.at<uchar>(i, j) = MatData[idx];
				idx += 1;
			}
			else if (chaneel == 3)
			{
				dst.at<Vec3b>(i, j) = Vec3b(MatData[idx], MatData[idx + 1], MatData[idx + 2]);
				idx += 3;
			}
			else if (chaneel == 4)
			{
				dst.at<Vec4b>(i, j) = Vec4b(MatData[idx], MatData[idx + 1], MatData[idx + 2], MatData[idx + 3]);
				idx += 4;
			}
			else
				return -2;
		}
	}
	fs.release();
	return 0;
}



void CImgProcessDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT i;
	UINT nFiles = ::DragQueryFile(hDropInfo, (UINT)-1, NULL, 0);
	for (i = 0; i < nFiles; i++)
	{
		TCHAR szFileName[_MAX_PATH];
		::DragQueryFile(hDropInfo, i, szFileName, _MAX_PATH);
		//char str[_MAX_PATH]; sprintf_s(str, "%hs", szFileName);
		string str = CW2A(szFileName);
		m_src = imread(str, -1);
		if (!m_src.empty())
		{
			Show_Image(m_src, IDC_SHOW_IMG);
			m_dsts.clear();
			while (m_MsgList.GetCount() != 0)
			{
				m_MsgList.DeleteString(0);
			}
			m_step = -1;
			break;
		}
		AfxMessageBox(szFileName);

	}
	CDialogEx::OnDropFiles(hDropInfo);
}
