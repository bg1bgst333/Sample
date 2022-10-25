// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// C�W�����o��
#include <commctrl.h>	// �R�����R���g���[��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("WindowFromPoint");				// �E�B���h�E�N���X����"WindowFromPoint".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("WindowFromPoint"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("WindowFromPoint"), _T("WindowFromPoint"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"WindowFromPoint"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("WindowFromPoint"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

	}

	// �E�B���h�E�n���h���̕\��.
	TCHAR tszHWnd[64] = {0};	// �E�B���h�E�n���h��������tszHWnd(����64)��{0}�ŏ�����.
	_stprintf(tszHWnd, _T("hWnd = 0x%08x"), hWnd);	// hWnd�𕶎���tszHWnd�ɕϊ�.
	MessageBox(NULL, tszHWnd, _T("WindowFromPoint"), MB_OK);	// tszHWnd��\��.
				
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

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
 
			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				HWND hButton;			// �{�^���̃E�B���h�E�n���h��hButton.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �{�^���̍쐬.
				hButton = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindow��WC_BUTTON�Ń{�^��"Button1"���쐬.
				if (hButton == NULL){	// hButton��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// �{�^���n���h���̕\��.
				TCHAR tszHButton[64] = {0};	// �{�^���n���h��������tszHButton(����64)��{0}�ŏ�����.
				_stprintf(tszHButton, _T("hButton = 0x%08x"), hButton);	// hButton�𕶎���tszHButton�ɕϊ�.
				MessageBox(NULL, tszHButton, _T("WindowFromPoint"), MB_OK);	// tszHButton��\��.

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

		// �E�B���h�E�̕`���v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// �`��J�n.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT�\����ps��{0}�ŏ�����.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ŕ`��J�n��, hDC�擾.
				
				// �`��I��.
				EndPaint(hwnd, &ps);	// EndPaint�ŕ`��I��.

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
					// Button1���I�����ꂽ��.
					case WM_APP + 1:

						// WM_APP + 1�u���b�N
						{

							// ���̈ʒu�̃E�B���h�E�n���h���\��.
							POINT pt = {0};	// �ʒupt��{0}�ŏ�����.
							GetCursorPos(&pt);	// GetCursorPos��pt���擾.
							HWND hPoint;	// ���̃|�C���g�̃E�B��		�h�E�n���h��hPoint.
							hPoint = WindowFromPoint(pt);	// WindowFromPoint��, ���̈ʒu�̃E�B���h�E�n���h�����擾��, hPoint�Ɋi�[.
							TCHAR tszHPoint[64] = {0};	// �n���h��������tszHPoint(����64)��{0}�ŏ�����.
							_stprintf(tszHPoint, _T("hPoint = 0x%08x"), hPoint);	// hPoint�𕶎���tszHPoint�ɕϊ�.
							MessageBox(NULL, tszHPoint, _T("WindowFromPoint"), MB_OK);	// tszHPoint��\��.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:	// ��L�ȊO�̒l�̎��̊��菈��.
 
						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

				}

				// ����̏����֌�����.
				break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �}�E�X�̍��{�^���������ꂽ��.
		case WM_LBUTTONDOWN:	// �}�E�X�̍��{�^���������ꂽ��.(uMsg��WM_LBUTTONDOWN�̎�.)

			// WM_LBUTTONDOWN�u���b�N
			{

				// �}�E�X�J�[�\���̈ʒu���擾.
				int x;	// �}�E�X���{�^���������ꂽ���̃}�E�X�J�[�\���̐��������̈ʒu.(x���W)
				int y;	// �}�E�X���{�^���������ꂽ���̃}�E�X�J�[�\���̐��������̈ʒu.(y���W)
				x = LOWORD(lParam);	// lParam�̉���16�r�b�g�̓}�E�X�J�[�\����x���W��\���Ă���̂�, LOWORD��lParam�̉���16�r�b�g���擾��, x�Ɋi�[.
				y = HIWORD(lParam);	// lParam�̏��16�r�b�g�̓}�E�X�J�[�\����y���W��\���Ă���̂�, HIWORD��lParam�̏��16�r�b�g���擾��, y�Ɋi�[.

				// �N���C�A���g���W���X�N���[�����W�ɕϊ�.
				POINT pt;	// POINT�\����pt�̐錾.
				pt.x = x;	// pt.x��x����.
				pt.y = y;	// pt.y��y����.
				ClientToScreen(hwnd, &pt);	// ClientToScreen��pt���X�N���[�����W�ɕϊ�.

				// ���̈ʒu�̃E�B���h�E�n���h�����擾��, �\��.
				HWND hPoint;	// ���̃|�C���g�̃E�B��		�h�E�n���h��hPoint.
				hPoint = WindowFromPoint(pt);	// WindowFromPoint��, ���̈ʒu�̃E�B���h�E�n���h�����擾��, hPoint�Ɋi�[.
				TCHAR tszHPoint[64] = {0};	// �n���h��������tszHPoint(����64)��{0}�ŏ�����.
				_stprintf(tszHPoint, _T("hPoint = 0x%08x"), hPoint);	// hPoint�𕶎���tszHPoint�ɕϊ�.
				MessageBox(NULL, tszHPoint, _T("WindowFromPoint"), MB_OK);	// tszHPoint��\��.

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