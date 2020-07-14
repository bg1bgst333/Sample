// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;		// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;		// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("PAINTSTRUCT");					// �E�B���h�E�N���X����"PAINTSTRUCT".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName =NULL;									// �Ȃ�
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("PAINTSTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("PAINTSTRUCT"), _T("PAINTSTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"PAINTSTRUCT"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL) {	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("PAINTSTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow Failure!"�ƃG���[���b�Z�[�W��\��.
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

	// �E�B���h�E�v���V�[�W���S�̂Ŏg����X�^�e�B�b�N�ϐ��̐錾.
	static HPEN hRedPen;		// �`�悷���`�̉��Ɏg����Ԃ��y���̃n���h�����i�[����HPEN�^�X�^�e�B�b�N�ϐ�hRedPen.
	static HBRUSH hRedBrush;	// �`�悷���`��h��Ԃ��̂Ɏg����Ԃ��u���V�̃n���h�����i�[����HBRUSH�^�X�^�e�B�b�N�ϐ�hRedBrush.
	static HPEN hGreenPen;		// �`�悷���`�̉��Ɏg����΂̃y���̃n���h�����i�[����HPEN�^�X�^�e�B�b�N�ϐ�hGreenPen.
	static HBRUSH hGreenBrush;	// �`�悷���`��h��Ԃ��̂Ɏg����΂̃u���V�̃n���h�����i�[����HBRUSH�^�X�^�e�B�b�N�ϐ�hGreenBrush.
	static HPEN hBluePen;		// �`�悷���`�̉��Ɏg������y���̃n���h�����i�[����HPEN�^�X�^�e�B�b�N�ϐ�hBluePen.
	static HBRUSH hBlueBrush;	// �`�悷���`��h��Ԃ��̂Ɏg������u���V�̃n���h�����i�[����HBRUSH�^�X�^�e�B�b�N�ϐ�hBlueBrush.
	static BYTE btDrawColor = 0;	// �ǂ̐F�œh�邩������ԕϐ�btDrawColor��0(��)�ŏ�����.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg) {	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �y���ƃu���V�̍쐬.
				hRedPen = CreatePen(PS_SOLID, 1, RGB(0xFF, 0x00, 0x00));	// CreatePen�ŐԂ��y�����쐬.
				hRedBrush = CreateSolidBrush(RGB(0xFF, 0x00, 0x00));		// CreateSolidBrush�ŐԂ��u���V���쐬.
				hGreenPen = CreatePen(PS_SOLID, 1, RGB(0x00, 0xFF, 0x00));	// CreatePen�ŗ΂̃y�����쐬.
				hGreenBrush = CreateSolidBrush(RGB(0x00, 0xFF, 0x00));		// CreateSolidBrush�ŗ΂̃u���V���쐬.
				hBluePen = CreatePen(PS_SOLID, 1, RGB(0x00, 0x00, 0xFF));	// CreatePen�Ő��y�����쐬.
				hBlueBrush = CreateSolidBrush(RGB(0x00, 0x00, 0xFF));		// CreateSolidBrush�Ő��u���V���쐬.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// �y���ƃu���V�̔j��.
				DeleteObject(hRedPen);		// DeleteObject��hRedPen��j��.
				DeleteObject(hRedBrush);	// DeleteObject��hRedBrush��j��.
				DeleteObject(hGreenPen);	// DeleteObject��hGreenPen��j��.
				DeleteObject(hGreenBrush);	// DeleteObject��hGreenBrush��j��.
				DeleteObject(hBluePen);		// DeleteObject��hBluePen��j��.
				DeleteObject(hBlueBrush);	// DeleteObject��hBlueBrush��j��.

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
				HPEN hOldPen;		// SelectObject�����܂Ŏg���Ă����Â��y���̃n���h��hOldPen.
				HBRUSH hOldBrush;	// SelectObject�����܂Ŏg���Ă����Â��u���V�̃n���h��hOldBrush.

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// btDrawColor�ŐF��ς���.
				if (btDrawColor == 0){	// ��
					hOldPen = (HPEN)SelectObject(hDC, hRedPen);	// �Ԃ��y����I��.
					hOldBrush = (HBRUSH)SelectObject(hDC, hRedBrush);	// �Ԃ��u���V��I��.
					btDrawColor = 1;	// �΂ɂ���.
				}
				else if (btDrawColor == 1){	// ��
					hOldPen = (HPEN)SelectObject(hDC, hGreenPen);	// �΂̃y����I��.
					hOldBrush = (HBRUSH)SelectObject(hDC, hGreenBrush);	// �΂̃u���V��I��.
					btDrawColor = 2;	// �ɂ���.
				}
				else{	// ��
					hOldPen = (HPEN)SelectObject(hDC, hBluePen);	// ���y����I��.
					hOldBrush = (HBRUSH)SelectObject(hDC, hBlueBrush);	// ���u���V��I��.
					btDrawColor = 0;	// �Ԃɂ���.
				}

				// ��`��`��.
				Rectangle(hDC, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom);	// ps.rcPaint�̗̈�ɋ�`�`��.

				// �y���ƃu���V�̏�Ԃ�߂�.
				SelectObject(hDC, hOldPen);		// �f�o�C�X�R���e�L�X�g�Ɍ���hOldPen�ɖ߂��悤�ɑI��������.
				SelectObject(hDC, hOldBrush);	// �f�o�C�X�R���e�L�X�g�Ɍ���hOldBrush�ɖ߂��悤�ɑI��������.

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