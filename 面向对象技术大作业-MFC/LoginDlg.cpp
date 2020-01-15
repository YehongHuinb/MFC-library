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
		MessageBox("ע����Ϣ����Ϊ��");
		return;
	}
	else if( pwd != again )
	{
		MessageBox("�����������벻һ��");
		return;
	}
	else
	{
		for( int i=0 ; i<num ; i++ )
		{
			if( name == check.user[i].name )
			{
				MessageBox("�û����ظ���");
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
	MessageBox("ע��ɹ�");
	EndDialog(TRUE);
}


void CLoginDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
