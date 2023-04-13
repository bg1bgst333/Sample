// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo

	// �{�����[���f�o�C�X�ꗗ���擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��hDevInfo�擾.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�łȂ����.

		// �o��.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfo���o��.

		// �񋓃��[�v.
		int i = 0;	// �C���f�b�N�Xi��0�ŏ�����.
		BOOL bLoop = TRUE;	// ���[�v���邩��bLoop��TRUE�ŏ�����.
		while (bLoop){	// bLoop��TRUE�̊Ԃ͑�����.

			// �f�o�C�X���̎擾.
			SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATA��spdd��{0}�ŏ�����.
			spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// �\���̂̃T�C�Y��sizeof�Ŏ擾��, spdd.cbSize�ɃZ�b�g.
			BOOL bRet = SetupDiEnumDeviceInfo(hDevInfo, i, &spdd);	// SetupDiEnumDeviceInfo�ŗ�.
			if (!bRet){	// FALSE�Ȃ�.
				bLoop = FALSE;	// bLoop��FALSE��.
			}
			else{	// TRUE�Ȃ�.
				// spdd.ClassGuid���o��.
				WCHAR *pwszGuidStr1;	// GUID��������w��WCHAR�|�C���^pwszGuidStr1.
				StringFromCLSID(spdd.ClassGuid, &pwszGuidStr1);	// StringFromCLSID��spdd.ClassGuid��GUID������ɕϊ�.
				_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1���o��.
				CoTaskMemFree(pwszGuidStr1);	// pwszGuidStr1�����.
				// �v���p�e�B�̎擾.(�N���X��.)
				DWORD dwRegType;	// �v���p�e�B�̌^.
				DWORD dwSize;	// �v���p�e�B�̃T�C�Y.
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���X���̃T�C�Y�擾.
				if (dwRegType == REG_SZ){	// ������.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSize���o��.
					BYTE *pBytes = new BYTE[dwSize];	// new��BYTE�z��̊m��.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���X�����擾.
					_tprintf(_T("SPDRP_CLASS: %s\n"), (TCHAR *)pBytes);	// pBytes���o��.
					delete [] pBytes;	// pBytes�����.
				}
				// �v���p�e�B�̎擾.(�N���XGUID.)
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASSGUID, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���XGUID�̃T�C�Y�擾.
				if (dwRegType == REG_SZ){	// ������.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSize���o��.
					BYTE *pBytes = new BYTE[dwSize];	// new��BYTE�z��̊m��.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASSGUID, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���XGUID���擾.
					_tprintf(_T("SPDRP_CLASSGUID: %s\n"), (TCHAR *)pBytes);	// pBytes���o��.
					delete [] pBytes;	// pBytes�����.
				}
				// �v���p�e�B�̎擾.(�f�o�C�X�̐���.)
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_DEVICEDESC, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�Ńf�o�C�X�̐����̃T�C�Y�擾.
				if (dwRegType == REG_SZ){	// ������.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSize���o��.
					BYTE *pBytes = new BYTE[dwSize];	// new��BYTE�z��̊m��.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_DEVICEDESC, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�Ńf�o�C�X�̐������擾.
					_tprintf(_T("SPDRP_DEVICEDESC: %s\n"), (TCHAR *)pBytes);	// pBytes���o��.
					delete [] pBytes;	// pBytes�����.
				}
				i++;	// i���C���N�������g.
			}

		}

		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.

	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}