// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
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

	// OLE�̏I������.
	OleUninitialize();	// OleUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}