// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Excel/Application.h"	// Excel::CApplication

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]) {	// main�֐���TCHAR��.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// Excel::CApplication�̐���
	Excel::CApplication *pApplication = Excel::CApplication::CreateInstance();	// Excel::CApplication::CreateInstance�ō쐬.

	// �擾����pApplication���o��.
	_tprintf(_T("pApplication = 0x%08x\n"), (unsigned long)pApplication);	// pApplication���o��.

	// �A�v���P�[�V�����̕\��.
	pApplication->put_Visible(TRUE);	// Excel::CApplication::put_Visible��TRUE�n���ĕ\��.

	// Workbooks�̎擾.
	IDispatch * pWorkbooks = NULL;	// IDispatch�|�C���^pWorkbooks��NULL�ŏ�����.
	pWorkbooks = pApplication->get_Workbooks();	// Excel::CApplication::get_Workbooks��pWorkbooks���擾.

	// �擾����pWorkbooks���o��.
	_tprintf(_T("IDispatch * pWorkbooks = 0x%08x\n"), (unsigned long)pWorkbooks);	// pWorkbooks���o��.

	// pWorkbooks�̔j��.
	if (pWorkbooks != NULL) {
		pWorkbooks->Release();
		pWorkbooks = NULL;
	}
	
	// pApplication�̔j��.
	if (pApplication != NULL) {
		delete pApplication;
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.
										
	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}