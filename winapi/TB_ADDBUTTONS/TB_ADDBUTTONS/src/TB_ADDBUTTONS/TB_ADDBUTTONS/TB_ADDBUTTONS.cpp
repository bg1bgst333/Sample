// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��hWnd.
	MSG msg;					// ���b�Z�[�Wmsg.
	WNDCLASS wc;				// �E�B���h�E�N���Xwc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("TB_ADDBUTTONS");					// �E�B���h�E�N���X��"TB_ADDBUTTONS".
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
	hWnd = CreateWindow(_T("TB_ADDBUTTONS"), _T("TB_ADDBUTTONS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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
	static HWND hStatusBar;	// �X�e�[�^�X�o�[�n���h��hStatusBar.
	static HWND hToolBar;	// �c�[���o�[�n���h��hToolBar.
	TBBUTTON tbb[] = {
		{0, IDM_ZERO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
	};
	static int stdid;
	static HINSTANCE hInstance;

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��E�z��̐錾
				LPCREATESTRUCT lpCS;	// CREATESTRUCT�\���̃|�C���^lpCS.
				TBADDBITMAP tbab;		// TBADDBITMAP�\����tbab.
				int iZero;

				// lpCS�̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��lpCS�ɕϊ�.

				// �R�����R���g���[���̏�����.
				InitCommonControls();	// InitCommonControls�ŃR�����R���g���[���̏�����.

				// �X�e�[�^�X�o�[�̍쐬.
				hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE, _T("ABCDE"), hwnd, ID_STATUS);	// CreateStatusWindow�ŃX�e�[�^�X�o�[�쐬.
				if (hStatusBar == NULL){	// hStatusBar��NULL.
						
					// �E�B���h�E�쐬���s
					return -1;	// -1��Ԃ�.

				}

				// �c�[���o�[�̍쐬.
				hToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | CCS_ADJUSTABLE | CCS_NORESIZE, 0, 0, 1152, 40, hwnd, (HMENU)ID_TOOLBAR1, lpCS->hInstance, NULL);	// CreateWindowEx�Ńc�[���o�[�쐬.
				if (hToolBar == NULL){	// hToolBar��NULL.

					// �E�B���h�E�쐬���s.
					DestroyWindow(hStatusBar);
					return -2;	// -2��Ԃ�.

				}
				SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
				tbab.hInst = NULL;
				tbab.nID = (int)LoadBitmap(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
				stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab);
				tbb[0].iBitmap = stdid;
				iZero = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Zero"));
				tbb[0].iString = iZero;
				SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)(LPTBBUTTON)&tbb);
				hInstance = lpCS->hInstance;

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

		// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		case WM_SIZE:	// �E�B���h�E�̃T�C�Y����	�X���ꂽ��.(uMsg��WM_SIZE�̎�.)

			// WM_SIZE�u���b�N
			{

				// �X�e�[�^�X�o�[�̃T�C�Y��n��.
				SendMessage(hStatusBar, WM_SIZE, wParam, lParam);

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
					// Set Text���I�����ꂽ��.
					case ID_ITEM_SETTEXT:

						// ID_ITEM_SETTEXT�u���b�N
						{

							// �X�e�[�^�X�o�[�Ƀe�L�X�g���Z�b�g.
							SendMessage(hStatusBar, SB_SETTEXT, (WPARAM)255 | 0, (LPARAM)_T("����������"));	// SB_SETTEXT��hStatusBar��0�Ԗڂ�"����������"���Z�b�g.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// Add Buttons���I�����ꂽ��.
					case ID_ITEM_ADDBUTTONS:

						// ID_ITEM_ADDBUTTONS�u���b�N
						{

							// �{�^���̒ǉ�.
							TBBUTTON tbb2[] = {
								{1, IDM_ONE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
							};
							TBADDBITMAP tbab2;		// TBADDBITMAP�\����tbab2.
							SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
							tbab2.hInst = NULL;
							tbab2.nID = (int)LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
							stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab2);
							tbb2[0].iBitmap = stdid;
               				int iOne = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("One"));
							tbb2[0].iString = iOne;
							SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)(LPTBBUTTON)&tbb2);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^����Zero�������ꂽ��.
					case IDM_ZERO:

						// IDM_ZERO�u���b�N
						{

							// "Zero"�ƕ\��.
							MessageBox(hwnd, _T("Zero"), _T("TB_ADDBUTTONS"), MB_OK);

						}

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