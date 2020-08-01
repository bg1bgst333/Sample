// ��d�C���N���[�h�h�~
#ifndef __WINDOW_H__
#define __WINDOW_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <string>		// std::wstring
#include <map>			// std::map

// �E�B���h�E�N���XCWindow
class CWindow{

	// public�����o
	public:

		// �����o�ϐ�
		std::wstring m_wstrWindowName;	// �E�B���h�E��m_wstrWindowName.
		// static�����o�ϐ�
		static std::map<HWND, CWindow *>m_mapWindowMap;	// �E�B���h�E�n���h�����L�[, CWindow�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapWindowMap.

		// �����o�֐�
		virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// CWindow�N���X���̃E�B���h�E�v���V�[�W��.

};

#endif