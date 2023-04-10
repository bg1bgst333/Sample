// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HDEVINFO hDevInfo;	// �f�o�C�X���n���h��hDevInfo

	// �f�B�X�N�f�o�C�X�ꗗ���擾.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_DISK, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevs��hDevInfo�擾.
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
				// spdd.ClassGuid���o��.
				WCHAR *pwszGuidStr1;	// GUID��������w��WCHAR�|�C���^pwszGuidStr1.
				StringFromCLSID(spdd.ClassGuid, &pwszGuidStr1);	// StringFromCLSID��spdd.ClassGuid��GUID������ɕϊ�.
				_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1���o��.
				::CoTaskMemFree(pwszGuidStr1);	// pwszGuidStr1�����.
				i++;	// i���C���N�������g.
			}

		}

		// �j��.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoList��hDevInfo��j��.

	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}