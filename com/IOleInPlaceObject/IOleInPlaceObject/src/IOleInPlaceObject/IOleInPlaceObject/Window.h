// ��d�C���N���[�h�h�~
#ifndef __WINDOW_H__
#define __WINDOW_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <string>	// std::string
#include <map>			// std::map
// �Ǝ��̃w�b�_
#include "HandlerConditions.h"	// �\����HandlerConditions

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �E�B���h�E�N���XCWindow�̒�`
class CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd.
		// static�����o�ϐ�
		static std::map<HWND, CWindow *>m_mapWindowMap;	// �E�B���h�E�n���h�����L�[, CWindow�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapWindowMap.
		static std::map<DWORD, HandlerConditions *>m_mapHandlerMap;	// DWORD�l���L�[, HandlerConditions�\���̃|�C���^��l�Ƃ���}�b�vm_mapHandlerMap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWindow();	// �R���X�g���N�^CWindow()
		virtual ~CWindow();	// �f�X�g���N�^~CWindow()
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpctszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[���w��o�[�W����)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(RECT�o�[�W����.)
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL DestroyChildren();	// �q�E�B���h�E�j���֐�DestroyChildren
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow.
		virtual void AddCommandHandler(UINT nID, UINT nCode, int(CWindow:: * handler)(WPARAM wParam, LPARAM lParam));	// �R�}���h�n���h���̒ǉ�.
		virtual void DeleteCommandHandler(UINT nID, UINT nCode);	// �R�}���h�n���h���̍폜.
		virtual int GetWindowText(LPTSTR lptszStringBuf, int nMaxCount) const;	// �e�L�X�g���擾.
		virtual void GetWindowText(tstring& rString) const;	// �e�L�X�g���擾.(tstring�̎Q�ƃo�[�W����.)
		virtual int GetWindowTextLength() const;	// �e�L�X�g�̒������擾.
		virtual void SetWindowText(LPCTSTR lpctszString);	// �e�L�X�g�̐ݒ�.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.
		virtual int OnClose();	// �E�B���h�E�������鎞.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h������������.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g��.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g��.

};

#endif