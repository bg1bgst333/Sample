// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Worksheet.h"	// Excel::CWorksheet

// �R���X�g���N�^CWorksheet
Excel::CWorksheet::CWorksheet() {

}

// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
Excel::CWorksheet::CWorksheet(IDispatch *pDispatch) {

	// m_pDispatch�ɃZ�b�g.
	m_pDispatch = pDispatch;

}

// �f�X�g���N�^~CWorksheet
Excel::CWorksheet::~CWorksheet() {

	// m_pDispatch�̉��.
	if (m_pDispatch != NULL) {	// m_pDispatch��NULL�łȂ����.
		m_pDispatch->Release();	// IDispatch::Release�ŉ��.
		m_pDispatch = NULL;	// NULL���Z�b�g.
	}

}

// Cells�v���p�e�B(Range�I�u�W�F�N�g)�̎擾.
Excel::CRange * Excel::CWorksheet::get_Cells() {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Cells";	// lpwszName��"Cells"�ŏ�����.
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
	CRange *pRange = new CRange(var.pdispVal);	// CRange�̃R���X�g���N�^��var.pdispVal���Z�b�g.
	return pRange;

}
