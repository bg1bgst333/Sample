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
	ITypeInfo *pTypeInfo;	// ITypeInfo�|�C���^pTypeInfo.
	TYPEATTR *pTypeAttr;	// TYPEATTR�\���̃|�C���^pTypeAttr.
	BSTR strName;	// BSTR������strName.
	BSTR strDocString;	// BSTR������strDocString.

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

	// ITypeInfo�|�C���^pTypeInfo�̎擾.
	hr = pDispatch->GetTypeInfo(0, 0, &pTypeInfo);	// IDispatch::GetTypeInfo��ITypeInfo�|�C���^pTypeInfo�擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("IDispatch::GetTypeInfo NG!\n"));	// "IDispatch::GetTypeInfo NG!"�Əo��.
		pDispatch->Release();	// IDispatch::Release�ŉ��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -3;	// -3��Ԃ��ďI��.
	}

	// IDispatch::GetTypeInfo�͐���.
	_tprintf(_T("IDispatch::GetTypeInfo OK!\n"));	// "IDispatch::GetTypeInfo OK!"�Əo��.

	// �擾����ITypeInfo�C���^�[�t�F�[�X�|�C���^pTypeInfo���o��.
	_tprintf(_T("pTypeInfo = 0x%08x\n"), (unsigned long)pTypeInfo);	// pTypeInfo���o��.

	// ���O�̎擾.
	hr = pTypeInfo->GetDocumentation(MEMBERID_NIL, &strName, &strDocString, NULL, NULL);	// ITypeInfo::GetDocumentation�Ō^�̖��O���擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("ITypeInfo::GetDocumentation NG!\n"));	// "ITypeInfo::GetDocumentation NG!"�Əo��.
		pTypeInfo->Release();	// ITypeInfo::Release�ŉ��.
		pDispatch->Release();	// IDispatch::Release�ŉ��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -4;	// -4��Ԃ��ďI��.
	}

	// ITypeInfo::GetDocumentation�͐���.
	_tprintf(_T("ITypeInfo::GetDocumentation OK!\n"));	// "ITypeInfo::GetDocumentation OK!"�Əo��.

	// �擾����strName���o��.
	_tprintf(_T("strName = %s\n"), strName);	// strName���o��.

	// �擾����strDocString���o��.
	_tprintf(_T("strDocString = %s\n"), strDocString);	// strDocString���o��.

	// �^�̑����̎擾.
	hr = pTypeInfo->GetTypeAttr(&pTypeAttr);	// ITypeInfo::GetTypeAttr�Ō^�̑������擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("ITypeInfo::GetTypeAttr NG!\n"));	// "ITypeInfo::GetTypeAttr NG!"�Əo��.
		SysFreeString(strName);	// SysFreeString��strName�����.
		SysFreeString(strDocString);	// SysFreeString��strDocString�����.
		pTypeInfo->Release();	// ITypeInfo::Release�ŉ��.
		pDispatch->Release();	// IDispatch::Release�ŉ��.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -5;	// -5��Ԃ��ďI��.
	}

	// ITypeInfo::GetTypeAttr�͐���.
	_tprintf(_T("ITypeInfo::GetTypeAttr OK!\n"));	// "ITypeInfo::GetTypeAttr OK!"�Əo��.

	// �擾����TYPEATTR�\���̃|�C���^pTypeAttr���o��.
	_tprintf(_T("pTypeAttr = 0x%08x\n"), (unsigned long)pTypeAttr);	// pTypeAttr���o��.

	// strName�̉��.
	SysFreeString(strName);	// SysFreeString��strName�����.

	// strDocString�̉��.
	SysFreeString(strDocString);	// SysFreeString��strDocString�����.

	// pTypeAttr�̉��.
	pTypeInfo->ReleaseTypeAttr(pTypeAttr);	// ITypeInfo::ReleaseTypeAttr��pTypeAttr�����.

	// pTypeInfo�̉��.
	pTypeInfo->Release();	// ITypeInfo::Release�ŉ��.

	// pDispatch�̉��.
	pDispatch->Release();	// IDispatch::Release�ŉ��.

	// lpwszCLSID�̉��.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}