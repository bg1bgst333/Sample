#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応
static long g_lLock = 0;	// ロック
#include "Unknown.h"		// Unknownの宣言
static CUnknown g_Unknown;	// Unknownオブジェクト
HMODULE g_hModule = NULL;

extern "C" BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
	g_hModule = hinstDLL;
	return TRUE;
}
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv){
	if (rclsid == CLSID_CUnknown){
		return g_Unknown.QueryInterface(riid, ppv);
	}
	else{
		*ppv =NULL;
		return CLASS_E_CLASSNOTAVAILABLE;
	}
}
STDAPI DllCanUnloadNow(void){
	return (g_lLock == 0) ? S_OK : S_FALSE;
}
STDAPI DllRegisterServer(void){
	TCHAR tszModulePath[MAX_PATH];
	HKEY hKey;
	long e;
	GetModuleFileName(g_hModule, tszModulePath, sizeof(tszModulePath) / sizeof(TCHAR));
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)_T("IUnknown"), (lstrlen(_T("IUnknown")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}\\InprocServer32"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)tszModulePath, (lstrlen(tszModulePath) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}\\InprocServer32"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, _T("ThreadingModel"), 0, REG_SZ, (BYTE *)_T("Apartment"), (lstrlen(_T("Apartment")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	e = RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}\\ProgID"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	if (e != ERROR_SUCCESS){
		return S_FALSE;
	}
	e = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)_T("IUnknown.CUnknown"), (lstrlen(_T("IUnknown.CUnknown")) + 1) * sizeof(TCHAR));
	if (e != ERROR_SUCCESS){
		RegCloseKey(hKey);
		return S_FALSE;
	}
	return S_OK;
}
STDAPI DllUnregisterServer(void){

	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}\\ProgID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}\\InprocServer32"));
	RegDeleteKey(HKEY_CLASSES_ROOT, _T("CLSID\\{4E0C8ADE-56FA-4d79-9654-8AA2BB27FEFC}"));

	return S_OK;
}