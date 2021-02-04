// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�Ə�����.
	HWND hWnd;							// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;							// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;						// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("WNDCLASS");						// �E�B���h�E�N���X����"WNDCLASS".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// �Ȃ�
	wc.cbClsExtra = sizeof(HCURSOR) * 2;					// HCURSOR�̃T�C�Y��2�{.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("WNDCLASS"), _T("WNDCLASS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"WNDCLASS"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

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

	// �X�^�e�B�b�N�ϐ��̏�����.
	static HCURSOR hOldCursor = NULL;	// hOldCursor��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾�Ə�����.
				HCURSOR hCrossCursor;	// �N���X�J�[�\���n���h��hCrossCursor.
				HCURSOR hWaitCursor;	// �E�F�C�g�J�[�\���n���h��hWaitCursor.

				// �N���X�J�[�\���̃��[�h.
				hCrossCursor = (HCURSOR)LoadImage(NULL, IDC_CROSS, IMAGE_CURSOR, 0, 0, LR_SHARED);	// LoadImage��IDC_CROSS�����[�h��, �n���h����hCrossCursor�Ɋi�[.

				// �N���X�g���������ɃN���X�J�[�\���n���h�����Z�b�g.
				SetClassLong(hwnd, 0, (LONG)hCrossCursor);	// SetClassLong�ŃN���X�g���������̐擪�ʒu0��hCrossCursor���Z�b�g.

				// �E�F�C�g�J�[�\���̃��[�h.
				hWaitCursor = (HCURSOR)LoadImage(NULL, IDC_WAIT, IMAGE_CURSOR, 0, 0, LR_SHARED);	// LoadImage��IDC_WAIT�����[�h��, �n���h����hWaitCursor�Ɋi�[.

				// �N���X�g���������ɃE�F�C�g�J�[�\���n���h�����Z�b�g.
				SetClassLong(hwnd, 4, (LONG)hWaitCursor);	// SetClassLong�ŃN���X�g���������̐擪����4�o�C�g�̈ʒu4��hWaitCursor���Z�b�g.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// �ȑO�̃J�[�\���ɖ߂�.
				SetCursor(hOldCursor);	// SetCursor��hOldCursor���Z�b�g.

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �}�E�X�̍��{�^���������ꂽ��.
		case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ��.(uMsg��WM_LBUTTONDOWN�̎�.)

			// WM_LBUTTONDOWN�u���b�N
			{

				// �ϐ��̐錾�Ə�����.
				HCURSOR hCrossCursor;	// �N���X�J�[�\���n���h��hCrossCursor.
				HCURSOR hArrowCursor;	// �A���[�J�[�\���n���h��hArrowCursor.
				HCURSOR hWaitCursor;	// �E�F�C�g�J�[�\���n���h��hWaitCursor.

				// �N���X�J�[�\���̎擾.
				hCrossCursor = (HCURSOR)GetClassLong(hwnd, 0);	// GetClassLong�ŃN���X�g���������擪�ʒu0�̒l���擾��, hCrossCursor�Ɋi�[.

				// �N���X�J�[�\�����Z�b�g.
				hOldCursor = SetCursor(hCrossCursor);	// SetCursor��hCrossCursor���Z�b�g��, �ȑO�̃J�[�\����hOldCursor�Ɋi�[.

				// 5�b�x�~.
				Sleep(5000);	// Sleep��5000�~���b�x�~.

				// GetClassLong�Ŋ���̃J�[�\��(�܂�A���[�J�[�\��.)���擾.
				hArrowCursor = (HCURSOR)GetClassLong(hwnd, GCL_HCURSOR);	// GetClassLong�Ŋ���̃J�[�\�����擾��, hArrowCursor�Ɋi�[.

				// �A���[�J�[�\�����Z�b�g.
				SetCursor(hArrowCursor);	// SetCursor��hArrowCursor���Z�b�g.

				// 5�b�x�~.
				Sleep(5000);	// Sleep��5000�~���b�x�~.

				// �E�F�C�g�J�[�\���̎擾.
				hWaitCursor = (HCURSOR)GetClassLong(hwnd, 4);	// GetClassLong�ŃN���X�g���������擪����4�o�C�g�̈ʒu4�̒l���擾��, hWaitCursor�Ɋi�[.

				// �E�F�C�g�J�[�\�����Z�b�g.
				SetCursor(hWaitCursor);	// SetCursor��hWaitCursor���Z�b�g.

				// 5�b�x�~.
				Sleep(5000);	// Sleep��5000�~���b�x�~.

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