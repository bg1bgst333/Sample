/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* ���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "japanese");	/* setlocale��LC_ALL, "japanese"���Z�b�g. */

	/* �}���`�o�C�g�����̏o��.(%hc) */
	wprintf(L"%hc\n", 'A');	/* wprintf��%hc�Ń}���`�o�C�g����'A'���o��. */

	/* �}���`�o�C�g������̏o��.(%hs) */
	wprintf(L"%hs\n", "ABCDE");	/* wprintf��%hs�Ń}���`�o�C�g������"ABCDE"���o��. */

	/* ���C�h�����̏o��.(%c) */
	wprintf(L"%c\n", L'��');	/* wprintf��%c�Ń��C�h����'��'���o��. */

	/* ���C�h������̏o��.(%s) */
	wprintf(L"%s\n", L"����������");	/* wprintf��%s�Ń��C�h������"����������"���o��. */

	/* �}���`�o�C�g�����̏o��.(%C) */
	wprintf(L"%C\n", 'A');	/* wprintf��%C�Ń}���`�o�C�g����'A'���o��. */

	/* �}���`�o�C�g������̏o��.(%S) */
	wprintf(L"%S\n", "ABCDE");	/* wprintf��%S�Ń}���`�o�C�g������"ABCDE"���o��. */

	/* �v���O�����̏I�� */
	return 0;

}