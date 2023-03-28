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

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}