/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̐錾�E������ */
	char *loc;
	FILE *fp1;
	FILE *fp2;
	wchar_t buf1[16] = {0};
	wchar_t buf2[16] = {0};

	/* "Japanese_Japan.932"�w�� */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */
	printf("loc = %s\n", loc);	/* loc���o��. */

	/* �t�@�C�����J��. */
	fp1 = fopen("test1.txt", "r,ccs=UNICODE");	/* fopen��"test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s. */
		perror("fopen 1");
		return -1;
	}

	/* �t�@�C�����̓f�[�^�����C�h������Ƃ��Ċi�[. */
	fwscanf(fp1, L"%s", buf1);	/* fwscanf��buf1�Ɋi�[. */
	wprintf(L"%s\n", buf1);	/* buf1���o��. */

	/* ����. */
	fclose(fp1); /* fclose��fp1�����. */

	/* �t�@�C�����J��. */
	fp2 = fopen("test2.txt", "r, ccs=UNICODE");	/* fopen��"test2.txt"���J��. */
	if (fp2 == NULL){	/* ���s. */
		perror("fopen 2");
		return -2;
	}

	/* �t�@�C�����̓f�[�^�����C�h������Ƃ��Ċi�[. */
	fwscanf(fp2, L"%s", buf2);	/* fwscanf��buf2�Ɋi�[. */
	wprintf(L"%s\n", buf2);	/* buf2���o��. */

	/* ����. */
	fclose(fp2); /* fclose��fp2�����. */

	/* �v���O�����̏I�� */
	return 0;

}