// �w�b�_�t�@�C���̃C���N���[�h
// �Ǝ��̃w�b�_�t�@�C��
#include "ParentWindow.h"	// CParentWindow

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	MSG msg;			// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

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

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬.
	CParentWindow *pParentWindow = new CParentWindow();	// CParentWindow�I�u�W�F�N�g���쐬��, pParentWindow�Ɋi�[.
	BOOL bRet = pParentWindow->Create(_T("CREATESTRUCT"), _T("CREATESTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance);	// pParentWindow->Create�ŃE�B���h�E�쐬.
	if (!bRet){	// ���s.
		delete pParentWindow;	// pParentWindow�̔j��.
		MessageBox(NULL, _T("CParentWindow::Create Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBox��"CParentWindow::Create Failure!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(2)

	}

	// �E�B���h�E�̕\��.
	ShowWindow(pParentWindow->m_hWnd, SW_SHOW);	// ShowWindow��pWindow->m_hWnd��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.

		// �E�B���h�E���b�Z�[�W����
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

	}

	// �E�B���h�E�̏I������.
	delete pParentWindow;	// pParentWindow�̔j��.

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// �E�B���h�E�v���V�[�W��WindowProc�̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����.
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		
		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�\���̂ւ̃|�C���^lpCreateStruct��NULL.
				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�^�ɃL���X�g����lpCreateStruct�Ɋi�[.
				if (lpCreateStruct != NULL){	// lpCreateStruct��NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��CWindow�I�u�W�F�N�g�|�C���^�ɃL���X�g��, pWindow�Ɋi�[.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ����Ċ���̏����֌�����.

		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

				// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ����Ċ���̏����֌�����.

	}

	// CWindow�I�u�W�F�N�g�|�C���^���擾�ł��Ȃ������ꍇ, �擾�ł����ꍇ�ŕ�����.
	if (pWindow == NULL){	// pWindow��NULL

		// DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�Ɉ��������̂܂ܓn����, DefWindowProc�̖߂�l�����̂܂ܕԂ�.

	}
	else{	// pWindow��NULL�łȂ���.

		// ����CWindow�I�u�W�F�N�g��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�Ɉ��������̂܂ܓn����, DynamicWindowProc�̖߂�l�����̂܂ܕԂ�.

	}

}