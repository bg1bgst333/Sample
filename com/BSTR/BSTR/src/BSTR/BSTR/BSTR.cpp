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

	// �e�����̏o��.
	wprintf(L"str[%d] = %lu\n", -1, *(str - 2));				// str��2�O(BSTR��2���Ȃ̂�4�o�C�g�O)�𕄍����������l�ŏo��.
	wprintf(L"str[%d] = 0x%08x\n", 0, (unsigned long)str[0]);	// str[0]�̏o��.
	wprintf(L"str[%d] = 0x%08x\n", 1, (unsigned long)str[1]);	// str[1]�̏o��.
	wprintf(L"str[%d] = 0x%08x\n", 2, (unsigned long)str[2]);	// str[2]�̏o��.
	wprintf(L"str[%d] = 0x%08x\n", 3, (unsigned long)str[3]);	// str[3]�̏o��.
	wprintf(L"str[%d] = 0x%08x\n", 4, (unsigned long)str[4]);	// str[4]�̏o��.
	wprintf(L"str[%d] = 0x%08x\n", 5, (unsigned long)str[5]);	// str��1��(BSTR��1���Ȃ̂�2�o�C�g��)���o��.

	// str�̉��.
	SysFreeString(str);	// SysFreeString��str�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}