// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��E�z��̐錾�E������
	int d = 10;	// d�̒l��10�ɏ�����.
	unsigned int x = 0xA;	// x�̒l��0xA�ɏ�����.
	TCHAR c = _T('A');	// c�̒l��'A'�ɏ�����.
	TCHAR str[] = _T("ABCDE");	// str�̕������"ABCDE"�ɏ�����.
	TCHAR all_str[256];	// �S�Ă̒l��A��������������i�[���镶���z��all_str.(����256)

	// ���ׂĂ̒l��A������������̍쐬.
	wsprintf(all_str, _T("d = %d, x = 0x%X, c = %c, str = %s"), d, x, c, str);	// wsprintf�őS�Ă̒l��A��������������쐬.

	// all_str�̏o��
	_tprintf(_T("all_str: %s\n"), all_str);	// _tprintf��all_str�o��.

	// �v���O�����̏I��
	return 0;

}