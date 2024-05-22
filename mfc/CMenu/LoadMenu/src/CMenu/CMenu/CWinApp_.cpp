// �w�b�_�t�@�C���̃C���N���[�h
#include "CWinApp_.h"	// CWinApp_�N���X
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CWinApp_�̃����o�̒�`
// �����o�֐�InitInstance()
BOOL CWinApp_::InitInstance(){	// �C���X�^���X�̏���������

	// �\���̂̐錾
	WNDCLASS wc = {0};		// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc��{0}�ŏ�����.
	CFrameWnd_ *pFrameWnd_;	// CFrameWnd_�̃I�u�W�F�N�g�|�C���^pFrameWnd_.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("CMenu");							// �E�B���h�E�N���X����"CMenu".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = AfxWndProc;							// MFC����̃E�B���h�E�v���V�[�W��AfxWndProc��ݒ�.
	wc.hInstance = AfxGetInstanceHandle();					// AfxGetInstanceHandle�Ŏ擾�������݂̃C���X�^���X�n���h��.
	wc.hIcon = LoadIcon(IDI_APPLICATION);					// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(IDC_ARROW);						// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = NULL;									// ���j���[�͂Ȃ�.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	AfxRegisterClass(&wc);	// AfxRegisterClass�ŃE�B���h�E�N���X��o�^.

	// CFrameWnd_�̃C���X�^���X�쐬
	pFrameWnd_ = new CFrameWnd_();	// new��CFrameWnd_�̃C���X�^���X���쐬��, pFrameWnd_�Ɋi�[.
	m_pMainWnd = pFrameWnd_;		// m_pMainWnd��pFrameWnd_���Z�b�g.

	// CFrameWnd_�̍쐬
	RECT rc = {0, 0, 640, 480};
	pFrameWnd_->Create(_T("CMenu"), _T("CMenu"), WS_OVERLAPPEDWINDOW, rc, NULL, NULL);	// CFrameWnd::Create��pFrameWnd_�̃C���X�^���X�̃E�B���h�E���쐬.

	// CFrameWnd_�̕\��
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindow�ŃE�B���h�E��\��.

	// CFrameWnd�̍X�V
	pFrameWnd_->UpdateWindow();	// UpdateWindow�ŃE�B���h�E���X�V.

	// ����������
	return TRUE;	// �����������Ȃ�TRUE��Ԃ�.

}