/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* main�֐��̒�` */
int main(void){

	/* �|�C���^�̐錾 */
	FILE *fp;	/* �t�@�C���|�C���^fp. */
	char buf[16];	/* char�^�o�b�t�@buf. */

	/* �t�@�C�����J��. */
	fp = _wfopen(L"test.txt", L"r");	/* _wfopen��L"test.txt"�Ƃ����t�@�C����Ǎ���p(L"r")�ŊJ��. */
	if (fp == NULL){	/* fp == NULL�Ȃ�t�@�C�����J���̂Ɏ��s. */

		/* �G���[���� */
		printf("Can't open file!\n");	/* printf��"Can't open file!"�Ƃ����G���[���b�Z�[�W���o��. */
		return -1;	/* �G���[�Ȃǈُ�I���̏ꍇ��, -1�Ȃǂ�0�ȊO�̒l��Ԃ�. */

	}

	/* �t�@�C������̓ǂݍ��� */
	fscanf(fp, "%s", buf);	/* fscanf��fp��ǂݍ����buf�Ɋi�[. */

	/* buf�̏o��. */
	printf("%s\n", buf);	/* printf��buf���o��. */

	/* �t�@�C�������. */
	fclose(fp);	/* fclose��fp�̎w���t�@�C�������. */

	/* �v���O�����̏I�� */
	return 0;	/* ����I�� */

}