
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "SaleSystem.h"

#include "MainFrm.h"
#include "CSelectView.h"
#include "CDisplayView.h"
#include "CDlgUser.h"
#include "CDlgSell.h"
#include "CDlgAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//ON_MESSAGE相应的是自定义消息
	//产生NM_X消息，自动调用OnMyChange函数
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//修改图标
	//SetClassLong(m_hWnd, GCLP_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_COCOS));
	SetClassLongPtr(m_hWnd, GCLP_HICON, (LONG_PTR)AfxGetApp()->LoadIconW(IDI_COCOS));
	//设置标题 右侧的标题
	SetTitle(TEXT("2019/12/03"));
	//设置左边的标题提
	//SetTitle(TEXT("销售管理系统"));

	//设置窗口大小
	MoveWindow(0, 0, 800, 500);
	//居中显示
	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	//才分一行两列
	m_splitter.CreateStatic(this, 1, 2);
	//左侧和右侧具体的显示内容
	//创建0行0列和0行1列的数据
	m_splitter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200,500), pContext);
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);

	return TRUE;
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam) {
	CCreateContext context;
	if (wParam == NM_A) {
		//MessageBox(TEXT("个人信息"));
		context.m_pNewViewClass = RUNTIME_CLASS(CDlgUser);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgUser), CSize(600, 500), &context);
		CDlgUser* pNewView = (CDlgUser*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
	else if (wParam == NM_B) {
		//MessageBox(TEXT("销售管理"));
		context.m_pNewViewClass = RUNTIME_CLASS(CDlgSell);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgSell), CSize(600, 500), &context);
		CDlgSell* pNewView = (CDlgSell*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
	else if (wParam == NM_C) {
		//MessageBox(TEXT("库存信息"));
		context.m_pNewViewClass = RUNTIME_CLASS(CDlgAdd);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgAdd), CSize(600, 500), &context);
		CDlgAdd* pNewView = (CDlgAdd*)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
	else if (wParam == NM_D) {
		//MessageBox(TEXT("库存添加"));
	}
	else if (wParam == NM_E) {
		//MessageBox(TEXT("存储删除"));
	}
	return 0;
}

void CMainFrame::On32771()
{
	// TODO: 在此添加命令处理程序代码
	//退出按钮
	exit(0);
}

//个人信息
void CMainFrame::On32772()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
}


void CMainFrame::On32773()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CMainFrame::On32774()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CMainFrame::On32775()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
}


void CMainFrame::On32776()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
}
