// ��d�C���N���[�h�h�~
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �A�v���P�[�V�����N���XCApplication�̒�`
class CApplication{

	// public�����o
	public:

		// public�����o�ϐ�
		CWindow *m_pMainWnd;	// ���C���E�B���h�E�|�C���^m_pMainWnd.

		// public�����o�֐�
		// �R���X�g���N�^
		CApplication();	// �R���X�g���N�^CApplication
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) = 0;	// �C���X�^���X�������֐�InitInstance.(�������z�֐�)
		virtual int Run();	// ���b�Z�[�W���[�v�����֐�Run.
		virtual int ExitInstance();	// �I�������֐�ExitInstance.

};

#endif