// �w�b�_�t�@�C���̃C���N���[�h
#define _WIN32_DCOM		// DCOM�̒�`
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <objbase.h>	// COM

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HRESULT hr;		// COM�̏������̌��ʂ��i�[����hr.
	HRESULT hr2;	// �Z�L�����e�B�������̌��ʂ��i�[����hr2.

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

	// �Z�L�����e�B������.
	hr2 = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);	// CoInitializeSecurity�ŃZ�L�����e�B������.
	if (hr2 == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("CoInitializeSecurity success!\n"));	// "CoInitializeSecurity success!"�Əo��.
	}
	else{	// ����ȊO.
		_tprintf(_T("Failed!\n"));	// "Failed!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -2;	// -2��Ԃ��Ĉُ�I��.
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}