/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	_locale_t loc1;
	wchar_t wstr[] = L"����������";
	int buf_size1;
	char *buf1_ptr = NULL;
	int len1;
	FILE *fp1 = NULL;

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"�ȃ��P�[��loc1���쐬. */
	
	/* �o�b�t�@�T�C�Y�擾. */
	buf_size1 = _wcstombs_l(NULL, wstr, 0, loc1);	/* �擪NULL�ŕK�v�o�b�t�@�T�C�Y��buf_size1�Ɋi�[. */

	/* ���C�h�����񂩂�}���`�o�C�g������֕ϊ�. */
	buf1_ptr = malloc((buf_size1 + 1) * sizeof(char));	/* (buf_size1 + 1)���̃������m��. */
	len1 = _wcstombs_l(buf1_ptr, wstr, buf_size1, loc1);	/* _wcstombs_l�ŕϊ�. */
	*(buf1_ptr + len1) = '\0';	/* �I�[��NULL. */

	/* �W���o�� */
	printf("buf1_ptr = %s\n", buf1_ptr);	/* buf1_ptr���o��. */
	printf("len1 = %d\n", len1);	/* len1���o��. *;

	/* �o�C�i���t�@�C���o�� */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("test1");
		_free_locale(loc1);	/* _free_locale��loc1�����. */
		free(buf1_ptr);	/* ��� */
		return -1;
	}
	fwrite(buf1_ptr, sizeof(char), len1, fp1);	/* fwrite��buf1_ptr����������. */
	fclose(fp1);	/* ���� */
	_free_locale(loc1);	/* _free_locale��loc1�����. */
	free(buf1_ptr);	/* ��� */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}