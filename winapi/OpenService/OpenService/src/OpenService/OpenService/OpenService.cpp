// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	SC_HANDLE hSCM = NULL;	// SC_HANDLE�^hSCM��NULL�ŏ�����.
	SC_HANDLE hService = NULL;	// SC_HANDLE�^hService��NULL�ŏ�����.
	LPCTSTR lpctszService = _T("Irmon");	// �T�[�r�X��lpctszService��"Irmon"�ŏ�����.

	// SCManager�̃I�[�v��
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);	// OpenSCManager��SCManager���J��, �n���h����hSCM�Ɋi�[.
	if (hSCM != NULL){	// NULL�łȂ���.

		// hSCM�̏o��.
		_tprintf(_T("hSCM = 0x%08x\n"), (unsigned long)hSCM);	// hSCM�̒l���o��.

		// Service�̃I�[�v��
		hService = OpenService(hSCM, lpctszService, SERVICE_START);	// OpenService��"Irmon"���J��.
		if (hService != NULL){	// NULL�łȂ���.

			// hService�̏o��.
			_tprintf(_T("hService = 0x%08x\n"), (unsigned long)hService);	// hService�̒l���o��.
			Sleep(5000);	// 5�b�҂�.
			CloseServiceHandle(hService);	// CloseServiceHandle��hService�����.

		}
		else{	// NULL�̎�.
			_tprintf(_T("OpenService failed!\n"));	// "OpenService failed!"�Əo��.
		}

		// hSCM�����.
		CloseServiceHandle(hSCM);	// CloseServiceHandle��hSCM�����.

	}
	else{	// NULL�̎�.
		_tprintf(_T("OpenSCManager failed!\n"));	// "OpenSCManager failed!"�Əo��.
	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}