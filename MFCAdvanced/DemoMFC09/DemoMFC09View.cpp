
// DemoMFC09View.cpp: CDemoMFC09View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC09.h"
#endif

#include "DemoMFC09Doc.h"
#include "DemoMFC09View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC09View

IMPLEMENT_DYNCREATE(CDemoMFC09View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC09View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDemoMFC09View 构造/析构

CDemoMFC09View::CDemoMFC09View() noexcept
{
	// TODO: 在此处添加构造代码
	hicon[0] = AfxGetApp()->LoadIcon(IDI_ICON1);
	hicon[1] = AfxGetApp()->LoadIcon(IDI_ICON2);
	hicon[2] = AfxGetApp()->LoadIcon(IDI_ICON3);
	hicon[3] = AfxGetApp()->LoadIcon(IDI_ICON4);
	hicon[4] = AfxGetApp()->LoadIcon(IDI_ICON5);
	hicon[5] = AfxGetApp()->LoadIcon(IDI_ICON6);
	hicon[6] = AfxGetApp()->LoadIcon(IDI_ICON7);
}

CDemoMFC09View::~CDemoMFC09View()
{
}

BOOL CDemoMFC09View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC09View 绘图

void CDemoMFC09View::OnDraw(CDC* pDC)
{
	CDemoMFC09Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < 7; ++i) {
		pDC->DrawIcon(10, i*50, hicon[i]);
	}
}


// CDemoMFC09View 打印

BOOL CDemoMFC09View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC09View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC09View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC09View 诊断

#ifdef _DEBUG
void CDemoMFC09View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC09View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC09Doc* CDemoMFC09View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC09Doc)));
	return (CDemoMFC09Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC09View 消息处理程序
