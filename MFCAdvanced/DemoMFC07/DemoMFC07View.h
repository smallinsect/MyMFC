
// DemoMFC07View.h: CDemoMFC07View 类的接口
//

#pragma once


class CDemoMFC07View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC07View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC07View)

// 特性
public:
	CDemoMFC07Doc* GetDocument() const;

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
	virtual ~CDemoMFC07View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestDemo();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CMenu menu;
};

#ifndef _DEBUG  // DemoMFC07View.cpp 中的调试版本
inline CDemoMFC07Doc* CDemoMFC07View::GetDocument() const
   { return reinterpret_cast<CDemoMFC07Doc*>(m_pDocument); }
#endif

