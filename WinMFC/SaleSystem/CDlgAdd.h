#pragma once


// CDlgAdd 对话框

class CDlgAdd : public CFormView
{
	DECLARE_DYNCREATE(CDlgAdd)

public:
	CDlgAdd();   // 标准构造函数
	virtual ~CDlgAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combx;
	int m_pricel;
	int m_numl;
	CString m_namer;
	int m_pricer;
	int m_numr;
};
