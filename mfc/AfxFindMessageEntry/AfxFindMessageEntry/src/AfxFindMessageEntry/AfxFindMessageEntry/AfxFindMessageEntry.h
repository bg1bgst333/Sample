// AfxFindMessageEntry.h : AfxFindMessageEntry �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CAfxFindMessageEntryApp:
// ���̃N���X�̎����ɂ��ẮAAfxFindMessageEntry.cpp ���Q�Ƃ��Ă��������B
//

class CAfxFindMessageEntryApp : public CWinApp
{
public:
	CAfxFindMessageEntryApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAfxFindMessageEntryApp theApp;