// CWinApp_.h : CWinApp_ �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CWinApp_App:
// ���̃N���X�̎����ɂ��ẮACWinApp_.cpp ���Q�Ƃ��Ă��������B
//

class CWinApp_App : public CWinApp
{
public:
	CWinApp_App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWinApp_App theApp;