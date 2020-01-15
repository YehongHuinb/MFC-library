#if !defined(AFX_MAINDLG_H__FAE2A084_58A2_477F_8860_5BC167096F95__INCLUDED_)
#define AFX_MAINDLG_H__FAE2A084_58A2_477F_8860_5BC167096F95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog
class Book
{
public:
	char author[10];
	char name[20];
	char publish[50];
	char id[20];
};
class CMainDlg : public CDialog
{
// Construction
public:
	User user[50];
	int ReadUser();
	int type;
	Book book[100];
	void Show();
	int Read();
	CMainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_DIALOG2 };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton7();
protected:
	HICON m_hIcon;
public:
//	static char NowName[20];
	afx_msg void OnEnChangeEdit6();
private:
	CString m_author;
	CString m_name;
	CString m_publish;
	CString m_id;
	CString m_newpwd;
	CString m_check;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__FAE2A084_58A2_477F_8860_5BC167096F95__INCLUDED_)
