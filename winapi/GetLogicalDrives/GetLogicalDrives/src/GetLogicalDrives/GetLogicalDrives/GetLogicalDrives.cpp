// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	DWORD d;	// �L���ȃh���C�u�������r�b�g��1�������Ă���DWORD�^�r�b�g�}�X�Nd.
	DWORD i;	// ���[�vDWORD�^�ϐ�i.

	// �L���ȃh���C�u�ꗗ���擾.
	d = GetLogicalDrives();	// GetLogicalDrives�Ńr�b�g�}�X�Nd���擾.

	// �h���C�u���^�[�̐��̕������J��Ԃ�.
	for (i = 0; i < 26; i++){	// �h���C�u���^�[��'A'����'Z'��26��.
		if (d & (1 << i)){	// i == 0�Ԗڂ�1�Ȃ�'A'�h���C�u���L��, i == 1�Ԗڂ�1�Ȃ�'B'�h���C�u���L��, ...�Ƒ����Ă�.
			_tprintf(_T("%c:\n"), 'A' + i);	// �L���ȃh���C�u���^�[���o��.
		}
	}

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}