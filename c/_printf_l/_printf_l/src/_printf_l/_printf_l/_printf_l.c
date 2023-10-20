/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	char *loc;
	_locale_t loc1;
	_locale_t loc2;

	/* "Japanese_Japan.932"�w�� */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */
	printf("loc = %s\n", loc);	/* loc���o��. */

	/* "Japanese_Japan.932"(Shift_JIS)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_locale��"Japanese_Japan.932"(Shift_JIS)�ȃ��P�[��loc1���쐬. */

	/* loc1�ŕW���o��. */
	_printf_l("%s", loc1, "����������\n");	/* _printf_l��loc1��"����������"���o��. */

	/* loc1�̉��. */
	_free_locale(loc1);	/* _free_locale��loc1�����. */

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc2�̐���. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"(EUC-JP)�ȃ��P�[��loc2���쐬. */

	/* loc2�ŕW���o��. */
	_printf_l("%s", loc2, "����������\n");	/* _printf_l��loc2��"����������"���o��. */

	/* loc2�̉��. */
	_free_locale(loc2);	/* _free_locale��loc2�����. */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}