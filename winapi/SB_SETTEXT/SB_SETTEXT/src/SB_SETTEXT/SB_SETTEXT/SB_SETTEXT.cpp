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
	wc.lpszClassName = _T("SB_SETTEXT");						// �E�B���h�E�N���X��"SB_SETTEXT".
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
	hWnd = CreateWindow(_T("SB_SETTEXT"), _T("SB_SETTEXT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�쐬.
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

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// uMsg���Ƃɏ����U�蕪��.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				LPCREATESTRUCT lpCS;	// CREATESTRUCT�\���̃|�C���^lpCS.

				// lpCS�̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��lpCS�ɕϊ�.

				// �R�����R���g���[���̏�����.
				InitCommonControls();	// InitCommonControls�ŃR�����R���g���[���̏�����.

				// �X�e�[�^�X�o�[�̍쐬.
				hStatusBar = CreateWindowEx(0, STATUSCLASSNAME, _T("����������"), WS_CHILD | WS_VISIBLE | CCS_BOTTOM, 0, 0, 0, 0, hwnd, (HMENU)ID_STATUS, lpCS->hInstance, NULL);	// CreateWindowEx�ŃX�e�[�^�X�o�[�쐬.
				if (hStatusBar == NULL){	// hStatusBar��NULL.
						
					// �E�B���h�E�쐬���s
					return -1;	// -1��Ԃ�.

				}

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

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵����.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Set Text���I�����ꂽ��.
					case ID_ITEM_SETTEXT:

						// ID_ITEM_SETTEXT�u���b�N
						{

							// �X�e�[�^�X�o�[��"����������"���Z�b�g.
							SendMessage(hStatusBar, SB_SETTEXT, (WPARAM)255 | 0, (LPARAM)_T("����������"));	// SB_SETTEXT��hStatusBar��"����������"���Z�b�g.

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

		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;

	}

	// ����̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc���Ă�, �߂�l�����̂܂ܕԂ�.

}