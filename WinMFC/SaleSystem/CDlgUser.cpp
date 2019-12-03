// CDlgUser.cpp: 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "CDlgUser.h"
#include "afxdialogex.h"


// CDlgUser 对话框

IMPLEMENT_DYNCREATE(CDlgUser, CFormView)

CDlgUser::CDlgUser()
	: CFormView(IDD_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CDlgUser::~CDlgUser()
{
}

void CDlgUser::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}


BEGIN_MESSAGE_MAP(CDlgUser, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgUser::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgUser::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgUser 消息处理程序

//确认密码按钮
void CDlgUser::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//拿到最新的值
	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty()) {
		MessageBox(TEXT("密码输入不能为空"));
		return;
	}
	if (m_newPwd != m_surePwd) {
		MessageBox(TEXT("新密码和确认密码不一致"));
		return;
	}
	MessageBox(TEXT("修改密码成功"));
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);//同步数据
}

//取消密码按钮
void CDlgUser::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);//同步数据
}


void CDlgUser::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//初始化

	m_user = TEXT("管理员");
	m_name = TEXT("小白菜");

	UpdateData(FALSE);
}
