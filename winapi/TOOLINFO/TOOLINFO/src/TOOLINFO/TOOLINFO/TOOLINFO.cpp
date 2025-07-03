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
	wc.lpszClassName = _T("TOOLINFO");							// �E�B���h�E�N���X��"TOOLINFO".
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
	hWnd = CreateWindow(_T("TOOLINFO"), _T("TOOLINFO"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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
		{0, IDM_ZERO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{1, IDM_ONE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{STD_FILENEW, ID_FILE_NEW, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{VIEW_PARENTFOLDER, ID_FOLDER_PARENT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
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
				int iOne;

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
				hToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | CCS_ADJUSTABLE | TBSTYLE_TOOLTIPS, 0, 0, 1152, 80, hwnd, (HMENU)ID_TOOLBAR1, lpCS->hInstance, NULL);	// CreateWindowEx�Ńc�[���o�[�쐬.
				if (hToolBar == NULL){	// hToolBar��NULL.

					// �E�B���h�E�쐬���s.
					DestroyWindow(hStatusBar);
					return -2;	// -2��Ԃ�.

				}
				SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
				BOOL b = SendMessage(hToolBar, TB_SETBITMAPSIZE, 0, MAKELPARAM(32, 31));
				tbab.hInst = NULL;
				tbab.nID = (int)LoadBitmap(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
				stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)2, (LPARAM)&tbab);
				tbb[0].iBitmap = stdid;
				stdid++;
				tbb[1].iBitmap = stdid;
				stdid++;
				iZero = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Zero"));
				tbb[0].iString = iZero;
				iOne = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("One"));
				tbb[1].iString = iOne;
				SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)2, (LPARAM)(LPTBBUTTON)&tbb);
				hInstance = lpCS->hInstance;
				SendMessage(hToolBar, TB_AUTOSIZE, 0, 0);	// TB_AUTOSIZE�Ńc�[���o�[�̍����������Œ���.

				// �c�[���`�b�v�쐬.
				HWND hToolTip = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwnd, NULL, hInstance, NULL);
				TOOLINFO ti = {0};
#if UNICODE
				ti.cbSize = sizeof(TOOLINFOW) - sizeof(void *);	// Unicode�����Z�b�g�Ńr���h�����ꍇ, �������Ȃ���TTM_ADDTOOL�Ŏ��s����.
#else
				ti.cbSize = sizeof(TOOLINFO);
#endif
				ti.hwnd = hToolBar;
				ti.hinst = hInstance;
				ti.uFlags = TTF_SUBCLASS;
				ti.uId = tbb[0].idCommand;
				ti.lpszText = _T("Zero!!!");
				SendMessage(hToolBar, TB_GETITEMRECT, 0, (LPARAM)&ti.rect);
				BOOL b1 = SendMessage(hToolTip, TTM_ADDTOOL, 0, (LPARAM)&ti);
				SendMessage(hToolBar, TB_SETTOOLTIPS, (WPARAM)hToolTip, 0);

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

				// �c�[���o�[�̃T�C�Y���E�B���h�E�̃N���C�A���g�̈�ɍ��킹�ă��T�C�Y.
				RECT rc;
				GetClientRect(hwnd, &rc);
				SendMessage(hToolBar, WM_SIZE, rc.right, rc.bottom);

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
								{2, IDM_TWO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
								{3, IDM_THREE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
							};
							TBADDBITMAP tbab2;		// TBADDBITMAP�\����tbab2.
							SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
							tbab2.hInst = NULL;
							tbab2.nID = (int)LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
							stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)2, (LPARAM)&tbab2);
							tbb2[0].iBitmap = stdid;
							stdid++;
							tbb2[1].iBitmap = stdid;
							stdid++;
							int iTwo = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Two"));
							tbb2[0].iString = iTwo;
							int iThree = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Three"));
							tbb2[1].iString = iThree;
							SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)2, (LPARAM)(LPTBBUTTON)&tbb2);
							TBBUTTON tbb3 = {
								STD_FILEOPEN, ID_FILE_OPEN, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0
							};
							TBADDBITMAP tbab3;		// TBADDBITMAP�\����tbab3.
							tbab3.hInst =  HINST_COMMCTRL;
							tbab3.nID = IDB_STD_SMALL_COLOR;
							stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab3);
							tbb3.iBitmap = stdid + STD_FILEOPEN;	// �Ȃ�������.
							stdid++;
							int iOpen = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Open"));
							tbb3.iString = iOpen;
							SendMessage(hToolBar, TB_INSERTBUTTON, 3, (LPARAM)&tbb3);
							SendMessage(hToolBar, TB_AUTOSIZE, 0, 0);	// TB_AUTOSIZE�Ńc�[���o�[�̍����������Œ���.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^����Zero�������ꂽ��.
					case IDM_ZERO:

						// IDM_ZERO�u���b�N
						{

							// "Zero"�ƕ\��.
							MessageBox(hwnd, _T("Zero"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^����One�������ꂽ��.
					case IDM_ONE:

						// IDM_ONE�u���b�N
						{

							// "One"�ƕ\��.
							MessageBox(hwnd, _T("One"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^����Two�������ꂽ��.
					case IDM_TWO:

						// IDM_TWO�u���b�N
						{

							// "Two"�ƕ\��.
							MessageBox(hwnd, _T("Two"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^����Three�������ꂽ��.
					case IDM_THREE:

						// IDM_THREE�u���b�N
						{

							// "Three"�ƕ\��.
							MessageBox(hwnd, _T("Three"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^���̐V�K�������ꂽ��.
					case ID_FILE_NEW:

						// ID_FILE_NEW�u���b�N
						{

							// "ID_FILE_NEW"�ƕ\��.
							MessageBox(hwnd, _T("ID_FILE_NEW"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^���̐e�t�H���_�������ꂽ��.
					case ID_FOLDER_PARENT:

						// ID_FOLDER_PARENT�u���b�N
						{

							// "ID_FOLDER_PARENT"�ƕ\��.
							MessageBox(hwnd, _T("ID_FOLDER_PARENT"), _T("TOOLINFO"), MB_OK);

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// �c�[���o�[�{�^���̊J���������ꂽ��.
					case ID_FILE_OPEN:

						// ID_FILE_OPEN�u���b�N
						{

							// "ID_FILE_OPEN"�ƕ\��.
							MessageBox(hwnd, _T("ID_FILE_OPEN"), _T("TOOLINFO"), MB_OK);

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

		// �R�����R���g���[������ʒm��������.
		case WM_NOTIFY:

			// WM_NOTIFY�u���b�N
			{

				// NMHDR�|�C���^�ւ̕ϊ�.
				NMHDR *pNMHDR = (NMHDR *)lParam;

				// pNMHDR->code�ŐU�蕪��.
				switch (pNMHDR->code){

					// �c�[���`�b�v�e�L�X�g��v�����ꂽ��.
					case TTN_NEEDTEXT:

						// TTN_NEEDTEXT�u���b�N.
						{

							// TOOLTIPTEXT�|�C���^�ւ̕ϊ�.
							TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)lParam;
							pTTT->hinst = hInstance;

							// lpTTT->hdr.idFrom�ŐU�蕪��.
							switch (pTTT->hdr.idFrom){

								// IDM_ZERO
								case IDM_ZERO:

									// IDM_ZERO�u���b�N.
									{

										// �c�[���`�b�v��"Zero"���Z�b�g.
										//pTTT->lpszText = _T("Zero");
										break;

									}

								// ����ȊO.
								default:

									break;

							}

							break;

						}

					// ����ȊO.
					default:

						break;

				}

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