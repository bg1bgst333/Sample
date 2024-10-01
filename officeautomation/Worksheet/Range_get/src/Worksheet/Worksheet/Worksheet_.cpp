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

	// A1�̒l���擾.
	Excel::CRange *pRangeA1 = NULL;	// CRange�|�C���^pRangeA1��NULL�ŏ�����.
	pRangeA1 = pActiveSheet->get_Range(_T("A1"));	// Excel::CWorksheet::get_Range��pRangeA1���擾.
	_tprintf(_T("CRange * pRangeA1 = 0x%08x\n"), (unsigned long)pRangeA1);	// pRangeA1���o��.
	VARIANT varA1;	// VARIANT�\����varA1.
	VariantInit(&varA1);	// varA1��VariantInit�ŏ�����.
	pRangeA1->get_Value(&varA1);	// Excel::CRange::get_Value�Œl���擾.
	if (varA1.vt == VT_R8) {	// 8�o�C�g����.
		_tprintf(_T("varA1.dblVal = %le\n"), varA1.dblVal);	// varA1.dblVal���o��.
	}
	else if (varA1.vt == VT_BSTR) {	// BSTR������
		char *old = setlocale(LC_ALL, "japanese");	// setlocale��LC_ALL, "japanese"���Z�b�g.
		_tprintf(_T("varA1.bstrVal = %s\n"), varA1.bstrVal);	// varA1.bstrVal���o��.
		setlocale(LC_ALL, old);	// setlocale��LC_ALL, old���Z�b�g.
	}
	VariantClear(&varA1);	// varA1��VariantClear�ŃN���A.

	// B1�̒l���擾.
	Excel::CRange *pRangeB1 = NULL;	// CRange�|�C���^pRangeB1��NULL�ŏ�����.
	pRangeB1 = pActiveSheet->get_Range(_T("B1"));	// Excel::CWorksheet::get_Range��pRangeB1���擾.
	_tprintf(_T("CRange * pRangeB1 = 0x%08x\n"), (unsigned long)pRangeB1);	// pRangeB1���o��.
	VARIANT varB1;	// VARIANT�\����varB1.
	VariantInit(&varB1);	// varB1��VariantInit�ŏ�����.
	pRangeB1->get_Value(&varB1);	// Excel::CRange::get_Value�Œl���擾.
	if (varB1.vt == VT_R8) {	// 8�o�C�g����.
		_tprintf(_T("varB1.dblVal = %le\n"), varB1.dblVal);	// varB1.dblVal���o��.
	}
	else if (varB1.vt == VT_BSTR) {	// BSTR������
		char *old = setlocale(LC_ALL, "japanese");	// setlocale��LC_ALL, "japanese"���Z�b�g.
		_tprintf(_T("varB1.bstrVal = %s\n"), varB1.bstrVal);	// varB1.bstrVal���o��.
		setlocale(LC_ALL, old);	// setlocale��LC_ALL, old���Z�b�g.
	}
	VariantClear(&varB1);	// varB1��VariantClear�ŃN���A.

	// pRangeB1�̔j��.
	if (pRangeB1 != NULL) {
		delete pRangeB1;
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