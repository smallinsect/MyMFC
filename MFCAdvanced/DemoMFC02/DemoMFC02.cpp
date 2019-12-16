
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

	// 声明消息映射宏
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
};

//定义消息宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

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

void MyFrame::OnPaint() {
	CPaintDC cdc(this);
	cdc.TextOut(100, 100, TEXT("小昆虫"));
}

void MyFrame::OnLButtonDown(UINT, CPoint) {
	MessageBox(TEXT("爱白菜的小昆虫"));
}
