
// DemoMFC10View.cpp: CDemoMFC10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC10.h"
#endif

#include "DemoMFC10Doc.h"
#include "DemoMFC10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC10View

IMPLEMENT_DYNCREATE(CDemoMFC10View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDemoMFC10View 构造/析构

CDemoMFC10View::CDemoMFC10View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC10View::~CDemoMFC10View()
{
}

BOOL CDemoMFC10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC10View 绘图

void CDemoMFC10View::OnDraw(CDC* /*pDC*/)
{
	CDemoMFC10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemoMFC10View 打印

BOOL CDemoMFC10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC10View 诊断

#ifdef _DEBUG
void CDemoMFC10View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC10Doc* CDemoMFC10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC10Doc)));
	return (CDemoMFC10Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC10View 消息处理程序
