/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* ���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "japanese");	/* setlocale��LC_ALL, "japanese"���Z�b�g. */

	/* ���C�h�����̏o��. */
	printf("%C\n", L'��');	/* printf��%C�Ń��C�h����'��'���o��. */

	/* ���C�h������̏o��. */
	printf("%S\n", L"����������");	/* printf��%S�Ń��C�h������"����������"���o��. */

	/* �v���O�����̏I�� */
	return 0;

}