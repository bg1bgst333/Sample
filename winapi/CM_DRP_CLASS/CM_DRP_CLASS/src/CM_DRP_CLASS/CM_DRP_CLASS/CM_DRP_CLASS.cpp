// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <setupapi.h>	// SetUpAPI
#include <cfgmgr32.h>	// Configuration Manager

// �֐��̃v���g�^�C�v�錾
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter);	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.
int GetDeviceNumberByDevicePath(TCHAR* ptszDevicePath);	// �f�o�C�X�p�X����f�o�C�X�i���o�[���擾.
BOOL GetVolumeDeviceNumberAndDevInst(TCHAR* ptszDriveLetter, DWORD &dwDeviceNumber, DWORD &dwDevInst);	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[��DevInst���擾.
int GetVolumeDevInst(TCHAR* ptszDriveLetter);	// �h���C�u���^�[����{�����[����DevInst���擾.
int GetDiskDevInst(DWORD dwDeviceNumber);	// �f�o�C�X�i���o�[����f�B�X�N��DevInst���擾.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.
	int iDeviceNumber = GetVolumeDeviceNumber(argv[1]);	// GetVolumeDeviceNumber��iDeviceNumber�擾.
	if (iDeviceNumber != -1){	// iDeviceNumber��-1�łȂ���ΐ���.
		_tprintf(_T("iDeviceNumber = %d\n"), iDeviceNumber);	// iDeviceNumber���o��.
	}

#if 0
	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[��DevInst���擾.
	DWORD dwDeviceNumber = 0;	// dwDeviceNumber��0�ŏ�����.
	DWORD dwDevInst = 0;	// dwDevInst��0�ŏ�����.
	BOOL bRet = GetVolumeDeviceNumberAndDevInst(argv[1], dwDeviceNumber, dwDevInst);	// GetVolumeDeviceNumberAndDevInst��dwDeviceNumber, dwDevInst���擾.
	if (bRet){	// TRUE�Ȃ琬��.
		_tprintf(_T("dwDeviceNumber = %d\n"), dwDeviceNumber);	// dwDeviceNumber���o��.
		_tprintf(_T("dwDevInst = %d\n"), dwDevInst);	// dwDevInst���o��.
	}
#endif

#if 0
	// �h���C�u���^�[����{�����[����DevInst���擾.
	int iDevInst = GetVolumeDevInst(argv[1]);	// GetVolumeDevInst��iDevInst�擾.
	if (iDevInst != -1){	// iDevInst��-1�łȂ���ΐ���.
		_tprintf(_T("iDevInst = %d\n"), iDevInst);	// iDevInst���o��.
	}
#endif

	// �f�o�C�X�i���o�[����f�B�X�N��DevInst���擾.
	int iDiskDevInst = -1;	// iDiskDevInst��-1�ŏ�����.
	if (iDeviceNumber != -1){	// iDeviceNumber��-1�łȂ����.
		iDiskDevInst = GetDiskDevInst((DWORD)iDeviceNumber);	// GetDiskDevInst��iDiskDevInst���擾.
		if (iDiskDevInst != -1){	// iDiskDevInst��-1�łȂ���ΐ���.
			_tprintf(_T("iDiskDevInst = %d\n"), iDiskDevInst);	// iDiskDevInst���o��.
		}
	}

	// iDiskDevInst�̐e��DevInst���擾.
	DWORD dwDevInstParent;	// �e��DevInst�ł���dwDevInstParent.
	if (iDiskDevInst != -1){	// iDiskDevInst��-1�łȂ����.
		CM_Get_Parent(&dwDevInstParent, (DWORD)iDiskDevInst, 0);	// CM_Get_Parent��iDiskDevInst�̐e�̃f�o�C�X��DevInst�ł���dwDevInstParent�擾.
		_tprintf(_T("dwDevInstParent = %lu\n"), dwDevInstParent);	// dwDevInstParent���o��.

		// dwDevInstParent�̃N���X���擾.
		ULONG ulLength = 0;	// �T�C�YulLength��0�ŏ�����.
		DWORD dwRet = CM_Get_DevNode_Registry_Property(dwDevInstParent, CM_DRP_CLASS, NULL, NULL, &ulLength, 0);	// CM_Get_DevNode_Registry_Property�ŃT�C�Y�����擾.
		if (dwRet == CR_BUFFER_SMALL){	// �o�b�t�@���p�ӂ���Ă��Ȃ�.
			BYTE *pBytes = new BYTE[ulLength];	// new��BYTE���I�z��(�T�C�YulLength)�m��.
			ZeroMemory(pBytes, ulLength);	// ZeroMemory�ŏ�����.
			dwRet = CM_Get_DevNode_Registry_Property(dwDevInstParent, CM_DRP_CLASS, NULL, pBytes, &ulLength, 0);	// CM_Get_DevNode_Registry_Property�ŃN���X���擾.
			if (dwRet == CR_SUCCESS){	// ����
				_tprintf(_T("CM_DRP_CLASS: %s\n"), (TCHAR*)pBytes);	// �N���X�����o��.
			}
			delete[] pBytes;	// pBytes���.
		}

	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}

// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter){

	// �z��̏�����
	TCHAR tszPath[MAX_PATH] = {0};

	// �p�X�̐��`
	_tcscat(tszPath, _T("\\\\.\\"));
	_tcscat(tszPath, ptszDriveLetter);
	_tcscat(tszPath, _T(":"));

	// �J��.
	HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFile��hVolume�擾.
	if (hVolume != INVALID_HANDLE_VALUE){	// �J������.
		DWORD dwSize = 0x400;	// ���ꂮ�炢�p�ӂ��Ă���.
		DWORD dwBytes = 0;
		BYTE *pBytes = (BYTE *)malloc(dwSize);	// �������m��.
		BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControl�Ńf�o�C�X�i���o�[�擾.
		STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBER�|�C���^�Ɉڂ��ւ���.
		DWORD dwDeviceNumber = pSDN->DeviceNumber;
		free(pBytes);	// ���������.
		CloseHandle(hVolume);	// ����.
		return (int)dwDeviceNumber;	// dwDeviceNumber��int�ɃL���X�g���ĕԂ�.
	}
	else{	// ���s.
		return -1;	// -1��Ԃ�.
	}

}

// �f�o�C�X�p�X����f�o�C�X�i���o�[���擾.
int GetDeviceNumberByDevicePath(TCHAR* ptszDevicePath){

	// �z��̏�����
	TCHAR tszPath[MAX_PATH] = {0};

	// �p�X�̐��`
	_tcscat(tszPath, ptszDevicePath);

	// �J��.
	HANDLE handle = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFile��handle�擾.
	if (handle != INVALID_HANDLE_VALUE){	// �J������.
		DWORD dwSize = 0x400;	// ���ꂮ�炢�p�ӂ��Ă���.
		DWORD dwBytes = 0;
		BYTE *pBytes = (BYTE *)malloc(dwSize);	// �������m��.
		BOOL bRet = DeviceIoControl(handle, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControl�Ńf�o�C�X�i���o�[�擾.
		STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBER�|�C���^�Ɉڂ��ւ���.
		DWORD dwDeviceNumber = pSDN->DeviceNumber;
		free(pBytes);	// ���������.
		CloseHandle(handle);	// ����.
		return (int)dwDeviceNumber;	// dwDeviceNumber��int�ɃL���X�g���ĕԂ�.
	}
	else{	// ���s.
		return -1;	// -1��Ԃ�.
	}

}

// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[��DevInst���擾.
BOOL GetVolumeDeviceNumberAndDevInst(TCHAR* ptszDriveLetter, DWORD &dwDeviceNumber, DWORD &dwDevInst){

	// �ϐ��̏�����.
	int iDeviceNumber = -1;	// iDeviceNumber��-1�ŏ�����.
	DWORD dwTemp = 0;	// dwTemp��0�ŏ�����.

	// �{�����[�������擾.
	TCHAR tszVolumeName[MAX_PATH] = {0};	// �{�����[����tszVolumeName(����MAX_PATH)��{0}�ŏ�����.
	TCHAR tszDrive[128] = {0};	// �h���C�u���^�[tszDrive(����128)��{0}�ŏ�����.
	_tcscat(tszDrive, ptszDriveLetter);	// ptszDriveLetter��A��.
	_tcscat(tszDrive, _T(":\\"));	// ":\\"��A��.
	BOOL bRet = GetVolumeNameForVolumeMountPoint(tszDrive, tszVolumeName, MAX_PATH);	// GetVolumeNameForVolumeMountPoint�Ń{�����[�����擾.
	if (!bRet){	// ���s.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �f�o�C�X�C���^�[�t�F�[�X�f�[�^�̗�
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo
	// �{�����[���f�o�C�X�̃f�o�C�X�C���^�[�t�F�[�X�N���X�̃f�o�C�X�����擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��GUID_DEVINTERFACE_VOLUME��hDevInfo�擾.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�łȂ����.
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
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize���̃��������m�ۂ�, �A�h���X��pspdidd�Ɋi�[.
				memset(pspdidd, 0, dwMemSize);	// ��������S��0�ɃN���A.
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSize��dwStructSize���Z�b�g.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATA��spdd��{0}�ŏ�����.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// �\���̂̃T�C�Y��sizeof�Ŏ擾��, spdd.cbSize�ɃZ�b�g.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetail��pspdidd�̒��g���擾.(spdd���擾.)
				if (bRet){	// TRUE�Ȃ�.
					// �f�o�C�X�p�X����{�����[����.
					TCHAR path[MAX_PATH] = {0};
					TCHAR tszVolumeName2[MAX_PATH] = {0};	// �{�����[����tszVolumeName2(����MAX_PATH)��{0}�ŏ�����.
					_tcscat(path,  pspdidd->DevicePath);
					_tcscat(path, _T("\\"));	// ���ꂪ�Ȃ��Ǝ��s!
					BOOL bRet = GetVolumeNameForVolumeMountPoint(path, tszVolumeName2, MAX_PATH);	// GetVolumeNameForVolumeMountPoint�Ń{�����[�����擾.
					if (bRet){	// ����.
						if (_tcscmp(tszVolumeName, tszVolumeName2) == 0){	// ����.
							// �f�o�C�X�i���o�[���擾.
							iDeviceNumber = GetDeviceNumberByDevicePath(pspdidd->DevicePath);	// GetDeviceNumberByDevicePath�Ńf�o�C�X�i���o�[�擾.
							// DevInst��dwTemp��.
							dwTemp = spdd.DevInst;	// �ŏI���.
						}
					}
					// DevInst���o��.
					_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInst���o��.
				}
				free(pspdidd);	// pspdidd�����.
				i++;	// i���C���N�������g.
			}
		}
		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.
	}

	// iDeviceNumber��0�ȏ�Ȃ琬��.
	if (iDeviceNumber >= 0){
		dwDeviceNumber = (DWORD)iDeviceNumber;
		dwDevInst = dwTemp;
		return TRUE;	// TRUE��Ԃ�.
	}
	
	// ���s.
	return FALSE;	// FALSE��Ԃ�.

}

// �h���C�u���^�[����{�����[����DevInst���擾.
int GetVolumeDevInst(TCHAR* ptszDriveLetter){

	// �ϐ��̏�����.
	int iDevInst = -1;	// iDevInst��-1�ŏ�����.

	// MS-DOS�f�o�C�X���̎擾.
	TCHAR tszDrive[3] = {0};	// �h���C�u���^�[tszDrive(����3.)��{0}�ŏ�����.
	_tcscat(tszDrive, ptszDriveLetter);	// ptszDriveLetter��A��.
	_tcscat(tszDrive, _T(":"));	// ":"��A��.
	TCHAR tszDeviceName[MAX_PATH] = {0};	// �f�o�C�X��tszDeviceName(����MAX_PATH.)��{0}�ŏ�����.
	QueryDosDevice(tszDrive, tszDeviceName, MAX_PATH);	// QueryDosDevice��tszDeviceName���擾.

	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo
	// �{�����[���f�o�C�X�ꗗ���擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��hDevInfo�擾.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�łȂ����.
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
				// DevInst���o��.
				_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInst���o��.
				// �v���p�e�B�̎擾.(�����f�o�C�X�I�u�W�F�N�g��.)
				DWORD dwRegType;	// �v���p�e�B�̌^.
				DWORD dwSize;	// �v���p�e�B�̃T�C�Y.
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_PHYSICAL_DEVICE_OBJECT_NAME, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŕ����f�o�C�X�I�u�W�F�N�g���̃T�C�Y�擾.
				if (dwRegType == REG_SZ){	// ������.
					BYTE *pBytes = new BYTE[dwSize];	// new��BYTE�z��̊m��.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_PHYSICAL_DEVICE_OBJECT_NAME, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŕ����f�o�C�X�I�u�W�F�N�g�����擾.
					TCHAR tszDeviceName2[MAX_PATH] = {0};	// �f�o�C�X��tszDeviceName2(����MAX_PATH.)��{0}�ŏ�����.
					_tcscpy(tszDeviceName2, (TCHAR *)pBytes);	// pBytes��tszDeviceName2�ɃR�s�[.
					if (_tcscmp(tszDeviceName, tszDeviceName2) == 0){	// ����.
						iDevInst = spdd.DevInst;	// spdd.DevInst��iDevInst�ɑ��.
					}
					delete [] pBytes;	// pBytes�����.
				}
				i++;	// i���C���N�������g.
			}

		}
		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.
	}

	// �֐��̏I���.
	return iDevInst;	// iDevInst��Ԃ�.

}

