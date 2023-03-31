// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <stdlib.h>		// �W�����[�e�B���e�B
#include <string.h>		// �����񏈗�
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �h���C�u���^�[����{�����[����.(�f�o�C�X�ԍ���.)
	TCHAR tszDrives[128] = {0};	// �h���C�u������Q���i�[�����TCHAR�^�z��tszDrives(����128)��{0}�ŏ�����.
	TCHAR *ptszDrive = NULL;	// �h���C�u��������w��TCHAR�^�|�C���^ptszDrive��NULL�ŏ�����.
	// �L���ȃh���C�u������Q���擾.
	GetLogicalDriveStrings(128, tszDrives);	// GetLogicalDriveStrings�ŗL���ȃh���C�u������Q���擾.
	// �h���C�u������ꗗ�o��.
	ptszDrive = tszDrives;	// �擪�ɃZ�b�g.
	while (*ptszDrive != _T('\0')){	// NULL�����łȂ�.
		_tprintf(_T("%s\n"), ptszDrive);	// ptszDrive���o��.
		// �{�����[�������o��.
		TCHAR tszVolumeName[MAX_PATH] = {0};	// �{�����[����tszVolumeName(����MAX_PATH)��{0}�ŏ�����.
		BOOL bRet = GetVolumeNameForVolumeMountPoint(ptszDrive, tszVolumeName, MAX_PATH);	// GetVolumeNameForVolumeMountPoint�Ń{�����[�����擾.
		if (bRet){	// ����.
			_tprintf(_T("tszVolumeName = %s\n"), tszVolumeName);	// tszVolumeName���o��.
		}
		// �f�o�C�X�ԍ����o��.
		TCHAR tszPath[MAX_PATH] = {0};
		_tcscat(tszPath, _T("\\\\.\\"));
		_tcscat(tszPath, ptszDrive);
		tszPath[_tcslen(tszPath) - 1] = _T('\0');
		HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFile��hVolume�擾.
		if (hVolume != NULL){	// �J������.
			DWORD dwSize = 0x400;	// ���ꂮ�炢�p�ӂ��Ă���.
			DWORD dwBytes = 0;
			BYTE *pBytes = (BYTE *)malloc(dwSize);	// �������m��.
			BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControl�Ńf�o�C�X�i���o�[�擾.
			STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBER�|�C���^�Ɉڂ��ւ���.
			DWORD dwDeviceNumber = pSDN->DeviceNumber;
			_tprintf(_T("dwDeviceNumber = %lu\n"), dwDeviceNumber);	// dwDeviceNumber���o��.
			free(pBytes);	// ���������.
			CloseHandle(hVolume);	// ����.
		}
		ptszDrive += _tcslen(ptszDrive) + 1;	// ptszDrive��(������ + 1)�̕������i��.
	}

	// �f�o�C�X�p�X����{�����[����.
	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo
	// �{�����[���f�o�C�X�̃f�o�C�X�C���^�[�t�F�[�X�N���X�̃f�o�C�X�����擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��GUID_DEVINTERFACE_VOLUME��hDevInfo�擾.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�łȂ����.
		// �o��.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfo���o��.
		// �񋓃��[�v.
		int i = 0;	// �C���f�b�N�Xi��0�ŏ�����.
		BOOL bLoop = TRUE;	// ���[�v���邩��bLoop��TRUE�ŏ�����.
		while (bLoop){	// bLoop��TRUE�̊Ԃ͑�����.
			// �f�o�C�X�C���^�[�t�F�[�X�f�[�^�̎擾.
			SP_DEVICE_INTERFACE_DATA spdid = {0};	// SP_DEVICE_INTERFACE_DATA��spdid��{0}�ŏ�����.
			spdid.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);	// spdid.cbSize��sizeof�ő�����SP_DEVICE_INTERFACE_DATA�̃T�C�Y���Z�b�g.
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_VOLUME, i, &spdid);	// SetupDiEnumDeviceInterfaces�ŗ�.
			if (!bRet){	// false�Ȃ�
				bLoop = FALSE;	// bLoop��FALSE��.
			}
			else{
				// �ڍ׏��̎擾.(SP_DEVINFO_DATA���擾.)
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// �C���^�[�t�F�[�X�̏ڍ׏��pspdidd��NULL�ŏ�����.
				DWORD dwMemSize = 0;	// �ڍ׏��̎擾�ɕK�v�ȃ������T�C�YdwMemSize��0�ŏ�����.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetail��dwMemSize�����擾.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// �\���̂̃T�C�YdwStructSize��sizeof�Ŏ擾.
				_tprintf(_T("dwMemSize = %lu, dwStructSize = %lu\n"), dwMemSize, dwStructSize);	// dwMemSize��dwStructSize���o��.
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize���̃��������m�ۂ�, �A�h���X��pspdidd�Ɋi�[.
				memset(pspdidd, 0, dwMemSize);	// ��������S��0�ɃN���A.
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSize��dwStructSize���Z�b�g.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATA��spdd��{0}�ŏ�����.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// �\���̂̃T�C�Y��sizeof�Ŏ擾��, spdd.cbSize�ɃZ�b�g.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetail��pspdidd�̒��g���擾.(spdd���擾.)
				if (bRet){	// TRUE�Ȃ�.
					// �f�o�C�X�p�X���o��.
					_tprintf(_T("pspdidd->DevicePath = %s\n"), pspdidd->DevicePath);	// pspdidd->DevicePath���o��.
					// �{�����[�������o��.
					TCHAR tszVolumeName[MAX_PATH] = {0};	// �{�����[����tszVolumeName(����MAX_PATH)��{0}�ŏ�����.
					// �f�o�C�X�p�X��"\"��ǉ�.
					TCHAR path[MAX_PATH] = {0};
					_tcscat(path,  pspdidd->DevicePath);
					_tcscat(path, _T("\\"));	// ���ꂪ�Ȃ��Ǝ��s!
					BOOL bRet = GetVolumeNameForVolumeMountPoint(path, tszVolumeName, MAX_PATH);	// GetVolumeNameForVolumeMountPoint�Ń{�����[�����擾.
					if (bRet){	// ����.
						_tprintf(_T("tszVolumeName = %s\n"), tszVolumeName);	// tszVolumeName���o��.
					}
					// DevInst���o��.
					_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInst���o��.
					// �f�o�C�X�ԍ����o��.
					TCHAR tszPath[MAX_PATH] = {0};
					_tcscat(tszPath, path);
					HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFile��hVolume�擾.
					if (hVolume != NULL){	// �J������.
						DWORD dwSize = 0x400;	// ���ꂮ�炢�p�ӂ��Ă���.
						DWORD dwBytes = 0;
						BYTE *pBytes = (BYTE *)malloc(dwSize);	// �������m��.
						BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControl�Ńf�o�C�X�i���o�[�擾.
						STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBER�|�C���^�Ɉڂ��ւ���.
						DWORD dwDeviceNumber = pSDN->DeviceNumber;
						_tprintf(_T("dwDeviceNumber = %lu\n"), dwDeviceNumber);	// dwDeviceNumber���o��.
						free(pBytes);	// ���������.
						CloseHandle(hVolume);	// ����.
					}
				}
				free(pspdidd);	// pspdidd�����.
				i++;	// i���C���N�������g.
			}
		}
		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}