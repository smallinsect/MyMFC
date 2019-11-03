
// StudyMFCView.cpp: CStudyMFCView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudyMFC.h"
#endif

#include "StudyMFCDoc.h"
#include "StudyMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudyMFCView

IMPLEMENT_DYNCREATE(CStudyMFCView, CView)

BEGIN_MESSAGE_MAP(CStudyMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CStudyMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CStudyMFCView 构造/析构

CStudyMFCView::CStudyMFCView() noexcept
{
	// TODO: 在此处添加构造代码

}

CStudyMFCView::~CStudyMFCView()
{
}

BOOL CStudyMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudyMFCView 绘图

void CStudyMFCView::OnDraw(CDC* /*pDC*/)
{
	CStudyMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudyMFCView 打印


void CStudyMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CStudyMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudyMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudyMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CStudyMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStudyMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CStudyMFCView 诊断

#ifdef _DEBUG
void CStudyMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CStudyMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudyMFCDoc* CStudyMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudyMFCDoc)));
	return (CStudyMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudyMFCView 消息处理程序
