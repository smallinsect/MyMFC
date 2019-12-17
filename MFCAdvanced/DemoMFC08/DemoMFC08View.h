﻿
// DemoMFC08View.h: CDemoMFC08View 类的接口
//

#pragma once


class CDemoMFC08View : public CView
{
protected: // 仅从序列化创建
	CDemoMFC08View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC08View)

// 特性
public:
	CDemoMFC08Doc* GetDocument() const;

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
	virtual ~CDemoMFC08View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DemoMFC08View.cpp 中的调试版本
inline CDemoMFC08Doc* CDemoMFC08View::GetDocument() const
   { return reinterpret_cast<CDemoMFC08Doc*>(m_pDocument); }
#endif

