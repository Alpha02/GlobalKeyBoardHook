
// UsingKeyBoardHookDlg.h : ͷ�ļ�
#include "KeyBoardHookDLL.h"
//

#pragma once


// CUsingKeyBoardHookDlg �Ի���
class CUsingKeyBoardHookDlg : public CDialogEx
{
// ����
public:
	CUsingKeyBoardHookDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_USINGKEYBOARDHOOK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	CKeyBoardHook myHook;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString new_char;
	CString str1;
	CString str2;
};
