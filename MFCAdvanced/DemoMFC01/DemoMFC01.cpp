
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
private:

};

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


