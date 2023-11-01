/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	char *loc;
	_locale_t loc1;
	_locale_t loc2;
	char buf1[128];
	char buf2[128];

	/* "Japanese_Japan.932"�w�� */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */
	printf("loc = %s\n", loc);	/* loc���o��. */

	/* "Japanese_Japan.932"(Shift_JIS)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_locale��"Japanese_Japan.932"(Shift_JIS)�ȃ��P�[��loc1���쐬. */

	/* loc1�ŕW������. */
	_scanf_l("%s", loc1, buf1);	/* _scanf_l��loc1�œ��͕������buf1�Ɋi�[. */

	/* buf1��W���o��. */
	printf("buf1 = %s\n", buf1);	/* printf��buf1���o��. */

	/* loc1�̉��. */
	_free_locale(loc1);	/* _free_locale��loc1�����. */

	/* ��������o�b�t�@���t���b�V��. */
	fflush(stdin);	/* fflush��stdin���t���b�V��. */

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc2�̐���. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"(EUC-JP)�ȃ��P�[��loc2���쐬. */

	/* loc2�ŕW������. */
	_scanf_l("%s", loc2, buf2);	/* _scanf_l��loc2�œ��͕������buf2�Ɋi�[. */

	/* buf2��W���o��. */
	printf("buf2 = %s\n", buf2);	/* printf��buf2���o��. */

	/* loc2�̉��. */
	_free_locale(loc2);	/* _free_locale��loc2�����. */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}