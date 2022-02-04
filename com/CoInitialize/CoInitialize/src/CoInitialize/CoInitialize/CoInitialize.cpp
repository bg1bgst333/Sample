// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��

// �X���b�h�̈����Ƃ��ēn���\����THREAD_PARAM�̒�`.
typedef struct{
	int m_iNo;				// �X���b�h�ԍ�
}THREAD_PARAM;	// �����THREAD_PARAM�^�̊���.

// ThreadProc�֐��̒�`
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// �ϐ��̐錾
	THREAD_PARAM *pTP;	// THREAD_PARAM�^�|�C���^pTP.

	// ����lpParameter��THREAD_PARAM�^�̃|�C���^�ɃL���X�g.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameter��THREAD_ARG�^�̃|�C���^�ɃL���X�g����, pTP�Ɋi�[.

	// "Thread Begin"
	_tprintf(_T("Thread Begin\n"));	// "Thread Begin"�Əo��.

	// ThreadProc�̒���COM�̏�����.
	HRESULT hr = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr�Ɋi�[.
	if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("ThreadProc: CoInitialize success!\n"));	// "CoInitialize success!"�Əo��.
	}

	// 5�b�x�~.
	Sleep(5000);	// Sleep��5000�~���b�x�~.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// "Thread End"
	_tprintf(_T("Thread End\n"));	// "Thread End"�Əo��.

	// �X���b�h�̏I��
	ExitThread((DWORD)pTP->m_iNo);	// ExitThread��pTP->m_iNo��(DWORD)�ɃL���X�g�������̂�n���ăX���b�h���I������.

}

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾
	HANDLE hThread;		// HANDLE�^�X���b�h�n���h��hThread
	DWORD dwThreadId;	// DWORD�^�X���b�hID dwThreadId
	THREAD_PARAM tp;	// �����Ƃ��ēn��THREAD_PARAM�^tp
	DWORD dwExitCode;	// DWORD�^�I���R�[�hdwExitCode

	// COM�̏�����.
	HRESULT hr = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr�Ɋi�[.
	if (hr == S_OK){	// S_OK�Ȃ珉��������.
		_tprintf(_T("CoInitialize success!\n"));	// "CoInitialize success!"�Əo��.
	}

	// 2��ڂ�COM�̏�����.
	HRESULT hr2 = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr2�Ɋi�[.
	if (hr2 == S_FALSE){	// S_FALSE�Ȃ炷�łɏ���������Ă���.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"�Əo��.
	}

	// �X���b�h�̊J�n
	tp.m_iNo = 0;	// m_iNo = 0
	hThread = CreateThread(NULL, 0, ThreadProc, &tp, 0, &dwThreadId);	// CreateThread�ŃX���b�h�����y�ъJ�n.(������tp��n���Ă���.)

	// �V�O�i����ԂɂȂ�܂őҋ@.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObject��hThread���V�O�i����ԂɂȂ�܂őҋ@.

	// �I���R�[�h�̎擾.
	GetExitCodeThread(hThread, &dwExitCode);	// GetExitCodeThread�ŃX���b�h�̏I���R�[�h���擾.
	_tprintf(_T("dwExitCode = %lu\n"), dwExitCode);	// dwExitCode�̒l���o��.
	if (hThread != NULL){	// hThread��NULL�łȂ�.
		CloseHandle(hThread);	// CloseHandle��hThread�����.
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}