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

	// �p�X����t�@�C���������𒊏o.
	TCHAR *ptszFileName = NULL;	// �t�@�C�������w��TCHAR�^�|�C���^ptszFileName��NULL�ŏ�����.
	ptszFileName = PathFindFileName(argv[1]);	// PathFindFileName��argv[1]�̃t�@�C���������𒊏o.
	_tprintf(_T("ptszFileName = %s\n"), ptszFileName);	// ptszFileName���o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}