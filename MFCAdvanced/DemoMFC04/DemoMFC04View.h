
// DemoMFC04View.h: CDemoMFC04View 类的接口
//

#pragma once


class CDemoMFC04View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC04View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC04View)

// 特性
public:
	CDemoMFC04Doc* GetDocument() const;

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
	virtual ~CDemoMFC04View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CPoint m_point;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	bool m_press;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DemoMFC04View.cpp 中的调试版本
inline CDemoMFC04Doc* CDemoMFC04View::GetDocument() const
   { return reinterpret_cast<CDemoMFC04Doc*>(m_pDocument); }
#endif

