#include <windows.h>

HINSTANCE hinst;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	static TCHAR szClassName[] = TEXT("MainWClass");
	WNDCLASSEX wcx;//窗口类
	HWND hwnd;//窗口句柄
	MSG msg;//消息
	hinst = hInstance;//应用程序实例句柄，保存为全局变量。

	//1、填充窗口类的数据结构
	wcx.cbSize = sizeof(wcx);//结构体大小
	wcx.style = CS_HREDRAW | CS_VREDRAW;//样式：窗口大小改变时重绘界面
	wcx.lpfnWndProc = MainWndProc;//窗口消息处理函数
	wcx.cbClsExtra = 0;//不使用类内存
	wcx.cbWndExtra = 0;//不使用窗口内存
	wcx.hInstance = hInstance;//所属的应用程序实例句柄
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);//图标：默认
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);//光标：默认
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景：白色
	wcx.lpszMenuName = NULL;//菜单：不使用
	wcx.lpszClassName = szClassName;//窗口类名
	wcx.hIconSm = (HICON)LoadImage(hInstance,
		MAKEINTRESOURCE(5),
		IMAGE_ICON,
		GetSystemMetrics(SM_CXSMICON),
		GetSystemMetrics(SM_CYSMICON),
		LR_DEFAULTCOLOR);//小图标

	//2、注册窗口
	if (!RegisterClassEx(&wcx))
	{
		return 1;
	}

	//3、创建窗口
	hwnd = CreateWindow(
		szClassName,//窗口名
		TEXT("BASE"),//窗口标题
		WS_OVERLAPPEDWINDOW,//窗口样式
		CW_USEDEFAULT,//水平位置X：默认
		CW_USEDEFAULT,//垂直位置Y：默认
		CW_USEDEFAULT,//宽度：默认
		CW_USEDEFAULT,//高度：默认
		NULL,//父窗口：无
		NULL,//菜单：使用窗口类的菜单
		hInstance,//应用程序实例句柄
		NULL//窗口创建时数据：无
	);

	if (!hwnd)
	{
		return 1;
	}

	//4、显示窗口和更新窗口
	ShowWindow(hwnd, nCmdShow);//SW_SHOWNORMAL
	UpdateWindow(hwnd);
	//msg
	//HWND        hwnd;窗口句柄
	//UINT        message;具体消息名称
	//WPARAM      wParam;附加消息 键盘消息
	//LPARAM      lParam;附加消息 鼠标消息
	//DWORD       time;消息产生时间
	//POINT       pt;附加消息 鼠标消息 x y
	//5、消息循环 GetMessage
	//LPMSG lpMsg, 消息
	//HWND hWnd, 捕获窗体的消息，填NULL代表捕获所有窗口
	//UINT wMsgFilterMin, 最小和最大的消息过滤，一般填0
	//UINT wMsgFilterMax 填0，捕获所有消息
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//翻译消息
		DispatchMessage(&msg);//分发消息
	}

	return 0;
}

//CALLBACK __stdcall
//DefWindowProcA(
//	_In_ HWND hWnd,//消息所属的窗口句柄
//	_In_ UINT Msg,//具体消息名称
//	_In_ WPARAM wParam,//键盘附加消息
//	_In_ LPARAM lParam);//鼠标附加消息
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
		MessageBox(hwnd, buf, TEXT("提示"), MB_OK);

		ReleaseDC(hwnd, hdc);
		break;
	case WM_PAINT://画图
		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN://键盘按下
		MessageBox(hwnd, TEXT("键盘"), TEXT("提示"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	//case WM_CLOSE:
	//	DestroyWindow(hwnd);//发送另一个消息WM_DESTROY
	//	break;
	}
	return DefWindowProc(hwnd, umsg, wParam, lParam);
}