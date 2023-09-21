/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	_locale_t loc1;
	FILE *fp1 = NULL;
	char buf1[16] = {0};
	int len1;
	int buf_size1;
	wchar_t *wstr1 = NULL;
	int wstr1_len;

	/* "Japanese_Japan.932"�w�� */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"�ȃ��P�[��loc1���쐬. */

	/* �o�C�i���t�@�C������ */
	fp1 = fopen("test1.txt", "rb");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("open test1");
		_free_locale(loc1);	/* _free_locale��loc1�����. */
		return -1;
	}
	len1 = fread(buf1, sizeof(char), 15, fp1);	/* fread�œǂݍ���, buf1�Ɋi�[. */
	buf1[len1] = '\0';	/* ������NULL����. */
	printf("buf1 = %s\n", buf1);	/* buf1���o��. */

	/* �o�b�t�@�T�C�Y�擾. */
	buf_size1 = _mbstowcs_l(NULL, buf1, 0, loc1);	/* �擪NULL�ŕK�v�o�b�t�@�T�C�Y��buf_size1�Ɋi�[. */
	printf("buf_size1 = %d\n", buf_size1);	/* buf_size1���o��. */

	/* �}���`�o�C�g�����񂩂烏�C�h������ɕϊ�. */
	wstr1 = malloc((buf_size1 + 1) * sizeof(wchar_t));	/* (buf_size1 + 1) * sizeof(wchar_t)���̃������m��. */
	wstr1_len = _mbstowcs_l(wstr1, buf1, buf_size1 + 1, loc1);	/* _mbstowcs_l�Ń��C�h������ɕϊ�. */
	if (wstr1_len < 0){	/* �}�C�i�X�͎��s. */
		perror("_mbstowcs_l test1");
		_free_locale(loc1);	/* _free_locale��loc1�����. */
		free(wstr1);	/* wstr1��� */
		fclose(fp1);	/* fp1�����. */
		return -2;
	}
	printf("wstr1 = %ls\n", wstr1);	/* printf��wstr1���o��. */
	 _free_locale(loc1);	/* _free_locale��loc1�����. */
	free(wstr1);	/* wstr1��� */
	fclose(fp1);	/* fp1�����. */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}