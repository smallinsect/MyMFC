// CDlgLogin.cpp: 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "CDlgLogin.h"
#include "afxdialogex.h"


// CDlgLogin 对话框

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgLogin::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDlgLogin 消息处理程序

//登录按钮
void CDlgLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//登录按钮拿到最新的值
	UpdateData(TRUE);

	if (m_user.IsEmpty() || m_pwd.IsEmpty()) {
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
	//获取正确的值

	CString name("小昆虫");
	CString pwd("123456");
	if (name != m_user) {
		MessageBox(TEXT("用户名错误"));
		return;
	}
	if (pwd != m_pwd) {
		MessageBox(TEXT("密码错误"));
		return;
	}
	//关闭当前的对话框
	CDialog::OnCancel();
}

//取消按钮
void CDlgLogin::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


BOOL CDlgLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_user = TEXT("小昆虫");
	m_pwd = TEXT("123456");
	//同步到控件中
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgLogin::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	//注释掉 防止按回车 进入下一个页面
	//CDialogEx::OnOK();
}


void CDlgLogin::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//关闭当前对话框
	//CDialogEx::OnClose();
	//退出当前程序
	exit(0);
}
