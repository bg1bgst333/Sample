// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl

// �R���X�g���N�^CUserControl
CUserControl::CUserControl() : CWindow(){

}

// �f�X�g���N�^~CUserControl
CUserControl::~CUserControl(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CUserControl::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CWindow::RegisterClass(hInstance, _T("CUserControl"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X��"CUserControl"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CUserControl::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClass�ŃE�B���h�E�N���X��lpctszClassName��o�^. 

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CUserControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CUserControl".
	return CWindow::Create(_T("CUserControl"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CUserControl"���w��.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CUserControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CUserControl::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CUserControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CUserControl::OnDestroy(){

	// �����ł͉����Ă΂Ȃ�.

}