// �w�b�_�t�@�C���̃C���N���[�h
#define _WIN32_DCOM		// DCOM�̒�`
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <objbase.h>	// COM

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HRESULT hr;	// COM�̏������̌��ʂ��i�[����hr.

	// MTA(�}���`�X���b�h�A�p�[�g�����g)�ɑ�����悤�ɐݒ�.
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);	// CoInitializeEx��COINIT_MULTITHREADED���w�肵�ď�����.
	if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("CoInitializeEx success!\n"));	// "CoInitializeEx success!"�Əo��.
	}
	else if (hr == S_FALSE){	// S_FALSE�Ȃ炷�łɏ���������Ă���.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"�Əo��.
	}
	else{	// ����ȊO.
		_tprintf(_T("Failed!\n"));	// "Failed!"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}