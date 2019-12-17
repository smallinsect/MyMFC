
// DemoMFC05View.cpp: CDemoMFC05View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC05.h"
#endif

#include "DemoMFC05Doc.h"
#include "DemoMFC05View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC05View

IMPLEMENT_DYNCREATE(CDemoMFC05View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC05View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CDemoMFC05View 构造/析构

CDemoMFC05View::CDemoMFC05View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC05View::~CDemoMFC05View()
{
}

BOOL CDemoMFC05View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC05View 绘图

void CDemoMFC05View::OnDraw(CDC* /*pDC*/)
{
	CDemoMFC05Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemoMFC05View 打印

BOOL CDemoMFC05View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC05View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC05View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC05View 诊断

#ifdef _DEBUG
void CDemoMFC05View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC05View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC05Doc* CDemoMFC05View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC05Doc)));
	return (CDemoMFC05Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC05View 消息处理程序

//窗口创建后自动调用
int CDemoMFC05View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//获取字体信息
	CClientDC dc(this);
	TEXTMETRIC tm;//字体信息结构体
	dc.GetTextMetrics(&tm);

	//设置宽度 高度
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);//创建插入符

	ShowCaret();//显示

	return 0;
}


void CDemoMFC05View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_point = point;

	SetCaretPos(point);

	m_str = TEXT("");
	m_str.Empty();

	CView::OnLButtonDown(nFlags, point);
}

//点击键盘，启动调用
void CDemoMFC05View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);

	if (nChar == VK_RETURN) {//换行
		m_str.Empty();
		TEXTMETRIC tm;//字体信息结构体
		dc.GetTextMetrics(&tm);//获取字体信息
		m_point.y = m_point.y + tm.tmHeight;
	}
	else if (nChar == VK_BACK) {//退格
		//获取背景色
		COLORREF color = dc.GetBkColor();
		//设置字体的颜色
		COLORREF oldColor = dc.SetTextColor(color);
		//白色重新写一次
		dc.TextOut(m_point.x, m_point.y, m_str);
		//去掉最后一个字符
		m_str = m_str.Left(m_str.GetLength() - 1);
		//恢复颜色
		dc.SetTextColor(oldColor);
	}
	else {
		m_str += (TCHAR)nChar;
	}

	CSize size = dc.GetTextExtent(m_str);//获取字符串长度
	int x = m_point.x + size.cx;
	int y = m_point.y;
	SetCaretPos(CPoint(x, y));
	dc.TextOut(m_point.x, m_point.y, m_str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
