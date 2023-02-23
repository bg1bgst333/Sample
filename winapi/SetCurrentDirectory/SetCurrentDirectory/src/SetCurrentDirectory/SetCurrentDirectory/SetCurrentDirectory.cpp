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

	// ��΃p�X�ݒ�
	// 2��̃f�B���N�g���p�X���擾����.
	TCHAR tszTwoUpPath[MAX_PATH] = {0};	// 2��̃f�B���N�g���p�X���i�[����TCHAR�^�z��tszTwoUpPath(����MAX_PATH)��{0}�ŏ�����.
	TCHAR *ptszFilePart = NULL;	// �p�X�̃t�@�C�����������w��TCHAR�^�|�C���^ptszFilePart��NULL�ŏ�����.
	TCHAR tszRelativePath[MAX_PATH] = {0};	// ���΃p�XtszRelativePath(����MAX_PATH)��{0}�ŏ�����.
	_stprintf(tszRelativePath, _T("%s\\..\\.."), tszCurrentPath);	// tszRelativePath��"\\..\\.."��A��.
	dwRet = GetFullPathName(tszRelativePath, MAX_PATH, tszTwoUpPath, &ptszFilePart);	// GetFullPathName��tszRelativePath�̃t���p�XtszTwoUpPath���擾.
	if (dwRet != 0){	// 0�ȊO�Ȃ琬��.
		_tprintf(_T("tszTwoUpPath = %s\n"), tszTwoUpPath);	// tszTwoUpPath���o��.
	}
	else{	// 0�Ȃ玸�s.
		_tprintf(_T("GetFullPathName failed.\n"));	// "GetFullPathName failed."���o��.
	}
	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X��, 2��̃f�B���N�g���p�X��ݒ肷��.
	BOOL bRet = SetCurrentDirectory(tszTwoUpPath);	// SetCurrentDirectory��tszTwoUpPath���Z�b�g.
	if (bRet){	// TRUE�Ȃ琬��.
		_tprintf(_T("SetCurrentDirectory success.\n"));	// "GetCurrentDirectory success."���o��.
		// �Ăь��݂̃p�X�擾.
		TCHAR tszCurrentPath[MAX_PATH] = {0};	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X���w��TCHAR�z��tszCurrentPath(����MAX_PATH)��{0}�ŏ�����.
		DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectory��tszCurrentPath���擾.
		if (dwRet != 0){	// ����.
			_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPath���o��.
		}
		else{	// ���s.
			_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."���o��.
		}
	}
	else{
		_tprintf(_T("SetCurrentDirectory failed.\n"));	// "SetCurrentDirectory failed."���o��.
	}

	// ���΃p�X�ݒ�
	// �����1��̃p�X��ݒ�.
	bRet = SetCurrentDirectory(_T(".."));	// SetCurrentDirectory��".."���Z�b�g.
	if (bRet){	// TRUE�Ȃ琬��.
		_tprintf(_T("SetCurrentDirectory success.\n"));	// "GetCurrentDirectory success."���o��.
		// �Ăь��݂̃p�X�擾.
		TCHAR tszCurrentPath[MAX_PATH] = {0};	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X���w��TCHAR�z��tszCurrentPath(����MAX_PATH)��{0}�ŏ�����.
		DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectory��tszCurrentPath���擾.
		if (dwRet != 0){	// ����.
			_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPath���o��.
		}
		else{	// ���s.
			_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."���o��.
		}
	}
	else{
		_tprintf(_T("SetCurrentDirectory failed.\n"));	// "SetCurrentDirectory failed."���o��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}