// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowserHost.h"	// CWebBrowserHost

// �R���X�g���N�^CWebBrowserHost
CWebBrowserHost::CWebBrowserHost() : CUserControl(){

}

// �f�X�g���N�^~CWebBrowserHost
CWebBrowserHost::~CWebBrowserHost(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CWebBrowserHost"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CWebBrowserHost"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CUserControl::RegisterClass(hInstance, lpctszClassName);	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��lpctszClassName��o�^. 

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWebBrowserHost::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CWebBrowserHost".
	return CUserControl::Create(_T("CWebBrowserHost"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CWebBrowserHost"���w��.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CWebBrowserHost::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CUserControl::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CWebBrowserHost::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWebBrowserHost::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CWebBrowserHost::OnDestroy(){

	// �����ł͉����Ă΂Ȃ�.

}