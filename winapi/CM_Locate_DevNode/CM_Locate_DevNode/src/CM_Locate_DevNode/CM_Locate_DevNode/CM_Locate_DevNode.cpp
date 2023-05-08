// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <cfgmgr32.h>	// Configuration Manager

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �w��̃f�o�C�X�C���X�^���X�p�X��DEVINST�擾.
	DWORD dwDevInst;	// �w��̃f�o�C�X�C���X�^���X�p�X��DEVINST�ł���dwDevInst.
	DWORD dwRet = CM_Locate_DevNode(&dwDevInst, argv[1], CM_LOCATE_DEVNODE_NORMAL);	// CM_Locate_DevNode�Ŏw��̃f�o�C�X�C���X�^���X�p�X��DEVINST�擾.
	if (dwRet == CR_SUCCESS){	// CR_SUCCESS�Ȃ琬��.
		_tprintf(_T("dwDevInst = %lu\n"), dwDevInst);	// dwDevInst���o��.
	}
	else{	// ���s.
		_tprintf(_T("CM_Locate_DevNode failure.\n"));	// "CM_Locate_DevNode failure."���o��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}