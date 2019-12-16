
// DemoMFC03View.cpp: CDemoMFC03View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC03.h"
#endif

#include "DemoMFC03Doc.h"
#include "DemoMFC03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC03View

IMPLEMENT_DYNCREATE(CDemoMFC03View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC03View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CDemoMFC03View 构造/析构

CDemoMFC03View::CDemoMFC03View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC03View::~CDemoMFC03View()
{
}

BOOL CDemoMFC03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC03View 绘图

void CDemoMFC03View::OnDraw(CDC* pDC)
{
	CDemoMFC03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOut(100, 100, TEXT("小昆虫"));
}


// CDemoMFC03View 打印

BOOL CDemoMFC03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC03View 诊断

#ifdef _DEBUG
void CDemoMFC03View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC03Doc* CDemoMFC03View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC03Doc)));
	return (CDemoMFC03Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC03View 消息处理程序


void CDemoMFC03View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox(TEXT("打昆虫"));
	CView::OnLButtonDown(nFlags, point);
}
