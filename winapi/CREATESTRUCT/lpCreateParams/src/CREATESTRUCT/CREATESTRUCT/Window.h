// ��d�C���N���[�h�h�~
#ifndef __WINDOW_H__
#define __WINDOW_H__

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <map>	// std::map

// �E�B���h�E�N���XCWindow
class CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd.

		// static�����o�ϐ�
		static std::map<HWND, CWindow *>m_mapWindowMap;	// �E�B���h�E�n���h�����L�[, CWindow�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapWindowMap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWindow();	// �R���X�g���N�^CWindow()
		virtual ~CWindow();	// �f�X�g���N�^~CWindow()
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.

};

#endif