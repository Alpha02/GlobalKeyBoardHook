
// UsingKeyBoardHookDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UsingKeyBoardHook.h"
#include "UsingKeyBoardHookDlg.h"
#include "afxdialogex.h"
#pragma comment(lib,"KeyBoardHookDLL.lib")		

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUsingKeyBoardHookDlg �Ի���




CUsingKeyBoardHookDlg::CUsingKeyBoardHookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUsingKeyBoardHookDlg::IDD, pParent)
	, new_char(_T(""))
	, str1(_T(""))
	, str2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUsingKeyBoardHookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, new_char);
	DDX_Text(pDX, IDC_EDIT2, str2);
}

BEGIN_MESSAGE_MAP(CUsingKeyBoardHookDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CUsingKeyBoardHookDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CUsingKeyBoardHookDlg ��Ϣ�������

BOOL CUsingKeyBoardHookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CWnd *pwnd=GetDlgItem(IDC_EDIT1); //ȡ�ñ༭�����ָ�� 
	myHook.StartHook(pwnd->GetSafeHwnd()); //ȡ�ñ༭��Ĵ��ھ������װ���� 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CUsingKeyBoardHookDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CUsingKeyBoardHookDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CUsingKeyBoardHookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUsingKeyBoardHookDlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);
	char ch=_ttoi(new_char);
	str2.AppendChar(ch);
	UpdateData(FALSE);
	CWnd *pwnd=GetDlgItem(IDC_EDIT1); //ȡ�ñ༭�����ָ�� 
	//myHook.StopHook();
	//myHook.StartHook(pwnd->GetSafeHwnd()); //ȡ�ñ༭��Ĵ��ھ������װ���� 
}
