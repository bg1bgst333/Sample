// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Workbook.h"	// Excel::CWorkbook

// �R���X�g���N�^CWorkbook
Excel::CWorkbook::CWorkbook() {

}

// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
Excel::CWorkbook::CWorkbook(IDispatch *pDispatch) {

	// m_pDispatch�ɃZ�b�g.
	m_pDispatch = pDispatch;

}

// �f�X�g���N�^~CCWorkbook
Excel::CWorkbook::~CWorkbook() {

	// m_pDispatch�̉��.
	if (m_pDispatch != NULL) {	// m_pDispatch��NULL�łȂ����.
		m_pDispatch->Release();	// IDispatch::Release�ŉ��.
		m_pDispatch = NULL;	// NULL���Z�b�g.
	}

}

// Worksheets�I�u�W�F�N�g�v���p�e�B�̎擾.
Excel::CWorksheets * Excel::CWorkbook::get_Worksheets() {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Worksheets";	// lpwszName��"Worksheets"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		return NULL;
	}

	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	VARIANT var;	// VARIANT�\����var.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	VariantInit(&var);	// var��VariantInit�ŏ�����.
	dispparams.cArgs = 0;	// �����̐���0.
	dispparams.rgvarg = NULL;	// NULL���w��.
	dispparams.rgdispidNamedArgs = NULL;	// NULL���w��.
	dispparams.cNamedArgs = 0;	// cNamedArgs��0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, &var, NULL, NULL);	// IDispatch::Invoke�ŃA�N�Z�X.
	if (FAILED(hr)) {	// ���s.
		return NULL;
	}

	// ����.
	CWorksheets *pWorksheets = new CWorksheets(var.pdispVal);	// CWorksheets�̃R���X�g���N�^��var.pdispVal���Z�b�g.
	return pWorksheets;

}