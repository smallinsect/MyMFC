
// DemoMFC06View.h: CDemoMFC06View 类的接口
//

#pragma once


class CDemoMFC06View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC06View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC06View)

// 特性
public:
	CDemoMFC06Doc* GetDocument() const;

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
	virtual ~CDemoMFC06View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // DemoMFC06View.cpp 中的调试版本
inline CDemoMFC06Doc* CDemoMFC06View::GetDocument() const
   { return reinterpret_cast<CDemoMFC06Doc*>(m_pDocument); }
#endif

