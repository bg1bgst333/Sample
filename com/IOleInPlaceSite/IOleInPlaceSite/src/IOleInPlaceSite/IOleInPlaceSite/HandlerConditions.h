// ��d�C���N���[�h�h�~
#ifndef __HANDLER_CONDITIONS_H__
#define __HANDLER_CONDITIONS_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �O���錾
class CWindow;	// �E�B���h�E�N���XCWindow

// �n���h���̔����������i�[����\����HandlerConditions
struct HandlerConditions{
	UINT m_nID;	// ���\�[�XID
	UINT m_nCode;	// �ʒm�R�[�h
	int (CWindow:: * m_fpHandler)(WPARAM wParam, LPARAM lParam);	// CWindow�N���X�����o�̃n���h���֐��ւ̃|�C���^m_fpHandler.
};

#endif