// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �|�C���^�E�z��̐錾�E������.
	WCHAR *pwszGuidStr1;	// GUID��������w��WCHAR�|�C���^pwszGuidStr1.
	WCHAR wszBuf[39] = {0};	// WCHAR�z��wszBuf(����39)��{0}�ŏ�����.

	// �{�����[���f�o�C�X�C���^�[�t�F�[�X�N���XGUID�𕶎���ɕϊ�.
	StringFromCLSID(GUID_DEVINTERFACE_VOLUME, &pwszGuidStr1);	// StringFromCLSID��GUID_DEVINTERFACE_VOLUME��GUID������ɕϊ�.

	// GUID������̏o��.
	_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1���o��.

	// �o�b�t�@�ɃR�s�[.
	_tcscpy(wszBuf, pwszGuidStr1);	// pwszGuidStr1��wszBuf�ɃR�s�[.

	// pwszGuidStr1�̉��.
	CoTaskMemFree(pwszGuidStr1);	// CoTaskMemFree�ŉ��.

	// GUID�������GUID�ɕϊ�.
	GUID guid2 = {0};	// GUID�\����guid2��{0}�ŏ�����.
	CLSIDFromString(wszBuf, &guid2);	// CLSIDFromString�ŕ����񂩂�GUID�ɕϊ�.

	// GUID������̏o��.
	_tprintf(_T("{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}\n"), guid2.Data1, guid2.Data2, guid2.Data3, guid2.Data4[0], guid2.Data4[1], guid2.Data4[2], guid2.Data4[3], guid2.Data4[4], guid2.Data4[5], guid2.Data4[6], guid2.Data4[7]);	// guid2��GUID������̏����ŏo��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}