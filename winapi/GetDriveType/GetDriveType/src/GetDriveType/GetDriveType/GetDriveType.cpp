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

	// �h���C�u�^�C�v�̎擾.
	TCHAR tszRootPathName[MAX_PATH] = {0};	// �h���C�u�̃��[�g�p�XtszRootPathName(����MAX_PATH)��{0}�ŏ�����.
	_tcscat(tszRootPathName, argv[1]);		// tszRootPathName��argv[1]��A��.
	_tcscat(tszRootPathName, _T(":\\"));	// ":\\"(�\������":\".)��A��.
	DWORD dwRet = GetDriveType(tszRootPathName);	// GetDriveType�Ńh���C�u�^�C�v�擾.
	if (dwRet == DRIVE_UNKNOWN){	// �s��.
		_tprintf(_T("DRIVE_UNKNOWN\n"));	// "DRIVE_UNKNOWN"���o��.
	}
	else if (dwRet == DRIVE_NO_ROOT_DIR){	// ���[�g�f�B���N�g���ł͂Ȃ�.
		_tprintf(_T("DRIVE_NO_ROOT_DIR\n"));	// "DRIVE_NO_ROOT_DIR"���o��.
	}
	else if (dwRet == DRIVE_REMOVABLE){	// �����[�o�u��.
		_tprintf(_T("DRIVE_REMOVABLE\n"));	// "DRIVE_REMOVABLE"���o��.
	}
	else if (dwRet == DRIVE_FIXED){	// �Œ�.
		_tprintf(_T("DRIVE_FIXED\n"));	// "DRIVE_FIXED"���o��.
	}
	else if (dwRet == DRIVE_REMOTE){	// �����[�g.
		_tprintf(_T("DRIVE_REMOTE\n"));	// "DRIVE_REMOTE"���o��.
	}
	else if (dwRet == DRIVE_CDROM){	// CD-ROM.
		_tprintf(_T("DRIVE_CDROM\n"));	// "DRIVE_CDROM"���o��.
	}
	else if (dwRet == DRIVE_RAMDISK){	// RAM�f�B�X�N.
		_tprintf(_T("DRIVE_RAMDISK\n"));	// "DRIVE_RAMDISK"���o��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}