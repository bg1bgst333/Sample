// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <dbt.h>		// �f�o�C�X�Ǘ�

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�Ə�����.
	HWND hWnd;							// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;							// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;						// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DEV_BROADCAST_VOLUME");			// �E�B���h�E�N���X����"DEV_BROADCAST_VOLUME".
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
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("DEV_BROADCAST_VOLUME"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("DEV_BROADCAST_VOLUME"), _T("DEV_BROADCAST_VOLUME"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"DEV_BROADCAST_VOLUME"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("DEV_BROADCAST_VOLUME"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W����
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

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
				switch (wParam) {	// wParam���ƂɐU�蕪��.

					// �f�o�C�X�m�[�h���ύX���ꂽ��.
					case DBT_DEVNODES_CHANGED:

						// DBT_DEVNODES_CHANGED�u���b�N
						{

							// "DBT_DEVNODES_CHANGED"�ƕ\��.
							MessageBox(hwnd, _T("DBT_DEVNODES_CHANGED"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBox��"DBT_DEVNODES_CHANGED"�ƕ\��.

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
							MessageBox(hwnd, _T("DBT_DEVICEARRIVAL"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBox��"DBT_DEVICEARRIVAL"�ƕ\��.

							// lParam��pDBH��.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParam��DEV_BROADCAST_HDR�|�C���^�ɃL���X�g����, pDBH�Ɋi�[.

							// pDBH�̊e�v�f���e�L�X�g�ϊ�.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintf��pDBH�̊e�v�f���������e�L�X�g��tszDBH�ɕϊ�.

							// tszDBH��\��.
							MessageBox(hwnd, tszDBH, _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBox��tszDBH��\��.

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
										_stprintf(tszDBV, _T("pDBV->dbcv_size = %lu,\n pDBV->dbcv_devicetype = %lu,\n pDBV->dbcv_reserved = %lu,\n pDBV->dbcv_unitmask = %lu,\n pDBV->dbcv_flags = %u"), pDBV->dbcv_size, pDBV->dbcv_devicetype, pDBV->dbcv_reserved, pDBV->dbcv_unitmask, pDBV->dbcv_flags);	// _stprintf��pDBV�̊e�v�f���������e�L�X�g��tszDBV�ɕϊ�.

										// tszDBV��\��.
										MessageBox(hwnd, tszDBV, _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBox��tszDBV��\��.

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

							// "DBT_DEVICEREMOVECOMPLETE"�ƕ\��.
							MessageBox(hwnd, _T("DBT_DEVICEREMOVECOMPLETE"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBox��"DBT_DEVICEREMOVECOMPLETE"�ƕ\��.

						}

						// ����̏����֌�����.
						break;

					// ��L�ȊO�̏���.
					default:

						// default�u���b�N
						{

							// "Other"�ƕ\��.
							MessageBox(hwnd, _T("Other"), _T("Other"), MB_OK);	// MessageBox��"Other"�ƕ\��.

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