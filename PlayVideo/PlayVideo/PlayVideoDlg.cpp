
// PlayVideoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PlayVideo.h"
#include "PlayVideoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlayVideoDlg �Ի���




CPlayVideoDlg::CPlayVideoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayVideoDlg::IDD, pParent)
	, TheImage(NULL)
	, vPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayVideoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlayVideoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CPlayVideoDlg::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_ShowImg, &CPlayVideoDlg::OnStnClickedShowimg)
	ON_BN_CLICKED(IDC_ReadImg_Button, &CPlayVideoDlg::OnBnClickedReadimgButton)
	ON_BN_CLICKED(IDC_EdgeDetect_Button, &CPlayVideoDlg::OnBnClickedEdgedetectButton)
	ON_BN_CLICKED(IDC_ReadVideo_Button, &CPlayVideoDlg::OnBnClickedReadvideoButton)
	ON_BN_CLICKED(IDC_Play_Button, &CPlayVideoDlg::OnBnClickedPlayButton)
END_MESSAGE_MAP()


// CPlayVideoDlg ��Ϣ�������

BOOL CPlayVideoDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CvSize ImgSize;
	ImgSize.height=IMAGE_HEIGHT;
	ImgSize.width=IMAGE_WIDTH;
	TheImage=cvCreateImage(ImgSize,IPL_DEPTH_8U,3);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPlayVideoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPlayVideoDlg::OnPaint()
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
		CDialog::OnPaint();//�ػ�Ի���
		CDialog::UpdateWindow();//���´��ڣ�û�ⲿ���ã�ͼ����ʾ������
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPlayVideoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPlayVideoDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPlayVideoDlg::OnStnClickedShowimg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPlayVideoDlg::OnBnClickedReadimgButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(
		TRUE,_T("*.bmp"),NULL,
		OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,
		_T("image files(*.bmp;*.jpg)|*.bmp;*.jpg|All Files(*.*)|*.*||"),
		NULL
		);//ѡ��ͼƬԼ��
	dlg.m_ofn.lpstrTitle=_T("Open Image");
	if (dlg.DoModal()!=IDOK) {MessageBox(_T("no picture"));}
	CString mPath=dlg.GetPathName();
	IplImage* ipl=cvLoadImage(mPath,1);
	if (!ipl) return;

	if(TheImage) cvZero(TheImage);

	ResizeImage(ipl);
	ShowImage(TheImage,IDC_ShowImg);
	cvReleaseImage(&ipl);;
}


void CPlayVideoDlg::ShowImage(IplImage* img,UINT ID)
{
	CDC* pDC=GetDlgItem(ID)->GetDC();//�����ʵ�ؼ���DC
	HDC hDC=pDC->GetSafeHdc();//��ȡHDC���豸����������л�ͼ����
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	int rw=rect.right-rect.left;
	int rh=rect.bottom-rect.top;
	int iw=img->width;
	int ih=img->height;
	int tx=(int)(rw-iw)/2;//��ͼƬ��ʾλ�������ڿؼ�������
	int ty=(int)(rh-ih)/2;

	SetRect(rect,tx,ty,tx+iw,ty+ih);
	CvvImage cimg;
	cimg.CopyOf(img);
	cimg.DrawToHDC(hDC,&rect);

	ReleaseDC(pDC);
	

}


void CPlayVideoDlg::ResizeImage(IplImage* img)
{
	//��ȡͼƬ�Ŀ�͸�
	int w=img->width;
	int h=img->height;
	//�ҳ���͸ߵĽϴ���
	int max=(w>h)?w:h;
	//���㽫ͼƬ���ŵ�TheImage ��������ı�������
	float scale=(float)((float)max/256.0f);
	//���Ž�ͼƬ���ŵ�TheImage��������Ҫ�ı�������
	int nw=(int)(w/scale);
	int nh=(int)(h/scale);

	//Ϊ�˽����ź��ͼƬ����TheImage���в�λ����Ҫ����ͼƬ��THeImage���Ͻ�
	//��������ֵ
	int tlx=(nw>nh)?0:(int)(256-nw)/2;
	int tly=(nw>nh)?(int)(256-nh)/2:0;
	//����TheImage��ROI������������ͼƬimg
	cvSetImageROI(TheImage,cvRect(tlx,tly,nw,nh) );
	//��ͼƬimg�������ţ�������TheImage��
	cvResize(img,TheImage);

	//����TheImage��ROI׼��������һ��ͼƬ
	cvResetImageROI(TheImage);
}


