
// DemoMFC08View.cpp: CDemoMFC08View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC08.h"
#endif

#include "DemoMFC08Doc.h"
#include "DemoMFC08View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC08View

IMPLEMENT_DYNCREATE(CDemoMFC08View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC08View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDemoMFC08View 构造/析构

CDemoMFC08View::CDemoMFC08View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC08View::~CDemoMFC08View()
{
}

BOOL CDemoMFC08View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC08View 绘图

void CDemoMFC08View::OnDraw(CDC* /*pDC*/)
{
	CDemoMFC08Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemoMFC08View 打印

BOOL CDemoMFC08View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC08View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC08View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC08View 诊断

#ifdef _DEBUG
void CDemoMFC08View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC08View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC08Doc* CDemoMFC08View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC08Doc)));
	return (CDemoMFC08Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC08View 消息处理程序
