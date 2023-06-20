// ��d�C���N���[�h�h�~
#ifndef __WEB_BROWSER_HOST_H__
#define __WEB_BROWSER_HOST_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <shlobj.h>	// �V�F���I�u�W�F�N�g
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl

// �E�F�u�u���E�U�z�X�g�N���XCWebBrowserHost
class CWebBrowserHost : public CUserControl, public IOleClientSite, public IOleInPlaceSite{

	// private�����o
	private:

		// private�����o�ϐ�
		LONG m_lRef;	// �Q�ƃJ�E���^m_lRef
		IWebBrowser2 *m_pWebBrowser2;	// IWebBrowser2�|�C���^m_pWebBrowser2
		HWND m_hWndUndetermined;	// ���m��̃E�B���h�E�n���h��m_hWndUndetermined

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
		virtual BOOL Navigate(LPCTSTR lpctszUrl);	// �w���URL�ɑJ�ڂ���֐�Navigate
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		// IUnknown
		STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);
		STDMETHODIMP_(ULONG) AddRef();
		STDMETHODIMP_(ULONG) Release();
		// IOleClientSite
		STDMETHODIMP GetContainer(IOleContainer **ppContainer);
		STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk);
		STDMETHODIMP OnShowWindow(BOOL fShow);
		STDMETHODIMP RequestNewObjectLayout();
		STDMETHODIMP SaveObject();
		STDMETHODIMP ShowObject();
		// IOleWindow
		STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode);
		STDMETHODIMP GetWindow(HWND *phwnd);
		// IOleInPlaceSite
		STDMETHODIMP CanInPlaceActivate();
		STDMETHODIMP DeactivateAndUndo();
		STDMETHODIMP DiscardUndoState();
		STDMETHODIMP GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo);
		STDMETHODIMP OnInPlaceActivate();
		STDMETHODIMP OnInPlaceDeactivate();
		STDMETHODIMP OnPosRectChange(LPCRECT lprcPosRect);
		STDMETHODIMP OnUIActivate();
		STDMETHODIMP OnUIDeactivate(BOOL fUndoable);
		STDMETHODIMP Scroll(SIZE scrollExtant);

};

#endif