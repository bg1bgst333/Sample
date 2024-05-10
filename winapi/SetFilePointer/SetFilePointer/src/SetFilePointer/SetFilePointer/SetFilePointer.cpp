// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hFile;		// HANDLE�^�t�@�C���n���h��hFile
	BYTE btBuf[16];		// BYTE�^�z��btBuf(����16)
	DWORD dwReadBytes;	// DWORD�^�ǂݍ��񂾃o�C�g��dwReadBytes.
	
	// �t�@�C�����J��
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}
	
	// �擪����2�o�C�g��Ɉړ�.
	SetFilePointer(hFile, 2, NULL, FILE_BEGIN);	// SetFilePointer�Ő擪����2�o�C�g��Ɉړ�.

	// 1�����ǂݍ���.
	ReadFile(hFile, btBuf, 1, &dwReadBytes, NULL);	// ReadFile��hFile�̓��e��btBuf��1�����ǂݍ���.
	btBuf[dwReadBytes] = 0x0;	// ������'\0'( = 0x0)�Ŗ��߂�.
	
	// btBuf���o��.
	printf("btBuf = %s\n", btBuf);	// printf��btBuf�̓��e���o��.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.
	
	// �v���O�����̏I��.
	return 0;

}