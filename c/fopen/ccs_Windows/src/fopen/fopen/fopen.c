/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̐錾 */
	FILE *fp1;
	FILE *fp2;

	/* �t�@�C�����J��. */
	fp1 = fopen("test1.txt", "w,ccs=UNICODE");	/* fopen��"test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s. */
		perror("fopen 1");
		return -1;
	}

	/* ���C�h�������L"����������"���o��. */
	fwprintf(fp1, L"%s", L"����������");	/* fwprintf��L"����������"���o��. */

	/* ����. */
	fclose(fp1); /* fclose��fp1�����. */

	/* �t�@�C�����J��. */
	fp2 = fopen("test2.txt", "w, ccs=UNICODE");	/* fopen��"test2.txt"���J��. */
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