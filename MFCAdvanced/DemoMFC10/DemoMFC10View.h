
// DemoMFC10View.h: CDemoMFC10View 类的接口
//

#pragma once


class CDemoMFC10View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC10View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC10View)

// 特性
public:
	CDemoMFC10Doc* GetDocument() const;

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
	virtual ~CDemoMFC10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DemoMFC10View.cpp 中的调试版本
inline CDemoMFC10Doc* CDemoMFC10View::GetDocument() const
   { return reinterpret_cast<CDemoMFC10Doc*>(m_pDocument); }
#endif

