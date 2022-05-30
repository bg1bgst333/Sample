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
	HRESULT hr8;	// IWbemClassObject::GetObjectText�̌��ʂ��i�[����hr8.
	HRESULT hr9;	// IWbemClassObject::Get�̌��ʂ��i�[����hr9.
	HRESULT hr10;	// IWbemServices::ExecQuery�̌��ʂ��i�[����hr10.
	HRESULT hr11;	// IEnumWbemClassObject::Next�̌��ʂ��i�[����hr11.
	HRESULT hr12;	// IWbemClassObject::GetObjectText�̌��ʂ��i�[����hr12.
	HRESULT hr13;	// IWbemClassObject::Get�̌��ʂ��i�[����hr13.
	HRESULT hr14;	// IWbemServices::ExecQuery�̌��ʂ��i�[����hr14.
	HRESULT hr15;	// IEnumWbemClassObject::Next�̌��ʂ��i�[����hr15.
	HRESULT hr16;	// IWbemClassObject::GetObjectText�̌��ʂ��i�[����hr16.
	HRESULT hr17;	// IWbemClassObject::Get�̌��ʂ��i�[����hr17.
	IWbemLocator *pLocator = NULL;	// IWbemLocator�C���^�[�t�F�[�X�|�C���^pLocator��NULL�ŏ�����.
	IWbemServices *pServices = NULL;	// IWbemServices�C���^�[�t�F�[�X�|�C���^pServices��NULL�ŏ�����.
	IEnumWbemClassObject *pEnumerator = NULL;	// IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator��NULL�ŏ�����.
	IEnumWbemClassObject *pEnumerator2 = NULL;	// IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator2��NULL�ŏ�����.
	IEnumWbemClassObject *pEnumerator3 = NULL;	// IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator3��NULL�ŏ�����.
	IWbemClassObject *pClassObject = NULL;	// IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject��NULL�ŏ�����.
	IWbemClassObject *pClassObject2 = NULL;	// IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject2��NULL�ŏ�����.
	IWbemClassObject *pClassObject3 = NULL;	// IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject3��NULL�ŏ�����.

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
	BSTR strQueryLanguage = SysAllocString(L"WQL");	// SysAllocString��strQueryLanguage��"WQL"�ŏ�����.
	BSTR strQuery = SysAllocString(L"SELECT * FROM Win32_DiskDrive");	// SysAllocString��strQuery��"SELECT * FROM Win32_DiskDrive"�ŏ�����.
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
			//_tprintf(_T("pEnumerator->Next OK!\n"));	// "pEnumerator->Next OK!"�Əo��.
			// �擾����IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject���o��.
			//_tprintf(_T("pClassObject = 0x%08x\n"), (unsigned long)pClassObject);	// pClassObject���o��.
			// �I�u�W�F�N�g�e�L�X�g�̎擾.
			BSTR strObjectText;
			hr8 = pClassObject->GetObjectText(0, &strObjectText);	// IWbemClassObject::GetObjectText�ŃI�u�W�F�N�g�̓��e���e�L�X�g�`���Ŏ擾.
			if (SUCCEEDED(hr8) && strObjectText){	// SUCCEEDED�}�N����strObjectText�Ŕ���.
				// pClassObject->GetObjectText�͐���.
				//_tprintf(_T("pClassObject->GetObjectText OK!\n"));	// "pClassObject->GetObjectText OK!"�Əo��.
				// ���C�h�������}���`�o�C�g�����ɕϊ�����.
				int iBufLen = WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
				char *pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
				WideCharToMultiByte(CP_ACP, 0, strObjectText, -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.
				//printf("%s", pszBuf);	// printf��pszBuf���o��.
				delete [] pszBuf;	// delete [] ��pszBuf�����.
				SysFreeString(strObjectText);	// SysFreeString��strObjectText�����.
			}
			// �v���p�e�B�̎擾.
			VARIANT vrDeviceID;	// �f�o�C�XID.
			hr9 = pClassObject->Get(L"DeviceID", 0, &vrDeviceID, 0, 0);	// IWbemClassObject::Get��"DeviceID"�v���p�e�B�̒l���擾.
			if (SUCCEEDED(hr9)){	// SUCCEEDED�}�N���Ŕ���.
				// pClassObject->Get�͐���.
				//_tprintf(_T("pClassObject->Get OK!\n"));	// "pClassObject->Get OK!"�Əo��.
				wprintf(L"DeviceID: %s\n", vrDeviceID.bstrVal);	// vrDeviceID.bstrVal���o��.

				// �N�G���̎��s.
				std::wstring q = L"ASSOCIATORS OF{Win32_DiskDrive.DeviceID=\'";	// "ASSOCIATORS OF{Win32_DiskDrive.DeviceID=\'"��q�ɃZ�b�g.
				q = q + vrDeviceID.bstrVal;	// vrDeviceID.bstrVal��A��.
				q = q + L"\'}";	// "\'}"��A��.
				q = q + L" WHERE AssocClass = Win32_DiskDriveToDiskPartition";	// " WHERE AssocClass = Win32_DiskDriveToDiskPartition"��A��.
				BSTR strQuery2 = SysAllocString(q.c_str());	// SysAllocString��strQuery2��q.c_str()�ŏ�����.
				hr10 = pServices->ExecQuery(strQueryLanguage, strQuery2, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator2);	// IWbemServices::ExecQuery�ŃN�G�����s.
				if (SUCCEEDED(hr10)){	// SUCCEEDED�}�N���Ŕ���.
					// pServices->ExecQuery�͐���.
					//_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"�Əo��.
					// �擾����IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator2���o��.
					//_tprintf(_T("pEnumerator2 = 0x%08x\n"), (unsigned long)pEnumerator2);	// pEnumerator2���o��.
					// pEnumerator2�̊e�v�f���.
					ULONG uReturn2 = 0;
					while (pEnumerator2){	// pEnumerator2��NULL�Ŗ������葱����.
						hr11 = pEnumerator2->Next(WBEM_INFINITE, 1, &pClassObject2, &uReturn2);	// IEnumWbemClassObject::Next�Ŏ��̗v�f���擾.
						if (uReturn2 == 0){	// �I��.
							break;
						}
						if (SUCCEEDED(hr11)){	// SUCCEEDED�}�N���Ŕ���.
							// pEnumerator2->Next�͐���.
							//_tprintf(_T("pEnumerator2->Next OK!\n"));	// "pEnumerator2->Next OK!"�Əo��.
							// �擾����IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject2���o��.
							//_tprintf(_T("pClassObject2 = 0x%08x\n"), (unsigned long)pClassObject2);	// pClassObject2���o��.
							// �I�u�W�F�N�g�e�L�X�g�̎擾.
							BSTR strObjectText2;
							hr12 = pClassObject2->GetObjectText(0, &strObjectText2);	// IWbemClassObject::GetObjectText�ŃI�u�W�F�N�g�̓��e���e�L�X�g�`���Ŏ擾.
							if (SUCCEEDED(hr12) && strObjectText2){	// SUCCEEDED�}�N����strObjectText2�Ŕ���.
								// pClassObject2->GetObjectText�͐���.
								//_tprintf(_T("pClassObject2->GetObjectText OK!\n"));	// "pClassObject2->GetObjectText OK!"�Əo��.
								// ���C�h�������}���`�o�C�g�����ɕϊ�����.
								int iBufLen2 = WideCharToMultiByte(CP_ACP, 0, strObjectText2, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
								char *pszBuf2 = new char[iBufLen2];	// iBufLen2��char�^�o�b�t�@���m��.
								WideCharToMultiByte(CP_ACP, 0, strObjectText2, -1, pszBuf2, iBufLen2, NULL, NULL);	// �ϊ�.
								//printf("%s", pszBuf2);	// printf��pszBuf2���o��.
								delete [] pszBuf2;	// delete [] ��pszBuf2�����.
								SysFreeString(strObjectText2);	// SysFreeString��strObjectText2�����.
							}
							// �v���p�e�B�̎擾.
							VARIANT vrDeviceID2;	// �f�o�C�XID.
							hr13 = pClassObject2->Get(L"DeviceID", 0, &vrDeviceID2, 0, 0);	// IWbemClassObject::Get��"DeviceID"�v���p�e�B�̒l���擾.
							if (SUCCEEDED(hr13)){	// SUCCEEDED�}�N���Ŕ���.
								// pClassObject2->Get�͐���.
								//_tprintf(_T("pClassObject2->Get OK!\n"));	// "pClassObject2->Get OK!"�Əo��.
								wprintf(L"  DeviceID: %s\n", vrDeviceID2.bstrVal);	// vrDeviceID2.bstrVal���o��.

								// �N�G���̎��s.
								std::wstring q2 = L"ASSOCIATORS OF{Win32_DiskPartition.DeviceID=\'";	// "ASSOCIATORS OF{Win32_DiskPartition.DeviceID=\'"��q2�ɃZ�b�g.
								q2 = q2 + vrDeviceID2.bstrVal;	// vrDeviceID2.bstrVal��A��.
								q2 = q2 + L"\'}";	// "\'}"��A��.
								q2 = q2 + L" WHERE AssocClass = Win32_LogicalDiskToPartition";	// " WHERE AssocClass = Win32_LogicalDiskToPartition"��A��.
								BSTR strQuery3 = SysAllocString(q2.c_str());	// SysAllocString��strQuery3��q2.c_str()�ŏ�����.
								hr14 = pServices->ExecQuery(strQueryLanguage, strQuery3, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator3);	// IWbemServices::ExecQuery�ŃN�G�����s.
								if (SUCCEEDED(hr14)){	// SUCCEEDED�}�N���Ŕ���.
									// pServices->ExecQuery�͐���.
									//_tprintf(_T("pServices->ExecQuery OK!\n"));	// "pServices->ExecQuery OK!"�Əo��.
									// �擾����IEnumWbemClassObject�C���^�[�t�F�[�X�|�C���^pEnumerator3���o��.
									//_tprintf(_T("pEnumerator3 = 0x%08x\n"), (unsigned long)pEnumerator3);	// pEnumerator3���o��.
									// pEnumerator3�̊e�v�f���.
									ULONG uReturn3 = 0;
									while (pEnumerator3){	// pEnumerator3��NULL�Ŗ������葱����.
										hr15 = pEnumerator3->Next(WBEM_INFINITE, 1, &pClassObject3, &uReturn3);	// IEnumWbemClassObject::Next�Ŏ��̗v�f���擾.
										if (uReturn3 == 0){	// �I��.
											break;
										}
										if (SUCCEEDED(hr15)){	// SUCCEEDED�}�N���Ŕ���.
											// pEnumerator3->Next�͐���.
											//_tprintf(_T("pEnumerator3->Next OK!\n"));	// "pEnumerator3->Next OK!"�Əo��.
											// �擾����IWbemClassObject�C���^�[�t�F�[�X�|�C���^pClassObject3���o��.
											//_tprintf(_T("pClassObject3 = 0x%08x\n"), (unsigned long)pClassObject3);	// pClassObject3���o��.
											// �I�u�W�F�N�g�e�L�X�g�̎擾.
											BSTR strObjectText3;
											hr16 = pClassObject3->GetObjectText(0, &strObjectText3);	// IWbemClassObject::GetObjectText�ŃI�u�W�F�N�g�̓��e���e�L�X�g�`���Ŏ擾.
											if (SUCCEEDED(hr16) && strObjectText3){	// SUCCEEDED�}�N����strObjectText3�Ŕ���.
												// pClassObject3->GetObjectText�͐���.
												//_tprintf(_T("pClassObject3->GetObjectText OK!\n"));	// "pClassObject3->GetObjectText OK!"�Əo��.
												// ���C�h�������}���`�o�C�g�����ɕϊ�����.
												int iBufLen3 = WideCharToMultiByte(CP_ACP, 0, strObjectText3, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
												char *pszBuf3 = new char[iBufLen3];	// iBufLen3��char�^�o�b�t�@���m��.
												WideCharToMultiByte(CP_ACP, 0, strObjectText3, -1, pszBuf3, iBufLen3, NULL, NULL);	// �ϊ�.
												//printf("%s", pszBuf3);	// printf��pszBuf3���o��.
												delete [] pszBuf3;	// delete [] ��pszBuf3�����.
												SysFreeString(strObjectText3);	// SysFreeString��strObjectText3�����.
											}
											// �v���p�e�B�̎擾.
											VARIANT vrDeviceID3;	// �f�o�C�XID.
											hr17 = pClassObject3->Get(L"DeviceID", 0, &vrDeviceID3, 0, 0);	// IWbemClassObject::Get��"DeviceID"�v���p�e�B�̒l���擾.
											if (SUCCEEDED(hr17)){	// SUCCEEDED�}�N���Ŕ���.
												// pClassObject3->Get�͐���.
												//_tprintf(_T("pClassObject3->Get OK!\n"));	// "pClassObject3->Get OK!"�Əo��.
												wprintf(L"    DeviceID: %s\n", vrDeviceID3.bstrVal);	// vrDeviceID3.bstrVal���o��.

												// vrDeviceID3�̃N���A.
												VariantClear(&vrDeviceID3);	// VariantClear��vrDeviceID3���N���A.
											}
										}
										pClassObject3->Release();	// IWbemClassObject::Release�ŉ��.
									}
									pEnumerator3->Release();	// IEnumWbemClassObject::Release�ŉ��.
								}
								SysFreeString(strQuery3);	// SysFreeString��strQuery3�����.

								// vrDeviceID2�̃N���A.
								VariantClear(&vrDeviceID2);	// VariantClear��vrDeviceID2���N���A.
							}
						}
						pClassObject2->Release();	// IWbemClassObject::Release�ŉ��.
					}
					pEnumerator2->Release();	// IEnumWbemClassObject::Release�ŉ��.
				}
				SysFreeString(strQuery2);	// SysFreeString��strQuery2�����.

				// vrDeviceID�̃N���A.
				VariantClear(&vrDeviceID);	// VariantClear��vrDeviceID���N���A.
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