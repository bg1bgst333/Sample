// ��d�C���N���[�h�h�~
#pragma once	// VisualC++�Ǝ��̃v���v���Z�b�T#pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CWinApp�̔h���N���XCWinApp_�̒�`
class CWinApp_ : public CWinApp{	// �A�v���P�[�V�����N���X

	// public�����o
	public:

		// public�����o�֐�
		// ���N���X�̃����o�֐��̃I�[�o�[���C�h
		virtual BOOL InitInstance();		// �C���X�^���X�̏���������

};

// �A�v���P�[�V�����C���X�^���X�̐錾
CWinApp_ theApp;	// CWinApp_�̃C���X�^���XtheApp��錾.