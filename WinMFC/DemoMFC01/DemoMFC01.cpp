

#include "DemoMFC01.h"

MyApp app;//ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance() {
	//��������
	MyFrame* frame = new MyFrame();
	//��ʾ����
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	this->m_pMainWnd = frame;//����ָ��Ӧ�ó���������ڵ�ָ��
	return TRUE;
}

MyFrame::MyFrame() {
	Create(NULL, TEXT("���ײ˵�С����"));
}