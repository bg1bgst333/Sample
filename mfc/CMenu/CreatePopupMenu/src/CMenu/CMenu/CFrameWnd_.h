// ��d�C���N���[�h�h�~
#pragma once	// VisualC++�Ǝ��̃v���v���Z�b�T#pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CFrameWnd�̔h���N���XCFrameWnd_�̒�`
class CFrameWnd_ : public CFrameWnd{	// �t���[���E�B���h�E�N���X

	// private�����o
	private:

		// private�����o�ϐ�
		BOOL m_bInitMenu;	// ���j���[�������t���Om_bInitMenu.
		CMenu m_cPopupMenu1;	// �����o�Ƃ��Ď����Ă����Ȃ��Ə������X�R�[�v�O�ꂽ��, �j�����ꂿ�Ⴄ.
		CMenu m_cPopupMenu2;	// �����o�Ƃ��Ď����Ă����Ȃ��Ə������X�R�[�v�O�ꂽ��, �j�����ꂿ�Ⴄ.
		CMenu m_cPopupMenu3;	// �����o�Ƃ��Ď����Ă����Ȃ��Ə������X�R�[�v�O�ꂽ��, �j�����ꂿ�Ⴄ.

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^
		CFrameWnd_();	// �R���X�g���N�^(�����Ȃ�)

		// �n���h��
		virtual void OnPaint();	// ��ʂ̕`���v�����ꂽ��.
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// ���j���[����Item1_1��UI�X�V�n���h��
		void OnItem1_1();	// ���j���[����Item1_1�̃R�}���h�n���h��
		void OnUpdateItem2_2(CCmdUI* pCmdUI);	// ���j���[����Item2_2��UI�X�V�n���h��
		void OnItem2_2();	// ���j���[����Item2_2�̃R�}���h�n���h��
		void OnUpdateItem3_3(CCmdUI* pCmdUI);	// ���j���[����Item3_3��UI�X�V�n���h��
		void OnItem3_3();	// ���j���[����Item3_3�̃R�}���h�n���h��

		// ���b�Z�[�W�}�b�v
		DECLARE_MESSAGE_MAP()	// ���b�Z�[�W�}�b�v�̗��p��錾.

};