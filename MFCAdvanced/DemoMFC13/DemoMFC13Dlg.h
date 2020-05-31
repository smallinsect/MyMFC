﻿
// DemoMFC13Dlg.h: 头文件
//

#pragma once


// CDemoMFC13Dlg 对话框
class CDemoMFC13Dlg : public CDialogEx
{
// 构造
public:
	CDemoMFC13Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMOMFC13_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton m_check;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};