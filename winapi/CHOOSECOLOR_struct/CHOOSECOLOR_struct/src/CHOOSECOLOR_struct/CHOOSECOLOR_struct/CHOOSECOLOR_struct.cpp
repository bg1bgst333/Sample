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
	wc.lpszClassName = _T("CHOOSECOLOR_struct");				// �E�B���h�E�N���X��"CHOOSECOLOR_struct".
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
	hWnd = CreateWindow(_T("CHOOSECOLOR_struct"), _T("CHOOSECOLOR_struct"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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
		{0, ID_COLOR_CHOOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
	};
	static int stdid;
	static HINSTANCE hInstance;
	static CHOOSECOLOR cc = {0};
	static COLORREF color = 0;
	static COLORREF customColors[16];
	static HDC hDC = NULL;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	static BITMAPINFO bi = {0};	// BITMAPINFO�\����bi.
	static RECT rc = {0};	// �N���C�A���g�̈��RECT�\����rc.
	static HBITMAP hDIBSection = NULL;	// DIB�Z�N�V�����n���h��hDIBSection.
	static LPBYTE lpBitsPixel = NULL;	// �s�N�Z����lpBitsPixel.
	static HDC hMemDC = NULL;	// �������f�o�C�X�R���e�L�X�g�n���h��hMemDC.
	static HBITMAP hOld = NULL;	// �ȑO�̃r�b�g�}�b�v�I�u�W�F�N�ghOld.
	static HPEN hPen = NULL;	// �y���I�u�W�F�N�g�n���h��hPen.
	static HPEN hOldPen = NULL;	// �Â��y��hOldPen.
	static BYTE r;	// ��
	static BYTE g;	// ��
	static BYTE b;	// ��

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��E�z��̐錾
				LPCREATESTRUCT lpCS;	// CREATESTRUCT�\���̃|�C���^lpCS.
				TBADDBITMAP tbab;		// TBADDBITMAP�\����tbab.
				int iColorChoose;

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
				SendMessage(hToolBar, TB_SETBITMAPSIZE, 0, MAKELPARAM(16, 15));
				tbab.hInst = NULL;
				tbab.nID = (int)LoadBitmap(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
				stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab);
				tbb[0].iBitmap = stdid;
				stdid++;
				iColorChoose = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Color"));
				tbb[0].iString = iColorChoose;
				SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)(LPTBBUTTON)&tbb);
				hInstance = lpCS->hInstance;
				SendMessage(hToolBar, TB_AUTOSIZE, 0, 0);	// TB_AUTOSIZE�Ńc�[���o�[�̍����������Œ���.

				// �F�I���_�C�A���O�̏�����.
				cc.lStructSize = sizeof(CHOOSECOLOR);
				cc.hwndOwner = hwnd;
				cc.rgbResult = color;
				cc.lpCustColors = customColors;
				cc.Flags = CC_FULLOPEN | CC_RGBINIT;

				// �f�o�C�X�R���e�L�X�g�̎擾.
				hDC = GetDC(hwnd);	// GetDC�Ńf�o�C�X�R���e�L�X�g�n���h��hDC���擾.

				// �r�b�g�}�b�v���̃Z�b�g.
				bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
				GetClientRect(hwnd, &rc);
				bi.bmiHeader.biWidth = rc.right;
				bi.bmiHeader.biHeight = rc.bottom;
				bi.bmiHeader.biPlanes = 1;
				bi.bmiHeader.biBitCount = 24;
				bi.bmiHeader.biCompression = BI_RGB;

				// DIB�Z�N�V�����̍쐬.
				hDIBSection = CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&lpBitsPixel, NULL, 0);

				// �������f�o�C�X�R���e�L�X�g�̍쐬.
				hMemDC = CreateCompatibleDC(hDC);

				// �r�b�g�}�b�v�I�u�W�F�N�g�̑I��.
				hOld = (HBITMAP)SelectObject(hMemDC, hDIBSection);

				// �Z�b�g����F(�ŏ��͔�).
				b = 255;
				g = 255;
				r = 255;

				// ���y�����쐬.
				hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));

				// �y���̑I��.
				hOldPen = (HPEN)SelectObject(hMemDC, hPen);

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

		// �`��v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// �`��J�n.
				PAINTSTRUCT ps = {0};
				HDC hPaintDC = BeginPaint(hwnd, &ps);

				// �`��.
				BitBlt(hPaintDC, 0, 0, bi.bmiHeader.biWidth, bi.bmiHeader.biHeight, hMemDC, 0, 0, SRCCOPY);

				// �`��I��.
				EndPaint(hwnd, &ps);

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�������鎞.
		case WM_CLOSE:	

			// WM_CLOSE�u���b�N
			{

				// �Â��y���ɖ߂�.
				if (hOldPen != NULL){
					SelectObject(hMemDC, hOldPen);
					hOldPen = NULL;
				}

				// �y���̔j��.
				if (hPen != NULL){
					DeleteObject(hPen);
					hPen = NULL;
				}

				// �Â��r�b�g�}�b�v�ɖ߂�.
				if (hOld != NULL){
					SelectObject(hMemDC, hOld);
					hOld = NULL;
				}

				// �������f�o�C�X�R���e�L�X�g�̔j��.
				if (hMemDC != NULL){
					DeleteDC(hMemDC);
					hMemDC = NULL;
				}

				// DIB�Z�N�V�����̔j��.
				if (hDIBSection != NULL){
					DeleteObject(hDIBSection);
					hDIBSection = NULL;
				}

				// �f�o�C�X�R���e�L�X�g�n���h���̉��.
				if (hDC != NULL){
					ReleaseDC(hwnd, hDC);
					hDC = NULL;
				}

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
					// ID_COLOR_CHOOSE(Choose Color)���I�����ꂽ��.
					case ID_COLOR_CHOOSE:

						// ID_COLOR_CHOOSE�u���b�N
						{

							// �F�I���_�C�A���O�\��.
							BOOL bRet = ChooseColor(&cc);	// ChooseColor�ŐF�I���_�C�A���O��\��.
							if (bRet){

								// �Â��y���ɖ߂�.
								if (hOldPen != NULL){
									SelectObject(hMemDC, hOldPen);
									hOldPen = NULL;
								}

								// �y���̔j��.
								if (hPen != NULL){
									DeleteObject(hPen);
									hPen = NULL;
								}

								// �w��̐F�ɕύX.
								COLORREF clrResult = cc.rgbResult;
								r = 0x00ffffff & clrResult;
								g = (0x00ffffff & clrResult) >> 8;
								b = (0x00ffffff & clrResult) >> 16;

								// �w��̃y�����쐬.
								hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));

								// �y���̑I��.
								hOldPen = (HPEN)SelectObject(hMemDC, hPen);

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

								// ID_COLOR_CHOOSE
								case ID_COLOR_CHOOSE:

									// IDM_ZERO�u���b�N.
									{

										// �c�[���`�b�v��"Color"���Z�b�g.
										pTTT->lpszText = _T("Color");
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

		// �}�E�X���{�^���������ꂽ��.
		case WM_LBUTTONDOWN:

			// WM_LBUTTONDOWN�u���b�N
			{

				// ���{�^����������Ă��鎞.
				if (wParam == MK_LBUTTON){
					// �}�E�X�J�[�\���̈ʒu�ɐF���Z�b�g.
					int x = LOWORD(lParam);
					int y = HIWORD(lParam);
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3] = b;
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 1] = g;
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 2] = r;
					InvalidateRect(hwnd, NULL, TRUE);
				}

			}

			// ����̏����֌�����.
			break;

		// �}�E�X���{�^���������ꂽ��.
		case WM_LBUTTONUP:

			// WM_LBUTTONUP�u���b�N
			{

				// �}�E�X�J�[�\���̈ʒu�ɐF���Z�b�g.
				int x = LOWORD(lParam);
				int y = HIWORD(lParam);
				lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3] = b;
				lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 1] = g;
				lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 2] = r;
				InvalidateRect(hwnd, NULL, TRUE);

			}

			// ����̏����֌�����.
			break;

		// �}�E�X���{�^�����ړ����̎�.
		case WM_MOUSEMOVE:

			// WM_LBUTTONUP�u���b�N
			{

				// xy���W.
				int x = LOWORD(lParam);
				int y = HIWORD(lParam);
				// ���{�^����������Ă��鎞.
				if (wParam == MK_LBUTTON){
					// �ړ����͌��݂̐F�̐�������.
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3] = b;
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 1] = g;
					lpBitsPixel[(bi.bmiHeader.biWidth * 3 + (bi.bmiHeader.biWidth * 3) % 4) * (bi.bmiHeader.biHeight - (y + 1)) + x * 3 + 2] = r;
					LineTo(hMemDC, x, y);
					MoveToEx(hMemDC, x, y, NULL);
					InvalidateRect(hwnd, NULL, TRUE);
				}
				else{	// ���{�^����������Ă��Ȃ���.
					// �n�_���ړ�.
					MoveToEx(hMemDC, x, y, NULL);
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