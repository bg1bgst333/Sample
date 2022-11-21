// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("BITMAP_struct");					// �E�B���h�E�N���X����"BITMAP_struct".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("BITMAP_struct"), _T("BITMAP_struct"), WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 0, 0, 480, 360, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"BITMAP_struct"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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
	static HBITMAP hBitmap = NULL;	// �r�b�g�}�b�v�n���h��hBitmap��NULL�ŏ�����.
	static HDC hDC = NULL;	// �f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ŏ�����.
	static HDC hMemDC = NULL;	// �������f�o�C�X�R���e�L�X�g�n���h��hMemDC��NULL�ŏ�����.
	static HBITMAP hOld = NULL;	// �ȑO�̃r�b�g�}�b�v�n���h��hOld��NULL�ŏ�����.
	static int dx = 0;	// ���������̕ω���dx.(����-, �E��+.)
	static int dy = 0;	// ���������̕ω���dy.(�オ-, ����+.)
	static BITMAP bitmap = {0};	// BITMAP�\���̃I�u�W�F�N�gbitmap��{0}�ŏ�����.

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

				// �r�b�g�}�b�v�̃��[�h
				hBitmap = (HBITMAP)LoadImage(lpCS->hInstance, _T("bitmap1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"bitmap1.bmp"�����[�h��, �߂�l�̃r�b�g�}�b�v�n���h����hBitmap�Ɋi�[����.
				if (hBitmap == NULL){	// hBitmap��NULL�Ȃ烍�[�h���s.

					// �G���[����
					MessageBox(hwnd, _T("LoadImage failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					return -1;	// �ُ�I���Ȃ̂�-1��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �r�b�g�}�b�v�̕��ƍ������擾.
				int iRet = GetObject(hBitmap, sizeof(BITMAP), &bitmap);	// GetObject�Ńr�b�g�}�b�v���bitmap���擾.
				if (iRet <= 0){	// ���s.

					// �G���[����
					MessageBox(hwnd, _T("GetObject failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"GetObject failed!"�ƃG���[���b�Z�[�W��\��.
					return -2;	// �ُ�I���Ȃ̂�-2��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �E�B���h�E�f�o�C�X�R���e�L�X�g�n���h���̎擾.
				hDC = GetDC(hwnd);	// GetDC��hDC�擾.
				if (hDC == NULL){	// NULL�Ȃ�.

					// �G���[����
					MessageBox(hwnd, _T("GetDC failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"GetDC failed!"�ƃG���[���b�Z�[�W��\��.
					if (hBitmap != NULL){	// NULL�łȂ����.
						DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.
						hBitmap = NULL;	// NULL���Z�b�g.
					}
					return -3;	// �ُ�I���Ȃ̂�-3��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �������f�o�C�X�R���e�L�X�g�̐���.
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC��hMemDC�擾.
				if (hMemDC == NULL){	// NULL�łȂ����.

					// �G���[����
					MessageBox(hwnd, _T("CreateCompatibleDC failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateCompatibleDC failed!"�ƃG���[���b�Z�[�W��\��.
					if (hDC != NULL){	// NULL�łȂ����.
						ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�̉��.
						hDC = NULL;	// NULL���Z�b�g.
					}
					if (hBitmap != NULL){	// NULL�łȂ����.
						DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.
						hBitmap = NULL;	// NULL���Z�b�g.
					}
					return -4;	// �ُ�I���Ȃ̂�-4��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �r�b�g�}�b�v��I��.
				hOld = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObject��hMemDC��hBitmap��I��.

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

				// �X�V�̈�̎擾.
				RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
				GetClientRect(hwnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
				RECT rcUpdate = {0};	// �X�V�̈�rcUpdate��{0}�ŏ�����.
				GetUpdateRect(hwnd, &rcUpdate, FALSE);	// GetUpdateRect�ōX�V�̈�rcUpdate���擾.
				// �X�N���[�����̎擾.
				SCROLLINFO siHorz = {0};	// ���������X�N���[�����siHorz.
				siHorz.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
				siHorz.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// �ʒu, �y�[�W, �����W.
				GetScrollInfo(hwnd, SB_HORZ, &siHorz);	// GetScrollInfo��siHorz�擾.
				SCROLLINFO siVert = {0};	// ���������X�N���[�����siVert.
				siVert.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
				siVert.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// �ʒu, �y�[�W, �����W.
				GetScrollInfo(hwnd, SB_VERT, &siVert);	// GetScrollInfo��siVert�擾.

				// �`��J�n.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT�^ps��{0}�ŏ�����.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaint��hDC�擾.

				// �`��.
				int x1 = 0;	// �]����x1��0�ŏ�����.
				int y1 = 0;	// �]����y1��0�ŏ�����.
				if (dx > 0){	// dx���v���X.
					x1 = siHorz.nPage + siHorz.nPos - (rcUpdate.right - rcUpdate.left);	// x1�̓y�[�W�� + �ʒu - 1 - (�ĕ`�悷��͈�).
				}
				else{	// dx��0�ȉ�.
					x1 = siHorz.nPos;	// x1�͈ʒu.
				}
				if (dy > 0){	// dy���v���X.
					y1 = siVert.nPage + siVert.nPos - (rcUpdate.bottom - rcUpdate.top);	// y1�̓y�[�W�� + �ʒu - 1 - (�ĕ`�悷��͈�).
				}
				else{	// dy��0�ȉ�.
					y1 = siVert.nPos;	// y1�͈ʒu.
				}
				BitBlt(hDC, rcUpdate.left, rcUpdate.top, rcUpdate.right - rcUpdate.left, rcUpdate.bottom - rcUpdate.top, hMemDC, x1, y1, SRCCOPY);	// BitBlt�œ]��.

				// �`��I��.
				EndPaint(hwnd, &ps);	// EndPaint�ŕ`��I��.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �ȑO�̃r�b�g�}�b�v�ɖ߂�.
				if (hOld != NULL){	// NULL�łȂ����.
					SelectObject(hMemDC, hOld);	// SelectObject��hOld��I��.
					hOld = NULL;	// NULL���Z�b�g.
				}

				// �������f�o�C�X�R���e�L�X�g�̔j��.
				if (hMemDC != NULL){	// NULL�łȂ����.
					DeleteDC(hMemDC);	// DeleteDC��hMemDC�̔j��.
					hMemDC = NULL;	// NULL���Z�b�g.
				}

				// �E�B���h�E�f�o�C�X�R���e�L�X�g�n���h���̉��.
				if (hDC != NULL){	// NULL�łȂ����.
					ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�̉��.
					hDC = NULL;	// NULL���Z�b�g.
				}

				// �r�b�g�}�b�v�̔j��.
				if (hBitmap != NULL){	// NULL�łȂ����.
					DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.
					hBitmap = NULL;	// NULL���Z�b�g.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �����X�N���[���o�[���X�N���[�����ꂽ��.
		case WM_HSCROLL:	// �����X�N���[���o�[���X�N���[�����ꂽ��.(uMsg��WM_HSCROLL�̎�.)

			// WM_HSCROLL�u���b�N
			{

				// ���������X�N���[���o�[�����擾.
				SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
				scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
				scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
				GetScrollInfo(hwnd, SB_HORZ, &scrHorz);	// GetScrollInfo��scrHorz���擾.

				// �܂݂̍ő�ʒu���v�Z.
				int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

				// �ω��ʂ�0�Ƀ��Z�b�g.
				dx = 0;	// dx��0�Ƀ��Z�b�g.
			
				// �ʒm�R�[�h����
				switch (LOWORD(wParam)){	// LOWORD(wParam)�ɍs��ꂽ����̒ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

					// 1�ԍ�
					case SB_LEFT:

						// 1�ԍ��ɃZ�b�g.
						scrHorz.nPos = scrHorz.nMin;	// ���݈ʒu��1�ԍ��ɃZ�b�g.
						break;	// ������.

					// 1�ԉE
					case SB_RIGHT:

						// 1�ԉE�ɃZ�b�g.
						scrHorz.nPos = scrHorz.nMax;	// ���݈ʒu��1�ԉE�ɃZ�b�g.
						break;	// ������.

					// 1��
					case SB_LINELEFT:

						// 1�񍶂ɖ߂�.
						if (scrHorz.nPos > scrHorz.nMin){	// scrHorz.nPos��scrHorz.nMin���傫���ꍇ.
							dx = -1;	// �ω���-1.
							scrHorz.nPos--;	// 1�߂�.
						}
						break;	// ������.

					// 1��E
					case SB_LINERIGHT:

						// 1��E�ɐi�߂�.
						if (scrHorz.nPos < iMaxPos){	// scrHorz.nPos��iMaxPos��菬�����ꍇ.
							dx = 1;	// �ω���1.
							scrHorz.nPos++;	// 1�i��.
						}
						break;	// ������.

					// 1�y�[�W��
					case SB_PAGELEFT:

						// SB_PAGELEFT�u���b�N.
						{

							// 1�y�[�W�߂�.
							int after = scrHorz.nPos - scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
							if (after >= scrHorz.nMin){	// �����𒴂��ĂȂ����.
								dx = -1 * scrHorz.nPage;	// 1�y�[�W���}�C�i�X.
								scrHorz.nPos -= scrHorz.nPage;	// 1�y�[�W���}�C�i�X.
							}
							else{	// �����𒴂�����.
								dx = -1 * (scrHorz.nPos - scrHorz.nMin);	// ���݈ʒu����ŏ��l�܂ł̍���-1�������ĕω��ʂƂ���.
								scrHorz.nPos = scrHorz.nMin;	// �ŏ��l��.
							}

						}

						// ������.
						break;	// break�Ŕ�����.

					// 1�y�[�W�E
					case SB_PAGERIGHT:

						// SB_PAGERIGHT�u���b�N.
						{

							// 1�y�[�W�i��.
							int after = scrHorz.nPos + scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
							if (after <= iMaxPos){	// ����𒴂��ĂȂ����.
								dx = scrHorz.nPage;	// 1�y�[�W���v���X.
								scrHorz.nPos += scrHorz.nPage;	// 1�y�[�W���v���X.
							}
							else{	// ����𒴂�����.
								dx = iMaxPos - scrHorz.nPos;	// iMaxPos���猻�݈ʒu�܂ł̍���ω��ʂƂ���.
								scrHorz.nPos = scrHorz.nMax;	// �ő�l��.
							}

						}

						// ������.
						break;	// break�Ŕ�����.

					// �X�N���[���܂݂������ꂽ��.
					case SB_THUMBPOSITION:


						// SB_THUMBPOSITION�u���b�N.
						{

							// �����ꂽ�ʒu���Z�b�g.
							int before = scrHorz.nPos;	// �ȑO.
							int after = HIWORD(wParam);	// �Ȍ�.
							dx = after - before;	// �ω��ʂ�after���傫����+, before���傫����-.
							scrHorz.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrHorz.nPos�ɃZ�b�g.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ����ȊO.
					default:

						// ������.
						break;	// break�Ŕ�����.

				}

				// scrHorz.nPos��hwnd��SB_HORZ�ɃZ�b�g.
				SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfo�Ō��݂�scrHorz.nPos��hwnd�ɃZ�b�g.
				// �N���C�A���g�̈�̃X�N���[��.
				ScrollWindow(hwnd, -dx, 0, NULL, NULL);	// ScrollWindow��-dx���X�N���[��.
				// �����̈�̌v�Z.
				RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
				GetClientRect(hwnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
				RECT rcInvalidate = {0};	// �����̈�rcInvalidate��{0}�ŏ�����.
				if (dx < 0){	// dx���}�C�i�X�̎�.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right = -dx;	// ������-dx(�v���X)
					rcInvalidate.bottom = rcClient.bottom;	// �c.
				}
				else{	// dx��0���v���X�̎�.
					rcInvalidate.left = rcClient.right - dx;	// �E����-dx(�}�C�i�X)
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right= rcClient.right;	// ��.
					rcInvalidate.bottom = rcClient.bottom;	// �c.
				}
				// �����̈�̍쐬.
				InvalidateRect(hwnd, &rcInvalidate, FALSE);	// InvalidateRect�Ŗ����̈�rcInvalidate�쐬.
				// �E�B���h�E�̍X�V.
				UpdateWindow(hwnd);	// UpdateWinow��hwnd�̍X�V.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �����X�N���[���o�[���X�N���[�����ꂽ��.
		case WM_VSCROLL:	// �����X�N���[���o�[���X�N���[�����ꂽ��.(uMsg��WM_VSCROLL�̎�.)

			// WM_VSCROLL�u���b�N
			{

				// ���������X�N���[���o�[�����擾.
				SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
				scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
				GetScrollInfo(hwnd, SB_VERT, &scrVert);	// GetScrollInfo��scrVert���擾.

				// �܂݂̍ő�ʒu���v�Z.
				int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

				// �ω��ʂ�0�Ƀ��Z�b�g.
				dy = 0;	// dy��0�Ƀ��Z�b�g.
			
				// �ʒm�R�[�h����
				switch (LOWORD(wParam)){	// LOWORD(wParam)�ɍs��ꂽ����̒ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

					// 1�ԏ�
					case SB_TOP:

						// 1�ԏ�ɃZ�b�g.
						scrVert.nPos = scrVert.nMin;	// ���݈ʒu��1�ԏ�ɃZ�b�g.
						break;	// ������.

					// 1�ԉ�
					case SB_BOTTOM:

						// 1�ԉ��ɃZ�b�g.
						scrVert.nPos = scrVert.nMax;	// ���݈ʒu��1�ԉ��ɃZ�b�g.
						break;	// ������.

					// 1���
					case SB_LINEUP:

						// 1���ɖ߂�.
						if (scrVert.nPos > scrVert.nMin){	// scrVert.nPos��scrVert.nMin���傫���ꍇ.
							dy = -1;	// �ω���-1.
							scrVert.nPos--;	// 1�߂�.
						}
						break;	// ������.

					// 1��
					case SB_LINEDOWN:

						// 1�񉺂ɐi�߂�.
						if (scrVert.nPos < iMaxPos){	// scrVert.nPos��iMaxPos��菬�����ꍇ.
							dy = 1;	// �ω���1.
							scrVert.nPos++;	// 1�i��.
						}
						break;	// ������.

					// 1�y�[�W��
					case SB_PAGEUP:

						// SB_PAGEUP�u���b�N.
						{

							// 1�y�[�W�߂�.
							int after = scrVert.nPos - scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
							if (after >= scrVert.nMin){	// �����𒴂��ĂȂ����.
								dy = -1 * scrVert.nPage;	// 1�y�[�W���}�C�i�X.
								scrVert.nPos -= scrVert.nPage;	// 1�y�[�W���}�C�i�X.
							}
							else{	// �����𒴂�����.
								dy = -1 * (scrVert.nPos - scrVert.nMin);	// ���݈ʒu����ŏ��l�܂ł̍���-1�������ĕω��ʂƂ���.
								scrVert.nPos = scrVert.nMin;	// �ŏ��l��.
							}

						}

						// ������.
						break;	// break�Ŕ�����.

					// 1�y�[�W��
					case SB_PAGEDOWN:

						// SB_PAGEDOWN�u���b�N.
						{

							// 1�y�[�W�i��.
							int after = scrVert.nPos + scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
							if (after <= iMaxPos){	// ����𒴂��ĂȂ����.
								dy = scrVert.nPage;	// 1�y�[�W���v���X.
								scrVert.nPos += scrVert.nPage;	// 1�y�[�W���v���X.
							}
							else{	// ����𒴂�����.
								dy = iMaxPos - scrVert.nPos;	// iMaxPos���猻�݈ʒu�܂ł̍���ω��ʂƂ���.
								scrVert.nPos = scrVert.nMax;	// �ő�l��.
							}

						}

						// ������.
						break;	// break�Ŕ�����.

					// �X�N���[���܂݂������ꂽ��.
					case SB_THUMBPOSITION:


						// SB_THUMBPOSITION�u���b�N.
						{

							// �����ꂽ�ʒu���Z�b�g.
							int before = scrVert.nPos;	// �ȑO.
							int after = HIWORD(wParam);	// �Ȍ�.
							dy = after - before;	// �ω��ʂ�after���傫����+, before���傫����-.
							scrVert.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrVert.nPos�ɃZ�b�g.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ����ȊO.
					default:

						// ������.
						break;	// break�Ŕ�����.

				}

				// scrVert.nPos��hwnd��SB_VERT�ɃZ�b�g.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfo�Ō��݂�scrVert.nPos��hwnd�ɃZ�b�g.
				// �N���C�A���g�̈�̃X�N���[��.
				ScrollWindow(hwnd, 0, -dy, NULL, NULL);	// ScrollWindow��-dy���X�N���[��.
				// �����̈�̌v�Z.
				RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
				GetClientRect(hwnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
				RECT rcInvalidate = {0};	// �����̈�rcInvalidate��{0}�ŏ�����.
				if (dy < 0){	// dy���}�C�i�X�̎�.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right = rcClient.right;	// ��.
					rcInvalidate.bottom = -dy;	// �ォ��-dy(�v���X)
				}
				else{	// dy��0���v���X�̎�.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.bottom - dy;	// ������-dy(�}�C�i�X)
					rcInvalidate.right= rcClient.right;	// ��.
					rcInvalidate.bottom = rcClient.bottom;	// �c.
				}
				// �����̈�̍쐬.
				InvalidateRect(hwnd, &rcInvalidate, FALSE);	// InvalidateRect�Ŗ����̈�rcInvalidate�쐬.
				// �E�B���h�E�̍X�V.
				UpdateWindow(hwnd);	// UpdateWinow��hwnd�̍X�V.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �}�E�X�̍��{�^���������ꂽ��.
		case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ��.(uMsg��WM_LBUTTONDOWN�̎�.)

			// WM_LBUTTONDOWN�u���b�N
			{

				// �N���C�A���g�̈��RECT���擾.
				RECT rc = {0};	// RECT�^rc��{0}�ŏ�����.
				GetClientRect(hwnd, &rc);	// �N���C�A���g�̈��RECT���擾.

				// ���������X�N���[���o�[�̏�����.
				SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
				scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
				scrHorz.nMin = 0;	// �ŏ��l��0.
				scrHorz.nMax = bitmap.bmWidth - 1;	// �ő�l��bitmap.bmWidth.
				scrHorz.nPage = rc.right - rc.left;	// �y�[�W�T�C�Y��rc.right - rc.left.
				scrHorz.nPos = 0;	// ���݈ʒu��0.
				scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
				SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// �X�N���[�������Z�b�g.

				// ���������X�N���[���o�[�̏�����.
				SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
				scrVert.nMin = 0;	// �ŏ��l��0.
				scrVert.nMax = bitmap.bmHeight - 1;	// �ő�l��bitmap.bmHeight.
				scrVert.nPage = rc.bottom - rc.top;	// �y�[�W�T�C�Y��rc.bottom - rc.top.
				scrVert.nPos = 0;	// ���݈ʒu��0.
				scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// �X�N���[�������Z�b�g.

				// �r�b�g�]��.
				BOOL b = BitBlt(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top, hMemDC, 0, 0, SRCCOPY);	// BitBlt��hMemDC����hDC�ɓ]��.

				// ���b�Z�[�W�{�b�N�X�ɃT�C�Y����\��.
				TCHAR tszBitmap[256] = {0};	// TCHAR�����z��tszBitmap(����256)��{0}�ŏ�����.
				_stprintf(tszBitmap, _T("bitmap.bmWidth = %d\nbitmap.bmHeight = %d\nbitmap.bmBitsPixel = %d\nbitmap.bmPlanes = %d\nbitmap.bmType = %d\nbitmap.bmWidthBytes = %d"), bitmap.bmWidth, bitmap.bmHeight, bitmap.bmBitsPixel, bitmap.bmPlanes, bitmap.bmType, bitmap.bmWidthBytes);	// bitmap�̊e�v�f�𕶎���ɕϊ�.
				MessageBox(hwnd, tszBitmap, _T("BITMAP_struct"), MB_OK);	// tszBitmap�����b�Z�[�W�{�b�N�X�\��.

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