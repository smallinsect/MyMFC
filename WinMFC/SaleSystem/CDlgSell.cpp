// CDlgSell.cpp: 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "CDlgSell.h"
#include "afxdialogex.h"


// CDlgSell 对话框

IMPLEMENT_DYNCREATE(CDlgSell, CFormView)

CDlgSell::CDlgSell()
	: CFormView(IDD_SELL)
	, m_price(0)
	, m_left(0)
	, m_num(0)
	, m_setinfor(_T(""))
{

}

CDlgSell::~CDlgSell()
{
}

void CDlgSell::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combx);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_left);
	DDX_Text(pDX, IDC_EDIT5, m_num);
	DDX_Text(pDX, IDC_EDIT3, m_setinfor);
}


BEGIN_MESSAGE_MAP(CDlgSell, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgSell::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgSell::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgSell::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDlgSell 消息处理程序


void CDlgSell::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//初始化 下拉框
	
	for (int i = 0; i < 5; ++i) {
		CString name;
		name.Format(TEXT("雪碧%d"), i);
		m_combx.AddString(name);
	}
	//默认选中第一件商品
	m_combx.SetCurSel(0);

	OnCbnSelchangeCombo1();
	//UpdateData(FALSE);//同步数据
}


void CDlgSell::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//切换商品 触发事件

	//先获取商品名称

	int idx = m_combx.GetCurSel();
	//根据索引获取具体的内容
	CString name;
	m_combx.GetLBText(idx, name);
	//根据商品的名称 获取商品的价格和数量
	for (int i = 0; i < 5; ++i) {
		CString str;
		str.Format(TEXT("雪碧%d"), i);
		if (name == str) {
			m_price = i+1;
			m_left = i+1;
			break;
		}
	}
	UpdateData(FALSE);//同步数据
}


void CDlgSell::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//获取最新值
	if (m_left < m_num || m_num < 0) {
		MessageBox(TEXT("输入的数量，不能大于库存，不能小于零"));
		return;
	}
	//购买
	//获取具体要购买的商品
	int idx = m_combx.GetCurSel();
	CString name;
	m_combx.GetLBText(idx, name);
	for (int i = 0; i < 5; ++i) {
		CString str;
		str.Format(TEXT("雪碧%d"), i);
		if (name == str) {
			//m_price = i + 1;
			m_left = m_left - m_num;
			break;
		}
	}
	CString str;
	str.Format(TEXT("商品：%s\r\n单价：%d\r\n个数：%d\r\n总价：%d\r\n"), name, m_price, m_num, m_price*m_num);
	m_setinfor = str;

	UpdateData(FALSE);//同步数据
	MessageBox(TEXT("购买成功"));
}


void CDlgSell::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_num = 0;
	UpdateData(FALSE);//同步数据
}
