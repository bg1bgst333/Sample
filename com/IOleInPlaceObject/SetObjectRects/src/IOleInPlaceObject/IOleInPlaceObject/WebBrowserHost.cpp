// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WebBrowserHost.h"	// CWebBrowserHost

// �R���X�g���N�^CWebBrowserHost
CWebBrowserHost::CWebBrowserHost() : CUserControl(){

	// �����o�̏�����
	m_pWebBrowser2 = NULL;	// m_pWebBrowser2��NULL�ŏ�����.
	m_hWndUndetermined = NULL;	// m_hWndUndetermined��NULL�ŏ�����.

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
	// IOleObject::SetClientSite��IOleClientSite�|�C���^���Z�b�g.
	hr = pOleObject->SetClientSite(pOleClientSite);	// pOleObject->SetClientSite��pOleClientSite���Z�b�g.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IOleObject::SetClientSite NG!\n"));	// "IOleObject::SetClientSite NG!"�Əo��.
		pOleClientSite->Release();	// Release�Ŕj��.
		pOleObject->Release();	// Release�Ŕj��.
		return FALSE;	// FALSE��Ԃ�.
	}
	OutputDebugString(_T("IOleObject::SetClientSite OK!\n"));	// "IOleObject::SetClientSite OK!"�Əo��.
	// IOleObject::DoVerb��IOleClientSite�|�C���^���Z�b�g.
	MSG msg;	// MSG�\����msg.
	RECT rc;	// RECT�\����rc.
	SetRectEmpty(&rc);	// SetRectEmpty��rc����ɂ���.
	hr = pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, &msg, pOleClientSite, 0, m_hWndUndetermined, &rc);	// pOleObject->DoVerb��pOleClientSite���Z�b�g.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IOleObject::DoVerb NG!\n"));	// "IOleObject::DoVerb NG!"�Əo��.
		pOleClientSite->Release();	// Release�Ŕj��.
		pOleObject->Release();	// Release�Ŕj��.
		return FALSE;	// FALSE��Ԃ�.
	}
	OutputDebugString(_T("IOleObject::DoVerb OK!\n"));	// "IOleObject::DoVerb OK!"�Əo��.
	pOleClientSite->Release();	// Release�Ŕj��.
	pOleObject->Release();	// Release�Ŕj��.
	return TRUE;	// TRUE��Ԃ�.

}

// �w���URL�ɑJ�ڂ���֐�Navigate
BOOL CWebBrowserHost::Navigate(LPCTSTR lpctszUrl){

	// �ϐ��̐錾
	BSTR bstrUrl;	// BSTR�^URL������bstrUrl.
	VARIANT varFlags;	// �t���O
	VARIANT varTargetFrameName;	// �^�[�Q�b�g�t���[����
	VARIANT varPostData;	// �|�X�g�f�[�^
	VARIANT varHeaders;	// �w�b�_�[

	// ������
	bstrUrl = SysAllocString(lpctszUrl);	// SysAllocString��lpctszUrl������bstrUrl���m��.
	VariantInit(&varFlags);	// VariantInit��varFlags��������.
	VariantInit(&varTargetFrameName);	// VariantInit��varTargetFrameName��������.
	VariantInit(&varPostData);	// VariantInit��varPostData��������.
	VariantInit(&varHeaders);	// VariantInit��varHeaders��������.

	// �J��
	HRESULT hr = m_pWebBrowser2->Navigate(bstrUrl, &varFlags, &varTargetFrameName, &varPostData, &varHeaders);	// IWebBrowser2::Navigate��bstrUrl�ɑJ��.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IWebBrowser2::Navigate NG!\n"));	// "IWebBrowser2::Navigate NG!"�Əo��.
		SysFreeString(bstrUrl);	// SysFreeString��bstrUrl�����.
		return FALSE;	// FALSE��Ԃ�.
	}

	// ����.
	OutputDebugString(_T("IWebBrowser2::Navigate OK!\n"));	// "IWebBrowser2::Navigate OK!"�Əo��.

	// �I������
	SysFreeString(bstrUrl);	// SysFreeString��bstrUrl�����.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E�j���֐�Destroy
