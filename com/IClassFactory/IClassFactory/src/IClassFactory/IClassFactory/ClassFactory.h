#pragma once
#include <windows.h>

class CClassFactory : public IClassFactory{

	public:

		CClassFactory();
		~CClassFactory();

		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);
		STDMETHODIMP_(ULONG) AddRef();
		STDMETHODIMP_(ULONG) Release();

		STDMETHODIMP CreateInstance(IUnknown* pUnkOuter, REFIID riid, LPVOID *ppv);
		STDMETHODIMP LockServer(BOOL bLock);

	private:

		LONG m_lRef;

};