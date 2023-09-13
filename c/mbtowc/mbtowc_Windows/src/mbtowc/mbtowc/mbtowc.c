/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̏����� */
	FILE *fp1 = NULL;
	char buf1[16] = {0};
	int len1 = 0;
	wchar_t wc1 = L'\0';
	int result1;

	/* "Japanese_Japan.932"�w�� */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */

	/* �o�C�i���t�@�C������ */
	fp1 = fopen("test1.txt", "rb");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("open test1");
		return -1;
	}
	len1 = fread(buf1, sizeof(char), 16, fp1);	/* fread�œǂݍ���, buf1�Ɋi�[. */
	printf("len1 = %d\n", len1);	/* len1���o��. */
	printf("buf1 = %s\n", buf1);	/* buf1���o��. */

	/* �}���`�o�C�g�������烏�C�h�����ɕϊ�. */
	result1 = mbtowc(&wc1, buf1, MB_CUR_MAX);	/* mbtowc�Ń��C�h�����ɕϊ�. */
	if (result1 < 0){	/* �}�C�i�X�͎��s. */
		perror("mbtowc test1");
		fclose(fp1);	/* fp1�����. */
		return -2;
	}
	printf("wc1 = %lc\n", wc1);	/* printf��wc1���o��. */

	/* �I������ */
	fclose(fp1);	/* fp1�����. */
	
	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}