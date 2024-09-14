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