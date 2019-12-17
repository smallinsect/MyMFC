
// DemoMFC07View.cpp: CDemoMFC07View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC07.h"
#endif

#include "DemoMFC07Doc.h"
#include "DemoMFC07View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC07View

IMPLEMENT_DYNCREATE(CDemoMFC07View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC07View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_DEMO, &CDemoMFC07View::OnTestDemo)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CDemoMFC07View 构造/析构

CDemoMFC07View::CDemoMFC07View() noexcept
{
	// TODO: 在此处添加构造代码

	menu.LoadMenu(IDR_MENU1);
}

CDemoMFC07View::~CDemoMFC07View()
{
}

BOOL CDemoMFC07View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC07View 绘图

void CDemoMFC07View::OnDraw(CDC* /*pDC*/)
{
	CDemoMFC07Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemoMFC07View 打印

BOOL CDemoMFC07View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC07View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC07View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC07View 诊断

#ifdef _DEBUG
void CDemoMFC07View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC07View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC07Doc* CDemoMFC07View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC07Doc)));
	return (CDemoMFC07Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC07View 消息处理程序


void CDemoMFC07View::OnTestDemo()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(TEXT("view"));
}


void CDemoMFC07View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//坐标转换
	ClientToScreen(&point);

	//获取子菜单
	CMenu* subMenu = menu.GetSubMenu(0);
	//子菜单作为快捷菜单，右击菜单
	subMenu->TrackPopupMenu(TPM_LEFTALIGN| TPM_LEFTBUTTON, 
		point.x, point.y, this);


	CView::OnLButtonDown(nFlags, point);
}
