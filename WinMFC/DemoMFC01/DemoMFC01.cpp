

#include "DemoMFC01.h"

MyApp app;//全局应用程序对象，有且仅有一个

BOOL MyApp::InitInstance() {
	//创建窗口
	MyFrame* frame = new MyFrame();
	//显示更新
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	this->m_pMainWnd = frame;//保存指向应用程序的主窗口的指针
	return TRUE;
}

MyFrame::MyFrame() {
	Create(NULL, TEXT("爱白菜的小昆虫"));
}