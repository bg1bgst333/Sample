// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
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
				_tprintf(_T("Found!\n"));	// "Found!"�Əo��.
				i++;	// i���C���N�������g.
			}
		}

		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}