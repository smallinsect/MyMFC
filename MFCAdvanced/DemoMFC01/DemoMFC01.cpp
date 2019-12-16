
#include <SDKDDKVer.h>
#include <afxwin.h>


//1、应用程序 CWinApp
class MyApp : public CWinApp {
public:
	//基类的虚函数
	//派生类只是重写
	//MFC程序的入口地址
	virtual BOOL InitInstance();

private:

};
//2、框架类 CFrameWnd
class MyFrame : public CFrameWnd {
public:
	MyFrame();
private:

};

//程序入口地址
BOOL MyApp::InitInstance() {

	//创建框架类对象
	MyFrame *frame = new MyFrame();
	//显示窗口
	frame->ShowWindow(SW_SHOWNORMAL);
	//更新窗口
	frame->UpdateWindow();

	m_pMainWnd = frame;
	return TRUE;
}

//有且只有一个全局的引用程序对象
MyApp myApp;

MyFrame::MyFrame() {
	//CWnd类的成员函数
	//CFrameWnd继承与CWnd
	Create(NULL, TEXT("小昆虫"));
}


