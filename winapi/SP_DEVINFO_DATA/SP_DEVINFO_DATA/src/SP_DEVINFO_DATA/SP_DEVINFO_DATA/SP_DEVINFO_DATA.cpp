// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <stdlib.h>		// �W�����[�e�B���e�B
#include <string.h>		// �����񏈗�
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

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

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}