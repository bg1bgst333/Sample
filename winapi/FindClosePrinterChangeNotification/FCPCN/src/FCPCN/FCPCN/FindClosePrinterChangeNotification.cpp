// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// �֐��v���g�^�C�v�錾.
void WINAPI ThreadProc(LPVOID lpParameter);	// �X���b�h��������ThreadProc.

// �X���b�h�ɓn�����\����THREAD_INFO�̒�`.
typedef struct{
	BOOL m_bRunning;	// ���s�����ǂ���.
	HANDLE m_hHandles[2];	// 0: �ύX�ʒm�n���h��, 1: ��~�n���h��
} THREAD_INFO;

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̒�`�Ə�����.
	HANDLE hThread = NULL;	// �X���b�h�n���h��hThread��NULL�ŏ�����.
	THREAD_INFO ti = {0};	// THREAD_INFO�\����ti��{0}�ŏ�����.
	DWORD dwThreadId = 0;	// �X���b�hID��dwThreadId��0�ŏ�����.

	// �X���b�h�̊J�n.
	_tprintf(_T("thread begin before.\n"));
	hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadProc, (LPVOID)&ti, 0, &dwThreadId);	// CreateThread��ThreadProc�J�n.

	// 1���x�~.
	_tprintf(_T("thread wait before.\n"));
	Sleep(1 * 60 * 1000);	// Sleep��1���҂�.

	// �I��������.
	ti.m_bRunning = FALSE;	// m_bRunning��FALSE��.
	SetEvent(ti.m_hHandles[1]);	// ��~�n���h�����V�O�i����Ԃ�.

	// �X���b�h�I����҂�.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObject�ŏI���܂ő҂�.

	// �X���b�h�n���h�������.
	_tprintf(_T("thread close before.\n"));
	CloseHandle(hThread);	// CloseHandle��hThread�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}

// �X���b�h��������ThreadProc�̒�`.
void WINAPI ThreadProc(LPVOID lpParameter){

	// �ϐ��̐錾�Ə�����.
	DWORD dwSize = 0;	// �o�b�t�@�T�C�YdwSize��0�ŏ�����.
	TCHAR *ptszBuf = NULL;	// �v�����^�����i�[���镶����o�b�t�@�|�C���^ptszBuf��NULL�ŏ�����.
	HANDLE hPrinter = NULL;	// �v�����^�n���h��hPrinter��NULL�ŏ�����.
	BOOL bOpen = FALSE;	// �v�����^���J��������\��bOpen��FALSE�ŏ�����.
	THREAD_INFO *pTI = NULL;	// THREAD_INFO�|�C���^pTI��NULL�ŏ�����.
	DWORD dwChange = 0;	// �����ς������������dwChange��0�ŏ�����.

	// �J�n.
	_tprintf(_T("threadproc begin before.\n"));

	// ������THREAD_INFO�ɖ߂�.
	pTI = (THREAD_INFO *)lpParameter;	// lpParameter��(THREAD_INFO *)�ɃL���X�g.
	pTI->m_bRunning = TRUE;	// m_bRunning��TRUE�ɂ���.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.
	ptszBuf = new TCHAR[dwSize];	// dwSize���̃o�b�t�@���m��.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ŋ���̃v�����^�����擾.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// �v�����^�n���h���̎擾.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinter�Ńv�����^��ptszBuf�̃v�����^���J��.
	if (bOpen){	// ����.
		if (hPrinter != NULL){	// �v�����^�n���h����NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter: 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter���o��.

			// �ύX�ʒm�n���h���̎擾.
			pTI->m_hHandles[0] = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, NULL);	// FindFirstPrinterChangeNotification�ŕύX�ʒm�n���h���擾.
			if (pTI->m_hHandles[0] != NULL){	// NULL�łȂ�.
				_tprintf(_T("pTI->m_hHandles[0]: 0x%08x\n"), (unsigned long)pTI->m_hHandles[0]);	// pTI->m_hHandles[0]���o��.
				
				// ��~�C�x���g�̍쐬.
				pTI->m_hHandles[1] = CreateEvent(NULL, FALSE, FALSE, _T("StopEvent"));	// CreateEvent��"StopEvent"���쐬.
				if (pTI->m_hHandles[1] != NULL){	// NULL�łȂ�.
					_tprintf(_T("pTI->m_hHandles[1]: 0x%08x\n"), (unsigned long)pTI->m_hHandles[1]);	// pTI->m_hHandles[1]���o��.

					// �Ď����[�v.
					while (pTI->m_bRunning){	// pTI->m_bRunning��TRUE�̊�.

						// 2�̃n���h�����Ď�.
						if (WaitForMultipleObjects(2, pTI->m_hHandles, FALSE, INFINITE) == WAIT_OBJECT_0){	// 2�̃n���h���̂ǂ��炩���V�O�i����ԂɂȂ�܂ő҂�.

							// �v�����^�̒ʒm�Ȃ̂���FindNextPrinterChangeNotification�ł킩��.
							if (FindNextPrinterChangeNotification(pTI->m_hHandles[0], &dwChange, NULL, NULL)){	// FindNextPrinterChangeNotification�Œʒm�m�F.
								_tprintf(_T("notify!\n"));
							}

						}
					}

					CloseHandle(pTI->m_hHandles[1]);	// �Ƃ肠������pTI->m_hHandles[1]��CloseHandle�ŕ���.
				}

				//CloseHandle(pTI->m_hHandles[0]);	// �Ƃ肠������pTI->m_hHandles[0]��CloseHandle�ŕ���.
				FindClosePrinterChangeNotification(pTI->m_hHandles[0]);	// pTI->m_hHandles[0]��FindClosePrinterChangeNotification�ŕ���.
			}

			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// ���������.
	delete[] ptszBuf;	// ptszBuf�����.

	// �I��.
	_tprintf(_T("threadproc after before.\n"));

}