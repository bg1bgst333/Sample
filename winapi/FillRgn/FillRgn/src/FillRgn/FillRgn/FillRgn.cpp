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
	wc.lpszClassName = _T("FillRgn");						// �E�B���h�E�N���X����"FillRgn".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("FillRgn"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}
 
	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("FillRgn"), _T("FillRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"FillRgn"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("FillRgn"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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
	static HRGN hRgn;		// �X�^�e�B�b�N�ȃ��[�W�����̃n���h��hRgn.
	static HBRUSH hBrush;	// HBRUSH�^�X�^�e�B�b�N�ϐ�hBrush.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.
 
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
 
			// WM_CREATE�u���b�N
			{

				// ���[�W�����̐���.
				hRgn = CreateRectRgn(50, 50, 300, 200);	// CreateRectRgn�ňʒu�ƃT�C�Y��(50, 50, 300, 200)�̋�`���[�W�������쐬.

				// �Ԃ��u���V�̍쐬.
				hBrush = CreateSolidBrush(RGB(0xFF, 0x00, 0x00));	// �Ԃ̃u���VhBrush.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.
 
			}
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
 
		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)
 
			// WM_DESTROY�u���b�N
			{

				// �Ԃ��u���V�̔j��.
				DeleteObject(hBrush);	// �Ԃ��u���VhBrush���폜.

				// ���[�W�����̍폜
				DeleteObject(hRgn);	// DeleteObject��hRgn���폜.

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

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// ���[�W�������w��̐F�œh��ׂ�.
				FillRgn(hDC, hRgn, hBrush);	// FillRgn��hBrush�̐F�œh��ׂ�.

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