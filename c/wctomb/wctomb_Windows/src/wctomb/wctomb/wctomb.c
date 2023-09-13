/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̏����� */
	const wchar_t wc = L'��';
	int wcsize = sizeof(wc);
	char mb1[MB_LEN_MAX + 1] = {0};
	int len1 = 0;
	FILE *fp1 = NULL;

	/* "Japanese_Japan.932"�w�� */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */

	/* �W���o�� */
	printf("wc = %lc\n", wc);	/* wc���o��. */
	printf("wc(%%04x) = 0x%04x\n", wc);	/* wc��16�i���o��. */
	printf("wcsize = %d\n", wcsize);	/* wcsize���o��. */

	/* ���C�h��������}���`�o�C�g�����֕ϊ�. */
	len1 = wctomb(mb1, wc);	/* wctomb�Ń��C�h��������}���`�o�C�g�����֕ϊ�. */

	/* �W���o�� */
	printf("mb1 = %s\n", mb1);	/* mb1���o��. */
	printf("len1 = %d\n", len1);	/* len1���o��. */

	/* �o�C�i���t�@�C���o�� */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("test1");
		return -1;
	}
	fwrite(mb1, sizeof(char), len1, fp1);	/* fwrite��mb1����������. */
	fclose(fp1);	/* ���� */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}