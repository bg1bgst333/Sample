// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]) {	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// CLSIDFromProgID�̌��ʂ��i�[����hr.
	CLSID clsid;	// CLSID���i�[����clsid.
	WCHAR *lpwszCLSID;	// CLSID��������w��WCHAR�|�C���^lpwszCLSID.
	IDispatch *pDispatch;	// IDispatch�|�C���^pDispatch.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// Word��ProgID����CLSID���擾.
	hr = CLSIDFromProgID(_T("Word.Application"), &clsid);	// CLSIDFromProgID��"Word.Application"��clsid���擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("CLSIDFromProgID NG!\n"));	// "CLSIDFromProgID NG!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -1;	// -1��Ԃ��ďI��.
	}

	// clsid�𕶎���ɕϊ���, �o��.
	StringFromCLSID(clsid, &lpwszCLSID);	// clsid��lpwszCLSID�ɕϊ�.
	wprintf(L"lpwszCLSID = %s\n", lpwszCLSID);	// lpwszCLSID���o��.

	// IDispatch�|�C���^pDispatch�̎擾.
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pDispatch));	// CoCreateInstance��, pDispatch�𐶐�.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("CoCreateInstance(IDispatch) NG!\n"));	// "CoCreateInstance(IDispatch) NG!"�Əo��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -2;	// -2��Ԃ��ďI��.
	}

	// CoCreateInstance�͐���.
	_tprintf(_T("CoCreateInstance(IDispatch) OK!\n"));	// "CoCreateInstance(IDispatch) OK!"�Əo��.

	// �擾����IDispatch�C���^�[�t�F�[�X�|�C���^pDispatch���o��.
	_tprintf(_T("pDispatch = 0x%08x\n"), (unsigned long)pDispatch);	// pDispatch���o��.
	
	// ���\�b�h��v���p�e�B��DISPID�̎擾.
	LPOLESTR lpwszName = L"Visible";	// lpwszName��"Visible"�ŏ�����.
	DISPID dispid;	// DISPID�^dispid.
	hr = pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNames��dispid�擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("IDispatch::GetIDsOfNames NG!\n"));	// "IDispatch::GetIDsOfNames NG!"�Əo��.
		pDispatch->Release();	// IDispatch::Release�ŉ��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -3;	// -3��Ԃ��ďI��.
	}

	// IDispatch::GetIDsOfNames�͐���.
	_tprintf(_T("IDispatch::GetIDsOfNames OK!\n"));	// "IDispatch::GetIDsOfNames OK!"�Əo��.

	// �擾����dispid���o��.
	_tprintf(_T("dispid = %d\n"), dispid);	// dispid���o��.

	// ���\�b�h��v���p�e�B�ɃA�N�Z�X.
	VARIANT var;	// VARIANT�\����var.
	DISPPARAMS dispparams;	// DISPPARAMS�\����dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidname��DISPID_PROPERTYPUT�ɏ�����.
	var.vt = VT_I4;	// 4�o�C�gint.
	var.lVal = 1;	// �l��1.
	dispparams.cArgs = 1;	// �����̐���1.
	dispparams.rgvarg = &var;	// &var���w��.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidname���w��.
	dispparams.cNamedArgs = 1;	// cNamedArgs��1.
	hr = pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, NULL, NULL, NULL);	// IDispatch::Invoke�ŃA�N�Z�X.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("IDispatch::Invoke NG!\n"));	// "IDispatch::Invoke NG!"�Əo��.
		pDispatch->Release();	// IDispatch::Release�ŉ��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -4;	// -4��Ԃ��ďI��.
	}

	// IDispatch::Invoke�͐���.
	_tprintf(_T("IDispatch::Invoke OK!\n"));	// "IDispatch::Invoke OK!"�Əo��.

	// pDispatch�̉��.
	pDispatch->Release();	// IDispatch::Release�ŉ��.

	// lpwszCLSID�̉��.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}