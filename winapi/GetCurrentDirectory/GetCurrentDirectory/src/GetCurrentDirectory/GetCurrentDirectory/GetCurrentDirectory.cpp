// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �z��̏�����
	TCHAR tszCurrentPath[MAX_PATH] = {0};	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X���w��TCHAR�z��tszCurrentPath(����MAX_PATH)��{0}�ŏ�����.

	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X���擾.
	DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectory��tszCurrentPath���擾.
	if (dwRet != 0){	// ����.
		_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPath���o��.
	}
	else{	// ���s.
		_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."���o��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}