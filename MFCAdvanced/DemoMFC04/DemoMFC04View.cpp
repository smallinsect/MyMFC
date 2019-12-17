
// DemoMFC04View.cpp: CDemoMFC04View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC04.h"
#endif

#include "DemoMFC04Doc.h"
#include "DemoMFC04View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC04View

IMPLEMENT_DYNCREATE(CDemoMFC04View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC04View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDemoMFC04View 构造/析构

CDemoMFC04View::CDemoMFC04View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC04View::~CDemoMFC04View()
{
}

BOOL CDemoMFC04View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC04View 绘图

void CDemoMFC04View::OnDraw(CDC* pDC)
{
	CDemoMFC04Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen pen(PS_DASH, 1, RGB(255, 0, 255));

	CPen* oldPen = (CPen*)pDC->SelectObject(&pen);

	pDC->TextOut(100, 200, TEXT("小昆虫"));
	pDC->LineTo(100, 100);

	pDC->MoveTo(200, 200);
	pDC->LineTo(500, 500);
	pDC->SelectObject(oldPen);//恢复画笔

	//画刷
	CBrush brush(RGB(255, 0, 255));

	//将创建好的画刷给画家
	CBrush* oldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Ellipse(20, 20, 200, 200);

	pDC->SelectObject(oldBrush);//恢复画笔

	//定义一个位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);

	CBrush brushBitmap(&bitmap);
	oldBrush = (CBrush*)pDC->SelectObject(&brushBitmap);

	pDC->Ellipse(200, 200, 400, 400);

	pDC->SelectObject(oldBrush);//恢复画笔

	CFont font;
	font.CreatePointFont(1000, TEXT("楷体"));
	CFont* oldFont = (CFont*)pDC->SelectObject(&font);

	pDC->TextOut(300, 300, TEXT("爱白菜的小昆虫"));

	pDC->SelectObject(oldFont);//恢复画笔
}


// CDemoMFC04View 打印

BOOL CDemoMFC04View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC04View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC04View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC04View 诊断

#ifdef _DEBUG
void CDemoMFC04View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC04View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC04Doc* CDemoMFC04View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC04Doc)));
	return (CDemoMFC04Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC04View 消息处理程序


void CDemoMFC04View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString str;
	str.Format(TEXT("%c"), nChar);
	MessageBox(str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CDemoMFC04View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_point = point;//保存的坐标
	m_press = true;//鼠标左键按下
	CView::OnLButtonDown(nFlags, point);
}


void CDemoMFC04View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CClientDC dc(this);
	//dc.MoveTo(m_point);
	//dc.LineTo(point);

	m_press = false;//鼠标抬起
	CView::OnLButtonUp(nFlags, point);
}


void CDemoMFC04View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_press) {
		CClientDC dc(this);//创建画家，指定绘画设备
		dc.MoveTo(m_point);
		dc.LineTo(point);

		m_point = point;//终点作为起点
	}

	CView::OnMouseMove(nFlags, point);
}
