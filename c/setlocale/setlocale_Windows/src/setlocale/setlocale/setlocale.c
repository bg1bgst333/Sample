/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̐錾 */
	char *loc1;
	char *loc2;
	char *loc3;
	char *loc4;
	char *loc5;
	char *loc6;
	char *loc7;
	char *loc8;
	char *loc9;

	/* NULL�w�� */
	loc1 = setlocale(LC_ALL, NULL);	/* setlocale��LC_ALL, NULL���w��. */
	printf("loc1 = %s\n", loc1);	/* loc1���o��. */

	/* ""�w�� */
	loc2 = setlocale(LC_ALL, "");	/* setlocale��LC_ALL, ""���w��. */
	printf("loc2 = %s\n", loc2);	/* loc2���o��. */

	/* "C"�w�� */
	loc3 = setlocale(LC_ALL, "C");	/* setlocale��LC_ALL, "C"���w��. */
	printf("loc3 = %s\n", loc3);	/* loc3���o��. */

	/* "Japanese_Japan.932"�w�� */
	loc4 = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���w��. */
	printf("loc4 = %s\n", loc4);	/* loc4���o��. */

	/* ������NULL�w��. */
	loc5 = setlocale(LC_ALL, NULL);	/* setlocale��LC_ALL, NULL���w��. */
	printf("loc5 = %s\n", loc5);	/* loc5���o��. */

	/* ������"C"�w��. */
	loc6 = setlocale(LC_ALL, "C");	/* setlocale��LC_ALL, "C"���w��. */
	printf("loc6 = %s\n", loc6);	/* loc6���o��. */

	/* ������""�w��. */
	loc7 = setlocale(LC_ALL, "");	/* setlocale��LC_ALL, ""���w��. */
	printf("loc7 = %s\n", loc7);	/* loc7���o��. */

	/* "Japanese"�w�� */
	loc8 = setlocale(LC_ALL, "Japanese");	/* setlocale��LC_ALL, "Japanese"���w��. */
	printf("loc8 = %s\n", loc8);	/* loc8���o��. */

	/* "UTF-8"�w�� */
	loc9 = setlocale(LC_ALL, "UTF-8");	/* setlocale��LC_ALL, "UTF-8"���w��. */
	printf("loc9 = %s\n", loc9);	/* loc9���o��. */

	/* �v���O�����̏I�� */
	return 0;

}