
// UsingKeyBoardHook.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUsingKeyBoardHookApp:
// �йش����ʵ�֣������ UsingKeyBoardHook.cpp
//

class CUsingKeyBoardHookApp : public CWinApp
{
public:
	CUsingKeyBoardHookApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUsingKeyBoardHookApp theApp;