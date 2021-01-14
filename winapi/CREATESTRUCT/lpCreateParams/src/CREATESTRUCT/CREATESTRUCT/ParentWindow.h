// ��d�C���N���[�h�h�~
#ifndef __PARENTWINDOW_H__
#define __PARENTWINDOW_H__

// �w�b�_�t�@�C���̃C���N���[�h
// �Ǝ��̃w�b�_�t�@�C��
#include "Window.h"	// CWindow
#include "ChildWindow.h"	// CChildWindow

// �E�B���h�E�N���XCParentWindow
class CParentWindow : public CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		CChildWindow *m_pChildWindow;	// �q�E�B���h�E�|�C���^m_pChildWindow.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		virtual ~CParentWindow();	// �f�X�g���N�^~CParentWindow()
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.

};

#endif