// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �}�N���̐錾
#define ID_BUTTON1	501	// Button1

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��hWnd.
	MSG msg;					// ���b�Z�[�Wmsg.
	WNDCLASS wc;				// �E�B���h�E�N���Xwc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DRAWITEMSTRUCT");						// �E�B���h�E�N���X��"DRAWITEMSTRUCT".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C��CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W��WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���XhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// �w�iWHITE_BRUSH.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �G���[����
		return -1;	// �ُ�I��(-1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("DRAWITEMSTRUCT"), _T("DRAWITEMSTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
	if (hWnd == NULL){

		// �G���[����
		return -2;	// �ُ�I��(-2)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W�擾.

		// �E�B���h�E���b�Z�[�W�̑��o
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W���ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// msg.wParam��Ԃ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				LPCREATESTRUCT lpCS;	// CREATESTRUCT�\���̃|�C���^lpCS.
				HWND hButton1;	// �{�^���n���h��hButton1.

				// lpCS�̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��lpCS�ɕϊ�.

				// Button1�̍쐬.(�����ɂ��Ă���.)
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_DISABLED, 50, 50, 200, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindow��"Button1"���쐬.
				if (hButton1 == NULL){
					return -1;
				}

				// �E�B���h�E�쐬����
				return 0;	// 0��Ԃ��ƃE�B���h�E�쐬�����ƂȂ�.

			}

			// ����̏����֌�����.
			break;

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT�𑗐M.

			}

			// ����̏����֌�����.
			break;

		// �I�[�i�[�h���[�ŕ`�悪�v�����ꂽ��.
		case WM_DRAWITEM:

			// WM_DRAWITEM�u���b�N
			{

				// �ϐ��̐錾
				LPDRAWITEMSTRUCT lpDIS;	// DRAWITEMSTRUCT�\���̃|�C���^lpDIS.
				HBRUSH hBrush;		// �u���V�n���h��hBrush.
				HBRUSH hOldBrush;	// �ȑO�̃u���V�n���h��hOldBrush.

				// lpDIS�̎擾.
				lpDIS = (LPDRAWITEMSTRUCT)lParam;	// lParam��lpDIS�ɕϊ�.

				// �{�^����������.
				if (lpDIS->itemState & ODS_DISABLED){	// ����.
					SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkMode�Ŕw�i����.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColor�ŕ����F�𔒂�.
						hBrush = CreateSolidBrush(RGB(0x80, 0x80, 0x80));	// CreateSolidBrush�ŊD�u���V���쐬.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObject��hBrush��I��.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangle�ŋ�`��`��.
						TextOut(lpDIS->hDC, 40, 40, _T("�����ɂȂ��Ă���"), lstrlen( _T("�����ɂȂ��Ă���")));	// TextOut��"�����ɂȂ��Ă���"��`��.
				}
				else{	// �L��.
					// ������Ă����Ԃ�.
					if (lpDIS->itemState & ODS_SELECTED){	// �r�b�g�t���OODS_SELECTED�������Ă���.
						SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkMode�Ŕw�i����.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColor�ŕ����F�𔒂�.
						hBrush = CreateSolidBrush(RGB(0xff, 0x0, 0x0));	// CreateSolidBrush�Őԃu���V���쐬.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObject��hBrush��I��.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangle�ŋ�`��`��.
						TextOut(lpDIS->hDC, 40, 40, _T("������Ă���"), lstrlen( _T("������Ă���")));	// TextOut��"������Ă���"��`��.
					}
					else{	// ������Ă��Ȃ�. 
						SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkMode�Ŕw�i����.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColor�ŕ����F�𔒂�.
						hBrush = CreateSolidBrush(RGB(0x0, 0x0, 0xff));	// CreateSolidBrush�Őu���V���쐬.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObject��hBrush��I��.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangle�ŋ�`��`��.
						TextOut(lpDIS->hDC, 40, 40, _T("������Ă��Ȃ�"), lstrlen( _T("������Ă��Ȃ�")));	// TextOut��"������Ă��Ȃ�"��`��.
					}
				}
				SelectObject(lpDIS->hDC, hOldBrush);	// SelectObject�ňȑO�̃u���V�ɖ߂�.
				DeleteObject(hBrush);	// DeleteObject��hBrush��j��.

				// TRUE��Ԃ�.
				return TRUE;

			}

			// ����̏����֌�����.
			break;

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Enable Button���I�����ꂽ��.
					case ID_ITEM_ENABLE_BUTTON:

						// ID_ITEM_ENABLE_BUTTON�u���b�N
						{

							// �`�F�b�N�ς݂������łȂ������ׂ�.
							UINT uiRet = GetMenuState(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND);	// GetMenuState��ID_ITEM_ENABLE_BUTTON���`�F�b�N����Ă邩�擾.
							if (uiRet & MF_CHECKED){	// �`�F�b�N����Ă���.
								EnableWindow(GetDlgItem(hwnd, ID_BUTTON1), FALSE);	// EnableWindow��ID_BUTTON1�𖳌���.
								// Enable Button�̃`�F�b�N���O��.
								CheckMenuItem(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND | MF_UNCHECKED);	// CheckMenuItem��ID_ITEM_ENABLE_BUTTON�̃`�F�b�N���O��.
							}
							else{	// �`�F�b�N����Ă��Ȃ�.
								EnableWindow(GetDlgItem(hwnd, ID_BUTTON1), TRUE);	// EnableWindow��ID_BUTTON1��L����.
								// Enable Button�Ƀ`�F�b�N������.
								CheckMenuItem(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND | MF_CHECKED);	// CheckMenuItem��ID_ITEM_ENABLE_BUTTON�Ƀ`�F�b�N.
							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;

				}

				// ����̏����֌�����.
				break;

			}

			// ����̏����֌�����.
			break;

		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;

	}

	// ����̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc���Ă�, �߂�l�����̂܂ܕԂ�.

}