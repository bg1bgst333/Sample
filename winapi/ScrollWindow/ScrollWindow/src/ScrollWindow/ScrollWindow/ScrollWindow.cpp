// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("ScrollWindow");					// �E�B���h�E�N���X����"ScrollWindow".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("ScrollWindow"), _T("ScrollWindow"), WS_OVERLAPPEDWINDOW | WS_VSCROLL, 0, 0, 480, 360, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"ScrollWindow"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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
	static SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.

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
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					return -1;	// �ُ�I���Ȃ̂�-1��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �E�B���h�E�f�o�C�X�R���e�L�X�g�n���h���̎擾.
				hDC = GetDC(hwnd);	// GetDC��hDC�擾.
				if (hDC == NULL){	// NULL�Ȃ�.

					// �G���[����
					MessageBox(hwnd, _T("GetDC failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"GetDC failed!"�ƃG���[���b�Z�[�W��\��.
					if (hBitmap != NULL){	// NULL�łȂ����.
						DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.
						hBitmap = NULL;	// NULL���Z�b�g.
					}
					return -2;	// �ُ�I���Ȃ̂�-2��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �������f�o�C�X�R���e�L�X�g�̐���.
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC��hMemDC�擾.
				if (hMemDC == NULL){	// NULL�łȂ����.

					// �G���[����
					MessageBox(hwnd, _T("CreateCompatibleDC failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateCompatibleDC failed!"�ƃG���[���b�Z�[�W��\��.
					if (hDC != NULL){	// NULL�łȂ����.
						ReleaseDC(hwnd, hDC);	// ReleaseDC��hDC�̉��.
						hDC = NULL;	// NULL���Z�b�g.
					}
					if (hBitmap != NULL){	// NULL�łȂ����.
						DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.
						hBitmap = NULL;	// NULL���Z�b�g.
					}
					return -3;	// �ُ�I���Ȃ̂�-3��Ԃ���, �E�B���h�E�������s�Ƃ���.

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
		case WM_VSCROLL:	// �����X�N���[���o�[���X�N���[�����ꂽ��.(uMsg��WM_VSCROLL�̎�.)

			// WM_VSCROLL�u���b�N
			{

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

					// 1�s��
					case SB_LINEUP:

						// 1�s��ɖ߂�.
						if (scrVert.nPos > 0){	// scrVert.nPos��1�ȏ�Ȃ�.
							scrVert.nPos--;	// scrVert.nPos�����炷.
							// �ω��ʂ����X�N���[��.
							ScrollWindow(hwnd, 0, 1, NULL, NULL);	// ScrollWindow�ŃX�N���[��.
						}
						break;	// ������.

					// 1�s��
					case SB_LINEDOWN:

						// 1�s���ɐi�߂�.
						if (scrVert.nPos < scrVert.nMax - (int)scrVert.nPage + 1){	// scrVert.nPos���Ō�̈ʒu���O�Ȃ�.
							scrVert.nPos++;	// scrVert.nPos�𑝂₷.
							// �ω��ʂ����X�N���[��.
							ScrollWindow(hwnd, 0, -1, NULL, NULL);	// ScrollWindow�ŃX�N���[��.
						}
						break;	// ������.

					// 1�y�[�W��
					case SB_PAGEUP:

						// SB_PAGEUP�u���b�N.
						{

							// 1�y�[�W�߂�.	
							int pos = scrVert.nPos;	// �ȑO�̈ʒu
							int page = scrVert.nPage;	// �y�[�W�T�C�Y
							int vMax = scrVert.nMax;	// �ő�l
							int after = pos - page;	// �y�[�W�T�C�Y�����������̈ʒu.
							int f = 0;	// ���ۂ̍ŏ��̈ʒu.
							int d = 0;	// �ω���.
							if (after <= f){	// �y�[�W�T�C�Y�����������̈ʒu��0�ȉ�.
								scrVert.nPos = f;	// �ʒu��0.
								d = pos;	// �ȑO�̈ʒu���ω���.
							}
							else{	// �����ĂȂ�.
								scrVert.nPos -= page;	// �y�[�W�T�C�Y������.
								d = page;	// �y�[�W�T�C�Y���ω���.
							}
							// �ω��ʂ����X�N���[��.
							ScrollWindow(hwnd, 0, d, NULL, NULL);	// ScrollWindow�ŃX�N���[��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// 1�y�[�W��
					case SB_PAGEDOWN:

						// SB_PAGEDOWN�u���b�N.
						{

							// 1�y�[�W�i��.
							int pos = scrVert.nPos;	// �ȑO�̈ʒu
							int page = scrVert.nPage;	// �y�[�W�T�C�Y
							int vMax = scrVert.nMax;	// �ő�l
							int after = pos + page;	// �y�[�W�T�C�Y�𑫂������̈ʒu.
							int f = vMax - page + 1;	// ���ۂ̍Ō�̈ʒu.
							int d = 0;	// �ω���.
							if (after >= f){	// �y�[�W�T�C�Y�𑫂������̈ʒu��, ���ۂ̍Ō�̈ʒu�𒴂��Ă���.
								scrVert.nPos = f;	// ���ۂ̍Ō�̈ʒu���Z�b�g.
								d = f - pos;	// �Ō�̈ʒu����ȑO�̈ʒu�܂ł��ω���.
							}
							else{	// �����Ă��Ȃ�.
								scrVert.nPos += page;	// �y�[�W�T�C�Y�𑫂�.
								d = page;	// �y�[�W�T�C�Y���ω���.
							}
							// �ω��ʂ����X�N���[��.
							ScrollWindow(hwnd, 0, -1 * d, NULL, NULL);	// ScrollWindow�ŃX�N���[��.

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
							scrVert.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrVert.nPos�ɃZ�b�g.
							// �ω��ʂ����X�N���[��.
							ScrollWindow(hwnd, 0, before - after, NULL, NULL);	// ScrollWindow�ŃX�N���[��.

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

			}

			// ������.
			break;	// break�Ŕ�����.

		// �}�E�X�̍��{�^���������ꂽ��.
		case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ��.(uMsg��WM_LBUTTONDOWN�̎�.)

			// WM_LBUTTONDOWN�u���b�N
			{

				// �r�b�g�]��.
				RECT rc = {0};	// RECT�^rc��{0}�ŏ�����.
				GetClientRect(hwnd, &rc);	// �N���C�A���g�̈��RECT���擾.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
				scrVert.nMin = 0;	// �ŏ��l��0.
				scrVert.nMax = 480 - 1;	// �ő�l��479.
				scrVert.nPage = rc.bottom - rc.top + 1;	// �y�[�W�T�C�Y��rc.bottom - rc.top + 1.
				scrVert.fMask = SIF_PAGE | SIF_RANGE;	// �y�[�W, �����W���Z�b�g.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// �X�N���[�������Z�b�g.
				scrVert.nPos = 0;	// ���݈ʒu��0.
				scrVert.fMask = SIF_POS;	// �ʒu���Z�b�g.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// �X�N���[�������Z�b�g.
				BOOL b = BitBlt(hDC, 0, 0, rc.right - rc.left + 1, rc.bottom - rc.top + 1, hMemDC, 0, 0, SRCCOPY);	// BitBlt��hMemDC����hDC�ɓ]��.

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