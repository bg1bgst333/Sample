// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// VARIANT�\���̂̐錾
	VARIANT vr;

	// VARIANT�\���̕ϐ�vr�̏�����
	VariantInit(&vr);	// VariantInit��vr��������.

	// ���͂���l�̌^���Z�b�g.
	vr.vt = VT_BSTR;	// BSTR

	// ������̊i�[.
	vr.bstrVal = SysAllocString(L"ABCDE");	// SysAllocString��"ABCDE"��������m�ۂ�, vr.bstrVal�ɃZ�b�g. 

	// �l�̏o��
	wprintf(L"vr.bstrVal = %s\n", vr.bstrVal);	// vr.bstrVal���o��.

	// VARIANT�̃N���A
	VariantClear(&vr);	// VariantClear��vr���I������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}