// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// COM�̏�����.
	HRESULT hr = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr�Ɋi�[.
	if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("CoInitialize success!\n"));	// "CoInitialize success!"�Əo��.
	}

	// ��������I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// 2��ڂ�COM�̏�����.
	HRESULT hr2 = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr2�Ɋi�[.
	if (hr2 == S_FALSE){	// S_FALSE�Ȃ炷�łɏ���������Ă���.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"�Əo��.
	}
	else if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("CoInitialize success!\n"));	// "CoInitialize success!"�Əo��.
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}