// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��E�z��̏�����.
	TCHAR tszText[] = _T("ABCDE");	// TCHAR�^�����z��tszText��"ABCDE"�ŏ�����.
	int iLen = 0;	// �e�L�X�g�̒���iLen��0�ŏ�����.

	// �e�L�X�g�̒������擾.
	iLen = lstrlen(tszText);	// lstrlen��tszText�̒������擾��, iLen�Ɋi�[.

	// �e�L�X�g�ƒ����̏o��.
	_tprintf(_T("tszText = %s\n"), tszText);	// tszText�̏o��.
	_tprintf(_T("iLen = %d\n"), iLen);	// iLen�̏o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}