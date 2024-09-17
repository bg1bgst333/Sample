// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
// �Ǝ��̃w�b�_
#include "Application.h"	// Word::CApplication

// �R���X�g���N�^CApplication
Word::CApplication::CApplication() {

}

// static�Ȑ����֐�CreateInstance.
Word::CApplication * Word::CApplication::CreateInstance() {

	// �ϐ��̐錾�Ə�����.
	CLSID clsid;	// CLSID���i�[����clsid.
	IDispatch * pDispatch = NULL;	// IDispatch�|�C���^pDispatch��NULL�ŏ�����.

	// "Word.Application"��CLSID�̎擾.
	HRESULT hr = CLSIDFromProgID(_T("Word.Application"), &clsid);	// CLSIDFromProgID��"Word.Application"��clsid���擾.
	if (FAILED(hr)) {	// ���s.
		return NULL;
	}

	// IDispatch�|�C���^pDispatch�̎擾.
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pDispatch));	// CoCreateInstance��, pDispatch�𐶐�.
	if (FAILED(hr)) {	// ���s.
		return NULL;
	}

	// ����.
	CApplication *pApplication = new CApplication();
	pApplication->m_pDispatch = pDispatch;
	return pApplication;

}

// �f�X�g���N�^~CApplication
Word::CApplication::~CApplication() {

	// m_pDispatch�̉��.
	if (m_pDispatch != NULL) {	// m_pDispatch��NULL�łȂ����.
		m_pDispatch->Release();	// IDispatch::Release�ŉ��.
		m_pDispatch = NULL;	// NULL���Z�b�g.
	}

}

// �\���E��\���v���p�e�B.
BOOL Word::CApplication::put_Visible(BOOL bVisible) {

	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Visible";	// lpwszName��"Visible"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		return FALSE;
	}

	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	VARIANT var;	// VARIANT�\����var.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	var.vt = VT_I4;	// 4�o�C�gint.
	if (bVisible) {	// TRUE�Ȃ�.
		var.lVal = 1;	// �l��1.
	}
	else {
		var.lVal = 0;	// �l��0.
	}
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
