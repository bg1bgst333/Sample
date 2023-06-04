// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <dbt.h>		// �f�o�C�X�Ǘ�
#include <map>			// std::map

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
TCHAR GetDriveLetterFromMask(unsigned long unitmask);	// ���j�b�g�}�X�N���h���C�u���^�[�ɕϊ�.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�Ə�����.
	HWND hWnd;							// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;							// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;						// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DBT_DEVICEQUERYREMOVEFAILED");	// �E�B���h�E�N���X����"DBT_DEVICEQUERYREMOVEFAILED".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// �Ȃ�
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("DBT_DEVICEQUERYREMOVEFAILED"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("DBT_DEVICEQUERYREMOVEFAILED"), _T("DBT_DEVICEQUERYREMOVEFAILED"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"DBT_DEVICEQUERYREMOVEFAILED"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("DBT_DEVICEQUERYREMOVEFAILED"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W����
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �X�^�e�B�b�N�I�u�W�F�N�g�̐錾.
	static std::map<HDEVNOTIFY, DWORD> mapNotifyDriveMap;	// �ʒm�n���h�����L�[, �h���C�u�}�X�N��l�Ƃ���std::map.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �f�o�C�X�̏�Ԃ��ω�������.
		case WM_DEVICECHANGE:	// �f�o�C�X�̏�Ԃ��ω�������.(uMsg��WM_DEVICECHANGE�̎�.)

			// WM_DEVICECHANGE�u���b�N
			{

				// �f�o�C�X�Ǘ��C�x���g�ɑ΂��鏈��.
				switch (wParam){	// wParam���ƂɐU�蕪��.

					// �f�o�C�X�m�[�h���ύX���ꂽ��.
					case DBT_DEVNODES_CHANGED:

						// DBT_DEVNODES_CHANGED�u���b�N
						{

							// "DBT_DEVNODES_CHANGED"�ƕ\��.
							OutputDebugString(_T("DBT_DEVNODES_CHANGED\n"));	// OutputDebugString��"DBT_DEVNODES_CHANGED"�ƕ\��.

						}

						// ����̏����֌�����.
						break;

					// �f�o�C�X���ڑ�����g�p�\�ɂȂ�����.
					case DBT_DEVICEARRIVAL:

						// DBT_DEVICEARRIVAL�u���b�N
						{

							// �ϐ��̐錾�E������
							DEV_BROADCAST_HDR *pDBH;	// DEV_BROADCAST_HDR�|�C���^pDBH.
							TCHAR tszDBH[1024] = {0};	// TCHAR�����z��tszDBH(����1024)��{0}�ŏ�����.

							// "DBT_DEVICEARRIVAL"�ƕ\��.
							OutputDebugString(_T("DBT_DEVICEARRIVAL\n"));	// OutputDebugString��"DBT_DEVICEARRIVAL"�ƕ\��.

							// lParam��pDBH��.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParam��DEV_BROADCAST_HDR�|�C���^�ɃL���X�g����, pDBH�Ɋi�[.

							// pDBH�̊e�v�f���e�L�X�g�ϊ�.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu\n"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintf��pDBH�̊e�v�f���������e�L�X�g��tszDBH�ɕϊ�.

							// tszDBH��\��.
							OutputDebugString(tszDBH);	// OutputDebugString��tszDBH��\��.

							// pDBH->dbch_devicetype���ƂɐU�蕪��.
							switch (pDBH->dbch_devicetype){

								// �{�����[���f�o�C�X
								case DBT_DEVTYP_VOLUME:

									// DBT_DEVTYP_VOLUME�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_VOLUME *pDBV;	// DEV_BROADCAST_VOLUME�|�C���^pDBV.
										TCHAR tszDBV[1024] = {0};	// TCHAR�����z��tszDBV(����1024)��{0}�ŏ�����.

										// pDBH��pDBV�ɕϊ�.
										pDBV = (DEV_BROADCAST_VOLUME *)pDBH;	// pDBH��DEV_BROADCAST_VOLUME�|�C���^�ɃL���X�g����, pDBV�Ɋi�[.

										// pDBV�̊e�v�f���e�L�X�g�ϊ�.
										_stprintf(tszDBV, _T("pDBV->dbcv_size = %lu,\n pDBV->dbcv_devicetype = %lu,\n pDBV->dbcv_reserved = %lu,\n pDBV->dbcv_unitmask = %lu,\n pDBV->dbcv_flags = %u\n"), pDBV->dbcv_size, pDBV->dbcv_devicetype, pDBV->dbcv_reserved, pDBV->dbcv_unitmask, pDBV->dbcv_flags);	// _stprintf��pDBV�̊e�v�f���������e�L�X�g��tszDBV�ɕϊ�.

										// tszDBV��\��.
										OutputDebugString(tszDBV);	// OutputDebugString��tszDBV��\��.

										// �h���C�u���^�[���擾.
										TCHAR tchLetter = GetDriveLetterFromMask(pDBV->dbcv_unitmask);	// GetDriveLetterFromMask��pDBV->dbcv_unitmask��tchLetter�ɕϊ�.
										TCHAR tszLetter[4];
										tszLetter[0] = tchLetter;	// 0�����ڂ�tchLetter.
										tszLetter[1] = _T('\0');	// 1�����ڂ�NULL����.
										_tcscat(tszLetter, _T(":\\"));	// ":\"��A��.
										TCHAR tszOutStr[128];
										_stprintf(tszOutStr, _T("tszLetter = %s\n"), tszLetter);
										OutputDebugString(tszOutStr);	// OutputDebugString��tszOutStr��\��.

										// �l�Ƀh���C�u�}�X�N�����݂��邩.
										for (std::map<HDEVNOTIFY, DWORD>::iterator itor = mapNotifyDriveMap.begin(); itor != mapNotifyDriveMap.end(); itor++){	// �}�b�v�̕��J��Ԃ�.
											if (itor->second == pDBV->dbcv_unitmask){	// �l�Ƀh���C�u�}�X�N��������.
												return TRUE;	// �����ŏI���.
											}
										}

										// �h���C�u�̃��[�g�f�B���N�g�����J��.
										HANDLE hDirectory = CreateFile(tszLetter, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);	// CreateFile��tszLetter���J��.(FILE_FLAG_BACKUP_SEMANTICS�Ńf�B���N�g�����J����.)
										if (hDirectory != INVALID_HANDLE_VALUE){	// ����.
											// DEV_BROADCAST_HANDLE�̏���.
											DEV_BROADCAST_HANDLE dbhandle = {0};	// DEV_BROADCAST_HANDLE�\����dbhandle��{0}�ŏ�����.
											dbhandle.dbch_size = sizeof(DEV_BROADCAST_HANDLE);	// �T�C�Y��sizeof(DEV_BROADCAST_HANDLE).
											dbhandle.dbch_devicetype = DBT_DEVTYP_HANDLE;	// �^�C�v��DBT_DEVTYP_HANDLE.
                                           	dbhandle.dbch_reserved = 0;	// �\��ς݂�0.
											dbhandle.dbch_handle = hDirectory;	// �f�B���N�g���n���h��.
											dbhandle.dbch_nameoffset = 0;	// �I�t�Z�b�g��0.
											dbhandle.dbch_hdevnotify = 0;	// ������0�ł���.
											// �f�o�C�X�ʒm�o�^.
											HDEVNOTIFY hDevNotify = RegisterDeviceNotification(hwnd, &dbhandle, DEVICE_NOTIFY_WINDOW_HANDLE);	// RegisterDeviceNotification��dbhandle��o�^��, hDevNotify�𓾂�.
											TCHAR tszHDevNotify[32] = {0};	// TCHAR�����z��tszHDevNotify(����32)��{0}�ŏ�����.
											_stprintf(tszHDevNotify, _T("hDevNotify = 0x%08x\n"), (unsigned long)hDevNotify);	// _stprintf��hDevNotify��tszHDevNotify�ɕϊ�.
											OutputDebugString(tszHDevNotify);	// OutputDebugString��tszHDevNotify��\��.
											// mapNotifyDriveMap�ɓo�^.
											mapNotifyDriveMap[hDevNotify] = pDBV->dbcv_unitmask;	// �L�[hDevNotify�ɒlpDBV->dbcv_unitmask���Z�b�g.
										}

									}

									// ����̏����֌�����.
									break;

								// ��L�ȊO�̏���.
								default:

									// default�u���b�N
									{

									}

									// ����̏����֌�����.
									break;

							}

						}

						// ����̏����֌�����.
						break;

					// �f�o�C�X�̍폜���v�����ꂽ��.
					case DBT_DEVICEQUERYREMOVE:

						// DBT_DEVICEQUERYREMOVE�u���b�N
						{

							// �ϐ��̐錾�E������
							DEV_BROADCAST_HDR *pDBH;	// DEV_BROADCAST_HDR�|�C���^pDBH.
							TCHAR tszDBH[1024] = {0};	// TCHAR�����z��tszDBH(����1024)��{0}�ŏ�����.

							// "DBT_DEVICEQUERYREMOVE"�ƕ\��.
							OutputDebugString(_T("DBT_DEVICEQUERYREMOVE\n"));	// OutputDebugString��"DBT_DEVICEQUERYREMOVE"�ƕ\��.

							// lParam��pDBH��.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParam��DEV_BROADCAST_HDR�|�C���^�ɃL���X�g����, pDBH�Ɋi�[.

							// pDBH�̊e�v�f���e�L�X�g�ϊ�.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu\n"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintf��pDBH�̊e�v�f���������e�L�X�g��tszDBH�ɕϊ�.

							// tszDBH��\��.
							OutputDebugString(tszDBH);	// OutputDebugString��tszDBH��\��.

							// pDBH->dbch_devicetype���ƂɐU�蕪��.
							switch (pDBH->dbch_devicetype){

								// �n���h��
								case DBT_DEVTYP_HANDLE:

									// DBT_DEVTYP_HANDLE�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_HANDLE *pDBHandle = (DEV_BROADCAST_HANDLE *)pDBH;	// DEV_BROADCAST_HDR�|�C���^����DEV_BROADCAST_HANDLE�|�C���^��.

										// "DBT_DEVTYP_HANDLE"��\��.
										OutputDebugString(_T("DBT_DEVTYP_HANDLE\n"));	// OutputDebugString��"DBT_DEVTYP_HANDLE"��\��.

										// �����Ńf�B���N�g���n���h�������.
										if (pDBHandle->dbch_handle != NULL){	// �f�B���N�g���J���Ă���.
											CloseHandle(pDBHandle->dbch_handle);	// �{���͂����ŕ���.
											pDBHandle->dbch_handle = NULL;	// NULL���Z�b�g.
										}

									}

									// ����̏����֌�����.
									break;

								// ��L�ȊO�̏���.
								default:

									// default�u���b�N
									{

									}

									// ����̏����֌�����.
									break;

							}

						}

						// ����̏����֌�����.
						break;

					// �f�o�C�X�̍폜�v���Ɏ��s������.
					case DBT_DEVICEQUERYREMOVEFAILED:

						// DBT_DEVICEQUERYREMOVEFAILED�u���b�N
						{

							// �ϐ��̐錾�E������
							DEV_BROADCAST_HDR *pDBH;	// DEV_BROADCAST_HDR�|�C���^pDBH.
							TCHAR tszDBH[1024] = {0};	// TCHAR�����z��tszDBH(����1024)��{0}�ŏ�����.

							// "DBT_DEVICEQUERYREMOVEFAILED"�ƕ\��.
							OutputDebugString(_T("DBT_DEVICEQUERYREMOVEFAILED\n"));	// OutputDebugString��"DBT_DEVICEQUERYREMOVEFAILED"�ƕ\��.

							// lParam��pDBH��.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParam��DEV_BROADCAST_HDR�|�C���^�ɃL���X�g����, pDBH�Ɋi�[.

							// pDBH�̊e�v�f���e�L�X�g�ϊ�.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu\n"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintf��pDBH�̊e�v�f���������e�L�X�g��tszDBH�ɕϊ�.

							// tszDBH��\��.
							OutputDebugString(tszDBH);	// OutputDebugString��tszDBH��\��.

							// pDBH->dbch_devicetype���ƂɐU�蕪��.
							switch (pDBH->dbch_devicetype){

								// �n���h��
								case DBT_DEVTYP_HANDLE:

									// DBT_DEVTYP_HANDLE�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_HANDLE *pDBHandle = (DEV_BROADCAST_HANDLE *)pDBH;	// DEV_BROADCAST_HDR�|�C���^����DEV_BROADCAST_HANDLE�|�C���^��.

										// "DBT_DEVTYP_HANDLE"��\��.
										OutputDebugString(_T("DBT_DEVTYP_HANDLE\n"));	// OutputDebugString��"DBT_DEVTYP_HANDLE"��\��.

										// �ʒm�n���h���������, �h���C�u�}�X�N���擾����, �f�B���N�g�����J���Ȃ���, �ʒm��o�^���Ȃ���.
										if (mapNotifyDriveMap.find(pDBHandle->dbch_hdevnotify) != mapNotifyDriveMap.end()){	// ���݂���.
											// �h���C�u���^�[���擾.
											DWORD dwDriveMask = mapNotifyDriveMap[pDBHandle->dbch_hdevnotify];
											TCHAR tchLetter = GetDriveLetterFromMask(dwDriveMask);	// GetDriveLetterFromMask��dwDriveMask��tchLetter�ɕϊ�.
											TCHAR tszLetter[4];
											tszLetter[0] = tchLetter;	// 0�����ڂ�tchLetter.
											tszLetter[1] = _T('\0');	// 1�����ڂ�NULL����.
											_tcscat(tszLetter, _T(":\\"));	// ":\"��A��.
											TCHAR tszOutStr[128];
											_stprintf(tszOutStr, _T("tszLetter = %s\n"), tszLetter);
											OutputDebugString(tszOutStr);	// OutputDebugString��tszOutStr��\��.
											// �h���C�u�̃��[�g�f�B���N�g�����J��.
											HANDLE hDirectory = CreateFile(tszLetter, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);	// CreateFile��tszLetter���J��.(FILE_FLAG_BACKUP_SEMANTICS�Ńf�B���N�g�����J����.)
											if (hDirectory != INVALID_HANDLE_VALUE){	// ����.
												BOOL bRet = UnregisterDeviceNotification(pDBHandle->dbch_hdevnotify);	// UnregisterDeviceNotification�ł���܂ł̒ʒm����U����.
												if (bRet){
													mapNotifyDriveMap.erase(pDBHandle->dbch_hdevnotify);	// mapNotifyDriveMap������폜.
													// DEV_BROADCAST_HANDLE�̏���.
													DEV_BROADCAST_HANDLE dbhandle = {0};	// DEV_BROADCAST_HANDLE�\����dbhandle��{0}�ŏ�����.
													dbhandle.dbch_size = sizeof(DEV_BROADCAST_HANDLE);	// �T�C�Y��sizeof(DEV_BROADCAST_HANDLE).
													dbhandle.dbch_devicetype = DBT_DEVTYP_HANDLE;	// �^�C�v��DBT_DEVTYP_HANDLE.
													dbhandle.dbch_reserved = 0;	// �\��ς݂�0.
													dbhandle.dbch_handle = hDirectory;	// �f�B���N�g���n���h��.
													dbhandle.dbch_nameoffset = 0;	// �I�t�Z�b�g��0.
													dbhandle.dbch_hdevnotify = 0;	// ������0�ł���.
													// �f�o�C�X�ʒm�o�^.
													HDEVNOTIFY hDevNotify = RegisterDeviceNotification(hwnd, &dbhandle, DEVICE_NOTIFY_WINDOW_HANDLE);	// RegisterDeviceNotification��dbhandle��o�^��, hDevNotify�𓾂�.
													TCHAR tszHDevNotify[32] = {0};	// TCHAR�����z��tszHDevNotify(����32)��{0}�ŏ�����.
													_stprintf(tszHDevNotify, _T("hDevNotify = 0x%08x\n"), (unsigned long)hDevNotify);	// _stprintf��hDevNotify��tszHDevNotify�ɕϊ�.
													OutputDebugString(tszHDevNotify);	// OutputDebugString��tszHDevNotify��\��.
													// mapNotifyDriveMap�ɓo�^.
													mapNotifyDriveMap[hDevNotify] = dwDriveMask;	// �L�[hDevNotify�ɒldwDriveMask���Z�b�g.
												}
											}
										}

									}

									// ����̏����֌�����.
									break;

								// ��L�ȊO�̏���.
								default:

									// default�u���b�N
									{

									}

									// ����̏����֌�����.
									break;

							}

						}

						// ����̏����֌�����.
						break;

					// �f�o�C�X�̍폜������������.
					case DBT_DEVICEREMOVECOMPLETE:

						// DBT_DEVICEREMOVECOMPLETE�u���b�N
						{

							// �ϐ��̐錾�E������
							DEV_BROADCAST_HDR *pDBH;	// DEV_BROADCAST_HDR�|�C���^pDBH.
							TCHAR tszDBH[1024] = {0};	// TCHAR�����z��tszDBH(����1024)��{0}�ŏ�����.

							// "DBT_DEVICEREMOVECOMPLETE"�ƕ\��.
							OutputDebugString(_T("DBT_DEVICEREMOVECOMPLETE\n"));	// OutputDebugString��"DBT_DEVICEREMOVECOMPLETE"�ƕ\��.

							// lParam��pDBH��.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParam��DEV_BROADCAST_HDR�|�C���^�ɃL���X�g����, pDBH�Ɋi�[.

							// pDBH�̊e�v�f���e�L�X�g�ϊ�.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu\n"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintf��pDBH�̊e�v�f���������e�L�X�g��tszDBH�ɕϊ�.

							// tszDBH��\��.
							OutputDebugString(tszDBH);	// OutputDebugString��tszDBH��\��.

							// pDBH->dbch_devicetype���ƂɐU�蕪��.
							switch (pDBH->dbch_devicetype){

								// �{�����[���f�o�C�X
								case DBT_DEVTYP_VOLUME:

									// DBT_DEVTYP_VOLUME�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_VOLUME *pDBV;	// DEV_BROADCAST_VOLUME�|�C���^pDBV.
										TCHAR tszDBV[1024] = {0};	// TCHAR�����z��tszDBV(����1024)��{0}�ŏ�����.

										// pDBH��pDBV�ɕϊ�.
										pDBV = (DEV_BROADCAST_VOLUME *)pDBH;	// pDBH��DEV_BROADCAST_VOLUME�|�C���^�ɃL���X�g����, pDBV�Ɋi�[.

										// pDBV�̊e�v�f���e�L�X�g�ϊ�.
										_stprintf(tszDBV, _T("pDBV->dbcv_size = %lu,\n pDBV->dbcv_devicetype = %lu,\n pDBV->dbcv_reserved = %lu,\n pDBV->dbcv_unitmask = %lu,\n pDBV->dbcv_flags = %u\n"), pDBV->dbcv_size, pDBV->dbcv_devicetype, pDBV->dbcv_reserved, pDBV->dbcv_unitmask, pDBV->dbcv_flags);	// _stprintf��pDBV�̊e�v�f���������e�L�X�g��tszDBV�ɕϊ�.

										// tszDBV��\��.
										OutputDebugString(tszDBV);	// OutputDebugString��tszDBV��\��.

										// �ʒm�n���h���̉���.
										HDEVNOTIFY hUnregistered = NULL;	// hUnregistered��NULL�ŏ�����.
										for (std::map<HDEVNOTIFY, DWORD>::iterator itor = mapNotifyDriveMap.begin(); itor != mapNotifyDriveMap.end(); itor++){	// �}�b�v�̕��J��Ԃ�.
											if (itor->second == pDBV->dbcv_unitmask){	// �l�Ƀh���C�u�}�X�N��������.
												BOOL bRet = UnregisterDeviceNotification(itor->first);	// �L�[�͒ʒm�n���h���Ȃ̂�UnregisterDeviceNotification�ŉ���.
												if (bRet){
													hUnregistered = itor->first;	// �����ςݒʒm�n���h��.
													break;
												}
											}
										}
										if (hUnregistered != NULL){	// �����ςݒʒm�n���h������������.
											mapNotifyDriveMap.erase(hUnregistered);	// �L�[hUnregistered�v�f���폜. 
										}

									}

									// ����̏����֌�����.
									break;

								// �n���h��
								case DBT_DEVTYP_HANDLE:

									// DBT_DEVTYP_HANDLE�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_HANDLE *pDBHandle = (DEV_BROADCAST_HANDLE *)pDBH;	// DEV_BROADCAST_HDR�|�C���^����DEV_BROADCAST_HANDLE�|�C���^��.

										// "DBT_DEVTYP_HANDLE"��\��.
										OutputDebugString(_T("DBT_DEVTYP_HANDLE\n"));	// OutputDebugString��"DBT_DEVTYP_HANDLE"��\��.

										// �ʒm�n���h���̉���.
										BOOL bRet = UnregisterDeviceNotification(pDBHandle->dbch_hdevnotify);	// UnregisterDeviceNotification�ŉ���.
										if (bRet){
											mapNotifyDriveMap.erase(pDBHandle->dbch_hdevnotify);	// �L�[pDBHandle->dbch_hdevnotify�v�f���폜. 
										}

									}

									// ����̏����֌�����.
									break;

								// ��L�ȊO�̏���.
								default:

									// default�u���b�N
									{

									}

									// ����̏����֌�����.
									break;

							}

						}

						// ����̏����֌�����.
						break;

					// ��L�ȊO�̏���.
					default:

						// default�u���b�N
						{

							// "Other"�ƕ\��.
							OutputDebugString(_T("Other\n"));	// OutputDebugString��"Other"�ƕ\��.

						}

						// ����̏����֌�����.
						break;

				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}

// ���j�b�g�}�X�N���h���C�u���^�[�ɕϊ�.
TCHAR GetDriveLetterFromMask(unsigned long unitmask){

	// �ϐ��̐錾
	TCHAR i;	// TCHAR�^i.

	// �}�X�N���ǂ̃h���C�u���^�[�������Ă��邩�T��.
	for (i = 0; i < 26; ++i){	// �h���C�u���J��Ԃ�.
		if (unitmask & 0x1){	// �r�b�g�����Ă�����.
			break;	// ������.
		}
		unitmask = unitmask >> 1;	// 1�E�V�t�g.
	}

	// i + 'A'��Ԃ�.
	return i + 'A';

}