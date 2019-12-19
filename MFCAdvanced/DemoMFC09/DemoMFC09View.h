
// DemoMFC09View.h: CDemoMFC09View 类的接口
//

#pragma once


class CDemoMFC09View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC09View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC09View)

// 特性
public:
	CDemoMFC09Doc* GetDocument() const;

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
	virtual ~CDemoMFC09View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	HICON hicon[7];
};

#ifndef _DEBUG  // DemoMFC09View.cpp 中的调试版本
inline CDemoMFC09Doc* CDemoMFC09View::GetDocument() const
   { return reinterpret_cast<CDemoMFC09Doc*>(m_pDocument); }
#endif

