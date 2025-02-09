// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�A���O�v���V�[�W��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��hWnd.
	MSG msg;					// ���b�Z�[�Wmsg.
	WNDCLASS wc;				// �E�B���h�E�N���Xwc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("BM_SETIMAGE");						// �E�B���h�E�N���X��"BM_SETIMAGE".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C��CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W��WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���XhInstance.
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	// �A�C�R��IDI_ICON1.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// �w�iWHITE_BRUSH.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// ���j���[��IDR_MAINMENU.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �G���[����
		return -1;	// �ُ�I��(-1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("BM_SETIMAGE"), _T("BM_SETIMAGE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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

	// static�ϐ��̐錾.
	static HBITMAP hBitmap1 = NULL;	// �r�b�g�}�b�v�n���h��hBitmap1.(�r�b�g�}�b�v�j���K�v.)

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				LPCREATESTRUCT lpCS;	// CREATESTRUCT�\���̃|�C���^lpCS.
				HWND hButton1;	// �{�^���n���h��hButton1.
				HWND hButton2;	// �{�^���n���h��hButton2.
				HICON hIcon1;	// �A�C�R���n���h��hIcon1.(�A�C�R���͔j���s�v.)

				// lpCS�̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��lpCS�ɕϊ�.

				// Button1�̍쐬.
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_ICON, 50, 50, 100, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindow��"Button1"���쐬.
				if (hButton1 == NULL){
					return -1;
				}

				// Button2�̍쐬.
				hButton2 = CreateWindow(WC_BUTTON, _T("Button2"), WS_CHILD | WS_VISIBLE | BS_BITMAP, 250, 50, 200, 100, hwnd, (HMENU)ID_BUTTON2, lpCS->hInstance, NULL);	// CreateWindow��"Button2"���쐬.
				if (hButton2 == NULL){
					return -2;
				}

				// �A�C�R���̃��[�h.
				hIcon1 = LoadIcon(lpCS->hInstance, MAKEINTRESOURCE(IDI_ICON1));	// LoadIcon��IDI_ICON1�����[�h.

				// �r�b�g�}�b�v�̃��[�h.
				hBitmap1 = (HBITMAP)LoadImage(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImage��IDB_BITMAP1�����[�h.

				// Button1�ɃA�C�R�����Z�b�g.
				SendMessage(hButton1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon1);	// BM_SETIMAGE��hIcon1���Z�b�g.

				// Button2�Ƀr�b�g�}�b�v���Z�b�g.
				SendMessage(hButton2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap1);	// BM_SETIMAGE��hBitmap1���Z�b�g.

				// �E�B���h�E�쐬����
				return 0;	// 0��Ԃ��ƃE�B���h�E�쐬�����ƂȂ�.

			}

			// ����̏����֌�����.
			break;

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �r�b�g�}�b�v�̔j��.
				if (hBitmap1 != NULL){
					DeleteObject(hBitmap1);
					hBitmap1 = NULL;
				}

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT�𑗐M.

			}

			// ����̏����֌�����.
			break;

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// �ǂꂪ�I�����ꂽ������.
				switch (LOWORD(wParam)){

					// Dialog���I�����ꂽ��.
					case ID_ITEM_DIALOG:

						// ID_ITEM_DIALOG�u���b�N
						{

							// �ϐ��̐錾
							HINSTANCE hInstance;	// �C���X�^���X�n���h��hInstance.

							// hInstance���擾.
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLong��hInstance�擾.

							// �_�C�A���O�{�b�N�X�̕\��
							DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), hwnd, DialogProc);	// DialogBox��IDD_DIALOG��\��.

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;

				}

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

// DialogProc�֐��̒�`
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// static�ϐ��̐錾.
	static HBITMAP hBitmap2 = NULL;	// �r�b�g�}�b�v�n���h��hBitmap2.(�r�b�g�}�b�v�j���K�v.)

	// �_�C�A���O���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �_�C�A���O�̏�������.
		case WM_INITDIALOG:

			// WM_INITDIALOG�u���b�N
			{

				// �ϐ��̐錾
				HINSTANCE hInstance;	// �C���X�^���X�n���h��hInstance.
				HICON hIcon2;	// �A�C�R���n���h��hIcon2.(�A�C�R���͔j���s�v.)
				HWND hButton3;	// �{�^���n���h��hButton3.
				HWND hButton4;	// �{�^���n���h��hButton4.

				// hInstance���擾.
				hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);	// GetWindowLong��hInstance�擾.

				// �A�C�R���̃��[�h.
				hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));	// LoadIcon��IDI_ICON2�����[�h.

				// �r�b�g�}�b�v�̃��[�h.
				hBitmap2 = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImage��IDB_BITMAP2�����[�h.

				// Button3�ɃA�C�R�����Z�b�g.
				hButton3 = GetDlgItem(hwndDlg, ID_BUTTON3);	// GetDlgItem��hButton3�擾.
				SendMessage(hButton3, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon2);	// BM_SETIMAGE��hIcon2���Z�b�g.

				// Button4�Ƀr�b�g�}�b�v���Z�b�g.
				hButton4 = GetDlgItem(hwndDlg, ID_BUTTON4);	// GetDlgItem��hButton4�擾.
				SendMessage(hButton4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);	// BM_SETIMAGE��hBitmap2���Z�b�g.


				// �����ł����̂�TRUE��Ԃ�.
				return TRUE;

			}

			// break�Ŕ�����.
			break;

		// �_�C�A���O������ꂽ��.
		case WM_CLOSE:

			// WM_CLOSE�u���b�N
			{

				// �r�b�g�}�b�v�̔j��.
				if (hBitmap2 != NULL){
					DeleteObject(hBitmap2);
					hBitmap2 = NULL;
				}

				// �_�C�A���O���I������.
				EndDialog(hwndDlg, IDOK);	// EndDialog�Ń_�C�A���O���I������.

				// �����ł����̂�TRUE��Ԃ�.
				return TRUE;

			}

			// break�Ŕ�����.
			break;

		// ��L�ȊO�̏���.
		default:

			// break�Ŕ�����.
			break;

	}

	// �����ł��ĂȂ��̂�FALSE��Ԃ�.
	return FALSE;

}