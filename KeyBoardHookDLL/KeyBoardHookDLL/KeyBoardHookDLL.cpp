// KeyBoardHookDLL.cpp : 定义 DLL 的初始化例程。
//
#include "stdafx.h"
#include "KeyBoardHookDLL.h"
#pragma data_seg("Titlename")
HWND glhWnd=NULL; 
HHOOK glhHook=NULL; //安装的鼠标钩子句柄 
HINSTANCE glhInstance=NULL;//DLL实例句柄 
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
	return CallNextHookEx(glhHook,nCode,wparam,lparam); //继续传递消息 
}
CKeyBoardHook::CKeyBoardHook() //类构造函数 
{ 
} 
CKeyBoardHook::~CKeyBoardHook() //类析构函数 
{ 
	StopHook(); 
} 
BOOL CKeyBoardHook::StartHook(HWND hWnd) //安装钩子并设定接收显示窗口句柄 
{ 
	BOOL bResult=FALSE;
	glhHook=SetWindowsHookEx(WH_KEYBOARD_LL,KeyboardProc,GetModuleHandle("KeyBoardHookDLL.dll"),0); 
	if(glhHook!=NULL) 
	{
		bResult=TRUE;
	}
	glhWnd=hWnd;//设置显示目标窗口标题编辑框的句柄 
	return bResult; 
} 
BOOL CKeyBoardHook::StopHook() //卸载钩子 
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