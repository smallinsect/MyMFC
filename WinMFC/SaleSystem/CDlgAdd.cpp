// CDlgAdd.cpp: 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "CDlgAdd.h"
#include "afxdialogex.h"


// CDlgAdd 对话框

IMPLEMENT_DYNCREATE(CDlgAdd, CFormView)

CDlgAdd::CDlgAdd()
	: CFormView(IDD_ADD)
	, m_pricel(0)
	, m_numl(0)
	, m_namer(_T(""))
	, m_pricer(0)
	, m_numr(0)
{

}

CDlgAdd::~CDlgAdd()
{
}

void CDlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combx);
	DDX_Text(pDX, IDC_EDIT1, m_pricel);
	DDX_Text(pDX, IDC_EDIT2, m_numl);
	DDX_Text(pDX, IDC_EDIT3, m_namer);
	DDX_Text(pDX, IDC_EDIT4, m_pricer);
	DDX_Text(pDX, IDC_EDIT5, m_numr);
}


BEGIN_MESSAGE_MAP(CDlgAdd, CFormView)
END_MESSAGE_MAP()


// CDlgAdd 消息处理程序
