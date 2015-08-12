#pragma once
#include <windows.h>
#include "IUnknown__h.h"

class CUnknown : public IUnknown_
{
	public:

		CUnknown();
		~CUnknown();

		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);
		STDMETHODIMP_(ULONG) AddRef();
		STDMETHODIMP_(ULONG) Release();

		STDMETHODIMP Method(void);

	private:

		LONG m_lRef;

};