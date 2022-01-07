// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <string.h>		// C�����񏈗�
#include <shlwapi.h>	// �V�F��API
#include <olectl.h>		// OLE�R���g���[��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;		// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;		// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;	// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("IPicture");						// �E�B���h�E�N���X����"IPicture".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IPicture"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("IPicture"), _T("IPicture"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"IPicture"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IPicture"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)

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
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����E�B���h�E�v���V�[�W��.

	// �X�^�e�B�b�N�ϐ��̏�����.
	static IPicture *pPicture = NULL;	// IPicture�|�C���^pPicture��NULL�ŏ�����.
	static HBITMAP hBitmap = NULL;	// HBITMAP�n���h��hBitmap��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:	// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾�Ə�����.
				HANDLE hFile;	// �t�@�C���n���h��hFile
				DWORD dwFileSize;	// �t�@�C���T�C�YhFileSize
				HGLOBAL hGlobal;	// �O���[�o���n���h��hGlobal
				LPVOID lpBuf;	// �o�b�t�@�|�C���^lpBuf
				IStream *pStream;	// IStream�|�C���^pStream
				TCHAR tszPath[MAX_PATH] = {0};	// tszPath(����MAX_PATH)��{0}�ŏ�����.

				// �摜�̃p�X.				
				GetModuleFileName(NULL, tszPath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.
				PathRemoveFileSpec(tszPath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.
				_tcscat(tszPath, _T("\\test.gif"));	// ��L�p�X��"\test.gif"��A��.

				// �摜�t�@�C�����J��.
				hFile = CreateFile(tszPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// "test.jpg"���J��.

				// �t�@�C���T�C�Y���擾.
				dwFileSize = GetFileSize(hFile, NULL);	// GetFileSize�Ńt�@�C���T�C�Y���擾.

				// �������m��.
				hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);	// dwFileSize���������m��.

				// ���b�N.
				lpBuf = GlobalLock(hGlobal);	// ���b�N���ă|�C���^�擾.

				// �ǂݍ���.
				ReadFile(hFile, lpBuf, dwFileSize, &dwFileSize, NULL);	// ReadFile�œǂݍ���.

				// ����.
				CloseHandle(hFile);	// �t�@�C���n���h�������.

				// �A�����b�N
				GlobalUnlock(hGlobal);	// �A�����b�N.

				// �O���[�o������������IStream���쐬.
				HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);	// CreateStreamOnHGlobal��pStream��IStream�|�C���^���i�[�����.
				if (SUCCEEDED(hr)){

					// IStream����IPicture�쐬.
					REFIID riid = IID_IPicture;	// riid��IID_IPicture�Ƃ���.
					HRESULT hr = OleLoadPicture(pStream, dwFileSize, FALSE, riid, (LPVOID*)&pPicture);	// OleLoadPicture��IStream����IPicture���擾.
					if (SUCCEEDED(hr)){

						// OLE�n���h���̎擾.
						OLE_HANDLE hOle;	// OLE�n���h��hOle.
						pPicture->get_Handle(&hOle);	// pPicture->get_Handle��hOle���擾.

						// �r�b�g�}�b�v�n���h���ւ̕ϊ�.
						hBitmap = (HBITMAP)hOle;	// HBITMAP�ɃL���X�g�ł���.

						// �r�b�g�}�b�v���.
						BITMAP bitmap;	// BITMAP�\����bitmap.
						GetObject(hBitmap, sizeof(BITMAP), &bitmap);	// GetObject�Ŏ擾.

					}

					// ���.
					pStream->Release();	// IStream�I�u�W�F�N�g�|�C���^�����.

				}

				// ���.
				GlobalFree(hGlobal);	// ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// IPicture�̉��.
				if (pPicture != NULL){	// NULL�łȂ�.
					pPicture->Release();	// pPicture->Release�ŉ��.
					pPicture = NULL;	// NULL�Ŗ��߂�.
				}

				// ���b�Z�[�W���[�v�𔲂���.
				PostQuitMessage(0);	// PostQuitMessage�Ŕ�����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��ʂ̕`���v�����ꂽ��.
		case WM_PAINT:	// ��ʂ̕`���v�����ꂽ��.(uMsg��WM_PAINT�̎�.)

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

				// hBitmap���g�p����悤�Ƀ������f�o�C�X�R���e�L�X�g�ɑI��������.
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObject��hMemDC�Ƀ��[�h�����r�b�g�}�b�vhBitmap��I��������.(����܂Ŏg���Ă����r�b�g�}�b�v�̃n���h�����Ԃ�̂�, hOldBitmap�Ɋi�[.)

				// �摜�̕\��.
				BitBlt(hDC, 0, 0, 640, 480, hMemDC, 0, 0, SRCCOPY);	// BitBlt��hMemDC�̃s�N�Z�����hDC�ɓ]�����邱�Ƃ�, �E�B���h�E�Ƀ��[�h�����摜���\�������.

				// �r�b�g�}�b�v�̏�Ԃ�߂�.
				SelectObject(hMemDC, hOldBitmap);	// �������f�o�C�X�R���e�L�X�g�Ɍ���hOldBitmap�ɖ߂��悤�ɑI��������.

				// �������f�o�C�X�R���e�L�X�g�̔j��
				DeleteDC(hMemDC);	// DeleteDC��hMemDC��j��.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		default:
				
			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}