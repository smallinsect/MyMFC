
#include <SDKDDKVer.h>
#include <afxwin.h>


//1��Ӧ�ó��� CWinApp
class MyApp : public CWinApp {
public:
	//������麯��
	//������ֻ����д
	//MFC�������ڵ�ַ
	virtual BOOL InitInstance();

private:

};

//2������� CFrameWnd
class MyFrame : public CFrameWnd {
public:
	MyFrame();

	// ������Ϣӳ���
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
};

//������Ϣ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

//������ڵ�ַ
BOOL MyApp::InitInstance() {

	//������������
	MyFrame *frame = new MyFrame();
	//��ʾ����
	frame->ShowWindow(SW_SHOWNORMAL);
	//���´���
	frame->UpdateWindow();

	m_pMainWnd = frame;
	return TRUE;
}

//����ֻ��һ��ȫ�ֵ����ó������
MyApp myApp;

MyFrame::MyFrame() {
	//CWnd��ĳ�Ա����
	//CFrameWnd�̳���CWnd
	Create(NULL, TEXT("С����"));
}

void MyFrame::OnPaint() {
	CPaintDC cdc(this);
	cdc.TextOut(100, 100, TEXT("С����"));
}

void MyFrame::OnLButtonDown(UINT, CPoint) {
	MessageBox(TEXT("���ײ˵�С����"));
}
