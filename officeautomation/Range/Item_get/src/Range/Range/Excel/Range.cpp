// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Range.h"	// Excel::CRange

// �R���X�g���N�^CRange
Excel::CRange::CRange() {

}

// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
Excel::CRange::CRange(IDispatch *pDispatch) {

	// m_pDispatch�ɃZ�b�g.
	m_pDispatch = pDispatch;

}

// �f�X�g���N�^~CRange
Excel::CRange::~CRange() {

	// m_pDispatch�̉��.
	if (m_pDispatch != NULL) {	// m_pDispatch��NULL�łȂ����.
		m_pDispatch->Release();	// IDispatch::Release�ŉ��.
		m_pDispatch = NULL;	// NULL���Z�b�g.
	}

}

// Item�v���p�e�B(Range�I�u�W�F�N�g)�̎擾.
Excel::CRange * Excel::CRange::get_Item(int i, int j) {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Item";	// lpwszName��"Item"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		return NULL;
	}

	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	VARIANT var[2];	// VARIANT�\���̔z��var.
	VARIANT varResult;	// ���ʂ��i�[����VARIANT�\����varResult.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	// �����̈����̏ꍇ, �t���Ȃ̂Œ���.(�s(i)��var[1], ��(j)��var[0]�ɂȂ�.)
	VariantInit(&var[1]);	// var[1]��������.
	var[1].vt = VT_I4;	// 4�o�C�gint.
	var[1].lVal = i;	// i����.
	VariantInit(&var[0]);	// var[0]��������.
	var[0].vt = VT_I4;	// 4�o�C�gint.
	var[0].lVal = j;	// j����.
	VariantInit(&varResult);	// VariantInit��varResult������.
	dispparams.cArgs = 2;	// �����̐���2.
	dispparams.rgvarg = var;	// var���w��.
	dispparams.rgdispidNamedArgs = NULL;	// NULL���w��.
	dispparams.cNamedArgs = 0;	// cNamedArgs��0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, &varResult, NULL, NULL);	// IDispatch::Invoke�ŃA�N�Z�X.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// ����.
	CRange *pRange = new CRange(varResult.pdispVal);	// CRange�̃R���X�g���N�^��varResult.pdispVal���Z�b�g.
	return pRange;

}
