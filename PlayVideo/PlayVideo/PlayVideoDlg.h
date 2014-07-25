
// PlayVideoDlg.h : ͷ�ļ�
//

#pragma once


// CPlayVideoDlg �Ի���
class CPlayVideoDlg : public CDialogEx
{
// ����
public:
	CPlayVideoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PLAYVIDEO_DIALOG };

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
	IplImage* TheImage;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedShowimg();
	afx_msg void OnBnClickedReadimgButton();
	void ShowImage(IplImage* img,UINT ID);
	void ResizeImage(IplImage* img);
	afx_msg void OnBnClickedEdgedetectButton();
	afx_msg void OnBnClickedReadvideoButton();
	afx_msg void OnBnClickedPlayButton();
private:
	CString vPath;
	int m_run;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//void PaintFontColor(int ID_CTL);
private:
//	COLORREF m_rgbFontColor;
public:
	afx_msg void OnBnClickedCancel();
};
