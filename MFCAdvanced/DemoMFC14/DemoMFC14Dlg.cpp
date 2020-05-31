
// DemoMFC14Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DemoMFC14.h"
#include "DemoMFC14Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemoMFC14Dlg 对话框



CDemoMFC14Dlg::CDemoMFC14Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMOMFC14_DIALOG, pParent)
	, m_input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoMFC14Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}

BEGIN_MESSAGE_MAP(CDemoMFC14Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDemoMFC14Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDemoMFC14Dlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDemoMFC14Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDemoMFC14Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDemoMFC14Dlg 消息处理程序

BOOL CDemoMFC14Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDemoMFC14Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemoMFC14Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemoMFC14Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemoMFC14Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取编辑区
	UpdateData(TRUE);

	if (m_input.GetLength() == 0) {
		MessageBox(TEXT("编辑区不能为空"));
		return;
	}
	//添加listbox数据
	m_listbox.AddString(m_input);
	//清空数据
	m_input.Empty();
	//将内容更新到编辑区
	UpdateData(FALSE);
}


void CDemoMFC14Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取当前选中的行
	int idx = m_listbox.GetCurSel();
	//删除指定的行
	m_listbox.DeleteString(idx);
}


void CDemoMFC14Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取当前选中的行
	int idx = m_listbox.GetCurSel();
	//获取选中的内容
	m_listbox.GetText(idx, m_input);
	//将内容更新到编辑区
	UpdateData(FALSE);
}


void CDemoMFC14Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取编辑区
	UpdateData(TRUE);
	if (m_input.GetLength() == 0) {
		MessageBox(TEXT("内容不能为空"));
		return;
	}
	//获取当前选中行
	int idx = m_listbox.GetCurSel();
	//删除当前选中行
	m_listbox.DeleteString(idx);
	//插入当前行新数据
	m_listbox.InsertString(idx, m_input);
	//内容更新到编辑区
	UpdateData(FALSE);
}
