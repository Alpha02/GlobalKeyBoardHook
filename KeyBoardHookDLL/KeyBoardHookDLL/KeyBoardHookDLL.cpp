// KeyBoardHookDLL.cpp : ���� DLL �ĳ�ʼ�����̡�
//
#include "stdafx.h"
#include "KeyBoardHookDLL.h"
#pragma data_seg("Titlename")
HWND glhWnd=NULL; 
HHOOK glhHook=NULL; //��װ����깳�Ӿ�� 
HINSTANCE glhInstance=NULL;//DLLʵ����� 
#pragma data_seg() 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wparam,LPARAM lparam) 
{ 
	if (nCode == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) lparam;
		//if ((lparam)>>30&1==0)return CallNextHookEx(glhHook,nCode,wparam,lparam);
		int c=p->vkCode;
		char ch[200];
		if((((p->flags)>>7)&1)==1){
			return CallNextHookEx(glhHook,nCode,wparam,lparam);
		}
		sprintf(ch,"%du",c);
			//if((lparam>>30)&1==1)return CallNextHookEx(glhHook,nCode,wparam,lparam);
		::SendMessage(glhWnd,WM_SETTEXT,0,(LPARAM)ch);
	}
	return CallNextHookEx(glhHook,nCode,wparam,lparam); //����������Ϣ 
}
CKeyBoardHook::CKeyBoardHook() //�๹�캯�� 
{ 
} 
CKeyBoardHook::~CKeyBoardHook() //���������� 
{ 
	StopHook(); 
} 
BOOL CKeyBoardHook::StartHook(HWND hWnd) //��װ���Ӳ��趨������ʾ���ھ�� 
{ 
	BOOL bResult=FALSE;
	glhHook=SetWindowsHookEx(WH_KEYBOARD_LL,KeyboardProc,GetModuleHandle("KeyBoardHookDLL.dll"),0); 
	if(glhHook!=NULL) 
	{
		bResult=TRUE;
	}
	glhWnd=hWnd;//������ʾĿ�괰�ڱ���༭��ľ�� 
	return bResult; 
} 
BOOL CKeyBoardHook::StopHook() //ж�ع��� 
{ 
	BOOL bResult=FALSE; 
	if(glhHook) 
	{ 
		bResult= UnhookWindowsHookEx(glhHook); 
		if(bResult) 
		{ 
			glhWnd=NULL;
			glhHook=NULL; 
		} 
	} 
	return bResult; 
} 