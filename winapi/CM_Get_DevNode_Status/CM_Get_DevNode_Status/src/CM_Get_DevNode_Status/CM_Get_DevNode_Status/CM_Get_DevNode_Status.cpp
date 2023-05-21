// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <stdlib.h>		// �W�����[�e�B���e�B
#include <string.h>		// �����񏈗�
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI
#include <initguid.h>	// GUID
#include <usbiodef.h>	// USB
#include <cfgmgr32.h>	// Configuration Manager

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo

	// USB�f�o�C�X�̃f�o�C�X�C���^�[�t�F�[�X�N���X�̃f�o�C�X�����擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_USB_DEVICE, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��GUID_DEVINTERFACE_USB_DEVICE��hDevInfo�擾.
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
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_USB_DEVICE, i, &spdid);	// SetupDiEnumDeviceInterfaces�ŗ�.
			if (!bRet){	// false�Ȃ�
				bLoop = FALSE;	// bLoop��FALSE��.
			}
			else{

				// �ڍ׏��̎擾.
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
					// �f�o�C�XID���i�[����o�b�t�@�̒������擾.
					unsigned long ulBufLen = 0;	// �o�b�t�@�̒���ulBufLen��0�ŏ�����.
					DWORD dwRet = 0;	// �������s��\���߂�ldwRet��0�ŏ�����.
					dwRet = CM_Get_Device_ID_Size(&ulBufLen, spdd.DevInst, 0);	// CM_Get_Device_ID_Size��ulBufLen���擾.
					if (dwRet == CR_SUCCESS){	// ����.
						_tprintf(_T("ulBufLen = %lu\n"), ulBufLen);	// ulBufLen���o��.
						// �f�o�C�XID�̎擾.
						TCHAR *ptszBuf = new TCHAR[ulBufLen + 1];	// �T�C�Y��ulBufLen + 1��TCHAR���I�z���new�Ŋm�ۂ�, �|�C���^��ptszBuf�Ɋi�[.
						dwRet = CM_Get_Device_ID(spdd.DevInst, ptszBuf, ulBufLen + 1, 0);	// CM_Get_Device_ID�Ńf�o�C�XID���擾.
						if (dwRet == CR_SUCCESS){	// ����.
							_tprintf(_T("ptszBuf = %s\n"), ptszBuf);	// ptszBuf���o��.
							// �f�o�C�X�̏�Ԃ��擾��, �����[�o�u��������.
							unsigned long ulStatus = 0;	// ���ulStatus��0�ŏ�����.
							unsigned long ulProblem = 0;	// ���ulProblem��0�ŏ�����.
							dwRet = CM_Get_DevNode_Status(&ulStatus, &ulProblem, spdd.DevInst, 0);	// CM_Get_DevNode_Status�ŏ�Ԃ��擾.
							if (dwRet == CR_SUCCESS){	// ����.
								if ((ulStatus & DN_DISABLEABLE) && (ulStatus & DN_REMOVABLE)){	// �������\�����O���\.
									_tprintf(_T("DN_DISABLEABLE and DN_REMOVABLE\n"));	// "DN_DISABLEABLE and DN_REMOVABLE"���o��.
								}
							}
						}
						delete [] ptszBuf;	// ���.
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