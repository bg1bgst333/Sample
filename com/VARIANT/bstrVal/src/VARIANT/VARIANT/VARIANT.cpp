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
	vr.bstrVal = SysAllocString(_T("ABCDE"));	// SysAllocString��"ABCDE"��������m�ۂ�, vr.bstrVal�ɃZ�b�g. 

	// �l�̏o��
	_tprintf(_T("vr.bstrVal = %s\n"), vr.bstrVal);	// vr.bstrVal���o��.

	// ������̉��.
	SysFreeString(vr.bstrVal);	// SysFreeString��vr.bstrVal�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}