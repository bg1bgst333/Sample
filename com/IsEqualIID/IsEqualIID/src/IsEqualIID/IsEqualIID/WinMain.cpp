// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �I�u�W�F�N�g�̐錾.
	CMainApplication app;	// CMainApplication�I�u�W�F�N�gapp.

	// �C���X�^���X�̏�����.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstance��FALSE�̏ꍇ.

		// �ُ�I��.
		app.ExitInstance();	// app.ExitInstance�ŏI�����������s.
		return -1;	// return��-1��Ԃ��Ĉُ�I��.

	}

	// ���b�Z�[�W���[�v����.
	return app.Run();	// app.Run�̖߂�l�����̂܂ܕԂ�..

}