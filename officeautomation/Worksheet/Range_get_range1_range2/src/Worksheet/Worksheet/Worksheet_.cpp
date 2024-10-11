// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <locale.h>		// ���P�[��

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

	// (1, 1)�̗̈���擾.
	Excel::CRange *pRange11 = NULL;	// CRange�|�C���^pRange11��NULL�ŏ�����.
	pRange11 = pActiveSheet->get_Cells(1, 1);	// Excel::CWorksheet::get_Cells��pRange11���擾.
	_tprintf(_T("CRange * pRange11 = 0x%08x\n"), (unsigned long)pRange11);	// pRange11���o��.

	// (2, 3)�̗̈���擾.
	Excel::CRange *pRange23 = NULL;	// CRange�|�C���^pRange23��NULL�ŏ�����.
	pRange23 = pActiveSheet->get_Cells(2, 3);	// Excel::CWorksheet::get_Cells��pRange23���擾.
	_tprintf(_T("CRange * pRange23 = 0x%08x\n"), (unsigned long)pRange23);	// pRange23���o��.

	// (1, 1)����(2, 3)�̗̈���擾.
	Excel::CRange *pRange1123 = NULL;	// CRange�|�C���^pRange1123��NULL�ŏ�����.
	pRange1123 = pActiveSheet->get_Range(pRange11, pRange23);	// Excel::CWorksheet::get_Range��pRange1123���擾.
	_tprintf(_T("CRange * pRange1123 = 0x%08x\n"), (unsigned long)pRange1123);	// pRange1123���o��.

	// (1, 1)����(2, 3)�̗̈�̌r����j���ɂ���.
	Excel::CBorders *pBorders1123 = NULL;	// CBorders�|�C���^pBorders1123��NULL�ŏ�����.
	pBorders1123 = pRange1123->get_Borders();	// Excel::CRange::get_Borders��pBorders1123���擾.
	_tprintf(_T("CBorders * pBorders1123 = 0x%08x\n"), (unsigned long)pBorders1123);	// pBorders1123���o��.
	pBorders1123->put_LineStyle(Excel::XlLineStyle::xlDash);	// Excel::CBorders::put_LineStyle�Ōr���X�^�C����j����.

	// pBorders1123�̔j��.
	if (pBorders1123 != NULL) {
		delete pBorders1123;
	}

	// pRange1123�̔j��.
	if (pRange1123 != NULL) {
		delete pRange1123;
	}

	// pRange23�̔j��.
	if (pRange23 != NULL) {
		delete pRange23;
	}

	// pRange11�̔j��.
	if (pRange11 != NULL) {
		delete pRange11;
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