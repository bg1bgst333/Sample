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
		
		// ���΃p�X�ł���.
		_tprintf(_T("Relative!\n"));	// "Relative!"�Əo��.

		// ��΃p�X���擾����.
		TCHAR tszFullPath[MAX_PATH] = {0};	// �t���p�X��������i�[����TCHAR�^�z��tszFullPath(����MAX_PATH)��{0}�ŏ�����.
		TCHAR *ptszFilePart = NULL;	// �p�X�̃t�@�C�����������w��TCHAR�^�|�C���^ptszFilePart��NULL�ŏ�����.
		DWORD dwRet = GetFullPathName(argv[1], MAX_PATH, tszFullPath, &ptszFilePart);	// GetFullPathName��argv[1]�̃t���p�X���擾.
		if (dwRet != 0){	// 0�ȊO�Ȃ琬��.
			_tprintf(_T("tszFullPath = %s\n"), tszFullPath);	// tszFullPath���o��.
			_tprintf(_T("ptszFilePart = %s\n"), ptszFilePart);	// ptszFilePart���o��.
		}
		else{	// 0�Ȃ玸�s.
			_tprintf(_T("GetFullPathName failed.\n"));	// "GetFullPathName failed."���o��.
		}

	}
	else{	// bRet��FALSE.
		_tprintf(_T("Not relative!\n"));	// "Not relative!"�Əo��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}