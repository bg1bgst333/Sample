// �w�b�_�t�@�C���̃C���N���[�h
#define _WIN32_DCOM		// DCOM�̒�`
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <objbase.h>	// COM
#include <wbemidl.h>	// WBEM
#include <string>		// std::string

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// COM�̏������̌��ʂ��i�[����hr.
	HRESULT hr2;	// �Z�L�����e�B�������̌��ʂ��i�[����hr2.
	HRESULT hr3;	// IWbemLocator�̐������ʂ��i�[����hr3.
	HRESULT hr4;	// IWbemLocator::ConnectServer�̌��ʂ��i�[����hr4.
	HRESULT hr5;	// CoSetProxyBlanket�̌��ʂ��i�[����hr5.
	HRESULT hr6;	// IWbemServices::ExecQuery�̌��ʂ��i�[����hr6.
	HRESULT hr7;	// IEnumWbemClassObject::Next�̌��ʂ��i�[����hr7.
	HRESULT hr8;	// IWbemClassObject::Get�̌��ʂ��i�[����hr8.
	IWbemLocator *pLocator = NULL;	// IWbemLocator�C���^�[�t�F�[�X�|�C���^pLocator��NULL�ŏ�����.
	IWbemServices *pServices = NULL;	// IWbemServices�C���^�[�t�F�[�X�|�C���^pServices��NULL�ŏ�����.
	IEnumWbemClassObject *pEnumerator = NULL;	// IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator��NULL�ŏ�����.
	IWbemClassObject *pClassObject = NULL;	// IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject��NULL�ŏ�����.

	// MTA(�}���`�X���b�h�A�p�[�g�����g)�ɑ�����悤�ɐݒ�.
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);	// CoInitializeEx��COINIT_MULTITHREADED���w�肵�ď�����.
	if (FAILED(hr)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �Z�L�����e�B������.
	hr2 = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);	// CoInitializeSecurity�ŃZ�L�����e�B������.
	if (FAILED(hr2)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -2;	// -2��Ԃ��Ĉُ�I��.
	}

	// IWbemLocator�C���^�[�t�F�[�X�̐���.
	hr3 = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLocator);	// CoCreateInstance��, IWbemLocator�C���^�[�t�F�[�X�𐶐�.
	if (FAILED(hr3)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -3;	// -3��Ԃ��Ĉُ�I��.
	}

	// CoCreateInstance�͐���.
	_tprintf(_T("CoCreateInstance OK!\n"));	// "CoCreateInstance OK!"�Əo��.

	// �擾����IWbemLocator�C���^�[�t�F�[�X�|�C���^pLocator���o��.
	_tprintf(_T("pLocator = 0x%08x\n"), (unsigned long)pLocator);	// pLocator���o��.

	// WMI�ւ̐ڑ�.
	BSTR strNetworkResource = SysAllocString(L"ROOT\\CIMV2");	// SysAllocString��strNetworkResource��"ROOT\\CIMV2"�ŏ�����.
	hr4 = pLocator->ConnectServer(strNetworkResource, NULL, NULL, 0, NULL, 0, 0, &pServices);	// IWbemLocator::ConnectServer�Őڑ�.
	if (FAILED(hr4)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		SysFreeString(strNetworkResource);	// SysFreeString��strNetworkResource�����.
		pLocator->Release();	// IWbemLocator::Release�ŉ��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -4;	// -4��Ԃ��Ĉُ�I��.
	}

	// pLocator->ConnectServer�͐���.
	_tprintf(_T("pLocator->ConnectServer OK!\n"));	// "pLocator->ConnectServer OK!"�Əo��.

	// �擾����IWbemServices�C���^�[�t�F�[�X�|�C���^pServices���o��.
	_tprintf(_T("pServices = 0x%08x\n"), (unsigned long)pServices);	// pServices���o��.

	// �v���L�V�ł̃Z�L�����e�B���x���ݒ�.
	hr5 = CoSetProxyBlanket(pServices, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);	// CoSetProxyBlanket�Ńv���L�V�Z�L�����e�B���x���ݒ�.
	if (FAILED(hr5)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		pServices->Release();	// IWbemServices::Release�ŉ��.
		SysFreeString(strNetworkResource);	// SysFreeString��strNetworkResource�����.
		pLocator->Release();	// IWbemLocator::Release�ŉ��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -5;	// -5��Ԃ��Ĉُ�I��.
	}

	// CoSetProxyBlanket�͐���.
	_tprintf(_T("CoSetProxyBlanket OK!\n"));	// "CoSetProxyBlanket OK!"�Əo��.

	// �N�G���̎��s.
	std::wstring q = L"ASSOCIATORS OF{Win32_USBController.Name=\'";	// "ASSOCIATORS OF{Win32_USBController.Name=\'"��q�ɃZ�b�g.
	q = q + L"Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)";	// "Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)"��A��.
	q = q + L"\'}";	// "\'}"��A��.
	BSTR strQueryLanguage = SysAllocString(L"WQL");	// SysAllocString��strQueryLanguage��"WQL"�ŏ�����.
	BSTR strQuery = SysAllocString(q.c_str());	// SysAllocString��strQuery��q.c_str()�ŏ�����.
	hr6 = pServices->ExecQuery(strQueryLanguage, strQuery, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator);	// IWbemServices::ExecQuery�ŃN�G�����s.
	if (FAILED(hr6)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		SysFreeString(strQuery);	// SysFreeString��strQuery�����.
		SysFreeString(strQueryLanguage);	// SysFreeString��strQueryLanguage�����.
		pServices->Release();	// IWbemServices::Release�ŉ��.
		SysFreeString(strNetworkResource);	// SysFreeString��strNetworkResource�����.
		pLocator->Release();	// IWbemLocator::Release�ŉ��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -6;	// -6��Ԃ��Ĉُ�I��.
	}

	// pServices->ExecQuery�͐���.
	_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"�Əo��.

	// �擾����IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator���o��.
	_tprintf(_T("pEnumerator = 0x%08x\n"), (unsigned long)pEnumerator);	// pEnumerator���o��.

	// pEnumerator�̊e�v�f���.
	ULONG uReturn = 0;
	while (pEnumerator){	// pEnumerator��NULL�Ŗ������葱����.
		hr7 = pEnumerator->Next(WBEM_INFINITE, 1, &pClassObject, &uReturn);	// IEnumWbemClassObject::Next�Ŏ��̗v�f���擾.
		if (uReturn == 0){	// �I��.
			break;
		}
		if (SUCCEEDED(hr7)){	// SUCCEEDED�}�N���Ŕ���.
			// pEnumerator->Next�͐���.
			_tprintf(_T("pEnumerator->Next OK!\n"));	// "pEnumerator->Next OK!"�Əo��.
			// �擾����IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject���o��.
			_tprintf(_T("pClassObject = 0x%08x\n"), (unsigned long)pClassObject);	// pClassObject���o��.
			// �I�u�W�F�N�g�e�L�X�g�̎擾.
			BSTR strObjectText;
			hr8 = pClassObject->GetObjectText(0, &strObjectText);	// IWbemClassObject::GetObjectText�ŃI�u�W�F�N�g�̓��e���e�L�X�g�`���Ŏ擾.
			if (SUCCEEDED(hr8) && strObjectText){	// SUCCEEDED�}�N����strObjectText�Ŕ���.
				// pClassObject->GetObjectText�͐���.
				_tprintf(_T("pClassObject->GetObjectText OK!\n"));	// "pClassObject->GetObjectText OK!"�Əo��.
				// ���C�h�������}���`�o�C�g�����ɕϊ�����.
				int iBufLen = WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
				char *pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
				WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.
				printf("%s", pszBuf);	// printf��pszBuf���o��.
				delete [] pszBuf;	// delete [] ��pszBuf�����.
				SysFreeString(strObjectText);	// SysFreeString��strObjectText�����.
			}
		}
		pClassObject->Release();	// IWbemClassObject::Release�ŉ��.
	}

	// COM�̏I������.
	pEnumerator->Release();	// IEnumWbemClassObject::Release�ŉ��.
	SysFreeString(strQuery);	// SysFreeString��strQuery�����.
	SysFreeString(strQueryLanguage);	// SysFreeString��strQueryLanguage�����.
	pServices->Release();	// IWbemServices::Release�ŉ��.
	SysFreeString(strNetworkResource);	// SysFreeString��strNetworkResource�����.
	pLocator->Release();	// IWbemLocator::Release�ŉ��.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}