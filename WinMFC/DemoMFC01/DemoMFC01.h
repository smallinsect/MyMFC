#pragma once

#include <SDKDDKVer.h>
//mfcͷ�ļ�
#include <afxwin.h>

class MyApp : public CWinApp {//CWinAppӦ�ó�����
public:
	//�������
	virtual BOOL InitInstance();
};

class MyFrame : public CFrameWnd {//CFrameWnd ���ڿ����
public:
	MyFrame();
};
