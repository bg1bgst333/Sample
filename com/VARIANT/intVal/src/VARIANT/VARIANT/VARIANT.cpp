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
	vr.vt = VT_I4;	// INT

	// �l�̑��
	vr.intVal = -123;	// vr.intVal��-123����.

	// �l�̏o��
	_tprintf(_T("vr.intVal = %d\n"), vr.intVal);	// vr.intVal���o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}