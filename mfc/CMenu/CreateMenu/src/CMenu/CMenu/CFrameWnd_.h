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
		CMenu *m_pMenu;	// CMenu�I�u�W�F�N�g�|�C���^m_pMenu.

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^
		CFrameWnd_();	// �R���X�g���N�^(�����Ȃ�)

		// �n���h��
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// ���j���[����Item1_1��UI�X�V�n���h��
		void OnItem1_1();	// ���j���[����Item1_1�̃R�}���h�n���h��
		virtual void OnPaint();	// ��ʂ̕`���v�����ꂽ��.

		// ���b�Z�[�W�}�b�v
		DECLARE_MESSAGE_MAP()	// ���b�Z�[�W�}�b�v�̗��p��錾.

};