/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <sys/types.h>	/* �h���^ */
#include <sys/stat.h>	/* �t�@�C����� */

/* main�֐��̒�` */
int main(void){

	/* �\���̂̐錾 */
	struct _stat sst;	/* _stat�\���̕ϐ�sst. */

	/* �t�@�C�������擾. */
	if (_stat("test.txt", &sst) == 0){	/* _stat��"test.txt"�̃t�@�C�������擾��, sst�Ɋi�[.(0�Ȃ琬��.) */

		/* �擾�ł�����, �t�@�C���T�C�Y�ƃh���C�u���^�[���o��. */
		printf("sst.st_size = %d\n", sst.st_size);	/* sst.st_size���o��. */
		printf("sst.st_dev = %d(drive = %c)\n", sst.st_dev, 'A' + sst.st_dev);	/* sst.st_dev���o��. */

	}

	/* ����I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}