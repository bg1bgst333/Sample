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
	PRINTER_DEFAULTS pd = {0};	// PRINTER_DEFAULTS�\����pd��{0}�ŏ�����.
	BOOL bOpen = FALSE;	// �v�����^���J��������\��bOpen��FALSE�ŏ�����.
	int aji1Size = sizeof(ADDJOB_INFO_1) + MAX_PATH + 1;	// aji1Size�̏�����.
	ADDJOB_INFO_1 *aji1 = NULL;	// ADDJOB_INFO_1�\����aji1��NULL�ŏ�����.
	DWORD dwNeeded = 0;	// �K�v�T�C�YdwNeeded��0�ŏ�����.
	int rc = 0;	// AddJob�̖߂�lrc��0�ŏ�����.
	JOB_INFO_1 *ji1 = NULL;	// JOB_INFO_1�\����ji1��NULL�ŏ�����.

	// ����̃v�����^�����擾.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinter��NULL��n���ăo�b�t�@�T�C�Y���擾.
	ptszBuf = new TCHAR[dwSize];	// dwSize���̃o�b�t�@���m��.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinter�Ŋ���̃v�����^�����擾.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBuf���o��.

	// ����̃v�����^���J��.
	pd.DesiredAccess = PRINTER_ACCESS_USE;	// ���[�U����.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, &pd);	// OpenPrinter�Ńv�����^��ptszBuf�̃v�����^���J��.
	if (bOpen){	// ����.
		if (hPrinter != NULL){	// �v�����^�n���h����NULL�ł͂Ȃ�.
			_tprintf(_T("hPrinter: 0x%08x\n"), (unsigned long)hPrinter);	// hPrinter���o��.

			// ����W���u�̒ǉ�.
			aji1 = (ADDJOB_INFO_1 *)new BYTE[aji1Size];	// aji1Size�̃��������m�ۂ�, aji1�Ɋi�[.
			rc = AddJob(hPrinter, 1, (LPBYTE)aji1, aji1Size, &dwNeeded);	// AddJob�ň���W���u�ǉ�.
			if (rc != 0){	// rc��0�ȊO�Ȃ琬��.(AddJob�̖߂�l�͖{��BOOL�����Aint�^rc�Ŏ���Ă���.���̓�͕ʓr�L�����Q��.)
				_tprintf(_T("aji1->JobId = %lu\n"), aji1->JobId);	// aji1->JobId���o��.
				_tprintf(_T("aji1->Path = %s\n"), aji1->Path);	// aji1->Path���o��.

				// ����W���u���̎擾.
				dwNeeded = 0;	// dwNeeded��0�ɖ߂�.
				rc = 0;	// rc��0�ɖ߂�.
				rc = GetJob(hPrinter, aji1->JobId, 1, NULL, 0, &dwNeeded);	// GetJob�ŕK�v�ȃo�b�t�@�T�C�Y���擾����.
				if (!(rc != 122 && dwNeeded < 1)){	// rc��122(ERROR_INSUFFICIENT_BUFFER)���Ԃ��Ă��邩, dwNeeded�����̒l�Ȃ�, �S�̂͐^�ƂȂ�, �o�b�t�@�T�C�Y�擾�Ƃ��Ă͐���.
					ji1 = (JOB_INFO_1 *)new BYTE[dwNeeded];	// dwNeeded�̃��������m�ۂ�, ji1�Ɋi�[.
					rc = 0;	// rc��0�ɖ߂�.
					rc = GetJob(hPrinter, aji1->JobId, 1, (LPBYTE)ji1, dwNeeded, &dwNeeded);	// GetJob��ji1���擾.
					if (rc != 0){	// rc��0�ȊO�Ȃ琬��.
						_tprintf(_T("ji1->JobId = %lu\n"), ji1->JobId);	// ji1->JobId���o��.
						MessageBox(NULL, _T("Debug Stop!"), _T("GetJob"), MB_OK);	// MessageBox�Ńf�o�b�O�p�Ɉ�U�������Ƃ߂�.
					}
					delete[] ji1;	// ji1�����.
				}

			}
			delete[] aji1;	// aji1�����.

			ClosePrinter(hPrinter);	// ClosePrinter��hPrinter�����.
		}
	}

	// ���������.
	delete[] ptszBuf;	// ptszBuf�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}