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
	PRINTER_NOTIFY_INFO *pPNI = NULL;	// PRINTER_NOTIFY_INFO�\���̃|�C���^pPNI��NULL�ŏ�����.
	int i = 0;	// ���[�v�p�ϐ�i��0�ŏ�����.
	PRINTER_NOTIFY_OPTIONS pno = {0};	// PRINTER_NOTIFY_OPTIONS�\����pno��{0}�ŏ�����.
	PRINTER_NOTIFY_OPTIONS_TYPE pnot[2];	// PRINTER_NOTIFY_OPTIONS_TYPE�\���̔z��pnot(�v�f��2)
	WORD pnf[PRINTER_NOTIFY_FIELD_OBJECT_GUID + 1];	// PRINTER_NOTIFY_FIELD_XXX���i�[����z��pnf.(�v�f��27)
	WORD jnf[JOB_NOTIFY_FIELD_BYTES_PRINTED + 1];	// JOB_NOTIFY_FIELD_XXX���i�[����z��jnf.(�v�f��24)

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
			pno.Version = 2;	// �o�[�W������2.
			pno.Count = 2;	// pnot�̗v�f����2.
			pno.pTypes = pnot;	// pTypes��pnot���w��.
			for (i = 0; i <= PRINTER_NOTIFY_FIELD_OBJECT_GUID; i++){
				pnf[i] = PRINTER_NOTIFY_FIELD_SERVER_NAME + i;
			}
			pnot[0].Type = PRINTER_NOTIFY_TYPE;
			pnot[0].Count = PRINTER_NOTIFY_FIELD_OBJECT_GUID + 1;
			pnot[0].pFields = pnf;
			for (i = 0; i <= JOB_NOTIFY_FIELD_BYTES_PRINTED; i++){
				jnf[i] = JOB_NOTIFY_FIELD_PRINTER_NAME + i;
			}
			pnot[1].Type = JOB_NOTIFY_TYPE;
			pnot[1].Count = JOB_NOTIFY_FIELD_BYTES_PRINTED + 1;
			pnot[1].pFields = jnf;
			pTI->m_hHandles[0] = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, &pno);	// FindFirstPrinterChangeNotification�ŕύX�ʒm�n���h���擾.(pno�̃A�h���X��n��.)
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
							if (FindNextPrinterChangeNotification(pTI->m_hHandles[0], &dwChange, &pno, (LPVOID *)&pPNI)){	// FindNextPrinterChangeNotification�Œʒm�m�F.(pno�̃A�h���X��n��.)
								_tprintf(_T("notify!\n"));
								if (dwChange & PRINTER_CHANGE_ADD_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_SET_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_FAILED_CONNECTION_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_FAILED_CONNECTION_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_JOB){
									_tprintf(_T("PRINTER_CHANGE_ADD_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_JOB){
									_tprintf(_T("PRINTER_CHANGE_SET_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_JOB){
									_tprintf(_T("PRINTER_CHANGE_DELETE_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_WRITE_JOB){
									_tprintf(_T("PRINTER_CHANGE_WRITE_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_FORM){
									_tprintf(_T("PRINTER_CHANGE_ADD_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_FORM){
									_tprintf(_T("PRINTER_CHANGE_SET_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_FORM){
									_tprintf(_T("PRINTER_CHANGE_DELETE_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PORT){
									_tprintf(_T("PRINTER_CHANGE_ADD_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_CONFIGURE_PORT){
									_tprintf(_T("PRINTER_CHANGE_CONFIGURE_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PORT){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PRINT_PROCESSOR){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINT_PROCESSOR\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINT_PROCESSOR){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINT_PROCESSOR\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_SET_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_TIMEOUT){
									_tprintf(_T("PRINTER_CHANGE_TIMEOUT\n"));
								}

								// PRINTER_NOTIFY_INFO�̃`�F�b�N.
								if (pPNI != NULL){ // pPNI��NULL�Ŗ���.
									_tprintf(_T("pPNI->Version = %lu\n"), pPNI->Version);
									_tprintf(_T("pPNI->Flags = %lu\n"), pPNI->Flags);
									_tprintf(_T("pPNI->Count = %lu\n"), pPNI->Count);
									for (i = 0; i < pPNI->Count; i++){
										_tprintf(_T("pPNI->aData[%d].Id = %08x\n"), i, pPNI->aData[i].Id);
										_tprintf(_T("pPNI->aData[%d].Type = %08x\n"), i, pPNI->aData[i].Type);
										switch (pPNI->aData[i].Type){
											case PRINTER_NOTIFY_TYPE:
												{
													_tprintf(_T("PRINTER_NOTIFY_TYPE\n"));
													switch (pPNI->aData[i].Field){
														case PRINTER_NOTIFY_FIELD_SERVER_NAME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_SERVER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_PRINTER_NAME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PRINTER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_SHARE_NAME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_SHARE_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_PORT_NAME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PORT_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_DRIVER_NAME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_DRIVER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_COMMENT:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_COMMENT: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_LOCATION:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_LOCATION: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_DEVMODE:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_DEVMODE\n"));
																break;
															}
														case PRINTER_NOTIFY_FIELD_SEPFILE:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_SEPFILE: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_PARAMETERS:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PARAMETERS: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_DATATYPE:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_DATATYPE: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR\n"));
																break;
															}
														case PRINTER_NOTIFY_FIELD_ATTRIBUTES:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_ATTRIBUTES\n"));
																if (PRINTER_ATTRIBUTE_QUEUED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_QUEUED\n"));
																}
																if (PRINTER_ATTRIBUTE_DIRECT & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_DIRECT\n"));
																}
																if (PRINTER_ATTRIBUTE_DEFAULT & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_DEFAULT\n"));
																}
																if (PRINTER_ATTRIBUTE_SHARED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_SHARED\n"));
																}
																if (PRINTER_ATTRIBUTE_NETWORK & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_NETWORK\n"));
																}
																if (PRINTER_ATTRIBUTE_HIDDEN & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_HIDDEN\n"));
																}
																if (PRINTER_ATTRIBUTE_LOCAL & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_LOCAL\n"));
																}
																if (PRINTER_ATTRIBUTE_ENABLE_DEVQ & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_ENABLE_DEVQ\n"));
																}
																if (PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS\n"));
																}
																if (PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST\n"));
																}
																if (PRINTER_ATTRIBUTE_WORK_OFFLINE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_WORK_OFFLINE\n"));
																}
																if (PRINTER_ATTRIBUTE_ENABLE_BIDI & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_ENABLE_BIDI\n"));
																}
																if (PRINTER_ATTRIBUTE_RAW_ONLY & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_ATTRIBUTE_RAW_ONLY\n"));
																}
																break;
															}
														case PRINTER_NOTIFY_FIELD_PRIORITY:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PRIORITY: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_START_TIME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_START_TIME: %02d:%02d\n"), pPNI->aData[i].NotifyData.adwData[0] / 60, pPNI->aData[i].NotifyData.adwData[0] % 60);
																break;
															}
														case PRINTER_NOTIFY_FIELD_UNTIL_TIME:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_UNTIL_TIME: %02d:%02d\n"), pPNI->aData[i].NotifyData.adwData[0] / 60, pPNI->aData[i].NotifyData.adwData[0] % 60);
																break;
															}
														case PRINTER_NOTIFY_FIELD_STATUS:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_STATUS\n"));
																if (PRINTER_STATUS_PAUSED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PAUSED\n"));
																}
																if (PRINTER_STATUS_ERROR & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_ERROR\n"));
																}
																if (PRINTER_STATUS_PENDING_DELETION & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PENDING_DELETION\n"));
																}
																if (PRINTER_STATUS_PAPER_JAM & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PAPER_JAM\n"));
																}
																if (PRINTER_STATUS_PAPER_OUT & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PAPER_OUT\n"));
																}
																if (PRINTER_STATUS_MANUAL_FEED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_MANUAL_FEED\n"));
																}
																if (PRINTER_STATUS_PAPER_PROBLEM & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PAPER_PROBLEM\n"));
																}
																if (PRINTER_STATUS_OFFLINE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_OFFLINE\n"));
																}
																if (PRINTER_STATUS_IO_ACTIVE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_IO_ACTIVE\n"));
																}
																if (PRINTER_STATUS_BUSY & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_BUSY\n"));
																}
																if (PRINTER_STATUS_PRINTING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PRINTING\n"));
																}
																if (PRINTER_STATUS_OUTPUT_BIN_FULL & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_OUTPUT_BIN_FULL\n"));
																}
																if (PRINTER_STATUS_NOT_AVAILABLE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_NOT_AVAILABLE\n"));
																}
																if (PRINTER_STATUS_WAITING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_WAITING\n"));
																}
																if (PRINTER_STATUS_PROCESSING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PROCESSING\n"));
																}
																if (PRINTER_STATUS_INITIALIZING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_INITIALIZING\n"));
																}
																if (PRINTER_STATUS_WARMING_UP & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_WARMING_UP\n"));
																}
																if (PRINTER_STATUS_TONER_LOW & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_TONER_LOW\n"));
																}
																if (PRINTER_STATUS_NO_TONER & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_NO_TONER\n"));
																}
																if (PRINTER_STATUS_PAGE_PUNT & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_PAGE_PUNT\n"));
																}
																if (PRINTER_STATUS_USER_INTERVENTION & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_USER_INTERVENTION\n"));
																}
																if (PRINTER_STATUS_OUT_OF_MEMORY & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_OUT_OF_MEMORY\n"));
																}
																if (PRINTER_STATUS_DOOR_OPEN & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_DOOR_OPEN\n"));
																}
																if (PRINTER_STATUS_SERVER_UNKNOWN & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_SERVER_UNKNOWN\n"));
																}
																if (PRINTER_STATUS_POWER_SAVE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("PRINTER_STATUS_POWER_SAVE\n"));
																}
																break;
															}
														case PRINTER_NOTIFY_FIELD_STATUS_STRING:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_STATUS_STRING: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case PRINTER_NOTIFY_FIELD_CJOBS:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_CJOBS: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_AVERAGE_PPM:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_AVERAGE_PPM: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_TOTAL_PAGES:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_TOTAL_PAGES: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_PAGES_PRINTED:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_PAGES_PRINTED: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_TOTAL_BYTES:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_TOTAL_BYTES: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case PRINTER_NOTIFY_FIELD_BYTES_PRINTED:
															{
																_tprintf(_T("PRINTER_NOTIFY_FIELD_BYTES_PRINTED: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														default:
															{
																break;
															}
													};
													break;
												}
											case JOB_NOTIFY_TYPE:
												{
													_tprintf(_T("JOB_NOTIFY_TYPE\n"));
													switch (pPNI->aData[i].Field){
														case JOB_NOTIFY_FIELD_PRINTER_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PRINTER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_MACHINE_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_MACHINE_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_PORT_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PORT_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_USER_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_USER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_NOTIFY_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_NOTIFY_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_DATATYPE:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_DATATYPE: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_PRINT_PROCESSOR:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PRINT_PROCESSOR: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_PARAMETERS:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PARAMETERS: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_DRIVER_NAME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_DRIVER_NAME: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_DEVMODE:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_DEVMODE\n"));
																break;
															}
														case JOB_NOTIFY_FIELD_STATUS:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_STATUS\n"));
																if (JOB_STATUS_PAUSED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_PAUSED\n"));
																}
																if (JOB_STATUS_ERROR & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_ERROR\n"));
																}
																if (JOB_STATUS_DELETING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_DELETING\n"));
																}
																if (JOB_STATUS_SPOOLING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_SPOOLING\n"));
																}
																if (JOB_STATUS_PRINTING & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_PRINTING\n"));
																}
																if (JOB_STATUS_OFFLINE & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_OFFLINE\n"));
																}
																if (JOB_STATUS_PAPEROUT & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_PAPEROUT\n"));
																}
																if (JOB_STATUS_PRINTED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_PRINTED\n"));
																}
																if (JOB_STATUS_DELETED & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_DELETED\n"));
																}
																if (JOB_STATUS_BLOCKED_DEVQ & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_BLOCKED_DEVQ\n"));
																}
																if (JOB_STATUS_USER_INTERVENTION & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_USER_INTERVENTION\n"));
																}
																if (JOB_STATUS_RESTART & pPNI->aData[i].NotifyData.adwData[0]){
																	_tprintf(_T("JOB_STATUS_RESTART\n"));
																}
																break;
															}
														case JOB_NOTIFY_FIELD_STATUS_STRING:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_STATUS_STRING: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_DOCUMENT:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_DOCUMENT: %s\n"), pPNI->aData[i].NotifyData.Data.pBuf);
																break;
															}
														case JOB_NOTIFY_FIELD_PRIORITY:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PRIORITY: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case JOB_NOTIFY_FIELD_POSITION:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_POSITION: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case JOB_NOTIFY_FIELD_SUBMITTED:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_SUBMITTED\n"));
																break;
															}
														case JOB_NOTIFY_FIELD_START_TIME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_START_TIME: %02d:%02d\n"), pPNI->aData[i].NotifyData.adwData[0] / 60, pPNI->aData[i].NotifyData.adwData[0] % 60);
																break;
															}
														case JOB_NOTIFY_FIELD_UNTIL_TIME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_UNTIL_TIME: %02d:%02d\n"), pPNI->aData[i].NotifyData.adwData[0] / 60, pPNI->aData[i].NotifyData.adwData[0] % 60);
																break;
															}
														case JOB_NOTIFY_FIELD_TIME:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_TIME: %02d:%02d\n"), pPNI->aData[i].NotifyData.adwData[0] / 60, pPNI->aData[i].NotifyData.adwData[0] % 60);
																break;
															}
														case JOB_NOTIFY_FIELD_TOTAL_PAGES:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_TOTAL_PAGES: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case JOB_NOTIFY_FIELD_PAGES_PRINTED:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_PAGES_PRINTED: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case JOB_NOTIFY_FIELD_TOTAL_BYTES:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_TOTAL_BYTES: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														case JOB_NOTIFY_FIELD_BYTES_PRINTED:
															{
																_tprintf(_T("JOB_NOTIFY_FIELD_BYTES_PRINTED: %d\n"), pPNI->aData[i].NotifyData.adwData[0]);
																break;
															}
														default:
															{
																break;
															}
													};
													break;
												}
											default:
												{
													break;
												}
										};
									}
									FreePrinterNotifyInfo(pPNI);	// FreePrinterNotifyInfo��pPNI�����.
								}

							}

						}
					}

					CloseHandle(pTI->m_hHandles[1]);	// �Ƃ肠������pTI->m_hHandles[1]��CloseHandle�ŕ���.
				}

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