/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̐錾 */
	char *loc;
	FILE *fp1;
	FILE *fp2;

	/* "Japanese_Japan.932"�w�� */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */
	printf("loc = %s\n", loc);	/* loc���o��. */

	/* �t�@�C�����J��. */
	fp1 = fopen("test1.txt", "w");	/* fopen��"test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s. */
		perror("fopen 1");
		return -1;
	}

	/* �}���`�o�C�g�������"����������"���o��. */
	fprintf(fp1, "%s", "����������");	/* fprintf��"����������"���o��.

	/* ����. */
	fclose(fp1); /* fclose��fp1�����. */

	/* �t�@�C�����J��. */
	fp2 = fopen("test2.txt", "w");	/* fopen��"test2.txt"���J��. */
	if (fp2 == NULL){	/* ���s. */
		perror("fopen 2");
		return -2;
	}

	/* ���C�h�������L"����������"���o��. */
	fwprintf(fp2, L"%s", L"����������");	/* fwprintf��L"����������"���o��. */

	/* ����. */
	fclose(fp2); /* fclose��fp2�����. */

	/* �v���O�����̏I�� */
	return 0;

}