// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// GUID�������GUID�ɕϊ�.
	GUID guid1 = {0};	// GUID�\����guid1��{0}�ŏ�����.
	WCHAR wszBuf[39] = L"{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B}";	// WCHAR�z��wszBuf(����39)��"{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B}"�ŏ�����.
	CLSIDFromString(wszBuf, &guid1);	// CLSIDFromString�ŕ����񂩂�GUID�ɕϊ�.

	// GUID��GUID������������.
	int iRet = IsEqualGUID(guid1, GUID_DEVINTERFACE_VOLUME);	// IsEqualGUID��GUID_DEVINTERFACE_VOLUME�Ɠ���������.
	if (iRet){	// TRUE
		_tprintf(_T("guid1 is GUID_DEVINTERFACE_VOLUME.\n"));	// "guid1 is GUID_DEVINTERFACE_VOLUME."�Əo��.
	}
	else{
		_tprintf(_T("guid1 is not GUID_DEVINTERFACE_VOLUME.\n"));	// "guid1 is not GUID_DEVINTERFACE_VOLUME."�Əo��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}