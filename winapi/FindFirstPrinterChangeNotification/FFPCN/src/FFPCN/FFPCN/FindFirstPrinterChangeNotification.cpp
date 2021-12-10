// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	DWORD dwSize = 0;	// �o�b�t�@�T�C�YdwSize��0�ŏ�����.
	TCHAR *ptszBuf = NULL;	// �v�����^�����i�[���镶����o�b�t�@�|�C���^ptszBuf��NULL�ŏ�����.
	HANDLE hPrinter = NULL;	// �v�����^�n���h��hPrinter��NULL�ŏ�����.
	BOOL bOpen = FALSE;	// �v�����^���J��������\��bOpen��FALSE�ŏ�����.
	HANDLE hChangeNotify = NULL;	// �ύX�ʒm�n���h��hChangeNotify��NULL�ŏ�����.

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
			hChangeNotify = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, NULL);	// FindFirstPrinterChangeNotification�ŕύX�ʒm�n���h���擾.
			_tprintf(_T("hChangeNotify: 0x%08x\n"), (unsigned long)hChangeNotify);	// hChangeNotify���o��.
			CloseHandle(hChangeNotify);	// �Ƃ肠������hChangeNotify��CloseHandle�ŕ���.

			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// ���������.
	delete[] ptszBuf;	// ptszBuf�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}