// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <psapi.h>		// �v���Z�X

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	DWORD dwProcessIds[1024] = {0};	// �v���Z�XID�z��dwProcessIds(�v�f��1024)��{0}�ŏ�����.
	DWORD cbNeeded = 0;	// ���ۂ̃T�C�YcbNeeded��0�ŏ�����.
	BOOL bEnum = FALSE;	// EnumProcesses�̌��ʂ�ێ�����bEnum��FALSE�ŏ�����.
	DWORD dwNum = 0;	// ���ۂ̗v�f��dwNum��0�ŏ�����.
	DWORD dwIndex = 0;	// ���[�v�p�ϐ�dwIndex��0�ŏ�����.
	
	// �v���Z�XID�̗�
	bEnum = EnumProcesses(dwProcessIds, sizeof(dwProcessIds), &cbNeeded);	// EnumProcesses�Ńv���Z�X�z����擾.
	if (bEnum){	// TRUE�Ȃ�.
		// �z��T�C�Y�̏o��.
		_tprintf(_T("sizeof(dwProcessIds) = %lu\n"), sizeof(dwProcessIds));	// �z��T�C�Y�̏o��.
		// ���ۂɕK�v�ȃT�C�Y�̏o��.
		_tprintf(_T("cbNeeded = %lu\n"), cbNeeded);	// ���ۂ̃T�C�Y���o��.
		// ���ۂɕK�v�ȗv�f��.
		dwNum = cbNeeded / sizeof(DWORD);	// ���ۂ̃T�C�Y��DWORD�̃T�C�Y�Ŋ���.
		_tprintf(_T("dwNum = %lu\n"), dwNum);	// ���ۂ̗v�f�����o��.
		// �e�v�f�̏o��.
		for (dwIndex = 0; dwIndex < dwNum; dwIndex++){	// dwNum���J��Ԃ�.
			_tprintf(_T("dwProcessIds[%lu] = %lu\n"), dwIndex, dwProcessIds[dwIndex]);	// �v���Z�XID�̏o��.
		}
	}

	// �v���O�����̏I��
	return 0;

}