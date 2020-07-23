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
	HANDLE hProcess = NULL;	// �v���Z�X�n���h��hProcess��NULL�ŏ�����.
	TCHAR tszProcessName[MAX_PATH] = {0};	// �v���Z�X��tszProcessName��{0}�ŏ�����.
	DWORD dwBeforeSize = MAX_PATH;	// tszProcessName�̗v�f��dwBeforeSize��MAX_PATH�ŏ�����.
	DWORD dwAfterSize = 0;	// �i�[���ꂽ�v�f��dwAfterSize��0�ŏ�����.

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
			// �v���Z�XID���o�͂���.
			_tprintf(_T("dwProcessIds[%lu] = %lu, "), dwIndex, dwProcessIds[dwIndex]);	// �v���Z�XID�̏o��.
			hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwProcessIds[dwIndex]);	// OpenProcess��dwProcessIds[dwIndex]�̃v���Z�X���J��.
			if (hProcess != NULL){	// NULL�łȂ���.
				// �v���Z�X�n���h���̏o��.
				_tprintf(_T("hProcess = %lu, "), (unsigned long)hProcess);	// hProcess���o��.
				// �v���Z�X���̎擾.
				dwAfterSize = GetProcessImageFileName(hProcess, tszProcessName, dwBeforeSize);	// GetProcessImageFileName�Ńv���Z�X�����擾.
				if (dwAfterSize > 0){	// dwAfterSize��0���傫���Ȃ�.
					_tprintf(_T("tszProcessName = %s\n"), tszProcessName);	// tszProcessName���o��.
				}
				else{	// dwAfterSize��0�ȉ�.
					_tprintf(_T("GetProcessImageFileName failed!\n"));	// "GetProcessImageFileName failed!"���o��.
				}
				CloseHandle(hProcess);	// hProcess�����.
			}
			else{	// NULL�̎�.
				_tprintf(_T("OpenProcess failed!\n"));	// "OpenProcess failed!"�Əo��.
			}
		}
	}

	// �v���O�����̏I��
	return 0;

}