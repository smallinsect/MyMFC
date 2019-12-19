// MyButton.cpp: 实现文件
//

#include "stdafx.h"
#include "DemoMFC11.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton 消息处理程序
void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x = rand() % 300;
	int y = rand() % 300;

	//获取按钮位置
	RECT rect;
	this->GetWindowRect(&rect);
	//按钮移动
	this->MoveWindow(x, y, rect.right - rect.left, rect.bottom - rect.top);

	CButton::OnMouseMove(nFlags, point);
}
