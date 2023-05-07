// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <setupapi.h>	// SetUpAPI
#include <cfgmgr32.h>	// Configuration Manager

// �֐��̃v���g�^�C�v�錾
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter);	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.
int GetDeviceNumberByDevicePath(TCHAR* ptszDevicePath);	// �f�o�C�X�p�X����f�o�C�X�i���o�[���擾.
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
	}

	// �f�o�C�X�̎��o��
	PNP_VETO_TYPE pvtVetoType;
	TCHAR tszVetoName[MAX_PATH] = {0};
	int iResult = CM_Request_Device_Eject(dwDevInstParent, &pvtVetoType, tszVetoName, MAX_PATH, 0);	// CM_Request_Device_Eject��dwDevInstParent�̎w���f�o�C�X�̎��o��.
	if (iResult == 0){	// iResult��0�Ȃ�.
		_tprintf(_T("CM_Request_Device_Eject succeed.\n"));	// "CM_Request_Device_Eject succeed."�Əo��.
	}
	else{
		_tprintf(_T("CM_Request_Device_Eject failure.\n"));	// "CM_Request_Device_Eject failure."�Əo��.
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