#pragma once


// CDlgLogin 对话框

class CDlgLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLogin)

public:
	CDlgLogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgLogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;
public:
	CString m_pwd;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClose();
};
