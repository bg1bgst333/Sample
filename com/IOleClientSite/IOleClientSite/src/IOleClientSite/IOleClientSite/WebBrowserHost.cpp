// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowserHost.h"	// CWebBrowserHost

// �R���X�g���N�^CWebBrowserHost
CWebBrowserHost::CWebBrowserHost() : CUserControl(){

	// �����o�̏�����
	m_pWebBrowser2 = NULL;	// m_pWebBrowser2��NULL�ŏ�����.

}

// �f�X�g���N�^~CWebBrowserHost
CWebBrowserHost::~CWebBrowserHost(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CWebBrowserHost"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CWebBrowserHost"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWebBrowserHost::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CUserControl::RegisterClass(hInstance, lpctszClassName);	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��lpctszClassName��o�^. 

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWebBrowserHost::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CWebBrowserHost".
	return CUserControl::Create(_T("CWebBrowserHost"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CWebBrowserHost"���w��.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CWebBrowserHost::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CUserControl::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.

}

// �u���E�U�̏������֐�InitBrowser
BOOL CWebBrowserHost::InitBrowser(){

	// IWebBrowser2�|�C���^���擾.
	HRESULT hr = CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pWebBrowser2));	// CoCreateInstance��IWebBrowser2�|�C���^���擾.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IWebBrowser2 NG!\n"));	// "IWebBrowser2 NG!"�Əo��.
		return FALSE;	// FALSE��Ԃ�.
	}
	OutputDebugString(_T("IWebBrowser2 OK!\n"));	// "IWebBrowser2 OK!"�Əo��.
	// IOleObject�|�C���^���擾.
	IOleObject *pOleObject;	// IOleObject�|�C���^pOleObject
	hr = m_pWebBrowser2->QueryInterface(IID_PPV_ARGS(&pOleObject));	// QueryInterface��pOleObject���擾.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IOleObject NG!\n"));	// "IOleObject NG!"�Əo��.
		return FALSE;	// FALSE��Ԃ�.
	}
	OutputDebugString(_T("IOleObject OK!\n"));	// "IOleObject OK!"�Əo��.
	// �������g��IOleClientSite�ɃL���X�g.
	IOleClientSite *pOleClientSite = static_cast<IOleClientSite *>(this);	// this��IOleClientSite�|�C���^pOleClientSite�ɃL���X�g.
	OutputDebugString(_T("IOleClientSite OK!\n"));	// "IOleClientSite OK!"�Əo��.
	pOleClientSite->Release();	// Release�Ŕj��.
	pOleObject->Release();	// Release�Ŕj��.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E�j���֐�Destroy
BOOL CWebBrowserHost::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWebBrowserHost::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �u���E�U������.
	BOOL bRet = InitBrowser();	// InitBrowser�Ńu���E�U������.
	if (!bRet){	// ���s.
		return -1;	// -1��Ԃ�.
	}
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CWebBrowserHost::OnDestroy(){

	// IWebBrowser2�|�C���^�̔j��.
	if (m_pWebBrowser2 != NULL){	// NULL�łȂ�.
		m_pWebBrowser2->Release();	// Release�Ŕj��.
		m_pWebBrowser2 = NULL;	// NULL���Z�b�g.
	}

}

// IUnknown::QueryInterface
STDMETHODIMP CWebBrowserHost::QueryInterface(const IID &riid, void **ppvObject){
	*ppvObject = NULL;
	if (riid == IID_IUnknown){
		*ppvObject = static_cast<IUnknown *>(this);
	}
	else if (riid == IID_IOleClientSite){
		*ppvObject = static_cast<IOleClientSite *>(this);
	}
	else{
		return E_NOINTERFACE;
	}
	AddRef();
	return S_OK;
}

// IUnknown::AddRef
STDMETHODIMP_(ULONG) CWebBrowserHost::AddRef(){
	return InterlockedIncrement(&m_lRef);
}

// IUnknown::Release
STDMETHODIMP_(ULONG) CWebBrowserHost::Release(){
	return InterlockedDecrement(&m_lRef);
}

// IOleClientSite::GetContainer
STDMETHODIMP CWebBrowserHost::GetContainer(IOleContainer **ppContainer){
	*ppContainer = NULL;
	return E_NOINTERFACE;
}

//�@IOleClientSite::GetMoniker
STDMETHODIMP CWebBrowserHost::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk){
	return E_NOTIMPL;
}

// IOleClientSite::OnShowWindow
STDMETHODIMP CWebBrowserHost::OnShowWindow(BOOL fShow){
	return S_OK;
}

// IOleClientSite::RequestNewObjectLayout
STDMETHODIMP CWebBrowserHost::RequestNewObjectLayout(){
	return E_NOTIMPL;
}

// IOleClientSite::SaveObject
STDMETHODIMP CWebBrowserHost::SaveObject(){
	return E_NOTIMPL;
}

// IOleClientSite::ShowObject
STDMETHODIMP CWebBrowserHost::ShowObject(){
	return S_OK;
}