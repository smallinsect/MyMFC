
// DemoMFC06View.cpp: CDemoMFC06View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC06.h"
#endif

#include "DemoMFC06Doc.h"
#include "DemoMFC06View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC06View

IMPLEMENT_DYNCREATE(CDemoMFC06View, CView)

BEGIN_MESSAGE_MAP(CDemoMFC06View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDemoMFC06View 构造/析构

CDemoMFC06View::CDemoMFC06View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemoMFC06View::~CDemoMFC06View()
{
}

BOOL CDemoMFC06View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoMFC06View 绘图

void CDemoMFC06View::OnDraw(CDC* /*pDC*/)
{
	CDemoMFC06Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemoMFC06View 打印

BOOL CDemoMFC06View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoMFC06View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoMFC06View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDemoMFC06View 诊断

#ifdef _DEBUG
void CDemoMFC06View::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFC06View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFC06Doc* CDemoMFC06View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC06Doc)));
	return (CDemoMFC06Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC06View 消息处理程序


void CDemoMFC06View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) {//定时器ID为1处理
		static int w = 0;
		w += 5;
		CString str = TEXT("发电量骄傲垃圾分类大家啊垃圾");
		//获取字符串的长度
		CClientDC dc(this);
		CSize size = dc.GetTextExtent(str);
		//如果字体宽度大于字符串的宽度，重新开始
		if (w > size.cx) {
			w = 0;
			//重新刷新窗口
			Invalidate();
		}

		int x = 30;
		int y = 30;
		CRect rect(x, y, x+w, y + size.cy);

		dc.TextOut(x, y, str);

		dc.SetTextColor(RGB(255, 0, 255));
		dc.DrawText(str, &rect, DT_LEFT);
	}
	CView::OnTimer(nIDEvent);
}


int CDemoMFC06View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//设置定时器
	//1定时器ID，500时间间隔，NULL使用系统默认函数
	SetTimer(1, 50, NULL);

	return 0;
}