BOOL CWebBrowserHost::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWebBrowserHost::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// m_hWndUndetermined��hwnd���i�[���Ă���.
	m_hWndUndetermined = hwnd;	// m_hWndUndetermined��hwnd���Z�b�g.

	// �u���E�U������.
	BOOL bRet = InitBrowser();	// InitBrowser�Ńu���E�U������.
	if (!bRet){	// ���s.
		return -1;	// -1��Ԃ�.
	}

	// ����URL�J��.
	bRet = Navigate(_T("https://www.yahoo.co.jp"));	// Navigate��"https://www.yahoo.co.jp"�ɑJ��.
	if (!bRet){	// ���s.
		OutputDebugString(_T("https://www.yahoo.co.jp NG!\n"));	// "https://www.yahoo.co.jp NG!"�Əo��.
	}

	// ����
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

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CWebBrowserHost::OnSize(UINT nType, int cx, int cy){

	// IOleInPlaceObject�|�C���^�̎擾
	IOleInPlaceObject *pOleInPlaceObject;	// IOleInPlaceObject�|�C���^pOleInPlaceObject
	HRESULT hr = m_pWebBrowser2->QueryInterface(IID_PPV_ARGS(&pOleInPlaceObject));	// QueryInterface��pOleInPlaceObject���擾.
	if (FAILED(hr)){	// ���s.
		OutputDebugString(_T("IOleInPlaceObject NG!\n"));	// "IOleInPlaceObject NG!"�Əo��.
	}
	else{	// ����.
		OutputDebugString(_T("IOleInPlaceObject OK!\n"));	// "IOleInPlaceObject OK!"�Əo��.
		RECT rc = {0, 0, cx, cy};	// RECT�\����rc��{0, 0, cx, cy}�ŏ�����.
		hr = pOleInPlaceObject->SetObjectRects(&rc, &rc);	// SetObjectRects�ŃC���v���[�X�I�u�W�F�N�g�͈̔͂�rc�Ƃ���.
		if (FAILED(hr)){	// ���s.
			OutputDebugString(_T("IOleInPlaceObject::SetObjectRects NG!\n"));	// "IOleInPlaceObject::SetObjectRects NG!"�Əo��.
		}
		else{	// ����.
			OutputDebugString(_T("IOleInPlaceObject::SetObjectRects OK!\n"));	// "IOleInPlaceObject::SetObjectRects OK!"�Əo��.
		}
		pOleInPlaceObject->Release();	// ���.
	}

}

// IUnknown::QueryInterface
STDMETHODIMP CWebBrowserHost::QueryInterface(const IID &riid, void **ppvObject){
	*ppvObject = NULL;
	if (riid == IID_IOleClientSite){
		*ppvObject = static_cast<IOleClientSite *>(this);
	}
	else if (riid == IID_IOleInPlaceSite){
		*ppvObject = static_cast<IOleInPlaceSite *>(this);
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

// IOleWindow::ContextSensitiveHelp
STDMETHODIMP CWebBrowserHost::ContextSensitiveHelp(BOOL fEnterMode){
	return E_NOTIMPL;
}

// IOleWindow::GetWindow
STDMETHODIMP CWebBrowserHost::GetWindow(HWND *phwnd){
	*phwnd = m_hWndUndetermined;
	return S_OK;
}

// IOleInPlaceSite::CanInPlaceActivate
STDMETHODIMP CWebBrowserHost::CanInPlaceActivate(){
	return S_OK;
}

// IOleInPlaceSite::DeactivateAndUndo
STDMETHODIMP CWebBrowserHost::DeactivateAndUndo(){
	return E_NOTIMPL;
}

// IOleInPlaceSite::DiscardUndoState
STDMETHODIMP CWebBrowserHost::DiscardUndoState(){
	return E_NOTIMPL;
}

// IOleInPlaceSite::GetWindowContext
STDMETHODIMP CWebBrowserHost::GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo){
	*ppFrame = NULL;
	*ppDoc = NULL;
	GetClientRect(m_hWndUndetermined, lprcPosRect);
	GetClientRect(m_hWndUndetermined, lprcClipRect);
	return S_OK;
}

// IOleInPlaceSite::OnInPlaceActivate
STDMETHODIMP CWebBrowserHost::OnInPlaceActivate(){
	return S_OK;
}

// IOleInPlaceSite::OnInPlaceDeactivate
STDMETHODIMP CWebBrowserHost::OnInPlaceDeactivate(){
	return E_NOTIMPL;
}

// IOleInPlaceSite::OnPosRectChange
STDMETHODIMP CWebBrowserHost::OnPosRectChange(LPCRECT lprcPosRect){
	return S_OK;
}

// IOleInPlaceSite::OnUIActivate
STDMETHODIMP CWebBrowserHost::OnUIActivate(){
	return S_OK;
}

// IOleInPlaceSite::OnUIDeactivate
STDMETHODIMP CWebBrowserHost::OnUIDeactivate(BOOL fUndoable){
	return E_NOTIMPL;
}

// IOleInPlaceSite::Scroll
STDMETHODIMP CWebBrowserHost::Scroll(SIZE scrollExtant){
	return E_NOTIMPL;
}