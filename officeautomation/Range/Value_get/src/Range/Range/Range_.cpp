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

	// Range�̎擾.
	Excel::CRange * pRange = NULL;	// CRange�|�C���^pRange��NULL�ŏ�����.
	pRange = pActiveSheet->get_Cells();	// Excel::CWorksheet::get_Cells��pRange���擾.

	// �擾����pRange���o��.
	_tprintf(_T("CRange * pRange = 0x%08x\n"), (unsigned long)pRange);	// pRange���o��.

	// Item��1�s�ڂ�1��ڂ�Range���擾.
	Excel::CRange *pRange11 = NULL;	// CRange�|�C���^pRange11��NULL�ŏ�����.
	pRange11 = pRange->get_Item(1, 1);	// Excel::CRange::get_Item(1, 1)��pRange11���擾.

	// �擾����pRange11���o��.
	_tprintf(_T("CRange * pRange11 = 0x%08x\n"), (unsigned long)pRange11);	// pRange11���o��.

	// 1�s�ڂ�1��ڂ̒l���擾.
	VARIANT var11;	// VARIANT�\����var11.
	VariantInit(&var11);	// var11��VariantInit�ŏ�����.
	pRange11->get_Value(&var11);	// Excel::CRange::get_Value�Œl���擾.
	if (var11.vt == VT_R8) {	// 8�o�C�g����.
		_tprintf(_T("var11.dblVal = %le\n"), var11.dblVal);	// var11.dblVal���o��.
	}
	else if (var11.vt == VT_BSTR) {	// BSTR������
		char *old = setlocale(LC_ALL, "japanese");	// setlocale��LC_ALL, "japanese"���Z�b�g.
		_tprintf(_T("var11.bstrVal = %s\n"), var11.bstrVal);	// var11.bstrVal���o��.
		setlocale(LC_ALL, old);	// setlocale��LC_ALL, old���Z�b�g.
	}
	VariantClear(&var11);	// var11��VariantClear�ŃN���A.

	// Item��1�s�ڂ�2��ڂ�Range���擾.
	Excel::CRange *pRange12 = NULL;	// CRange�|�C���^pRange12��NULL�ŏ�����.
	pRange12 = pRange->get_Item(1, 2);	// Excel::CRange::get_Item(1, 2)��pRange12���擾.

	// �擾����pRange12���o��.
	_tprintf(_T("CRange * pRange12 = 0x%08x\n"), (unsigned long)pRange12);	// pRange12���o��.

	// 1�s�ڂ�2��ڂ̒l���擾.
	VARIANT var12;	// VARIANT�\����var12.
	VariantInit(&var12);	// var12��VariantInit�ŏ�����.
	pRange12->get_Value(&var12);	// Excel::CRange::get_Value�Œl���擾.
	if (var12.vt == VT_R8) {	// 8�o�C�g����.
		_tprintf(_T("var12.dblVal = %le\n"), var12.dblVal);	// var12.dblVal���o��.
	}
	else if (var12.vt == VT_BSTR) {	// BSTR������
		char *old = setlocale(LC_ALL, "japanese");	// setlocale��LC_ALL, "japanese"���Z�b�g.
		_tprintf(_T("var12.bstrVal = %s\n"), var12.bstrVal);	// var12.bstrVal���o��.
		setlocale(LC_ALL, old);	// setlocale��LC_ALL, old���Z�b�g.
	}
	VariantClear(&var12);	// var12��VariantClear�ŃN���A.

	// pRange12�̔j��.
	if (pRange12 != NULL) {
		delete pRange12;
	}

	// pRange11�̔j��.
	if (pRange11 != NULL) {
		delete pRange11;
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