// �f�o�C�X�i���o�[����f�B�X�N��DevInst���擾.
int GetDiskDevInst(DWORD dwDeviceNumber){

	// �f�o�C�X�C���^�[�t�F�[�X�f�[�^�̗�
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo
	int iDevInst = -1;	// �Ԃ�DevInst�̒liDevInst��-1�ŏ�����.
	// �f�B�X�N�f�o�C�X�̃f�o�C�X�C���^�[�t�F�[�X�N���X�̃f�o�C�X�����擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_DISK, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��GUID_DEVINTERFACE_DISK��hDevInfo�擾.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUE�łȂ����.
		// �񋓃��[�v.
		int i = 0;	// �C���f�b�N�Xi��0�ŏ�����.
		BOOL bLoop = TRUE;	// ���[�v���邩��bLoop��TRUE�ŏ�����.
		while (bLoop){	// bLoop��TRUE�̊Ԃ͑�����.
			// �f�o�C�X�C���^�[�t�F�[�X�f�[�^�̎擾.
			SP_DEVICE_INTERFACE_DATA spdid = {0};	// SP_DEVICE_INTERFACE_DATA��spdid��{0}�ŏ�����.
			spdid.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);	// spdid.cbSize��sizeof�ő�����SP_DEVICE_INTERFACE_DATA�̃T�C�Y���Z�b�g.
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_DISK, i, &spdid);	// SetupDiEnumDeviceInterfaces�ŗ�.
			if (!bRet){	// false�Ȃ�
				bLoop = FALSE;	// bLoop��FALSE��.
			}
			else{
				// �ڍ׏��̎擾.(SP_DEVINFO_DATA���擾.)
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// �C���^�[�t�F�[�X�̏ڍ׏��pspdidd��NULL�ŏ�����.
				DWORD dwMemSize = 0;	// �ڍ׏��̎擾�ɕK�v�ȃ������T�C�YdwMemSize��0�ŏ�����.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetail��dwMemSize�����擾.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// �\���̂̃T�C�YdwStructSize��sizeof�Ŏ擾.
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize���̃��������m�ۂ�, �A�h���X��pspdidd�Ɋi�[.
				memset(pspdidd, 0, dwMemSize);	// ��������S��0�ɃN���A.
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSize��dwStructSize���Z�b�g.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATA��spdd��{0}�ŏ�����.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// �\���̂̃T�C�Y��sizeof�Ŏ擾��, spdd.cbSize�ɃZ�b�g.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetail��pspdidd�̒��g���擾.(spdd���擾.)
				if (bRet){	// TRUE�Ȃ�.
					// DevInst���o��.
					_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInst���o��.
					// �f�o�C�X�i���o�[���擾.
					int iDeviceNumber = GetDeviceNumberByDevicePath(pspdidd->DevicePath);	// GetDeviceNumberByDevicePath�Ńf�o�C�X�i���o�[�擾.
					if (iDeviceNumber == (int)dwDeviceNumber){	// ����.
						iDevInst = spdd.DevInst;	// spdd.DevInst��iDevInst�ɑ��.
					}
				}
				free(pspdidd);	// pspdidd�����.
				i++;	// i���C���N�������g.
			}
		}
		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.
	}

	// �֐��̏I���.
	return iDevInst;	// iDevInst��Ԃ�.

}