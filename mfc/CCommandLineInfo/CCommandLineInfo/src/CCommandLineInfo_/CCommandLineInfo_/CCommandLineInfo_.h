// CCommandLineInfo_.h : CCommandLineInfo_ �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CCommandLineInfo_App:
// ���̃N���X�̎����ɂ��ẮACCommandLineInfo_.cpp ���Q�Ƃ��Ă��������B
//

class CCommandLineInfo_App : public CWinApp
{
public:
	CCommandLineInfo_App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCommandLineInfo_App theApp;