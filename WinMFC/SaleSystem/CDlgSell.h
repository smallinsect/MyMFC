#pragma once


// CDlgSell 对话框

class CDlgSell : public CFormView
{
	DECLARE_DYNCREATE(CDlgSell)

public:
	CDlgSell();   // 标准构造函数
	virtual ~CDlgSell();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELL};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combx;
	int m_price;
	int m_left;
public:
	int m_num;
	CString m_setinfor;
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
