// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
 
// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// �ϐ��̐錾
	HWND hWnd;			// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
 
	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("SelectClipRgn");					// �E�B���h�E�N���X����"SelectClipRgn".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.
 
	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.
 
		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("SelectClipRgn"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}
 
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("SelectClipRgn"), _T("SelectClipRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"SelectClipRgn"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("SelectClipRgn"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)
 
	}
 
	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.
 
	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.
 
		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.
 
	}
 
	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.
 
}
 
// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E�v���V�[�W���S�̂Ŏg����X�^�e�B�b�N�ϐ��̐錾.
	static HBITMAP hBitmap;	// ���[�h�����r�b�g�}�b�v�̃n���h�����i�[����HBITMAP�^�X�^�e�B�b�N�ϐ�hBitmap.
	static HRGN hRgn1;		// �X�^�e�B�b�N�ȋ�`���[�W�����̃n���h��hRgn1.
	static HRGN hRgn2;		// �X�^�e�B�b�N�ȑȉ~���[�W�����̃n���h��hRgn2.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.
 
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
 
			// WM_CREATE�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾
				LPCREATESTRUCT lpcs;	// lParam����n���ꂽCREATESTRUCT�ւ̃|�C���^���i�[����lpcs.

				// lParam��lpcs�ɓn��.
				lpcs = (LPCREATESTRUCT)lParam; // lParam��LPCREATESTRUCT�ɃL���X�g����lpcs�Ɋi�[.

				// �r�b�g�}�b�v�̃��[�h
				hBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"test.bmp"�����[�h��, �߂�l�̃r�b�g�}�b�v�n���h����hBitmap�Ɋi�[����.
				if (hBitmap == NULL) {	// hBitmap��NULL�Ȃ烍�[�h���s.

					// �G���[����
					MessageBox(hwnd, _T("LoadImage failed!"), _T("SelectClipRgn"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
					return -1;	// �ُ�I���Ȃ̂�-1��Ԃ���, �E�B���h�E�������s�Ƃ���.

				}

				// ��`�̃��[�W�����𐶐�.
				hRgn1 = CreateRectRgn(10, 10, 250, 250);	// CreateRectRgn�ŋ�`�̃��[�W�����𐶐�.

				// �ȉ~�̃��[�W�����𐶐�.
				hRgn2 = CreateEllipticRgn(100, 50, 400, 300);	//  CreateEllipticRgn�őȉ~�̃��[�W�����𐶐�.

				// ���[�W�����̌���.
				CombineRgn(hRgn1, hRgn1, hRgn2, RGN_OR);	// hRgn1��hRgn2�̗̈�̘a.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.
 
			}
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
 
		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)
 
			// WM_DESTROY�u���b�N
			{

				// �r�b�g�}�b�v�̏I������
				if (hBitmap != NULL) {	// hBitmap��NULL�łȂ��ꍇ.(���[�h�����܂܂̏�Ԃ̏ꍇ.)

					// �r�b�g�}�b�v�̔j��
					DeleteObject(hBitmap);	// DeleteObject��hBitmap�̔j��.
					hBitmap = NULL;	// hBitmap��NULL�ɂ��Ă���.

				}

				// �ȉ~���[�W�����̍폜
				DeleteObject(hRgn2);	// DeleteObject��hRgn2���폜.

				// ��`���[�W�����̍폜
				DeleteObject(hRgn1);	// DeleteObject��hRgn1���폜.

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)
 
			}
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��ʂ̕`���v�����ꂽ��.
		case WM_PAINT:		// ��ʂ̕`���v�����ꂽ��.(uMsg��WM_PAINT�̎�.)
 
			// WM_PAINT�u���b�N
			{

				// ���̃u���b�N�̃��[�J���ϐ��̐錾
				HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hDC.
				PAINTSTRUCT ps;		// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̌^�̕ϐ�ps.
				HDC hMemDC;			// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�ƌ݊����̂��郁�����f�o�C�X�R���e�L�X�g�n���h�����i�[����HDC�^�ϐ�hMemDC.
				HBITMAP hOldBitmap;	// SelectObject�����܂őI�����Ă����Â��r�b�g�}�b�v�̃n���h��hOldBitmap.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// �������f�o�C�X�R���e�L�X�g�̐���
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�ghDC�ƌ݊����̂��郁�����f�o�C�X�R���e�L�X�ghMemDC�𐶐�.

				// ���[�h�����r�b�g�}�b�v"test.bmp"���g�p����悤�Ƀ������f�o�C�X�R���e�L�X�g�ɑI��������.
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObject��hMemDC�Ƀ��[�h�����r�b�g�}�b�vhBitmap��I��������.(����܂Ŏg���Ă����r�b�g�}�b�v�̃n���h�����Ԃ�̂�, hOldBitmap�Ɋi�[.)

				// �N���b�v���[�W�����̑I��.
				SelectClipRgn(hDC, hRgn1);	// hRgn1�̌`�ɃN���b�v.

				// ���[�h�����摜�̕\��.
				BitBlt(hDC, 0, 0, 640, 480, hMemDC, 0, 0, SRCCOPY);	// BitBlt��hMemDC�̃s�N�Z�����hDC�ɓ]�����邱�Ƃ�, �E�B���h�E�Ƀ��[�h�����摜���\�������.

				// �N���b�v���[�W�����̉���.
				SelectClipRgn(hDC, NULL);	// NULL���w�肷��Ɖ���.

				// �r�b�g�}�b�v�̏�Ԃ�߂�.
				SelectObject(hMemDC, hOldBitmap);	// �������f�o�C�X�R���e�L�X�g�Ɍ���hOldBitmap�ɖ߂��悤�ɑI��������.

				// �������f�o�C�X�R���e�L�X�g�̔j��
				DeleteDC(hMemDC);	// DeleteDC��hMemDC��j��.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

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