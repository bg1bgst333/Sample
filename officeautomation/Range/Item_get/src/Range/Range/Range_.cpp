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

	// Worksheets�̎擾.
	Excel::CWorksheets * pWorksheets = NULL;	// CWorksheets�|�C���^pWorksheets��NULL�ŏ�����.
	pWorksheets = pWorkbook->get_Worksheets();	// Excel::CWorkbook::get_Worksheets��pWorksheets���擾.

	// �擾����pWorksheets���o��.
	_tprintf(_T("CWorksheets * pWorksheets = 0x%08x\n"), (unsigned long)pWorksheets);	// pWorksheets���o��.

	// Worksheet��ǉ�.
	Excel::CWorksheet * pWorksheet = NULL;	// CWorksheet�|�C���^pWorksheet��NULL�ŏ�����.
	pWorksheet = pWorksheets->Add();	// Excel::CWorksheets::Add��Worksheet��ǉ���, ������擾.

	// �ǉ�����pWorksheet���o��.
	_tprintf(_T("CWorksheet * pWorksheet = 0x%08x\n"), (unsigned long)pWorksheet);	// pWorksheet���o��.

	// Range�̎擾.
	Excel::CRange * pRange = NULL;	// CRange�|�C���^pRange��NULL�ŏ�����.
	pRange = pWorksheet->get_Cells();	// Excel::CWorksheet::get_Cells��pRange���擾.

	// �擾����pRange���o��.
	_tprintf(_T("CRange * pRange = 0x%08x\n"), (unsigned long)pRange);	// pRange���o��.

	// Item��3�s�ڂ�2��ڂ�Range���擾.
	Excel::CRange *pRange2 = NULL;	// CRange�|�C���^pRange2��NULL�ŏ�����.
	pRange2 = pRange->get_Item(3, 2);	// Excel::CRange::get_Item(3, 2)��pRange2���擾.

	// �擾����pRange2���o��.
	_tprintf(_T("CRange * pRange2 = 0x%08x\n"), (unsigned long)pRange2);	// pRange2���o��.

	// pRange2�̔j��.
	if (pRange2 != NULL) {
		delete pRange2;
	}

	// pRange�̔j��.
	if (pRange != NULL) {
		delete pRange;
	}

	// pWorksheet�̔j��.
	if (pWorksheet != NULL) {
		delete pWorksheet;
	}

	// pWorksheets�̔j��.
	if (pWorksheets != NULL) {
		delete pWorksheets;
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