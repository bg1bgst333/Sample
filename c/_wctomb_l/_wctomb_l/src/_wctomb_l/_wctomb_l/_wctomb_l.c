/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	_locale_t loc1;
	const wchar_t wc = L'��';
	int len1 = 0;
	char mb1[MB_LEN_MAX + 1] = {0};
	FILE *fp1 = NULL;

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"�ȃ��P�[��loc1���쐬. */

	/* ���C�h��������}���`�o�C�g�����֕ϊ�. */
	len1 = _wctomb_l(mb1, wc, loc1);	/* _wctomb_l�Ń��C�h��������loc1���P�[���ȃ}���`�o�C�g�����֕ϊ�. */
	printf("len1 = %d\n", len1);	/* len1���o��. */

	/* �o�C�i���t�@�C���o�� */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("test1");
		_free_locale(loc1);	/* _free_locale��loc1�����. */
		return -1;
	}
	fwrite(mb1, sizeof(char), len1, fp1);	/* fwrite��mb1����������. */
	fclose(fp1);	/* ���� */

	/* loc1�̉��. */
	_free_locale(loc1);	/* _free_locale��loc1�����. */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}