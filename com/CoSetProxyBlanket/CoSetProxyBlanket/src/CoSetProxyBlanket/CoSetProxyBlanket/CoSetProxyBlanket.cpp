// �w�b�_�t�@�C���̃C���N���[�h
#define _WIN32_DCOM		// DCOM�̒�`
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <objbase.h>	// COM
#include <wbemidl.h>	// WBEM

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// COM�̏������̌��ʂ��i�[����hr.
	HRESULT hr2;	// �Z�L�����e�B�������̌��ʂ��i�[����hr2.
	HRESULT hr3;	// IWbemLocator�̐������ʂ��i�[����hr3.
	HRESULT hr4;	// IWbemLocator::ConnectServer�̌��ʂ��i�[����hr4.
	HRESULT hr5;	// CoSetProxyBlanket�̌��ʂ��i�[����hr5.
	IWbemLocator *pLocator = NULL;	// IWbemLocator�C���^�[�t�F�[�X�|�C���^pLocator��NULL�ŏ�����.
	IWbemServices *pServices = NULL;	// IWbemServices�C���^�[�t�F�[�X�|�C���^pServices��NULL�ŏ�����.

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

	// COM�̏I������.
	pServices->Release();	// IWbemServices::Release�ŉ��.
	SysFreeString(strNetworkResource);	// SysFreeString��strNetworkResource�����.
	pLocator->Release();	// IWbemLocator::Release�ŉ��.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}