void CPlayVideoDlg::OnBnClickedEdgedetectButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	IplImage* gray=0,*edge=0;
	gray=cvCreateImage(cvSize(IMAGE_WIDTH,IMAGE_HEIGHT),IPL_DEPTH_8U,1);
	edge=cvCreateImage(cvSize(IMAGE_WIDTH,IMAGE_HEIGHT),IPL_DEPTH_8U,1);
	cvCvtColor(TheImage,gray,CV_BGR2GRAY);
	cvCanny(gray,edge,30,100,3);

	cvCvtColor(edge,TheImage,CV_GRAY2BGR);
	ShowImage(TheImage,IDC_ShowImg);

	cvReleaseImage(&gray);
	cvReleaseImage(&edge);
}

/************************************************************************/
/* ������Ƶ����                                                                     */
/************************************************************************/
void CPlayVideoDlg::OnBnClickedReadvideoButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//cvZero()
	CFileDialog dlg(
		TRUE,
		_T("*.avi"),
		NULL,
		OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,
		_T("*.avi|*.avi| All Files(*.*)|(*.*)||"),
		NULL
		);
		dlg.m_ofn.lpstrTitle=_T("Open Video");
		if (dlg.DoModal()!=IDOK)
			return;
		vPath=dlg.GetPathName();
		//ʹ�޹ذ�ť��Ч
		GetDlgItem(IDC_Play_Button)->EnableWindow(TRUE);
		GetDlgItem(IDC_ReadImg_Button)->EnableWindow(FALSE);
		//ʹ��һ֡�Ļ�����ʾ�ڿؼ���
		CvCapture* myCapture=cvCreateFileCapture(vPath);
		IplImage* myImage=cvQueryFrame(myCapture);
		ResizeImage(myImage);
		ShowImage(TheImage,IDC_ShowImg);
		//cvReleaseImage(&myImage);
		cvReleaseCapture(&myCapture);;
}


void CPlayVideoDlg::OnBnClickedPlayButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CvCapture *pCapture=NULL;
	IplImage* pFrame=NULL;
	if (vPath==" ")
	{
		MessageBox("��ѡ����Ƶ�ļ�");
		return;
	}else
	{
		if (!(pCapture=cvCreateFileCapture(vPath)))
		{
			MessageBox("����Ƶ�ļ�ʧ��");
			return;
		}
	}
	//������Ƶʱ�����ͼƬ����Ƶ���Լ����Ű�ťʧЧ
	GetDlgItem(IDC_ReadImg_Button)->EnableWindow(FALSE);
	GetDlgItem(IDC_ReadVideo_Button)->EnableWindow(FALSE);
	GetDlgItem(IDC_Play_Button)->EnableWindow(FALSE);
	GetDlgItem(IDC_EdgeDetect_Button)->EnableWindow(FALSE);
	
	/************************************************************************/
	/* �������δ��벻̫����                                                                     */
	/************************************************************************/
	cvNamedWindow("videoSmile");
	cvResizeWindow("videoSmile",1,1);
	HWND hWnd=(HWND)cvGetWindowHandle("videoSmile");
	HWND hParent=::GetParent(hWnd);
	HWND hwnd1=::FindWindow("CmymfcDlg","PlayVideo");
	::SetParent(hWnd,hwnd1);
	::ShowWindow(hParent,SW_HIDE);

	//��ȡ��Ƶ�ļ���֡��
	int frames=(int)cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_COUNT);
	int numfrm=0;
	//����������
	if (TheImage)
		cvZero(TheImage);

	m_run=1;
	while ( (numfrm<frames)&(m_run==1))
	{
		pFrame=cvQueryFrame(pCapture);
		IplImage* newframe=cvCloneImage(pFrame);
		ResizeImage(newframe); //�������������ʹ����Ϊ�봰���м� ������������Ѿ���newframe cvResize��TheImage����
		ShowImage(TheImage,IDC_ShowImg);
		/************************************************************************/
		/* ����ط��Ӹ��洢֡�Ĺ���  ��δ�ӣ�                                                                   */
		/************************************************************************/
		if (cvWaitKey(20)==27) break;
		numfrm++;
		cvReleaseImage(&newframe);
	}
	m_run=0;

	//��ͼ����������
	if (TheImage)
	{
		cvZero(TheImage);
		ShowImage(TheImage,IDC_ShowImg);
	}

	GetDlgItem(IDC_ReadImg_Button)->EnableWindow(TRUE);
	GetDlgItem(IDC_ReadVideo_Button)->EnableWindow(TRUE);
	GetDlgItem(IDC_Play_Button)->EnableWindow(TRUE);

	cvReleaseCapture(&pCapture);
	cvDestroyWindow("videoSmile");

	return ;

}
