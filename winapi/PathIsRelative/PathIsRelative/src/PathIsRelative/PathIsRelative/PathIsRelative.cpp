// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <shlwapi.h>	// �V�F��API

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �^����ꂽ�����̃p�X�����΃p�X���ǂ����`�F�b�N.
	BOOL bRet = PathIsRelative(argv[1]);	// PathIsRelative��argv[1]�Ƃ����p�X�����΃p�X���ǂ����`�F�b�N.
	if (bRet){	// bRet��TRUE.
		_tprintf(_T("Relative!\n"));	// "Relative!"�Əo��.
	}
	else{	// bRet��FALSE.
		_tprintf(_T("Not relative!\n"));	// "Not relative!"�Əo��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}