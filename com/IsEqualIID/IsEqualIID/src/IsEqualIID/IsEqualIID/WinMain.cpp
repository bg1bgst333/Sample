// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�I�u�W�F�N�g�̐錾�E������.
	CMainApplication app;	// CMainApplication�I�u�W�F�N�gapp.
	HRESULT hr;	// COM�̏������̌��ʂ��i�[����hr.
	TCHAR tszText[256] = {0};	// �\������e�L�X�gtszText(����256)��{0}�ŏ�����.

	// OLE�̏�����
	hr = OleInitialize(NULL);	// OleInitialize��NULL��n���ď�����.
	if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_stprintf(tszText, _T("OleInitialize success!\n"));	// "OleInitialize success!"��tszText�ɃZ�b�g.
		OutputDebugString(tszText);	// OutputDebugString��tszText���o��.
	}
	else if (hr == S_FALSE){	// S_FALSE�Ȃ炷�łɏ���������Ă���.
		_stprintf(tszText, _T("Already initialized!\n"));	// "Already initialized!"��tszText�ɃZ�b�g.
		OutputDebugString(tszText);	// OutputDebugString��tszText���o��.
	}
	else{	// ����ȊO.
		_stprintf(tszText, _T("Failed!\n"));	// "Failed!"��tszText�ɃZ�b�g.
		OutputDebugString(tszText);	// OutputDebugString��tszText���o��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �C���X�^���X�̏�����.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstance��FALSE�̏ꍇ.

		// �ُ�I��.
		app.ExitInstance();	// app.ExitInstance�ŏI�����������s.
		// OLE�̏I������.
		OleUninitialize();	// OleUninitialize�ŏI������.
		return -1;	// return��-1��Ԃ��Ĉُ�I��.

	}

	// ���b�Z�[�W���[�v����.
	int iRet = app.Run();	// app.Run�̖߂�l��iRet�Ɋi�[.
	// OLE�̏I������.
	OleUninitialize();	// OleUninitialize�ŏI������.
	return iRet;	// iRet��Ԃ��ďI��.

}