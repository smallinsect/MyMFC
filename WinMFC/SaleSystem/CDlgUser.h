#pragma once


// CDlgUser 对话框

class CDlgUser : public CFormView
{
	DECLARE_DYNCREATE(CDlgUser)

public:
	CDlgUser();   // 标准构造函数
	virtual ~CDlgUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;
	CString m_name;
	CString m_newPwd;
	CString m_surePwd;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnInitialUpdate();
};
