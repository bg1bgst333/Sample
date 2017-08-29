#include <cstdio>		// ïWèÄì¸èoóÕ
#include <tchar.h>		// TCHARëŒâû
#include "ClassFactory.h"
#include "Unknown.h"
#include "DllMain.h"	// DllMainÇÃêÈåæ

CClassFactory::CClassFactory() : m_lRef(0){

	m_lRef = 1;

}

CClassFactory::~CClassFactory(){

}

STDMETHODIMP CClassFactory::QueryInterface(REFIID riid, LPVOID *ppv){

	*ppv = NULL;

	if (riid == IID_IUnknown || riid == IID_IClassFactory){
		*ppv = static_cast<IClassFactory *>(this);
	}
	else{
		return E_NOINTERFACE;
	}
	_tprintf(_T("CClassFactory::QueryInterface!\n"));
	AddRef();
	return S_OK;

}

STDMETHODIMP_(ULONG) CClassFactory::AddRef(){

	_tprintf(_T("CClassFactory::AddRef!\n"));
	LockModule();
	return InterlockedIncrement(&m_lRef);

}

STDMETHODIMP_(ULONG) CClassFactory::Release(){

	_tprintf(_T("CClassFactory::Release!\n"));
	LONG res = InterlockedDecrement(&m_lRef);
	if (res == 0){
		UnlockModule();
		delete this;
	}
	return res;

}

STDMETHODIMP CClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, LPVOID *ppv){

	_tprintf(_T("CClassFactory::CreateInstance\n"));
	if (pUnkOuter != NULL){
		return CLASS_E_NOAGGREGATION;
	}
	CUnknown *pUnknown = new CUnknown();
	if (pUnknown == NULL){
		return E_OUTOFMEMORY;
	}
	HRESULT hr = pUnknown->QueryInterface(riid, ppv);
	pUnknown->Release();
	return hr;

}

STDMETHODIMP CClassFactory::LockServer(BOOL bLock){

	_tprintf(_T("CClassFactory::LockServer\n"));
	if (bLock){
		LockModule();
	}
	else{
		UnlockModule();
	}
	return S_OK;

}