// ��d�C���N���[�h�h�~
#ifndef __CHILDWINDOW_H__
#define __CHILDWINDOW_H__

// �w�b�_�t�@�C���̃C���N���[�h
// �Ǝ��̃w�b�_�t�@�C��
#include "Window.h"	// CWindow

// �E�B���h�E�N���XCChildWindow
class CChildWindow : public CWindow{

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		virtual ~CChildWindow();	// �f�X�g���N�^~CChildWindow()
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.

};

#endif