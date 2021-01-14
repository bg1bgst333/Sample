// �w�b�_�t�@�C���̃C���N���[�h
// �Ǝ��̃w�b�_�t�@�C��
#include "ParentWindow.h"	// CParentWindow

// �f�X�g���N�^~CParentWindow()
CParentWindow::~CParentWindow(){

	// �I������
	if (m_pChildWindow != NULL){
		delete m_pChildWindow;
		m_pChildWindow = NULL;
	}

}

// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CParentWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

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

					// �q�E�B���h�E�쐬.
					m_pChildWindow = new CChildWindow();	// �I�u�W�F�N�g�쐬.
					m_pChildWindow->Create(_T("CREATESTRUCT"), _T("CREATESTRUCT"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 300, 300, hwnd, (HMENU)WM_APP + 1, lpCreateStruct->hInstance);	// �E�B���h�E�쐬.

				}

				// 0��Ԃ��Đ���.
				return 0;	// 0��Ԃ�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.(����ƃ��b�Z�[�W���[�v��GetMessage�̖߂�l��0�ɂȂ�̂�, ���b�Z�[�W���[�v���甲����.)

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:

			// default�u���b�N
			{

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂߂�DefWindowProc�Ɋ���̏�����C����.

}