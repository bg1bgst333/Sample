// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI
#include <cfgmgr32.h>	// Configuration Manager

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo

	// ���ׂẴf�o�C�X�ꗗ���擾.
	hDevInfo = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES);	// SetupDiGetClassDevs��hDevInfo�擾.
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

				// �v���p�e�B�̎擾.(�T�[�r�X��.)
				DWORD dwRegType;	// �v���p�e�B�̌^.
				DWORD dwSize;	// �v���p�e�B�̃T�C�Y.
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_SERVICE, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃT�[�r�X���̃T�C�Y�擾.
				if (dwRegType == REG_SZ){	// ������.
					//_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSize���o��.
					BYTE *pBytes = new BYTE[dwSize];	// new��BYTE�z��̊m��.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_SERVICE, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃT�[�r�X�����擾.
					//_tprintf(_T("SPDRP_SERVICE: %s\n"), (TCHAR *)pBytes);	// pBytes���o��.
					// "USBSTOR"�̏ꍇ.
					if (_tcscmp((TCHAR *)pBytes, _T("USBSTOR")) == 0){	// pBytes��"USBSTOR"�̏ꍇ.
						_tprintf(_T("SPDRP_SERVICE: %s\n"), (TCHAR *)pBytes);	// pBytes���o��.
						// �f�o�C�X�̏�Ԃ��擾��, �����[�o�u��������.
						unsigned long ulStatus = 0;	// ���ulStatus��0�ŏ�����.
						unsigned long ulProblem = 0;	// ���ulProblem��0�ŏ�����.
						DWORD dwRet = CM_Get_DevNode_Status(&ulStatus, &ulProblem, spdd.DevInst, 0);	// CM_Get_DevNode_Status�ŏ�Ԃ��擾.
						if (dwRet == CR_SUCCESS){	// ����.
							if ((ulStatus & DN_DISABLEABLE) && (ulStatus & DN_REMOVABLE)){	// �������\�����O���\.
								_tprintf(_T("DN_DISABLEABLE and DN_REMOVABLE\n"));	// "DN_DISABLEABLE and DN_REMOVABLE"���o��.
								// �v���p�e�B�̎擾.(�N���X��.)
								DWORD dwRegType;	// �v���p�e�B�̌^.
								DWORD dwSize;	// �v���p�e�B�̃T�C�Y.
								SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���X���̃T�C�Y�擾.
								if (dwRegType == REG_SZ){	// ������.
									//_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSize���o��.
									BYTE *ptszClass = new BYTE[dwSize];	// new��BYTE�z��̊m��.
									SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, ptszClass, dwSize, &dwSize);	// SetupDiGetDeviceRegistryProperty�ŃN���X�����擾.
									_tprintf(_T("SPDRP_CLASS: %s\n"), (TCHAR *)ptszClass);	// ptszClass���o��.
									delete [] ptszClass;	// ptszClass�����.
								}
								// �f�o�C�XID���i�[����o�b�t�@�̒������擾.
								unsigned long ulBufLen = 0;	// �o�b�t�@�̒���ulBufLen��0�ŏ�����.
								BOOL bRet = SetupDiGetDeviceInstanceId(hDevInfo, &spdd, NULL, 0, &ulBufLen);	// SetupDiGetDeviceInstanceId��ulBufLen���擾.
								_tprintf(_T("ulBufLen = %lu\n"), ulBufLen);	// ulBufLen���o��.
								TCHAR *ptszDevID = new TCHAR[ulBufLen];	// �T�C�Y��ulBufLen��TCHAR���I�z���new�Ŋm�ۂ�, �|�C���^��ptszDevID�Ɋi�[.(ulBufLen��NULL�����܂�.)
								// �f�o�C�XID�̎擾.
								bRet = SetupDiGetDeviceInstanceId(hDevInfo, &spdd, ptszDevID, ulBufLen, &ulBufLen);	// SetupDiGetDeviceInstanceId��ptszDevID���擾.
								if (bRet){	// bRet��TRUE.
									_tprintf(_T("ptszDevID = %s\n"), ptszDevID);	// ptszDevID���o��.
								}
								delete [] ptszDevID;	// ���.
								// �f�o�C�X�̎��o��
								PNP_VETO_TYPE pvtVetoType;
								TCHAR tszVetoName[MAX_PATH] = {0};
								int iResult = CM_Request_Device_Eject(spdd.DevInst, &pvtVetoType, tszVetoName, MAX_PATH, 0);	// CM_Request_Device_Eject��spdd.DevInst�̎w���f�o�C�X�̎��o��.
								if (iResult == 0){	// iResult��0�Ȃ�.
									_tprintf(_T("CM_Request_Device_Eject succeed.\n"));	// "CM_Request_Device_Eject succeed."�Əo��.
								}
								else{
									_tprintf(_T("CM_Request_Device_Eject failure.\n"));	// "CM_Request_Device_Eject failure."�Əo��.
								}
							}
						}
					}
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