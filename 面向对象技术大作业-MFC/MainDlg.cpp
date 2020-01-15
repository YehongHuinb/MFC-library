// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "MainDlg.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
	, m_author(_T(""))
	, m_name(_T(""))
	, m_publish(_T(""))
	, m_id(_T(""))
	, m_newpwd(_T(""))
	, m_check(_T(""))
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_BOOK);
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT1, m_author);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_publish);
	DDX_Text(pDX, IDC_EDIT4, m_id);
	DDX_Text(pDX, IDC_EDIT5, m_newpwd);
	DDX_Text(pDX, IDC_EDIT6, m_check);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMainDlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT1, &CMainDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON7, &CMainDlg::OnBnClickedButton7)
	ON_EN_CHANGE(IDC_EDIT6, &CMainDlg::OnEnChangeEdit6)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_list.InsertColumn(0,"����",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"����",LVCFMT_CENTER,150);
	m_list.InsertColumn(2,"������",LVCFMT_CENTER,150);
	m_list.InsertColumn(3,"���",LVCFMT_CENTER,100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	Show();

	if(type == 1)
	{
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMainDlg::OnButton3()//��Ӳ���
{
	// TODO: Add your control notification handler code here
	int num = Read();
	CString name,author,publish,id;
	GetDlgItem(IDC_EDIT1)->GetWindowText(author);
	GetDlgItem(IDC_EDIT2)->GetWindowText(name);
	GetDlgItem(IDC_EDIT3)->GetWindowText(publish);
	GetDlgItem(IDC_EDIT4)->GetWindowText(id);
	if( author.IsEmpty() || name.IsEmpty() || publish.IsEmpty() || id.IsEmpty() )
	{
		MessageBox("��ӵ���Ϣ����Ϊ��");
		return;
	}
	else
	{
		for( int i=0 ; i<num ; i++ )
		{
			if( id == book[i].id )
			{
				MessageBox("��Ų����ظ���");
				return;
			}
		}
	}

	ofstream file;
	file.open( "./book.txt" , ios_base::out|ios_base::out|ios_base::app );
	file << author.GetBuffer(0) 
		 <<"   "<< name.GetBuffer(0)
		 <<"   "<< publish.GetBuffer(0)
		 <<"   "<< id.GetBuffer(0) << endl;
	file.close();
	MessageBox("��ӳɹ�");
	Show();
}

void CMainDlg::Show()
{
	m_list.DeleteAllItems();
	int num = Read();
	for(int i =0;i<num;i++)
	{
		m_list.InsertItem(i,0);
		m_list.SetItemText(i,0,book[i].author);
		m_list.SetItemText(i,1,book[i].name);
		m_list.SetItemText(i,2,book[i].publish);
		m_list.SetItemText(i,3,book[i].id);
	}
}

int CMainDlg::Read()//��ȡ���������Ϣ
{
	ifstream file;
	file.open( "./book.txt" , ios_base::out|ios_base::out );
	int i = 0;
	while(!file.eof())
	{
		file >> book[i].author
			 >> book[i].name
			 >> book[i].publish
			 >> book[i].id;
		i++;
	}
	i--;
	file.close();	
	return i;
}

void CMainDlg::OnButton4()//ɾ������
{
	int mark = m_list.GetSelectionMark();
	if(mark == -1)
	{
		MessageBox("����ѡ����Ҫɾ����ͼ����Ϣ");
		return;
	}
	int num = Read();
	CString name = m_list.GetItemText( mark , 3 );
	ofstream outfile;
	outfile.open( "./book.txt" , ios_base::out|ios_base::out|ios_base::trunc );
	for(int i=0;i<num;i++)
	{
		if(strcmp( name , book[i].id )==0)
		{
			continue;
		}
		outfile << book[i].author
			    <<"  "<<book[i].name
				<<"  "<<book[i].publish
				<<"  "<<book[i].id <<endl;

	}
	outfile.close();

	MessageBox("ɾ���ɹ�");
	Show();
}

void CMainDlg::OnButton5()//��ѯ����
{
	// TODO: Add your control notification handler code here
	bool find = FALSE;
	bool repeat = FALSE;
	int num = Read();
	int *item = (int *)calloc( num , sizeof(int) );
	int check = 0;
	for( int i=1 ; i<num ; i++ )
		item[i] = -1;
	CString name,author,publish,id;
	GetDlgItem(IDC_EDIT1)->GetWindowText(author);
	GetDlgItem(IDC_EDIT2)->GetWindowText(name);
	GetDlgItem(IDC_EDIT3)->GetWindowText(publish);
	GetDlgItem(IDC_EDIT4)->GetWindowText(id);

	if( author.IsEmpty() && name.IsEmpty() && publish.IsEmpty() && id.IsEmpty() )
	{
		Show();
	}//�մ򿪽���ʱ��ʾ������

	m_list.DeleteAllItems();
	if(!author.IsEmpty())
	{
		int a= 0 ;
		for(int i=0 ; i<num ; i++)
		{
			if( strstr(book[i].author,author)!=NULL )
			{
				for( int j=0 ; j<check ; j++ )
				{
					if( item[j]==i )
					{
						repeat = TRUE;
						break;
					}
				}
				if( !repeat )
				{
					m_list.InsertItem(a,0);
					m_list.SetItemText(a,0,book[i].author);
					m_list.SetItemText(a,1,book[i].name);
					m_list.SetItemText(a,2,book[i].publish);
					m_list.SetItemText(a,3,book[i].id);
					find = TRUE;
					item[check++] = i;
				}
			}
		}
	}
	repeat = FALSE;
	if(!name.IsEmpty())
	{
		int a= 0 ;
		for(int i =0;i<num;i++)
		{
			if( strstr(book[i].name,name)!=NULL )
			{
				for( int j=0 ; j<check ; j++ )
				{
					if( item[j]==i )
					{
						repeat = TRUE;
						break;
					}
				}
				if( !repeat )
				{
					m_list.InsertItem(a,0);
					m_list.SetItemText(a,0,book[i].author);
					m_list.SetItemText(a,1,book[i].name);
					m_list.SetItemText(a,2,book[i].publish);
					m_list.SetItemText(a,3,book[i].id);
					find = TRUE;
					item[check++] = i;
				}
			}
		}
	}
	repeat = FALSE;
	if( !publish.IsEmpty() )
	{
		int a= 0 ;
		for(int i =0;i<num;i++)
		{
			if( strstr(book[i].publish,publish)!=NULL )
			{
				for( int j=0 ; j<check ; j++ )
				{
					if( item[j]==i )
					{
						repeat = TRUE;
						break;
					}
				}
				if( !repeat )
				{
					m_list.InsertItem(a,0);
					m_list.SetItemText(a,0,book[i].author);
					m_list.SetItemText(a,1,book[i].name);
					m_list.SetItemText(a,2,book[i].publish);
					m_list.SetItemText(a,3,book[i].id);
					find = TRUE;
					item[check++] = i;
				}
			}
		}
	}
	repeat = FALSE;
	if( !id.IsEmpty() )
	{
		int a= 0 ;
		for(int i =0;i<num;i++)
		{
			if(strcmp(id,book[i].id)==0)
			{
				for( int j=0 ; j<check ; j++ )
				{
					if( item[j]==i )
					{
						repeat = TRUE;
						break;
					}
				}
				if( !repeat )
				{
					m_list.InsertItem(a,0);
					m_list.SetItemText(a,0,book[i].author);
					m_list.SetItemText(a,1,book[i].name);
					m_list.SetItemText(a,2,book[i].publish);
					m_list.SetItemText(a,3,book[i].id);
					find = TRUE;
					item[check++] = i;
				}
			}
		}
	}

	if( !find )
	{
		MessageBox( _T("���޴������Ϣ����") );
		Show();
	}
}

void CMainDlg::OnButton6()//�޸��������
{
	// TODO: Add your control notification handler code here
	CString newpwd;
	CString check;
	GetDlgItem(IDC_EDIT5)->GetWindowText(newpwd);
	GetDlgItem(IDC_EDIT6)->GetWindowText(check);
	if( newpwd.IsEmpty()||check.IsEmpty() )
	{
		MessageBox("��������ȫ��Ϣ");
		return;
	}
	else if( newpwd != check )
	{
		MessageBox("�������벻һ��");
		return;
	}
	ofstream outfile;
	ifstream ofs;
	char now_name[20] = {0};
	int num = ReadUser();
	outfile.open( "./user.txt" , ios_base::out|ios_base::out|ios_base::trunc );
	ofs.open( "./NowUser.txt" , ios_base::out|ios_base::out );

	ofs >> now_name;

	for(int i=0;i<num;i++)
	{
		if(strcmp( now_name , user[i].name ) == 0)
		{
			strcpy(user[i].pwd,newpwd);
		}
		outfile << user[i].name
			    << "   " << user[i].pwd 
				<< "   " << user[i].type <<endl;
	}
	outfile.close();
	ofs.close();
	MessageBox("�����޸ĳɹ�");
	m_newpwd.Empty();
	m_check.Empty();
	UpdateData(FALSE);
}

int CMainDlg::ReadUser()//��ȡ����Ա����ͨ�û���������Ϣ
{
	ifstream file;
	file.open( "./user.txt" , ios_base::out|ios_base::out );
	int i = 0;
	while(!file.eof())//�����ļ�������
	{
		file >> user[i].name
			 >> user[i].pwd
			 >> user[i].type;
		i++;
	}
	i--;
	file.close();	
	return i;
}

void CMainDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMainDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMainDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_author.Empty();
	m_name.Empty();
	m_publish.Empty();
	m_id.Empty();
	UpdateData(FALSE);
}


void CMainDlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
