// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �|�C���^�̐錾.
	WCHAR *pwszGuidStr1;	// GUID��������w��WCHAR�|�C���^pwszGuidStr1.

	// �{�����[���f�o�C�X�C���^�[�t�F�[�X�N���XGUID�𕶎���ɕϊ�.
	StringFromCLSID(GUID_DEVINTERFACE_VOLUME, &pwszGuidStr1);	// StringFromCLSID��GUID_DEVINTERFACE_VOLUME��GUID������ɕϊ�.

	// GUID������̏o��.
	_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1���o��.

	// pwszGuidStr1�̉��.
	CoTaskMemFree(pwszGuidStr1);	// CoTaskMemFree�ŉ��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}