#pragma once

#include <SDKDDKVer.h>
#include <afxwin.h>

class MyApp : public CWinApp{

public:
	virtual BOOL InitInstance();

};

class MyFrame :public CFrameWnd {
public:
	MyFrame();
};