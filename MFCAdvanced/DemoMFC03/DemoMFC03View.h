
// DemoMFC03View.h: CDemoMFC03View 类的接口
//

#pragma once


class CDemoMFC03View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC03View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC03View)

// 特性
public:
	CDemoMFC03Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDemoMFC03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DemoMFC03View.cpp 中的调试版本
inline CDemoMFC03Doc* CDemoMFC03View::GetDocument() const
   { return reinterpret_cast<CDemoMFC03Doc*>(m_pDocument); }
#endif

