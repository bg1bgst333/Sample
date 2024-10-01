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

	// A1�̗̈���擾.
	Excel::CRange *pRangeA1 = NULL;	// CRange�|�C���^pRangeA1��NULL�ŏ�����.
	pRangeA1 = pActiveSheet->get_Range(_T("A1"));	// Excel::CWorksheet::get_Range��pRangeA1���擾.
	_tprintf(_T("CRange * pRangeA1 = 0x%08x\n"), (unsigned long)pRangeA1);	// pRangeA1���o��.

	// A1�̘g�̌r�����擾.
	IDispatch *pBordersA1 = NULL;	// IDispatch�|�C���^pBordersA1��NULL�ŏ�����.
	pBordersA1 = pRangeA1->get_Borders();	// Excel::CRange::get_Borders��pBordersA1���擾.
	_tprintf(_T("IDispatch * pBordersA1 = 0x%08x\n"), (unsigned long)pBordersA1);	// pBordersA1���o��.

	// B2:C3�̗̈���擾.
	Excel::CRange *pRangeB2C3 = NULL;	// CRange�|�C���^pRangeB2C3��NULL�ŏ�����.
	pRangeB2C3 = pActiveSheet->get_Range(_T("B2:C3"));	// Excel::CWorksheet::get_Range��pRangeB2C3���擾.
	_tprintf(_T("CRange * pRangeB2C3 = 0x%08x\n"), (unsigned long)pRangeB2C3);	// pRangeB2C3���o��.

	// B2:C3�̘g�̌r�����擾.
	IDispatch *pBordersB2C3 = NULL;	// IDispatch�|�C���^pBordersB2C3��NULL�ŏ�����.
	pBordersB2C3 = pRangeB2C3->get_Borders();	// Excel::CRange::get_Borders��pBordersB2C3���擾.
	_tprintf(_T("IDispatch * pBordersB2C3 = 0x%08x\n"), (unsigned long)pBordersB2C3);	// pBordersB2C3���o��.

	// pBordersB2C3�̔j��.
	if (pBordersB2C3 != NULL) {
		pBordersB2C3->Release();
		pBordersB2C3 = NULL;
	}

	// pRangeB2C3�̔j��.
	if (pRangeB2C3 != NULL) {
		delete pRangeB2C3;
	}

	// pBordersA1�̔j��.
	if (pBordersA1 != NULL) {
		pBordersA1->Release();
		pBordersA1 = NULL;
	}

	// pRangeA1�̔j��.
	if (pRangeA1 != NULL) {
		delete pRangeA1;
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