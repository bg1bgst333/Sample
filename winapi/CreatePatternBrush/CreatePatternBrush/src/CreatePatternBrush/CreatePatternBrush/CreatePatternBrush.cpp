// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �r�b�g�}�b�v�̃��[�h.
	HBITMAP hBitmap = (HBITMAP)LoadImage(hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��"test.bmp"�����[�h.
	if (hBitmap == NULL){	// ���[�h���s.

		// �G���[����
		MessageBox(NULL, _T("LoadImage failed!"), _T("CreatePatternBrush"), MB_OK | MB_ICONHAND);	// MessageBox��"LoadImage failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �p�^�[���u���V�̍쐬.
	HBRUSH hbrBackground = CreatePatternBrush(hBitmap);	// CreatePatternBrush�Ńp�^�[���u���V���쐬.
	if (hbrBackground == NULL){	// �쐬���s.

		// �G���[����
		MessageBox(NULL, _T("CreatePatternBrush failed!"), _T("CreatePatternBrush"), MB_OK | MB_ICONHAND);	// MessageBox��"CreatePatternBrush failed!"�ƃG���[���b�Z�[�W��\��.
		DeleteObject(hBitmap);	// DeleteObject�Ńr�b�g�}�b�v�j��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("CreatePatternBrush");				// �E�B���h�E�N���X����"CreatePatternBrush".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = hbrBackground;							// �w�i�͍쐬�����u���VhbrBackground.
	wc.lpszMenuName = NULL;										// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;											// 0�ł���.
	wc.cbWndExtra = 0;											// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreatePatternBrush"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		DeleteObject(hbrBackground);	// DeleteObject�Ńu���V�j��.
		DeleteObject(hBitmap);	// DeleteObject�Ńr�b�g�}�b�v�j��.
		return -3;	// �ُ�I��(3)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CreatePatternBrush"), _T("CreatePatternBrush"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"CreatePatternBrush"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreatePatternBrush"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		DeleteObject(hbrBackground);	// DeleteObject�Ńu���V�j��.
		DeleteObject(hBitmap);	// DeleteObject�Ńr�b�g�}�b�v�j��.
		return -4;	// �ُ�I��(4)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.

	}

	// �v���O�����̏I��
	DeleteObject(hbrBackground);	// DeleteObject�Ńu���V�j��.
	DeleteObject(hBitmap);	// DeleteObject�Ńr�b�g�}�b�v�j��.
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
		
			// WM_CREATE�u���b�N
			{

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���b�Z�[�W���[�v�𔲂���.
				PostQuitMessage(0);	// PostQuitMessage�Ŕ�����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}