// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �\���́E�z��̐錾�E������
	GUID guid1;	// GUID�\���̕ϐ�guid1.
	WCHAR wszGuidStr1[39] = {0};	// GUID��������i�[����WCHAR�����z��wszGuidStr1(����39)��{0}�ŏ�����.

	// �l�̃Z�b�g.
	guid1.Data1 = 0x11111111;	// guid1.Data1��0x11111111���Z�b�g.
	guid1.Data2 = 0x2222;	// guid1.Data2��0x2222���Z�b�g.
	guid1.Data3 = 0x3333;	// guid1.Data3��0x3333���Z�b�g.
	guid1.Data4[0] = 0x44;	// guid1.Data4[0]��0x44���Z�b�g.
	guid1.Data4[1] = 0x55;	// guid1.Data4[1]��0x55���Z�b�g.
	guid1.Data4[2] = 0x66;	// guid1.Data4[2]��0x66���Z�b�g.
	guid1.Data4[3] = 0x66;	// guid1.Data4[3]��0x66���Z�b�g.
	guid1.Data4[4] = 0x66;	// guid1.Data4[4]��0x66���Z�b�g.
	guid1.Data4[5] = 0x66;	// guid1.Data4[5]��0x66���Z�b�g.
	guid1.Data4[6] = 0x66;	// guid1.Data4[6]��0x66���Z�b�g.
	guid1.Data4[7] = 0x66;	// guid1.Data4[7]��0x66���Z�b�g.

	// GUID������ւ̕ϊ�.
	StringFromGUID2(guid1, wszGuidStr1, 39);	// StringFromGUID2��GUID�𕶎���ɕϊ�.

	// GUID������̏o��.
	_tprintf(_T("%s\n"), wszGuidStr1);	// wszGuidStr1���o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}