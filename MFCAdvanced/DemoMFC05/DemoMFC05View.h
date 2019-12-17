
// DemoMFC05View.h: CDemoMFC05View 类的接口
//

#pragma once


class CDemoMFC05View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC05View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC05View)

// 特性
public:
	CDemoMFC05Doc* GetDocument() const;

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
	virtual ~CDemoMFC05View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_point;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString m_str;
};

#ifndef _DEBUG  // DemoMFC05View.cpp 中的调试版本
inline CDemoMFC05Doc* CDemoMFC05View::GetDocument() const
   { return reinterpret_cast<CDemoMFC05Doc*>(m_pDocument); }
#endif

