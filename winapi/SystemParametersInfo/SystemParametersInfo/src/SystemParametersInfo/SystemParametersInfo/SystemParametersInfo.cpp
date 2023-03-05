// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("SystemParametersInfo");			// �E�B���h�E�N���X����"SystemParametersInfo".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("SystemParametersInfo"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("SystemParametersInfo"), _T("SystemParametersInfo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"SystemParametersInfo"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("SystemParametersInfo"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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

	// �X�^�e�B�b�N�ϐ��̏�����.
	static SHFILEINFO sfi = {0};	// �t�@�C����������SHFILEINFO�^�ϐ�sfi��{0}�ŏ�����.
	static RECT rc = {0};	// �f�X�N�g�b�v�̈�̃T�C�Yrc��{0}�ŏ�����.

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

		// ��ʂ̕`���v�����ꂽ��.
		case WM_PAINT:		// ��ʂ̕`���v�����ꂽ��.(uMsg��WM_PAINT�̎�.)

			// WM_PAINT�u���b�N
			{

				// �`��J�n.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT�^ps��{0}�ŏ�����.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaint��hDC�擾.

				// �\�����Ǝ�ނƃA�C�R���n���h����`��.
				TextOut(hDC, 50, 50, sfi.szDisplayName, lstrlen(sfi.szDisplayName));	// TextOut��sfi.szDisplayName��`��.
				TextOut(hDC, 50, 100, sfi.szTypeName, lstrlen(sfi.szTypeName));	// TextOut��sfi.szTypeName��`��.
				TCHAR tszHIcon[64] = {0};	// sfi.hIcon�𕶎���ɂ������̂��i�[����TCHAR�^�z��tszHIcon(����64)��{0}�ŏ�����.
				_stprintf(tszHIcon, _T("sfi.hIcon = 0x%08x"), (unsigned int)sfi.hIcon);	// sfi.hIcon�𕶎���ɕϊ���, tszHIcon�Ɋi�[.
				TextOut(hDC, 50, 150, tszHIcon, lstrlen(tszHIcon));	// TextOut��tszHIcon��`��.

				// �f�X�N�g�b�v�̈�̃T�C�Y��`��.
				TCHAR tszLeft[64] = {0};	// rc.left�𕶎���ɂ������̂��i�[����TCHAR�^�z��tszLeft(����64)��{0}�ŏ�����.
				_stprintf(tszLeft, _T("rc.left = %d"), rc.left);	// rc.left�𕶎���ɕϊ���, tszLeft�Ɋi�[.
				TextOut(hDC, 250, 50, tszLeft, lstrlen(tszLeft));	// TextOut��tszLeft��`��.
				TCHAR tszTop[64] = {0};	// rc.top�𕶎���ɂ������̂��i�[����TCHAR�^�z��tszTop(����64)��{0}�ŏ�����.
				_stprintf(tszTop, _T("rc.top = %d"), rc.top);	// rc.top�𕶎���ɕϊ���, tszTop�Ɋi�[.
				TextOut(hDC, 250, 100, tszTop, lstrlen(tszTop));	// TextOut��tszTop��`��.
				TCHAR tszRight[64] = {0};	// rc.right�𕶎���ɂ������̂��i�[����TCHAR�^�z��tszRight(����64)��{0}�ŏ�����.
				_stprintf(tszRight, _T("rc.right = %d"), rc.right);	// rc.right�𕶎���ɕϊ���, tszRight�Ɋi�[.
				TextOut(hDC, 250, 150, tszRight, lstrlen(tszRight));	// TextOut��tszRight��`��.
				TCHAR tszBottom[64] = {0};	// rc.bottom�𕶎���ɂ������̂��i�[����TCHAR�^�z��tszBottom(����64)��{0}�ŏ�����.
				_stprintf(tszBottom, _T("rc.bottom = %d"), rc.bottom);	// rc.bottom�𕶎���ɕϊ���, tszBottom�Ɋi�[.
				TextOut(hDC, 250, 200, tszBottom, lstrlen(tszBottom));	// TextOut��tszBottom��`��.

				// �`��I��.
				EndPaint(hwnd, &ps);	// EndPaint�ŕ`��I��.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// sfi.hIcon�̔j��.
				if (sfi.hIcon != NULL){	// sfi.hIcon��NULL�łȂ����.
					DestroyIcon(sfi.hIcon);	// DestroyIcon��sfi.hIcon��j��.
					sfi.hIcon = NULL;	// sfi.hIcon��NULL���Z�b�g.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Open���I�����ꂽ��.
					case ID_FILE_OPEN:

						// ID_FILE_OPEN�u���b�N
						{

							// �ϐ��̐錾�E������.
							OPENFILENAME ofn = {0};	// OPENFILENAME�\���̕ϐ�ofn��{0}�ŏ�����.
							TCHAR tszFilePath[MAX_PATH] = {0};	// �t�@�C���p�XtszFilePath(����MAX_PATH)��0�ŏ�����.

							// ofn�ɒl���Z�b�g.
							ofn.lStructSize = sizeof(OPENFILENAME);	// �\���̂̃T�C�Y.
							ofn.lpstrFile = tszFilePath;	// �t�@�C���p�X.
							ofn.nMaxFile = MAX_PATH;	// �t�@�C���p�X�̍ő咷.

							// �t�@�C���I��.
							if (!GetOpenFileName(&ofn)){	// GetOpenFileName�Ńt�@�C����I��.

								// �I�����Ȃ������ꍇ.(�L�����Z��)
								return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

							}

							// �t�@�C�������������擾.
							TCHAR tszFileTitle[64] = {0};	// �t�@�C��������tszFileTitle(����64)��{0}�ŏ�����.
							GetFileTitle(tszFilePath, tszFileTitle, 64);	// GetFileTitle��tszFileTitle���擾.

							// �E�B���h�E�^�C�g����tszFileTitle���Z�b�g.
							SetWindowText(hwnd, tszFileTitle);	// SetWindowText��tszFileTitle���Z�b�g.

							// �t�@�C�������擾.
							SHGetFileInfo(tszFilePath, 0, &sfi, sizeof(SHFILEINFO), SHGFI_DISPLAYNAME | SHGFI_TYPENAME | SHGFI_ICON);	// SHGetFileInfo�ŕ\�����Ǝ�ނƃA�C�R�����擾.

							// ��ʍX�V.
							InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRect�őS�̂𖳌��̈�Ƃ���.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Info���I�����ꂽ��.
					case ID_SYSTEM_INFO:

						// ID_SYSTEM_INFO�u���b�N
						{

							// �V�X�e�����(�f�X�N�g�b�v�̈�̃T�C�Y)���擾.
							SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);	// SystemParametersInfo�Ńf�X�N�g�b�v�̈�̃T�C�Yrc���擾.

							// ��ʍX�V.
							InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRect�őS�̂𖳌��̈�Ƃ���.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:
						
						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

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