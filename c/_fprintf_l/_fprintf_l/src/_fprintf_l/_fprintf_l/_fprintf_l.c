/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��̐錾�E������ */
	_locale_t loc1;
	_locale_t loc2;
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	/* "Japanese_Japan.932"(Shift_JIS)���P�[��loc1�̐���. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_locale��"Japanese_Japan.932"(Shift_JIS)�ȃ��P�[��loc1���쐬. */

	/* loc1�Ńt�@�C���o��. */
	fp1 = fopen("test1.txt", "w");	/* "test1.txt"���J��. */
	if (fp1 == NULL){	/* ���s */
		perror("test1");
		_free_locale(loc1);	/* _free_locale��loc1�����. */
		return -1;
	}
	_fprintf_l(fp1, "%s", loc1, "����������");	/* _fprintf_l��loc1��"����������"���o��. */
	fclose(fp1);	/* ���� */
	_free_locale(loc1);	/* _free_locale��loc1�����. */

	/* "Japanese_Japan.20932"(EUC-JP)���P�[��loc2�̐���. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_locale��"Japanese_Japan.20932"(EUC-JP)�ȃ��P�[��loc2���쐬. */

	/* loc2�Ńt�@�C���o��. */
	fp2 = fopen("test2.txt", "w");	/* "test2.txt"���J��. */
	if (fp2 == NULL){	/* ���s */
		perror("test2");
		_free_locale(loc2);	/* _free_locale��loc2�����. */
		return -2;
	}
	_fprintf_l(fp2, "%s", loc2, "����������");	/* _fprintf_l��loc2��"����������"���o��. */
	fclose(fp2);	/* ���� */
	_free_locale(loc2);	/* _free_locale��loc2�����. */

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}