
#include "DemoMFC02.h"

MyApp app;

BOOL MyApp::InitInstance() {
	MyFrame* frame = new MyFrame();

	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	this->m_pMainWnd = frame;
	return TRUE;
}


//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()//鼠标左键按下 映射入口
	ON_WM_CHAR()//键盘按下 映射入口
	ON_WM_PAINT()//绘图
END_MESSAGE_MAP()

MyFrame::MyFrame() {
	Create(NULL, TEXT("爱白菜的小昆虫"));
}
//鼠标左键按下
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d, y=%d"), point.x, point.y);

	//MessageBox(buf);

	//MFC中的字符串CString
	CString str;
	str.Format(TEXT("x=%d,,,,y=%d"), point.x, point.y);
	//MessageBox(str);
}
//键盘按下
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	CString str;
	str.Format(TEXT("按下了%c键"), nChar);

	MessageBox(str);
}
//绘图
void MyFrame::OnPaint() {
	CPaintDC dc(this);//CDC中查找其他

	dc.TextOutA(100, 100, TEXT("爱白菜的小昆虫"));
	//画椭圆
	dc.Ellipse(10, 10, 100, 100);
}