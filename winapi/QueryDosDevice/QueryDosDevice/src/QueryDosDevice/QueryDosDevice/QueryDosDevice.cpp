// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// MS-DOS�f�o�C�X���̎擾.
	TCHAR tszDrive[3] = {0};	// �h���C�u���^�[tszDrive(����3.)��{0}�ŏ�����.
	_tcscat(tszDrive, argv[1]);	// argv[1]��A��.
	_tcscat(tszDrive, _T(":"));	// ":"��A��.
	TCHAR tszDeviceName[MAX_PATH] = {0};	// �f�o�C�X��tszDeviceName(����MAX_PATH.)��{0}�ŏ�����.
	QueryDosDevice(tszDrive, tszDeviceName, MAX_PATH);	// QueryDosDevice��tszDeviceName���擾.
	_tprintf(_T("%s\n"), tszDeviceName);	// tszDeviceName�̏o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}