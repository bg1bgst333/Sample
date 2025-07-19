// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �O���[�o���ϐ�.
HWND g_hFindDlg = NULL;	// �����_�C�A���O�n���h��g_hFindDlg��NULL�ŏ�����.
TCHAR g_tszFindWhat[80] = {0};	// ����������g_tszFindWhat��{0}�ŏ�����.
FINDREPLACE g_fr = {0};	// FINDREPLACE�\���̕ϐ�g_fr��{0}�ŏ�����.
int iSearchStart = 0;	// �����J�n�ʒuiSearchStart��0�ŏ�����.

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��
void DoFindText(HWND hwnd);	// FindText�����s����֐�DoFindText
void FindNext(HWND hwnd, HWND hEdit);	// ���̈�v�������T���֐�FindNext

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��hWnd.
	MSG msg;					// ���b�Z�[�Wmsg.
	WNDCLASS wc;				// �E�B���h�E�N���Xwc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("EM_SCROLLCARET");					// �E�B���h�E�N���X��"EM_SCROLLCARET".
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
	hWnd = CreateWindow(_T("EM_SCROLLCARET"), _T("EM_SCROLLCARET"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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

	// �X�^�e�B�b�N�ϐ��̐錾
	static CHOOSEFONT cf = {0};	// CHOOSEFONT�\����cf��{0}�ŏ�����.
	static LOGFONT lf = {0};	// LOGFONT�\����lf��{0}�ŏ�����.
	static UINT uMessage;	// RegisterWindowMessage�̖߂�luMessage.
	static TCHAR tszReplace[80] = {0};	// �u�����镶����tszReplace(����80)��{0}�ŏ�����.
	static HWND hEdit = NULL;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit��NULL�ŏ�����.

	// �o�^�ς݃��b�Z�[�W�������ꍇ.
	if (uMsg == uMessage){
		LPFINDREPLACE lpFR = (LPFINDREPLACE)lParam;
		if (lpFR->Flags & FR_FINDNEXT){	// ���������������ꂽ��.
			FindNext(hwnd, hEdit);
		}
		if (lpFR->Flags & FR_DIALOGTERM){	// �_�C�A���O�����ꂽ��.
			g_hFindDlg = NULL;
		}
		return 0;	// 0��Ԃ�.
	}

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// CHOOSEFONT�̏�����.
				cf.lStructSize = sizeof(CHOOSEFONT);
				cf.hwndOwner = hwnd;
				cf.lpLogFont = &lf;
				cf.Flags = CF_EFFECTS | CF_SCREENFONTS;

				// FINDREPLACE�̏�����.
				uMessage = RegisterWindowMessage(FINDMSGSTRING);	// RegisterWindowMessage��FINDMSGSTRING��o�^.

				// �G�f�B�b�g�R���g���[���̕\��.
				LPCREATESTRUCT lpCS = (LPCREATESTRUCT)lParam;
				hEdit = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL | WS_HSCROLL | WS_VSCROLL, 0, 0, 200, 200, hwnd, (HMENU)IDC_EDIT1, lpCS->hInstance, NULL);
				if (hEdit == NULL){	// ���s
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

		// �E�B���h�E�T�C�Y���ύX���ꂽ��.
		case WM_SIZE:

			// WM_SIZE�u���b�N
			{

				// �G�f�B�b�g�{�b�N�X�̃T�C�Y�����E�B���h�E��t�ɂ���.
				int iWidth = LOWORD(lParam);
				int iHeight = HIWORD(lParam);
				MoveWindow(hEdit, 0, 0, iWidth, iHeight, TRUE);

			}

			// ����̏����֌�����.
			break;

		// �`��v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// �`��J�n.
				PAINTSTRUCT ps = {0};
				HDC hPaintDC = BeginPaint(hwnd, &ps);
				HFONT hFont = CreateFontIndirect(&lf);	// CreateFontIndirect��lf����t�H���g�����.
				HFONT hOld = (HFONT)SelectObject(hPaintDC, hFont);
				SetTextColor(hPaintDC, cf.rgbColors);

				// �`��I��.
				SelectObject(hPaintDC, hOld);
				DeleteObject(hFont);
				EndPaint(hwnd, &ps);

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
					// ID_FONT_CHOOSE(Choose Font)���I�����ꂽ��.
					case ID_FONT_CHOOSE:

						// ID_FONT_CHOOSE�u���b�N
						{

							// �t�H���g�I���_�C�A���O�̕\��.
							BOOL bRet = ChooseFont(&cf);	// ChooseFont�Ńt�H���g�I���_�C�A���O�̕\��.
							if (bRet){
								InvalidateRect(hwnd, NULL, TRUE);
							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ID_SEACH_DIALOG(Search Dialog)���I�����ꂽ��.
					case ID_SEACH_DIALOG:

						// ID_SEACH_DIALOG�u���b�N
						{

							// �����_�C�A���O�̕\��.
							DoFindText(hwnd);

						}

						// ����̏����֌�����.
						break;

					// ID_REPLACE_DIALOG(Replace Dialog)���I�����ꂽ��.
					case ID_REPLACE_DIALOG:

						// ID_REPLACE_DIALOG�u���b�N
						{

						}

						// ����̏����֌�����.
						break;

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

// FindText�����s����֐�DoFindText
void DoFindText(HWND hwnd){

	// �����_�C�A���O�����邩.
	if (g_hFindDlg == NULL){	// �Ȃ�.
		ZeroMemory(&g_fr, sizeof(FINDREPLACE));
		g_fr.lStructSize = sizeof(FINDREPLACE);
		g_fr.hwndOwner = hwnd;
		g_fr.lpstrFindWhat = g_tszFindWhat;
		g_fr.wFindWhatLen = 80;
		g_fr.Flags = FR_DOWN;
		g_hFindDlg = FindText(&g_fr);
	}
	else{
		SetFocus(g_hFindDlg);
	}

}

// ���̈�v�������T���֐�FindNext
void FindNext(HWND hwnd, HWND hEdit){

	// �e�L�X�g���擾.
	int iLen = GetWindowTextLength(hEdit);
	TCHAR *tszBuf = new TCHAR[iLen + 1];
	ZeroMemory(tszBuf, (iLen + 1) * sizeof(TCHAR));
	GetWindowText(hEdit, tszBuf, iLen + 1);

	// �����������T��.
	TCHAR * ptszStr = g_fr.lpstrFindWhat;
	TCHAR * ptszPos = _tcsstr(tszBuf + iSearchStart, ptszStr);

	// ����������.
	if (ptszPos != NULL){
		int iFoundPos = (int)(ptszPos - tszBuf);
		int iFoundLen = lstrlen(ptszStr);
		SetFocus(hEdit);
		SendMessage(hEdit, EM_SETSEL, iFoundPos, iFoundPos + iFoundLen);
		SendMessage(hEdit, EM_SCROLLCARET, 0, 0);
		iSearchStart = iFoundPos + iFoundLen;
	}
	else{	// ������Ȃ�������.
		MessageBox(hwnd, _T("�݂���܂���"), _T("EM_SCROLLCARET"), MB_OK);
		iSearchStart = 0;
	}
	delete [] tszBuf;

}