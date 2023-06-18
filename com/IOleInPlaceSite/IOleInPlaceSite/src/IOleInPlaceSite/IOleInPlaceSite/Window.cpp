// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// �E�B���h�E�}�b�vm_mapWindowMap.
std::map<DWORD, HandlerConditions *> CWindow::m_mapHandlerMap;	// �n���h���}�b�vm_mapHandlerMap.

// �R���X�g���N�^CWindow()
CWindow::CWindow(){

	// �����o�̏�����.
	m_hWnd = NULL;	// m_hWnd��NULL�ŏ�����.

}

// �f�X�g���N�^~CWindow()
CWindow::~CWindow(){

	// �����o�̏I������.
	Destroy();	// Destroy���Ă�.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// ���j���[����NULL.
	return RegisterClass(hInstance, lpctszClassName, NULL);	// RegisterClass(���j���[���w��o�[�W����)�̃��j���[����NULL���w��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[���w��o�[�W����)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpctszMenuName){

	// �ϐ��E�\���̂̐錾
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc.

	// �E�B���h�E�N���X�\����wc�Ƀp�����[�^���Z�b�g.
	wc.lpszClassName = lpctszClassName;	// �E�B���h�E�N���X����lpctszClassName���Z�b�g����.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW�Ƃ���.
	wc.lpfnWndProc = StaticWindowProc;	// �E�B���h�E�v���V�[�W���ɂ͉��Œ�`����StaticWindowProc���w�肷��.
	wc.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject�Ŕ��u���V��w�i�Ƃ���.
	wc.lpszMenuName = lpctszMenuName;	// ���j���[�ɂ�lpctszMenuName���Z�b�g.
	wc.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wc.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!::RegisterClass(&wc)){	// WindowsAPI��RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �o�^�����Ȃ̂�TRUE.
	return TRUE;	// return��TRUE��Ԃ�.

}

// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc�֐��̒�`
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����.
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�ւ̃|�C���^lpCreateStruct��NULL.

				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�^�ɃL���X�g����lpCreateStruct�Ɋi�[.
				if (lpCreateStruct != NULL){	// lpCreateStruct��NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��CWindow�I�u�W�F�N�g�|�C���^�ɃL���X�g��, pWindow�Ɋi�[.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:

			// default�u���b�N
			{

				// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

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

// �E�B���h�E�쐬�֐�Create.
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.(�Ō�̈����ɃI�u�W�F�N�g���g�̃|�C���^this��n��.)
	if (m_hWnd == NULL){	// m_hWnd��NULL�Ȃ玸�s.

		// m_hWnd��NULL�Ȃ�E�B���h�E�쐬���s�Ȃ̂ŃG���[����.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�쐬�����Ȃ̂�TRUE.
	return TRUE;	// return��TRUE��Ԃ�.

}

// �E�B���h�E�쐬�֐�Create.(RECT�o�[�W����.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// RECT�Ŏw�肳�ꂽ�T�C�Y��x, y, iWidth, iHeight�ɕϊ�.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃE�B���h�E�쐬.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)

	// �E�B���h�E�N���X����"CWindow".
	return CWindow::Create(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CWindow"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CWindow::Destroy(){

	// �ϐ��̏�����.
	BOOL bDestroy = FALSE;	// �j���ɐ������ǂ���������bDestroy��FALSE�ɏ�����.

	// �j������.
	if (m_hWnd != NULL){	// m_hWnd��NULL�łȂ���.
		bDestroy = DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
		if (bDestroy){	// TRUE�Ȃ�.
			m_hWnd = NULL;	// m_hWnd��NULL���Z�b�g.
			return bDestroy;	// bDestroy��Ԃ�.
		}
	}

	// ���ʂ�Ȃ�(�j�����������Ȃ�����)�̂�FALSE.
	return FALSE;	// return��FALSE��Ԃ�.

}

// �q�E�B���h�E�j���֐�DestroyChildren
BOOL CWindow::DestroyChildren(){

	// �����ł͉�������, ���FALSE��Ԃ�.
	return FALSE;

}

// �E�B���h�E�\���֐�ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��.
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// �R�}���h�n���h���̒ǉ�.
void CWindow::AddCommandHandler(UINT nID, UINT nCode, int(CWindow:: * handler)(WPARAM wParam, LPARAM lParam)){

	// HandlerConditions�̐����ƒǉ�.
	HandlerConditions *pCond = new HandlerConditions();	// HandlerConditions�I�u�W�F�N�g���쐬��, �|�C���^��pCond�Ɋi�[.
	pCond->m_nID = nID;	// pCond->m_nID��nID���i�[.
	pCond->m_nCode = nCode;	// pCond->m_nCode��nCode���i�[.
	pCond->m_fpHandler = handler;	// pCond->m_fpHandler��handler���i�[.
	m_mapHandlerMap.insert(std::pair<DWORD, HandlerConditions *>((DWORD)MAKEWPARAM(nID, nCode), pCond));	// m_mapHandlerMap.insert��nID, nCode��MAKEWPARAM�������̂��L�[, pCond��l�Ƃ��ēo�^.

}

// �R�}���h�n���h���̍폜.
void CWindow::DeleteCommandHandler(UINT nID, UINT nCode){

	// �n���h���}�b�v����w��̃n���h�������폜.
	HandlerConditions *pCond = NULL;	// HandlerConditions�I�u�W�F�N�g�|�C���^pCond��NULL�ɏ�����.
	std::map<DWORD, HandlerConditions *>::iterator itor = m_mapHandlerMap.find((DWORD)(MAKEWPARAM(nID, nCode)));	// find�ŃL�[��(DWORD)(MAKEWPARAM(nID, nCode))�Ƃ���HandlerConditions�I�u�W�F�N�g�|�C���^�̃C�e���[�^���擾.
	if (itor != m_mapHandlerMap.end()){	// ����������.
		pCond = m_mapHandlerMap[(DWORD)(MAKEWPARAM(nID, nCode))];	// (DWORD)(MAKEWPARAM(nID, nCode))���g���ăn���h���}�b�v����HandlerConditions�I�u�W�F�N�g�|�C���^�������o��.
		delete pCond;	// HandlerConditions�I�u�W�F�N�g��j��.
		m_mapHandlerMap.erase(itor);	// itor�̎w���v�f���폜.
	}

}

// �e�L�X�g���擾.
int CWindow::GetWindowText(LPTSTR lptszStringBuf, int nMaxCount) const {

	// �w�肳�ꂽ�E�B���h�E�̃e�L�X�g���擾����.
	return ::GetWindowText(m_hWnd, lptszStringBuf, nMaxCount);	// Win32API��GetWindowText�Ńe�L�X�g���擾����, �߂�l��Ԃ�.

}

// �e�L�X�g���擾.(tstring�̎Q�ƃo�[�W����.)
void CWindow::GetWindowText(tstring& rString) const{

	// �e�L�X�g�̒������擾.
	int iLen = GetWindowTextLength();	// CWindow::GetWindowTextLength�Œ������擾.

	// �o�b�t�@���m��.
	TCHAR *ptszBuf = new TCHAR[iLen + 1];	// TCHAR�o�b�t�@ptszBuf(����iLen + 1)���m��.
	ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));	// ptszBuf�̏�����.

	// �e�L�X�g���擾.
	GetWindowText(ptszBuf, iLen + 1);	// CWindow::GetWindowText�Ńe�L�X�g���擾.

	// �n���ꂽ�Q��rString�Ɋi�[.
	rString = ptszBuf;	// rString��ptszBuf���R�s�[.

	// �o�b�t�@�����.
	delete [] ptszBuf;	// delete[]��ptszBuf�����.

}

// �e�L�X�g�̒������擾.
int CWindow::GetWindowTextLength() const {
	
	// �w�肳�ꂽ�E�B���h�E�̃e�L�X�g�̒������擾���ĕԂ�.
	return ::GetWindowTextLength(m_hWnd);	// Win32API��GetWindowTextLength�Œ������擾���Ă��̂܂ܕԂ�.

}

// �e�L�X�g�̐ݒ�.
void CWindow::SetWindowText(LPCTSTR lpctszString){

	// �w�肳�ꂽ�E�B���h�E�e�L�X�g��ݒ肷��.
	::SetWindowText(m_hWnd, lpctszString);	// Win32API��SetWindowText��lpctszString���Z�b�g.

}

// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// OnCreate�ɔC����.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwnd��lParam��OnCreate�ɓn��, ���Ƃ͔C����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		case WM_SIZE:

			// WM_SIZE�u���b�N
			{

				// OnSize�ɔC����.
				OnSize((UINT)wParam, LOWORD(lParam), HIWORD(lParam));	// OnSize�ɔC����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�̕`���v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// OnPaint�ɔC����.
				OnPaint();	// OnPaint���Ă�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�������鎞.
		case WM_CLOSE:

			// WM_CLOSE�u���b�N
			{

				// OnClose�ɔC����.
				if (OnClose() != 0){	// 0�ȊO�Ȃ�.
					return 0;	// 0��Ԃ�.(���Ȃ��Ȃ�.)
				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �����X�N���[���o�[���X�N���[�����ꂽ��.
		case WM_HSCROLL:	// �����X�N���[���o�[���X�N���[�����ꂽ��.(uMsg��WM_HSCROLL�̎�.)

			// WM_HSCROLL�u���b�N
			{

				// OnHScroll�ɔC����.
				OnHScroll(LOWORD(wParam), HIWORD(wParam));	// OnHScroll�ɔC����.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �����X�N���[���o�[���X�N���[�����ꂽ��.
		case WM_VSCROLL:	// �����X�N���[���o�[���X�N���[�����ꂽ��.(uMsg��WM_VSCROLL�̎�.)

			// WM_VSCROLL�u���b�N
			{

				// OnVScroll�ɔC����.
				OnVScroll(LOWORD(wParam), HIWORD(wParam));	// OnVScroll�ɔC����.

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

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CWindow::OnDestroy(){

	// �E�B���h�E�n���h����NULL.
	m_hWnd = NULL;	// NULL���Z�b�g.

	// �I�����b�Z�[�W�̑��M.
	PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CWindow::OnPaint(){

}

// �E�B���h�E�������鎞.
int CWindow::OnClose(){

	// �q�E�B���h�E�̔j��.
	DestroyChildren();	// DestroyChildren�Ŏq�E�B���h�E�̔j��.

	// ��ɕ�����̂Ƃ���.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}

// �R�}���h������������.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// wParam����n���h�����������o��.
	HandlerConditions *pCond = NULL;	// HandlerConditions�I�u�W�F�N�g�|�C���^pCond��NULL�ɏ�����.
	if (m_mapHandlerMap.find((const unsigned long)wParam) != m_mapHandlerMap.end()){	// find�ŃL�[��wParam�Ƃ���HandlerConditions�I�u�W�F�N�g�|�C���^������������.
		pCond = m_mapHandlerMap[(const unsigned long)wParam];	// wParam�ŃL�[���擾�ł���̂�, ������g���ăn���h���}�b�v����HandlerConditions�I�u�W�F�N�g�|�C���^�������o��.
	}
	if (pCond != NULL){	// pCond��NULL�łȂ��Ȃ�, �n���h���o�^����Ă���.
		int iRet = (this->*pCond->m_fpHandler)(wParam, lParam);	// �o�^�����n���h��pCond->m_fpHandler���Ăяo��, �߂�l��iRet�Ɋi�[.
		if (iRet == 0){	// 0�Ȃ珈��������.
			return TRUE;	// �����������̂�TRUE.
		}
	}

	// �������Ă��Ȃ��̂�FALSE.
	return FALSE;	// return��FALSE��Ԃ�.

}

// ���������X�N���[���o�[�C�x���g��.
void CWindow::OnHScroll(UINT nSBCode, UINT nPos){

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfo��scrHorz���擾.

	// �܂݂̍ő�ʒu���v�Z.
	int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

	// �ʒm�R�[�h����
	switch (nSBCode){	// �ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

		// 1�ԍ�
		case SB_LEFT:

			// 1�ԍ��ɃZ�b�g.
			scrHorz.nPos = scrHorz.nMin;	// ���݈ʒu��1�ԍ��ɃZ�b�g.
			break;	// ������.

		// 1�ԉE
		case SB_RIGHT:

			// 1�ԉE�ɃZ�b�g.
			scrHorz.nPos = scrHorz.nMax;	// ���݈ʒu��1�ԉE�ɃZ�b�g.
			break;	// ������.

		// 1��
		case SB_LINELEFT:

			// 1�񍶂ɖ߂�.
			if (scrHorz.nPos > scrHorz.nMin){	// scrHorz.nPos��scrHorz.nMin���傫���ꍇ.
				scrHorz.nPos--;	// 1�߂�.
			}
			break;	// ������.

		// 1��E
		case SB_LINERIGHT:

			// 1��E�ɐi�߂�.
			if (scrHorz.nPos < iMaxPos){	// scrHorz.nPos��iMaxPos��菬�����ꍇ.
				scrHorz.nPos++;	// 1�i��.
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGELEFT:

			// SB_PAGELEFT�u���b�N.
			{

				// 1�y�[�W�߂�.
				int after = scrHorz.nPos - scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after >= scrHorz.nMin){	// ���[�𒴂��ĂȂ����.
					scrHorz.nPos -= scrHorz.nPage;	// 1�y�[�W���}�C�i�X.
				}
				else{	// ���[�𒴂�����.
					scrHorz.nPos = scrHorz.nMin;	// �ŏ��l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// 1�y�[�W�E
		case SB_PAGERIGHT:

			// SB_PAGERIGHT�u���b�N.
			{

				// 1�y�[�W�i��.
				int after = scrHorz.nPos + scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after <= iMaxPos){	// �E�[�𒴂��ĂȂ����.
					scrHorz.nPos += scrHorz.nPage;	// 1�y�[�W���v���X.
				}
				else{	// �E�[�𒴂�����.
					scrHorz.nPos = scrHorz.nMax;	// �ő�l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X�N���[���܂݂������ꂽ��.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITION�u���b�N.
			{

				// �����ꂽ�ʒu���Z�b�g.
				int before = scrHorz.nPos;	// �ȑO.
				int after = nPos;	// �Ȍ�.
				scrHorz.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrHorz.nPos�ɃZ�b�g.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// scrHorz.nPos��hwnd��SB_HORZ�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfo�Ō��݂�scrHorz.nPos��m_hWnd�ɃZ�b�g.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈���쐬.(NULL�Ȃ̂őS�̂������̈�.)
	UpdateWindow(m_hWnd);	// UpdateWindow�ŃE�B���h�E�̍X�V.

}

// ���������X�N���[���o�[�C�x���g��.
void CWindow::OnVScroll(UINT nSBCode, UINT nPos){

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfo��scrVert���擾.

	// �܂݂̍ő�ʒu���v�Z.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

	// �ʒm�R�[�h����
	switch (nSBCode){	// �ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

		// 1�ԏ�
		case SB_TOP:

			// 1�ԏ�ɃZ�b�g.
			scrVert.nPos = scrVert.nMin;	// ���݈ʒu��1�ԏ�ɃZ�b�g.
			break;	// ������.

		// 1�ԉ�
		case SB_BOTTOM:

			// 1�ԉ��ɃZ�b�g.
			scrVert.nPos = scrVert.nMax;	// ���݈ʒu��1�ԉ��ɃZ�b�g.
			break;	// ������.

		// 1���
		case SB_LINEUP:

			// 1���ɖ߂�.
			if (scrVert.nPos > scrVert.nMin){	// scrVert.nPos��scrVert.nMin���傫���ꍇ.
				scrVert.nPos--;	// 1�߂�.
			}
			break;	// ������.

		// 1��
		case SB_LINEDOWN:

			// 1�񉺂ɐi�߂�.
			if (scrVert.nPos < iMaxPos){	// scrVert.nPos��iMaxPos��菬�����ꍇ.
				scrVert.nPos++;	// 1�i��.
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGEUP:

			// SB_PAGEUP�u���b�N.
			{

				// 1�y�[�W�߂�.
				int after = scrVert.nPos - scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after >= scrVert.nMin){	// �����𒴂��ĂȂ����.
					scrVert.nPos -= scrVert.nPage;	// 1�y�[�W���}�C�i�X.
				}
				else{	// �����𒴂�����.
					scrVert.nPos = scrVert.nMin;	// �ŏ��l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// 1�y�[�W��
		case SB_PAGEDOWN:

			// SB_PAGEDOWN�u���b�N.
			{

				// 1�y�[�W�i��.
				int after = scrVert.nPos + scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after <= iMaxPos){	// ����𒴂��ĂȂ����.
					scrVert.nPos += scrVert.nPage;	// 1�y�[�W���v���X.
				}
				else{	// ����𒴂�����.
					scrVert.nPos = scrVert.nMax;	// �ő�l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X�N���[���܂݂������ꂽ��.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITION�u���b�N.
			{

				// �����ꂽ�ʒu���Z�b�g.
				int before = scrVert.nPos;	// �ȑO.
				int after = nPos;	// �Ȍ�.
				scrVert.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrVert.nPos�ɃZ�b�g.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// scrVert.nPos��hwnd��SB_VERT�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfo�Ō��݂�scrVert.nPos��m_hWnd�ɃZ�b�g.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈���쐬.(NULL�Ȃ̂őS�̂������̈�.)
	UpdateWindow(m_hWnd);	// UpdateWindow�ŃE�B���h�E�̍X�V.

}