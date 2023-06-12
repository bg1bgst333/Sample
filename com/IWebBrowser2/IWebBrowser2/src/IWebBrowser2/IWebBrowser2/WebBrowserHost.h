// ��d�C���N���[�h�h�~
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <shlobj.h>	// �V�F���I�u�W�F�N�g
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl

// �E�F�u�u���E�U�z�X�g�N���XCWebBrowserHost
class CWebBrowserHost : public CUserControl{

	// private�����o
	private:

		// private�����o�ϐ�
		IWebBrowser2 *m_pWebBrowser2;	// IWebBrowser2�|�C���^m_pWebBrowser2

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWebBrowserHost();	// �R���X�g���N�^CWebBrowserHost
		virtual ~CWebBrowserHost();	// �f�X�g���N�^~CWebBrowserHost
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL InitBrowser();	// �u���E�U�̏������֐�InitBrowser
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.

};

#endif