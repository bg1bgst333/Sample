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
	HANDLE hFile = NULL;	// HANDLE�^�t�@�C���n���h��hFile��NULL�ŏ�����.
	DWORD dwFileSize = 0;	// dwFileSize��0�ŏ�����.
	BYTE *pbtBuf = NULL;	// pbtBuf��NULL�ŏ�����.
	DWORD dwReadBytes = 0;	// dwReadBytes��0�ŏ�����.
	HANDLE hWriteFile = NULL;	// hWriteFile��NULL�ŏ�����.
	DWORD dwWrittenBytes = 0;	// dwWrittenBytes��0�ŏ�����.
	JOB_INFO_2 *ji2 = NULL;	// JOB_INFO_2�\����ji2��NULL�ŏ�����.

	// test.txt�̓ǂݍ���.
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"test.txt"���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE){	// hFile��INVALID_HANDLE_VALUE�Ȃ�.
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.
	}
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSize�Ńt�@�C���T�C�Y���擾.
	pbtBuf = new BYTE[dwFileSize + 1];	// (dwFileSize + 1)���̃������m��.
	ReadFile(hFile, pbtBuf, dwFileSize, &dwReadBytes, NULL);	// �ǂݍ����pbtBuf�Ɋi�[.
	pbtBuf[dwReadBytes] = 0x0;	// ������'\0'( = 0x0)�Ŗ��߂�.
	printf("dwReadBytes = %d\n", (int)dwReadBytes);	// 
	printf("pbtBuf = %s\n", pbtBuf);	// printf��pbtBuf�̓��e���o��.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

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
						_tprintf(_T("ji1->pPrinterName = %s\n"), ji1->pPrinterName);	// ji1->pPrinterName���o��.
						_tprintf(_T("ji1->pMachineName = %s\n"), ji1->pMachineName);	// ji1->pMachineName���o��.
						_tprintf(_T("ji1->pUserName = %s\n"), ji1->pUserName);	// ji1->pUserName���o��.
						_tprintf(_T("ji1->pDocument = %s\n"), ji1->pDocument);	// ji1->pDocument���o��.
						_tprintf(_T("ji1->pDatatype = %s\n"), ji1->pDatatype);	// ji1->pDatatype���o��.
						_tprintf(_T("ji1->pStatus = %s\n"), ji1->pStatus);	// ji1->pStatus���o��.

						// JOB_INFO_2�̎擾.
						dwNeeded = 0;	// dwNeeded��0�ɖ߂�.
						rc = 0;	// rc��0�ɖ߂�.
						rc = GetJob(hPrinter, aji1->JobId, 2, NULL, 0, &dwNeeded);	// GetJob�ŕK�v�ȃo�b�t�@�T�C�Y���擾����.
						if (!(rc != 122 && dwNeeded < 1)){	// rc��122(ERROR_INSUFFICIENT_BUFFER)���Ԃ��Ă��邩, dwNeeded�����̒l�Ȃ�, �S�̂͐^�ƂȂ�, �o�b�t�@�T�C�Y�擾�Ƃ��Ă͐���.
							ji2 = (JOB_INFO_2 *)new BYTE[dwNeeded];	// dwNeeded�̃��������m�ۂ�, ji2�Ɋi�[.
							rc = 0;	// rc��0�ɖ߂�.
							rc = GetJob(hPrinter, aji1->JobId, 2, (LPBYTE)ji2, dwNeeded, &dwNeeded);	// GetJob��ji2���擾.
							if (rc != 0){	// rc��0�ȊO�Ȃ琬��.
								_tprintf(_T("ji2->JobId = %lu\n"), ji2->JobId);	// ji2->JobId���o��.

								// �W���u���ꎞ��~.
								SetJob(hPrinter, aji1->JobId, 2, (LPBYTE)ji2, JOB_CONTROL_PAUSE);	// SetJob��ji2��JOB_CONTROL_PAUSE���Z�b�g.

								// �����̕ύX.
								ji2->pDevMode->dmFields = DM_ORIENTATION;	// ����.
								ji2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;	// ��.

								// spl�t�@�C���ւ̏�������.
								hWriteFile = CreateFile(aji1->Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��aji1->Path���J����, �擾�����n���h����hWriteFile�Ɋi�[.
								WriteFile(hWriteFile, pbtBuf, dwReadBytes, &dwWrittenBytes, NULL);	// WriteFile�ŏ�������.
								CloseHandle(hWriteFile);	// CloseHandle�ŕ���.

								// �W���u���ĊJ.
								SetJob(hPrinter, aji1->JobId, 2, (LPBYTE)ji2, JOB_CONTROL_RESUME);	// SetJob��ji2��JOB_CONTROL_RESUME���Z�b�g.

								// ����X�P�W���[���v��.
								ScheduleJob(hPrinter, aji1->JobId);	// ScheduleJob��aji1->JobId�̃W���u�����s.

							}
							delete[] ji2;	// ji2�����.
						}
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
	delete[] pbtBuf;	// pbtBuf�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}