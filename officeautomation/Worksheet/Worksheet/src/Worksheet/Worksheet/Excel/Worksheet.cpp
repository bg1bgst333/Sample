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