// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��E�z��̏�����.
	TCHAR tszText1[] = _T("ABCDE");	// TCHAR�^�����z��tszText1��"ABCDE"�ŏ�����.
	TCHAR tszText2[16] = {0};		// TCHAR�^�����z��tszText2(����16)��{0}�ŏ�����.

	// �R�s�[�O��2�̃e�L�X�g���o��.
	_tprintf(_T("before:\n"));	// "before:"�Əo��.
	_tprintf(_T("tszText1 = %s\n"), tszText1);	// tszText1�̏o��.
	_tprintf(_T("tszText2 = %s\n"), tszText2);	// tszText2�̏o��.

	// �e�L�X�g�̃R�s�[.
	lstrcpy(tszText2, tszText1);	// lstrcpy��tszText1��tszText2�ɃR�s�[.

	// �R�s�[���2�̃e�L�X�g���o��.
	_tprintf(_T("after:\n"));	// "after:"�Əo��.
	_tprintf(_T("tszText1 = %s\n"), tszText1);	// tszText1�̏o��.
	_tprintf(_T("tszText2 = %s\n"), tszText2);	// tszText2�̏o��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}
