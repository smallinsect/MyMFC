#include <windows.h>

HINSTANCE hinst;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	static TCHAR szClassName[] = TEXT("MainWClass");
	WNDCLASSEX wcx;//������
	HWND hwnd;//���ھ��
	MSG msg;//��Ϣ
	hinst = hInstance;//Ӧ�ó���ʵ�����������Ϊȫ�ֱ�����

	//1����䴰��������ݽṹ
	wcx.cbSize = sizeof(wcx);//�ṹ���С
	wcx.style = CS_HREDRAW | CS_VREDRAW;//��ʽ�����ڴ�С�ı�ʱ�ػ����
	wcx.lpfnWndProc = MainWndProc;//������Ϣ������
	wcx.cbClsExtra = 0;//��ʹ�����ڴ�
	wcx.cbWndExtra = 0;//��ʹ�ô����ڴ�
	wcx.hInstance = hInstance;//������Ӧ�ó���ʵ�����
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ͼ�꣺Ĭ��
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);//��꣺Ĭ��
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��������ɫ
	wcx.lpszMenuName = NULL;//�˵�����ʹ��
	wcx.lpszClassName = szClassName;//��������
	wcx.hIconSm = (HICON)LoadImage(hInstance,
		MAKEINTRESOURCE(5),
		IMAGE_ICON,
		GetSystemMetrics(SM_CXSMICON),
		GetSystemMetrics(SM_CYSMICON),
		LR_DEFAULTCOLOR);//Сͼ��

	//2��ע�ᴰ��
	if (!RegisterClassEx(&wcx))
	{
		return 1;
	}

	//3����������
	hwnd = CreateWindow(
		szClassName,//������
		TEXT("BASE"),//���ڱ���
		WS_OVERLAPPEDWINDOW,//������ʽ
		CW_USEDEFAULT,//ˮƽλ��X��Ĭ��
		CW_USEDEFAULT,//��ֱλ��Y��Ĭ��
		CW_USEDEFAULT,//��ȣ�Ĭ��
		CW_USEDEFAULT,//�߶ȣ�Ĭ��
		NULL,//�����ڣ���
		NULL,//�˵���ʹ�ô�����Ĳ˵�
		hInstance,//Ӧ�ó���ʵ�����
		NULL//���ڴ���ʱ���ݣ���
	);

	if (!hwnd)
	{
		return 1;
	}

	//4����ʾ���ں͸��´���
	ShowWindow(hwnd, nCmdShow);//SW_SHOWNORMAL
	UpdateWindow(hwnd);
	//msg
	//HWND        hwnd;���ھ��
	//UINT        message;������Ϣ����
	//WPARAM      wParam;������Ϣ ������Ϣ
	//LPARAM      lParam;������Ϣ �����Ϣ
	//DWORD       time;��Ϣ����ʱ��
	//POINT       pt;������Ϣ �����Ϣ x y
	//5����Ϣѭ�� GetMessage
	//LPMSG lpMsg, ��Ϣ
	//HWND hWnd, ���������Ϣ����NULL���������д���
	//UINT wMsgFilterMin, ��С��������Ϣ���ˣ�һ����0
	//UINT wMsgFilterMax ��0������������Ϣ
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//������Ϣ
		DispatchMessage(&msg);//�ַ���Ϣ
	}

	return 0;
}

//CALLBACK __stdcall
//DefWindowProcA(
//	_In_ HWND hWnd,//��Ϣ�����Ĵ��ھ��
//	_In_ UINT Msg,//������Ϣ����
//	_In_ WPARAM wParam,//���̸�����Ϣ
//	_In_ LPARAM lParam);//��긽����Ϣ
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam)
{
	static int xPos, yPos;
	static HDC hdc;
	static TCHAR buf[1024];
	static INT len;
	PAINTSTRUCT ps;
	switch (umsg)
	{
	case WM_LBUTTONDOWN:
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		hdc = GetDC(hwnd);
		len = wsprintf(buf, TEXT("xPos=%d yPos=%d"), xPos, yPos);
		//TextOut(hdc, 0, 0, buf, len);
		MessageBox(hwnd, buf, TEXT("��ʾ"), MB_OK);

		ReleaseDC(hwnd, hdc);
		break;
	case WM_PAINT://��ͼ
		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN://���̰���
		MessageBox(hwnd, TEXT("����"), TEXT("��ʾ"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	//case WM_CLOSE:
	//	DestroyWindow(hwnd);//������һ����ϢWM_DESTROY
	//	break;
	}
	return DefWindowProc(hwnd, umsg, wParam, lParam);
}