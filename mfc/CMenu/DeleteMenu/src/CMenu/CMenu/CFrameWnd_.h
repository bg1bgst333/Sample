// ��d�C���N���[�h�h�~
#pragma once	// VisualC++�Ǝ��̃v���v���Z�b�T#pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CFrameWnd�̔h���N���XCFrameWnd_�̒�`
class CFrameWnd_ : public CFrameWnd{	// �t���[���E�B���h�E�N���X

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^
		CFrameWnd_();	// �R���X�g���N�^(�����Ȃ�)

		// �n���h��
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// ���j���[����Item1_1��UI�X�V�n���h��
		void OnItem1_1();	// ���j���[����Item1_1�̃R�}���h�n���h��
		void OnUpdateItem1_2(CCmdUI* pCmdUI);	// ���j���[����Item1_2��UI�X�V�n���h��
		void OnItem1_2();	// ���j���[����Item1_2�̃R�}���h�n���h��
		void OnUpdateItem1_3(CCmdUI* pCmdUI);	// ���j���[����Item1_3��UI�X�V�n���h��
		void OnItem1_3();	// ���j���[����Item1_3�̃R�}���h�n���h��

		// ���b�Z�[�W�}�b�v
		DECLARE_MESSAGE_MAP()	// ���b�Z�[�W�}�b�v�̗��p��錾.

};