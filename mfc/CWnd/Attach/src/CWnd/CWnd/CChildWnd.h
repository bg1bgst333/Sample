// ��d�C���N���[�h�h�~
#pragma once	// VisualC++�Ǝ��̃v���v���Z�b�T#pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <afxwin.h>	// MFC�W��
#include <tchar.h>	// TCHAR�^

// CWnd�̔h���N���XCChildWnd�̒�`
class CChildWnd : public CWnd{	// �q�E�B���h�E�N���X

	// public�����o
	public:

		// public�����o�֐�
		// �n���h��
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.

		// ���b�Z�[�W�}�b�v
		DECLARE_MESSAGE_MAP()	// ���b�Z�[�W�}�b�v�̗��p��錾.

};
