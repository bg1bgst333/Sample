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
	Excel::CWorkbooks * pWorkbooks = NULL;	// CWorkbooks�|�C���^pWorkbooks��NULL�ŏ�����.
	pWorkbooks = pApplication->get_Workbooks();	// Excel::CApplication::get_Workbooks��pWorkbooks���擾.

	// �擾����pWorkbooks���o��.
	_tprintf(_T("CWorkbooks * pWorkbooks = 0x%08x\n"), (unsigned long)pWorkbooks);	// pWorkbooks���o��.

	// xlsx�t�@�C���̃p�X����.
	TCHAR tszCurrentPath[MAX_PATH] = { 0 };	// ���̃v���Z�X�̌��݂̃f�B���N�g���p�X���w��TCHAR�z��tszCurrentPath(����MAX_PATH)��{0}�ŏ�����.
	GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectory��tszCurrentPath���擾.
	_tcscat(tszCurrentPath, _T("\\"));	// "\"��A��.
	_tcscat(tszCurrentPath, _T("test.xlsx"));	// "test.xlsx"��A��.

	// Workbook���J��.
	Excel::CWorkbook * pWorkbook = NULL;	// CWorkbook�|�C���^pWorkbook��NULL�ŏ�����.
	pWorkbook = pWorkbooks->Open(tszCurrentPath);	// Excel::CWorkbooks::Open��tszCurrentPath���J��, ������擾.

	// �ǉ�����pWorkbook���o��.
	_tprintf(_T("CWorkbook * pWorkbook = 0x%08x\n"), (unsigned long)pWorkbook);	// pWorkbook���o��.

	// ActiveSheet�̎擾.
	Excel::CWorksheet * pActiveSheet = NULL;	// CWorksheet�|�C���^pActiveSheet��NULL�ŏ�����.
	pActiveSheet = pWorkbook->get_ActiveSheet();	// Excel::CWorkbook::get_ActiveSheet��pActiveSheet���擾.

	// �擾����pActiveSheet���o��.
	_tprintf(_T("CWorksheet * pActiveSheet = 0x%08x\n"), (unsigned long)pActiveSheet);	// pActiveSheet���o��.

	// Range�̎擾.
	Excel::CRange * pRange = NULL;	// CRange�|�C���^pRange��NULL�ŏ�����.
	pRange = pActiveSheet->get_Cells();	// Excel::CWorksheet::get_Cells��pRange���擾.

	// �擾����pRange���o��.
	_tprintf(_T("CRange * pRange = 0x%08x\n"), (unsigned long)pRange);	// pRange���o��.

	// Item��1�s�ڂ�1��ڂ�Range���擾.
	Excel::CRange *pRange2 = NULL;	// CRange�|�C���^pRange2��NULL�ŏ�����.
	pRange2 = pRange->get_Item(1, 1);	// Excel::CRange::get_Item(1, 1)��pRange2���擾.

	// �擾����pRange2���o��.
	_tprintf(_T("CRange * pRange2 = 0x%08x\n"), (unsigned long)pRange2);	// pRange2���o��.

	// 1�s�ڂ�1��ڂɒl456���Z�b�g.
	pRange2->put_Value(456);	// Excel::CRange::put_Value(456)�Œl456���Z�b�g.

	// pRange2�̔j��.
	if (pRange2 != NULL) {
		delete pRange2;
	}

	// pRange�̔j��.
	if (pRange != NULL) {
		delete pRange;
	}

	// pActiveSheet�̔j��.
	if (pActiveSheet != NULL) {
		delete pActiveSheet;
	}

	// pWorkbook�̔j��.
	if (pWorkbook != NULL) {
		delete pWorkbook;
	}

	// pWorkbooks�̔j��.
	if (pWorkbooks != NULL) {
		delete pWorkbooks;
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