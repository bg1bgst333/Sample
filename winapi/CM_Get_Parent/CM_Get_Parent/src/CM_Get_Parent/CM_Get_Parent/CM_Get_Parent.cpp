// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// �֐��̃v���g�^�C�v�錾
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter);	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	int iDeviceNumber;	// �f�o�C�X�i���o�[.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �h���C�u���^�[����{�����[���̃f�o�C�X�i���o�[���擾.
	iDeviceNumber = GetVolumeDeviceNumber(argv[1]);	// GetVolumeDeviceNumber��iDeviceNumber�擾.
	if (iDeviceNumber != -1){	// iDeviceNumber��-1�łȂ���ΐ���.
		_tprintf(_T("iDeviceNumber = %d\n"), iDeviceNumber);	// iDeviceNumber���o��.
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