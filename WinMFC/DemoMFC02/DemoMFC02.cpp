
#include "DemoMFC02.h"

MyApp app;

BOOL MyApp::InitInstance() {
	MyFrame* frame = new MyFrame();

	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	this->m_pMainWnd = frame;
	return TRUE;
}


//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()//���������� ӳ�����
	ON_WM_CHAR()//���̰��� ӳ�����
	ON_WM_PAINT()//��ͼ
END_MESSAGE_MAP()

MyFrame::MyFrame() {
	Create(NULL, TEXT("���ײ˵�С����"));
}
//����������
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d, y=%d"), point.x, point.y);

	//MessageBox(buf);

	//MFC�е��ַ���CString
	CString str;
	str.Format(TEXT("x=%d,,,,y=%d"), point.x, point.y);
	//MessageBox(str);
}
//���̰���
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	CString str;
	str.Format(TEXT("������%c��"), nChar);

	MessageBox(str);
}
//��ͼ
void MyFrame::OnPaint() {
	CPaintDC dc(this);//CDC�в�������

	dc.TextOutA(100, 100, TEXT("���ײ˵�С����"));
	//����Բ
	dc.Ellipse(10, 10, 100, 100);
}