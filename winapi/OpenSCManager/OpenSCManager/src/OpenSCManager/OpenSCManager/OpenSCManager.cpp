// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	SC_HANDLE hSCM = NULL;	// SC_HANDLE�^hSCM��NULL�ŏ�����.

	// SCManager�̃I�[�v��
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);	// OpenSCManager��SCManager���J��, �n���h����hSCM�Ɋi�[.
	if (hSCM != NULL){	// NULL�łȂ���.
		_tprintf(_T("hSCM = 0x%08x\n"), (unsigned long)hSCM);	// hSCM�̒l���o��.
		CloseServiceHandle(hSCM);	// CloseServiceHandle��hSCM�����.
	}
	else{	// NULL�̎�.
		_tprintf(_T("OpenSCManager failed!\n"));	// "OpenSCManager failed!"�Əo��.
	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}