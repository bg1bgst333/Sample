// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Border.h"	// Excel::CBorder

// �R���X�g���N�^CBorder
Excel::CBorder::CBorder() {

}

// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
Excel::CBorder::CBorder(IDispatch *pDispatch) {

	// m_pDispatch�ɃZ�b�g.
	m_pDispatch = pDispatch;

}

// �f�X�g���N�^~CBorder
Excel::CBorder::~CBorder() {

	// m_pDispatch�̉��.
	if (m_pDispatch != NULL) {	// m_pDispatch��NULL�łȂ����.
		m_pDispatch->Release();	// IDispatch::Release�ŉ��.
		m_pDispatch = NULL;	// NULL���Z�b�g.
	}

}

// LineStyle�v���p�e�B�̐ݒ�.
BOOL Excel::CBorder::put_LineStyle(XlLineStyle xlLineStyle) {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"LineStyle";	// lpwszName��"LineStyle"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// �n���ꂽ�����̃Z�b�g.
	VARIANT var;	// VARIANT�\����var.
	VariantInit(&var);	// var��VariantInit�ŏ�����.
	var.vt = VT_I4;
	var.lVal = xlLineStyle;
	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	dispparams.cArgs = 1;	// �����̐���1.
	dispparams.rgvarg = &var;	// &var���w��.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidname���w��.
	dispparams.cNamedArgs = 1;	// cNamedArgs��1.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, NULL, NULL, NULL);	// IDispatch::Invoke�ŃA�N�Z�X.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// ����.
	return TRUE;

}

// Weight�v���p�e�B�̐ݒ�.
BOOL Excel::CBorder::put_Weight(XlBorderWeight xlBorderWeight) {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Weight";	// lpwszName��"Weight"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// �n���ꂽ�����̃Z�b�g.
	VARIANT var;	// VARIANT�\����var.
	VariantInit(&var);	// var��VariantInit�ŏ�����.
	var.vt = VT_I4;
	var.lVal = xlBorderWeight;
	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	dispparams.cArgs = 1;	// �����̐���1.
	dispparams.rgvarg = &var;	// &var���w��.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidname���w��.
	dispparams.cNamedArgs = 1;	// cNamedArgs��1.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, NULL, NULL, NULL);	// IDispatch::Invoke�ŃA�N�Z�X.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// ����.
	return TRUE;

}
