/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̐錾 */
	FILE *fp1;

	/* �t�@�C�����J��. */
	fp1 = fopen("test1.txt", "w, ccs=UTF-8");	/* fopen��"test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s. */
		perror("fopen 1");
		return -1;
	}

	/* ���C�h�������L"����������"���o��. */
	fwprintf(fp1, L"%s", L"����������");	/* fwprintf��L"����������"���o��. */

	/* ����. */
	fclose(fp1); /* fclose��fp1�����. */

	/* �v���O�����̏I�� */
	return 0;

}