// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �z��E�|�C���^�̏�����.
	TCHAR tszDrives[128] = {0};	// �h���C�u������Q���i�[�����TCHAR�^�z��tszDrives(����128)��{0}�ŏ�����.
	TCHAR *ptszDrive = NULL;	// �h���C�u��������w��TCHAR�^�|�C���^ptszDrive��NULL�ŏ�����.

	// �L���ȃh���C�u������Q���擾.
	GetLogicalDriveStrings(128, tszDrives);	// GetLogicalDriveStrings�ŗL���ȃh���C�u������Q���擾.

	// �h���C�u������ꗗ�o��.
	ptszDrive = tszDrives;	// �擪�ɃZ�b�g.
	while (*ptszDrive != _T('\0')){	// NULL�����łȂ�.
		_tprintf(_T("%s\n"), ptszDrive);	// ptszDrive���o��.
		ptszDrive += _tcslen(ptszDrive) + 1;	// ptszDrive��(������ + 1)�̕������i��.
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}