// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <stdlib.h>		// �W�����[�e�B���e�B
#include <string.h>		// C�����񏈗�
#include <cfgmgr32.h>	// Configuration Manager

// �֐��̃v���g�^�C�v�錾
int GetDevInstByDriveLetterViaPhysicalDeviceObjectName(TCHAR* ptszDriveLetter);	// �h���C�u���^�[���畨���f�o�C�X�I�u�W�F�N�g�����o�R����DevInst�擾.

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h���C�������̐�.
	_tprintf(_T("argc = %d\n"), argc);	// argc���o��.
	if (argc != 2){	// 2�ȊO�̓G���[.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �����f�o�C�X�I�u�W�F�N�g���o�R��DevInst�擾.
	int iDevInst = GetDevInstByDriveLetterViaPhysicalDeviceObjectName(argv[1]);	// GetDevInstByDriveLetterViaPhysicalDeviceObjectName��argv[1]��n����iDevInst���擾.
	if (iDevInst != -1){	// iDevInst��-1�łȂ���ΐ���.
		_tprintf(_T("iDevInst = %d\n"), iDevInst);	// iDevInst���o��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}

// �h���C�u���^�[���畨���f�o�C�X�I�u�W�F�N�g�����o�R����DevInst�擾.
int GetDevInstByDriveLetterViaPhysicalDeviceObjectName(TCHAR* ptszDriveLetter){

	// MS-DOS�f�o�C�X���̎擾.
	TCHAR tszDrive[3] = {0};	// �h���C�u���^�[tszDrive(����3.)��{0}�ŏ�����.
	_tcscat(tszDrive, ptszDriveLetter);	// ptszDriveLetter��A��.
	_tcscat(tszDrive, _T(":"));	// ":"��A��.
	TCHAR tszDeviceName[MAX_PATH] = {0};	// �f�o�C�X��tszDeviceName(����MAX_PATH.)��{0}�ŏ�����.
	QueryDosDevice(tszDrive, tszDeviceName, MAX_PATH);	// QueryDosDevice��tszDeviceName���擾.

	// �f�o�C�X�c���[�T��
	DWORD dwDevInst;	// DEVINST�ldwDevInst.
	DWORD dwDevInstNext;	// ����DEVINST�ldwDevInstNext.
	DWORD dwRet = CM_Locate_DevNode(&dwDevInst, NULL, CM_LOCATE_DEVNODE_NORMAL);	// CM_Locate_DevNode�̑�2������NULL�ɂ����, ���[�g�f�o�C�X��DEVINST��Ԃ�.
	if (dwRet == CR_SUCCESS){	// CR_SUCCESS�Ȃ琬��.
		_tprintf(_T("dwDevInst = %lu\n"), dwDevInst);	// dwDevInst���o��.

		// ���[�v.
		while (TRUE){	// �������[�v.

			// ���W�X�g������f�o�C�X�̕����f�o�C�X�I�u�W�F�N�g�����擾.
			ULONG ulLength = 0;	// �T�C�YulLength��0�ŏ�����.
			DWORD dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME, NULL, NULL, &ulLength, 0);	// CM_Get_DevNode_Registry_Property�ŃT�C�Y�����擾.
			BYTE *pBytes = new BYTE[ulLength];	// new��BYTE���I�z��(�T�C�YulLength)�m��.
			ZeroMemory(pBytes, ulLength);	// ZeroMemory�ŏ�����.
			dwRet = CM_Get_DevNode_Registry_Property(dwDevInst, CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME, NULL, pBytes, &ulLength, 0);	// CM_Get_DevNode_Registry_Property�ŕ����f�o�C�X�I�u�W�F�N�g���擾.
			_tprintf(_T("CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME: %s\n"), (TCHAR *)pBytes);	// �����f�o�C�X�I�u�W�F�N�g�����o��.
			if (dwRet != CR_SUCCESS || _tcscmp(tszDeviceName, (TCHAR *)pBytes) != 0){	// CR_SUCCESS�ł͂Ȃ�, �܂���tszDeviceName��pBytes�������łȂ��ꍇ.
				delete [] pBytes;	// ���.
				dwRet = CM_Get_Child(&dwDevInstNext, dwDevInst, 0);	// CM_Get_Child�Ŏq��DevInst�擾.
				if (dwRet == CR_SUCCESS){	// ����.
					dwDevInst = dwDevInstNext;
					continue;	// ���[�v�擪�ɖ߂�.
				}
				else{	// ���s.
					return -1;	// -1��Ԃ�.
				}
			}
			else{	// �f�o�C�X�����v
				delete [] pBytes;	// ���.
				return dwDevInst;
			}

		}

	}
	else{	// ���s.
		_tprintf(_T("CM_Locate_DevNode failure.\n"));	// "CM_Locate_DevNode failure."���o��.
		return -1;	// -1��Ԃ�.
	}

}