// CCmdTarget_.h : CCmdTarget_ �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CCmdTarget_App:
// ���̃N���X�̎����ɂ��ẮACCmdTarget_.cpp ���Q�Ƃ��Ă��������B
//

class CCmdTarget_App : public CWinApp
{
public:
	CCmdTarget_App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCmdTarget_App theApp;