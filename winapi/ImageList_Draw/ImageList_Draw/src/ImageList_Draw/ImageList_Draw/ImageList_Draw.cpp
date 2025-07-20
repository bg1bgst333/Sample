// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <commctrl.h>	// �R�����R���g���[��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��hWnd.
	MSG msg;					// ���b�Z�[�Wmsg.
	WNDCLASS wc;				// �E�B���h�E�N���Xwc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("ImageList_Draw");					// �E�B���h�E�N���X��"ImageList_Draw".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C��CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W��WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���XhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// �w�iWHITE_BRUSH.
	wc.lpszMenuName = NULL;										// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �G���[����
		return -1;	// �ُ�I��(-1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("ImageList_Draw"), _T("ImageList_Draw"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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

	// �E�B���h�E�v���V�[�W���S�̂Ŏg����X�^�e�B�b�N�ϐ��̐錾.
	static HBITMAP hBitmap1;	// ���[�h�����r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hBitmap1.
	static HBITMAP hBitmap2;	// ���[�h�����r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hBitmap2.
	static HIMAGELIST hImageList;	// �C���[�W���X�g�n���h�����i�[����HIMAGELIST�^�X�^�e�B�b�N�ϐ�hImageList.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾
				LPCREATESTRUCT lpcs;	// lParam����n���ꂽCREATESTRUCT�ւ̃|�C���^���i�[����lpcs.

				InitCommonControls();

				// lParam��lpcs�ɓn��.
				lpcs = (LPCREATESTRUCT)lParam; // lParam��LPCREATESTRUCT�ɃL���X�g����lpcs�Ɋi�[.

				// �r�b�g�}�b�v�̃��[�h
				hBitmap1 = (HBITMAP)LoadImage(lpcs->hInstance, _T("image1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"image1.bmp"�����[�h��, �߂�l�̃r�b�g�}�b�v�n���h����hBitmap1�Ɋi�[����.
				if (hBitmap1 == NULL){	// hBitmap1��NULL�Ȃ烍�[�h���s.

					// �G���[����
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ImageList_Draw"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					return -1;	// �ُ�I���Ȃ̂�-1��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}
				hBitmap2 = (HBITMAP)LoadImage(lpcs->hInstance, _T("image2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"image2.bmp"�����[�h��, �߂�l�̃r�b�g�}�b�v�n���h����hBitmap2�Ɋi�[����.
				if (hBitmap2 == NULL){	// hBitmap2��NULL�Ȃ烍�[�h���s.

					// �G���[����
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ImageList_Draw"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					if (hBitmap1 != NULL){	// hBitmap1��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)
						// �r�b�g�}�b�v�̔j��
						DeleteObject(hBitmap1);	// DeleteObject��hBitmap1�̔j��.
						hBitmap1 = NULL;	// hBitmap1��NULL�ɂ��Ă���
					}
					return -2;	// �ُ�I���Ȃ̂�-2��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �C���[�W���X�g�̍쐬
				hImageList = ImageList_Create(32, 32, ILC_COLOR24, 1, 1);	// ImageList_Create�ŃC���[�W���X�g���쐬.
				if (hImageList == NULL){	// hImageList��NULL�Ȃ玸�s.

					// �G���[����
					MessageBox(hwnd, _T("ImageList_Create failed!"), _T("ImageList_Draw"), MB_OK | MB_ICONHAND);	// MessageBox��"ImageList_Create failed!"�ƃG���[���b�Z�[�W��\��.
					if (hBitmap2 != NULL){	// hBitmap2��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)
						// �r�b�g�}�b�v�̔j��
						DeleteObject(hBitmap2);	// DeleteObject��hBitmap2�̔j��.
						hBitmap2 = NULL;	// hBitmap2��NULL�ɂ��Ă���
					}
					if (hBitmap1 != NULL){	// hBitmap1��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)
						// �r�b�g�}�b�v�̔j��
						DeleteObject(hBitmap1);	// DeleteObject��hBitmap1�̔j��.
						hBitmap1 = NULL;	// hBitmap1��NULL�ɂ��Ă���
					}
					return -3;	// �ُ�I���Ȃ̂�-3��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// �C���[�W���X�g�ւ̒ǉ�.
				ImageList_Add(hImageList, hBitmap1, NULL);	// ImageList_Add��hImageList��hBitmap1��ǉ�.
				ImageList_Add(hImageList, hBitmap2, NULL);	// ImageList_Add��hImageList��hBitmap2��ǉ�.

				// �`��̍X�V.
				InvalidateRect(hwnd, NULL, TRUE);

			}

			// ����̏����֌�����.
			break;

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �C���[�W���X�g�̏I������
				if (hImageList != NULL){	// hImageList��NULL�łȂ��ꍇ.

					// �C���[�W���X�g�̔j��
					ImageList_Destroy(hImageList);
					hImageList = NULL;

				}

				// �r�b�g�}�b�v�̏I������
				if (hBitmap2 != NULL){	// hBitmap2��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)
					// �r�b�g�}�b�v�̔j��
					DeleteObject(hBitmap2);	// DeleteObject��hBitmap2�̔j��.
					hBitmap2 = NULL;	// hBitmap2��NULL�ɂ��Ă���
				}
				if (hBitmap1 != NULL){	// hBitmap1��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)
					// �r�b�g�}�b�v�̔j��
					DeleteObject(hBitmap1);	// DeleteObject��hBitmap1�̔j��.
					hBitmap1 = NULL;	// hBitmap1��NULL�ɂ��Ă���.
				}

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT�𑗐M.

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

				// �`��.
				ImageList_Draw(hImageList, 0, hPaintDC, 50, 50, ILD_NORMAL);	// ImageList_Draw��0��(50, 50)�ɕ`��.
				ImageList_Draw(hImageList, 1, hPaintDC, 50 + 32, 50, ILD_NORMAL);	// ImageList_Draw��1��(50 + 32, 50)�ɕ`��.
				ImageList_Draw(hImageList, 0, hPaintDC, 50 + 32 + 32, 50, ILD_NORMAL);	// ImageList_Draw��0��(50 + 32 + 32, 50)�ɕ`��.
				ImageList_Draw(hImageList, 1, hPaintDC, 50 + 32 + 32 + 32, 50, ILD_NORMAL);	// ImageList_Draw��1��(50 + 32 + 32 + 32, 50)�ɕ`��.

				// �`��I��.
				EndPaint(hwnd, &ps);

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.


		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;

	}

	// ����̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc���Ă�, �߂�l�����̂܂ܕԂ�.

}