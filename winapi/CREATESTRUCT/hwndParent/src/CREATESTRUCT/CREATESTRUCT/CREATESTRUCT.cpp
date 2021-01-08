// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <string.h>		// C�����񏈗�

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc2.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;						// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;						// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;					// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.
	WNDCLASS wc2;					// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc2.
	TCHAR tszWndProc[256] = {0};	// �E�B���h�E�v���V�[�W���A�h���X������tszWndProc(����256)��{0}�ŏ�����.
	TCHAR tszWndProc2[256] = {0};	// �E�B���h�E�v���V�[�W���A�h���X������tszWndProc2(����256)��{0}�ŏ�����.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("CREATESTRUCT");					// �E�B���h�E�N���X����"CREATESTRUCT".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// �Ȃ�
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�v���V�[�W��WindowProc�̃A�h���X������̕\��.
	_stprintf(tszWndProc, _T("_tWinMain#WindowProc = 0x%08x"), (unsigned long)WindowProc);	// WindowProc�𕶎���ɕϊ�.
	MessageBox(NULL, tszWndProc, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc��\��.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �q�E�B���h�E�N���X�̐ݒ�
	wc2.lpszClassName = _T("Child_Window");						// �E�B���h�E�N���X����"Child_Window".
	wc2.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc2.lpfnWndProc = WindowProc2;								// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc2.
	wc2.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wc2.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc2.hCursor = LoadCursor(NULL, IDC_ARROW);					// �J�[�\���͖��.
	wc2.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc2.lpszMenuName = NULL;									// �Ȃ�
	wc2.cbClsExtra = 0;											// 0�ł���.
	wc2.cbWndExtra = 0;											// 0�ł���.

	// �E�B���h�E�v���V�[�W��WindowProc2�̃A�h���X������̕\��.
	_stprintf(tszWndProc2, _T("_tWinMain#WindowProc2 = 0x%08x"), (unsigned long)WindowProc2);	// WindowProc2�𕶎���ɕϊ�.
	MessageBox(NULL, tszWndProc2, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc2��\��.

	// �q�E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc2)) {	// RegisterClass�Ŏq�E�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("CREATESTRUCT"), _T("CREATESTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"CREATESTRUCT"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -3;	// �ُ�I��(3)

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W����
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾�Ə�����.
				LPCREATESTRUCT lpCreateStruct;	// CREATESTRUCT�\���̃|�C���^lpCreateStruct.
				WNDPROC wndProc;	// �E�B���h�E�v���V�[�W��wndProc.
				WNDPROC wndProc2;	// �E�B���h�E�v���V�[�W��wndProc2.
				TCHAR tszHInstance[256] = {0};	// �A�v���P�[�V�����C���X�^���X�n���h��������tszHInstance(����256)��{0}�ŏ�����.
				TCHAR tszWndProc[256] = {0};	// �E�B���h�E�v���V�[�W��������tszWndProc(����256)��{0}�ŏ�����.
				TCHAR tszWndProc2[256] = {0};	// �E�B���h�E�v���V�[�W��������tszWndProc2(����256)��{0}�ŏ�����.
				TCHAR tszHWnd[256] = {0};		// �E�B���h�E�n���h��������tszHWnd(����256)��{0}�ŏ�����.
				HWND hWnd2 = NULL;	// �E�B���h�E�n���h��hWnd2��NULL�ŏ�����.

				// �E�B���h�E�v���V�[�W���A�h���X������̕\��.
				wndProc = (WNDPROC)GetWindowLong(hwnd, GWL_WNDPROC);	// GetWindowLong��GWL_WNDPROC���w�肵��wndProc���擾.
				_stprintf(tszWndProc, _T("WindowProc#WindowProc = 0x%08x"), (unsigned long)wndProc);	// wndProc�𕶎���ɕϊ�.
				MessageBox(NULL, tszWndProc, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc��\��.

				// �E�B���h�E�n���h��������̕\��.
				_stprintf(tszHWnd, _T("WindowProc#hwnd = 0x%08x"), (unsigned long)hwnd);	// hwnd�𕶎���ɕϊ�.
				MessageBox(NULL, tszHWnd, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszHWnd��\��.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾�Ǝq�E�B���h�E�̍쐬.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g��, lpCreateStruct�Ɋi�[.
				hWnd2 = CreateWindow(_T("Child_Window"), _T("CREATESTRUCT"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)WM_APP + 1, lpCreateStruct->hInstance, NULL);	// CreateWindow��hwnd��e�Ƃ���q�E�B���h�E�̍쐬��, �E�B���h�E�n���h����hWnd2�Ɋi�[.(lpCreateStruct->hInstance���w��.�Ō�̈�����NULL��n��.)

				// �q�E�B���h�E�v���V�[�W���A�h���X������̕\��.
				wndProc2 = (WNDPROC)GetWindowLong(hWnd2, GWL_WNDPROC);	// GetWindowLong��GWL_WNDPROC���w�肵��wndProc2���擾.
				_stprintf(tszWndProc2, _T("WindowProc#WindowProc2 = 0x%08x"), (unsigned long)wndProc2);	// wndProc2�𕶎���ɕϊ�.
				MessageBox(NULL, tszWndProc2, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc2��\��.

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

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}

// WindowProc2�֐��̒�`
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾�Ə�����.
				LPCREATESTRUCT lpCreateStruct;	// CREATESTRUCT�\���̃|�C���^lpCreateStruct.
				WNDPROC wndProc;	// �E�B���h�E�v���V�[�W��wndProc.
				WNDPROC wndProc2;	// �E�B���h�E�v���V�[�W��wndProc2.
				TCHAR tszWndProc[256] = {0};	// �E�B���h�E�v���V�[�W��������tszWndProc(����256)��{0}�ŏ�����.
				TCHAR tszWndProc2[256] = {0};	// �E�B���h�E�v���V�[�W��������tszWndProc2(����256)��{0}�ŏ�����.
				TCHAR tszHWndParent[256] = {0};		// �e�E�B���h�E�n���h��������tszHWndParent(����256)��{0}�ŏ�����.

				// lParam��lpCreateStruct�ɃL���X�g.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g��, lpCreateStruct�Ɋi�[.

				// �e�E�B���h�E�v���V�[�W���A�h���X������̕\��.
				wndProc = (WNDPROC)GetWindowLong(lpCreateStruct->hwndParent, GWL_WNDPROC);	// GetWindowLong��GWL_WNDPROC���w�肵��wndProc���擾.(�e�E�B���h�E�n���h����lpCreateStruct->hwndParent�Ɋi�[����Ă���.)
				_stprintf(tszWndProc, _T("WindowProc2#WindowProc = 0x%08x"), (unsigned long)wndProc);	// wndProc�𕶎���ɕϊ�.
				MessageBox(NULL, tszWndProc, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc��\��.

				// �e�E�B���h�E�n���h��������̕\��.
				_stprintf(tszHWndParent, _T("WindowProc2#lpCreateStruct->hwndParent = 0x%08x"), (unsigned long)lpCreateStruct->hwndParent);	// lpCreateStruct->hwndParent�𕶎���ɕϊ�.
				MessageBox(NULL, tszHWndParent, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszHWndParent��\��.

				// �E�B���h�E�v���V�[�W���A�h���X������̕\��.
				wndProc2 = (WNDPROC)GetWindowLong(hwnd, GWL_WNDPROC);	// GetWindowLong��GWL_WNDPROC���w�肵��wndProc2���擾.
				_stprintf(tszWndProc2, _T("WindowProc2#WindowProc2 = 0x%08x"), (unsigned long)wndProc2);	// wndProc2�𕶎���ɕϊ�.
				MessageBox(NULL, tszWndProc2, _T("CREATESTRUCT"), MB_OK);	// MessageBox��tszWndProc2��\��.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

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