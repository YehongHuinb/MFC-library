// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LoginDlg.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, &CLoginDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	EndDialog(TRUE);	
}

void CLoginDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString name,pwd,again;
	CMainDlg check;
	int num = check.ReadUser();
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(pwd);
	GetDlgItem(IDC_EDIT5)->GetWindowText(again);
	if( name.IsEmpty() || pwd.IsEmpty() || again.IsEmpty() )
	{
		MessageBox("注册信息不能为空");
		return;
	}
	else if( pwd != again )
	{
		MessageBox("两次密码输入不一致");
		return;
	}
	else
	{
		for( int i=0 ; i<num ; i++ )
		{
			if( name == check.user[i].name )
			{
				MessageBox("用户名重复！");
				return;
			}
		}
	}
	ofstream file;
	file.open( "./user.txt" , ios_base::out|ios_base::out|ios_base::app );
	file << name.GetBuffer(0)
		 <<"   "<< pwd.GetBuffer(0)
		 <<"   "<< 1 << endl;
	file.close();
	MessageBox("注册成功");
	EndDialog(TRUE);
}


void CLoginDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
