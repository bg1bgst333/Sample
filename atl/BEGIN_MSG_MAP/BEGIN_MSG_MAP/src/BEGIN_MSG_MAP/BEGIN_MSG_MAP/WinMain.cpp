// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR
// �Ǝ��̃w�b�_
#include "stdafx.h"	// stdafx.h
#include "CustomWindow.h"	// CCustomWindow

// _Module�̒�`.
CComModule _Module;	// ���̂͂����ɒ�`.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// Windows�v���O�����̃G���g���|�C���g

	// ������
	_Module.Init(NULL, hInstance);	// _Module.Init�ŏ�����.

	// �E�B���h�E�̍쐬.
	CCustomWindow customWnd;	// CCustomWindow�I�u�W�F�N�gcustomWnd��錾.
	customWnd.Create(NULL, CWindow::rcDefault, _T("BEGIN_MSG_MAP"), WS_OVERLAPPEDWINDOW);	// customWnd.Create�ŃE�B���h�E��"BEGIN_MSG_MAP"�̃E�B���h�E���쐬.
	customWnd.ShowWindow(SW_SHOW);	// customWnd.ShowWindow�ŃE�B���h�E��\��.

	// ���b�Z�[�W���[�v.
	MSG msg;	// MSG�\���̕ϐ�msg��錾.
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// ���b�Z�[�W�������.

		// ���b�Z�[�W����.
		TranslateMessage(&msg);	// TranslateMessage�ŕϊ�����.
		DispatchMessage(&msg);	// DispatchMessage�ő��o����.

	}
	
	// �I������
	_Module.Term();	// _Module.Term�ŏI������.

	// �v���O�����̏I��.
	return msg.wParam;	// msg.wParam��Ԃ��Đ���I��.

}