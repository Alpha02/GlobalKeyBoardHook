class AFX_EXT_CLASS CKeyBoardHook:public CObject //AFX_EXT_CLASS��������Ϊ������
{ 
public: 
	CKeyBoardHook();//������Ĺ��캯��
	~CKeyBoardHook();//��������������� 
	BOOL StartHook(HWND hWnd);//��װ���Ӻ��� 
	BOOL StopHook();//ж�ع��Ӻ��� 
}; 
