// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <commctrl.h>	// �R�����R���g���[��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�X

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("EM_LINEINDEX");					// �E�B���h�E�N���X����"EM_LINEINDEX".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// IDR_MAINMENU.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("EM_LINEINDEX"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("EM_LINEINDEX"), _T("EM_LINEINDEX"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"EM_LINEINDEX"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("EM_LINEINDEX"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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
	static HWND hEdit = NULL;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit��NULL�ŏ�����.
	static HFONT hFont1 = NULL;	// 1�ڂ̃t�H���g�n���h��hFont1��NULL�ŏ�����.
	static HFONT hFont2 = NULL;	// 2�ڂ̃t�H���g�n���h��hFont2��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �G�f�B�b�g�R���g���[���̍쐬.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_WANTRETURN | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 50, 200, 100, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[��"Edit1"���쐬.
				if (hEdit == NULL){	// hEdit��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �t�H���g�̍쐬.
				hFont1 = CreateFont(30, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("�l�r �S�V�b�N"));	// CreateFont��"�l�r �S�V�b�N"�t�H���g��GDI�I�u�W�F�N�g��V�K�ɍ쐬��, hFont1�Ɋi�[.(�ݒ�̓f�t�H���g�̂��̂ɂ��Ă���.)
				hFont2 = CreateFont(40, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("�l�r ����"));	// CreateFont��"�l�r ����"�t�H���g��GDI�I�u�W�F�N�g��V�K�ɍ쐬��, hFont2�Ɋi�[.(�ݒ�̓f�t�H���g�̂��̂ɂ��Ă���.)

				// Edit1��hFont1���Z�b�g.
				SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont1, 0);	// WM_SETFONT��hEdit��hFont1���Z�b�g.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// �t�H���g�̔j��.
				if (hFont1 != NULL){	// hFont1��NULL�łȂ�.
					DeleteObject(hFont1);	// DeleteObject��hFont1��j��.
					hFont1 = NULL;	// hFont1��NULL���Z�b�g.
				}
				if (hFont2 != NULL){	// hFont2��NULL�łȂ�.
					DeleteObject(hFont2);	// DeleteObject��hFont2��j��.
					hFont2 = NULL;	// hFont2��NULL���Z�b�g.
				}

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Item1-1���I�����ꂽ��.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1�u���b�N
						{

							// Edit1��hFont1���Z�b�g.
							SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont1, 0);	// WM_SETFONT��hEdit��hFont1���Z�b�g.
							
							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item1-2���I�����ꂽ��.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2�u���b�N
						{

							// Edit1��hFont2���Z�b�g.
							SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont2, 0);	// WM_SETFONT��hEdit��hFont2���Z�b�g.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item2-1���I�����ꂽ��.
					case ID_ITEM_2_1:

						// ID_ITEM_2_1�u���b�N
						{

							// �t�H���g�n���h���ƕ����̍������擾.
							HFONT hFont = (HFONT)SendMessage(hEdit, WM_GETFONT, NULL, NULL);	// WM_GETFONT��hFont���擾.
							HDC hDC = GetDC(hEdit);	// hDC�擾.
							HFONT hOld = (HFONT)SelectObject(hDC, hFont);	// hDC��hFont��I��.
							TEXTMETRIC tm = {0};	// TEXTMETRIC�\����tm��{0}�ŏ�����.
							GetTextMetrics(hDC, &tm);	// GetTextMetrics��tm���擾.
							TCHAR tszText[128] = {0};	// TCHAR�����z��tszText(����128)��{0}�ŏ�����.
							_stprintf(tszText, _T("hFont = 0x%08x, tm.tmHeight = %d\n"), hFont, tm.tmHeight);	// hFont��tm.tmHeight�𕶎���ɕϊ�.
							MessageBox(hwnd, tszText, _T("EM_LINEINDEX"), MB_OK);	// tszText��\��.
							SelectObject(hDC, hOld);	// hDC��hOld�I��.
							ReleaseDC(hEdit, hDC);	// hDC���.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item2-2���I�����ꂽ��.
					case ID_ITEM_2_2:

						// ID_ITEM_2_2�u���b�N
						{

							// �L�����b�g�̈ʒu���擾.
							POINT pt = {0};	// POINT�\����pt��{0}�ŏ�����.
							GetCaretPos(&pt);	// GetCaretPos�ňʒupt���擾.
							TCHAR tszPoint[128] = {0};	// TCHAR�����z��tszPoint(����128)��{0}�ŏ�����.
							_stprintf(tszPoint, _T("(%d, %d)"), pt.x, pt.y);	// (pt.x, pt.y)��tszPoint�ɕϊ�.
							MessageBox(hwnd, tszPoint, _T("EM_LINEINDEX"), MB_OK);	// tszPoint��\��.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Item3-1���I�����ꂽ��.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1�u���b�N
						{

							// �L�����b�g�̈ʒu�̕����Ɋւ�������擾.
							POINT pt = {0};	// POINT�\����pt��{0}�ŏ�����.
							GetCaretPos(&pt);	// GetCaretPos�ňʒupt���擾.
							DWORD dwPos = (DWORD)SendMessage(hEdit, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));	// ���Wpt����L�����b�g�̈ʒu�̕����Ɋւ�����dwPos���擾.
							WORD wRow = HIWORD(dwPos);	// HIWORD(dwPos)�͉��s�ڂ�������wRow.
							WORD wAllLen = LOWORD(dwPos);	// LOWORD(dwPos)�̓L�����b�g�܂ł̑�������wAllLen.
							TCHAR tszPos[128] = {0};	// TCHAR�����z��tszPos(����128)��{0}�ŏ�����.
							_stprintf(tszPos, _T("wRow = %d, wAllLen = %d"), wRow, wAllLen);	// wRow, wAllLen��tszPos�ɕϊ�.
							MessageBox(hwnd, tszPos, _T("EM_LINEINDEX"), MB_OK);	// tszPos��\��.

							// �w�肵���s(�����ł̓L�����b�g�̂���s���w��)�̐擪�܂ł̑����������擾.
							WORD wRowStart = (WORD)SendMessage(hEdit, EM_LINEINDEX, wRow, 0);	// �w��s�̐擪�܂ł̑�������wRowStart.
							WORD wCol = wAllLen - wRowStart;	// ���̍s�̉���ڂ�(wCol)��wAllLen����wRowStart������������.
							TCHAR tszResult[128] = {0};	// TCHAR�����z��tszResult(����128)��{0}�ŏ�����.
							_stprintf(tszResult, _T("wRowStart = %d, wCol = %d"), wRowStart, wCol);	// wRowStart, wCol��tszResult�ɕϊ�.
							MessageBox(hwnd, tszResult, _T("EM_LINEINDEX"), MB_OK);	// tszResult��\��.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:	// ��L�ȊO�̒l�̎��̊��菈��.

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

				}
	
				// ����̏����֌�����.
				break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

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