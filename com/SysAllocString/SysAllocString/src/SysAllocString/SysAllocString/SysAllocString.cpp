// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// BSTR�^������str�ɕ���������蓖�Ă�.
	BSTR str = SysAllocString(L"ABCDE");	// SysAllocString��str�Ƀ��C�h�������"ABCDE"�����蓖�Ă�.

	// str�̏o��.
	wprintf(L"%s\n", str);	// wprintf��str���o��.

	// str�̉��.
	SysFreeString(str);	// SysFreeString��str�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}