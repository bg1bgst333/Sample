// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <dbt.h>		// �f�o�C�X�Ǘ�
#include <initguid.h>	// GUID
#include <usbiodef.h>	// USB

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�Ə�����.
	HWND hWnd;							// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;							// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;						// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DEV_BROADCAST_DEVICEINTERFACE");	// �E�B���h�E�N���X����"DEV_BROADCAST_DEVICEINTERFACE".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("DEV_BROADCAST_DEVICEINTERFACE"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("DEV_BROADCAST_DEVICEINTERFACE"), _T("DEV_BROADCAST_DEVICEINTERFACE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"DEV_BROADCAST_DEVICEINTERFACE"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("DEV_BROADCAST_DEVICEINTERFACE"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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

	// �X�^�e�B�b�N�ϐ��̐錾.
	static HDEVNOTIFY hDevNotify;	// �ʒm�n���h��hDevNotify.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ʒm�t�B���^�̏���.
				DEV_BROADCAST_DEVICEINTERFACE dbd = {0};	// DEV_BROADCAST_DEVICEINTERFACE�\����dbd��{0}�ŏ�����.
				dbd.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);	// �T�C�Y��sizeof(DEV_BROADCAST_DEVICEINTERFACE).
				dbd.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;	// �^�C�v��DBT_DEVTYP_DEVICEINTERFACE.
				dbd.dbcc_classguid = GUID_DEVINTERFACE_USB_DEVICE;	// �N���X��GUID_DEVINTERFACE_USB_DEVICE.
				// �f�o�C�X�ʒm�o�^.
				hDevNotify = RegisterDeviceNotification(hwnd, &dbd, DEVICE_NOTIFY_WINDOW_HANDLE);	// RegisterDeviceNotification��dbd��o�^��, hDevNotify�𓾂�.
				TCHAR tszHDevNotify[32] = {0};	// TCHAR�����z��tszHDevNotify(����32)��{0}�ŏ�����.
				_stprintf(tszHDevNotify, _T("hDevNotify = 0x%08x\n"), (unsigned long)hDevNotify);	// _stprintf��hDevNotify��tszHDevNotify�ɕϊ�.
				OutputDebugString(tszHDevNotify);	// OutputDebugString��tszHDevNotify��\��.

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

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �f�o�C�X�ʒm����.
				BOOL bRet = UnregisterDeviceNotification(hDevNotify);	// UnregisterDeviceNotification��hDevNotify������.

			}

			// ������.
			break;	// break�Ŕ�����.

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

									}

									// ����̏����֌�����.
									break;

								// �f�o�C�X�C���^�[�t�F�[�X
								case DBT_DEVTYP_DEVICEINTERFACE:

									// DBT_DEVTYP_DEVICEINTERFACE�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_DEVICEINTERFACE *pDBD;	// DEV_BROADCAST_DEVICEINTERFACE�|�C���^pDBD.
										TCHAR tszDBD[1024] = {0};	// TCHAR�����z��tszDBD(����1024)��{0}�ŏ�����.

										// pDBH��pDBD�ɕϊ�.
										pDBD = (DEV_BROADCAST_DEVICEINTERFACE *)pDBH;	// pDBH��DEV_BROADCAST_DEVICEINTERFACE�|�C���^�ɃL���X�g����, pDBD�Ɋi�[.

										// pDBD�̊e�v�f���e�L�X�g�ϊ�.
										WCHAR wszGuidStr[256] = {0};	// GUID��������i�[����WCHAR�����z��wszGuidStr(����256)��{0}�ŏ�����.
										StringFromGUID2(pDBD->dbcc_classguid, wszGuidStr, 256);	// StringFromGUID2��pDBD->dbcc_classguid��wszGuidStr�ɕϊ�.
										_stprintf(tszDBD, _T("pDBD->dbcc_size = %lu,\n pDBD->dbcc_devicetype = %lu,\n pDBD->dbcc_reserved = %lu,\n pDBD->dbcc_classguid = %s,\n pDBD->dbcc_name = %s\n"), pDBD->dbcc_size, pDBD->dbcc_devicetype, pDBD->dbcc_reserved, wszGuidStr, pDBD->dbcc_name);	// _stprintf��pDBD�̊e�v�f���������e�L�X�g��tszDBD�ɕϊ�.

										// tszDBD��\��.
										OutputDebugString(tszDBD);	// OutputDebugString��tszDBD��\��.

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
							TCHAR tszDBH[1024] = { 0 };	// TCHAR�����z��tszDBH(����1024)��{0}�ŏ�����.

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

									}

									// ����̏����֌�����.
									break;

								// �f�o�C�X�C���^�[�t�F�[�X
								case DBT_DEVTYP_DEVICEINTERFACE:

									// DBT_DEVTYP_DEVICEINTERFACE�u���b�N
									{

										// �ϐ��̐錾�E������
										DEV_BROADCAST_DEVICEINTERFACE *pDBD;	// DEV_BROADCAST_DEVICEINTERFACE�|�C���^pDBD.
										TCHAR tszDBD[1024] = {0};	// TCHAR�����z��tszDBD(����1024)��{0}�ŏ�����.

										// pDBH��pDBD�ɕϊ�.
										pDBD = (DEV_BROADCAST_DEVICEINTERFACE *)pDBH;	// pDBH��DEV_BROADCAST_DEVICEINTERFACE�|�C���^�ɃL���X�g����, pDBD�Ɋi�[.

										// pDBD�̊e�v�f���e�L�X�g�ϊ�.
										WCHAR wszGuidStr[256] = {0};	// GUID��������i�[����WCHAR�����z��wszGuidStr(����256)��{0}�ŏ�����.
										StringFromGUID2(pDBD->dbcc_classguid, wszGuidStr, 256);	// StringFromGUID2��pDBD->dbcc_classguid��wszGuidStr�ɕϊ�.
										_stprintf(tszDBD, _T("pDBD->dbcc_size = %lu,\n pDBD->dbcc_devicetype = %lu,\n pDBD->dbcc_reserved = %lu,\n pDBD->dbcc_classguid = %s,\n pDBD->dbcc_name = %s\n"), pDBD->dbcc_size, pDBD->dbcc_devicetype, pDBD->dbcc_reserved, wszGuidStr, pDBD->dbcc_name);	// _stprintf��pDBD�̊e�v�f���������e�L�X�g��tszDBD�ɕϊ�.

										// tszDBD��\��.
										OutputDebugString(tszDBD);	// OutputDebugString��tszDBD��\��.

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