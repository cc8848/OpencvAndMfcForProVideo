
// PlayVideo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
//����
#include "CvvImage.h"
#include "cv.h"
#include "highgui.h"
#define  IMAGE_WIDTH 256
#define  IMAGE_HEIGHT 256
#define  IMAGE_CHANNELS 3

// CPlayVideoApp:
// �йش����ʵ�֣������ PlayVideo.cpp
//

class CPlayVideoApp : public CWinApp
{
public:
	CPlayVideoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPlayVideoApp theApp;