// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <commctrl.h>	// �R�����R���g���[��

// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�XID

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�A���O�̏���������R�[���o�b�N�֐�DialogProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("ListView_SetItemText");				// �E�B���h�E�N���X����"ListView_SetItemText".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;									// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;											// 0�ł���.
	wc.cbWndExtra = 0;											// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.

		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ListView_SetItemText"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("ListView_SetItemText"), _T("ListView_SetItemText"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"ListView_SetItemText"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ListView_SetItemText"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

	// �E�B���h�E���b�Z�[�W�ɑ΂��鏈��.
	switch (uMsg){	// switch-casa����uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:		// �E�B���h�E�̍쐬���J�n���ꂽ��.(uMsg��WM_CREATE�̎�.)
		
			// WM_CREATE�u���b�N
			{

				// �R�����R���g���[���̏�����
				InitCommonControls();	// InitCommonControls�ŃR�����R���g���[���̏�����.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)

			// WM_DESTROY�u���b�N
			{

				// ���b�Z�[�W���[�v�𔲂���.
				PostQuitMessage(0);	// PostQuitMessage�Ŕ�����.

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
					// Dialog���I�����ꂽ��.
					case ID_DIALOG:

						// ID_DIALOG�u���b�N
						{

							// �ϐ��̐錾
							HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��

							// hInstance���擾
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLong�ŃA�v���P�[�V�����C���X�^���X�n���h�����擾��, hInstance�Ɋi�[.

							// �_�C�A���O�{�b�N�X�̕\��
							DialogBox(hInstance, MAKEINTRESOURCEW(IDD_DIALOG1), hwnd, DialogProc);	// DialogBox�Ń_�C�A���O�{�b�N�X��\��.(�_�C�A���O�̏�����DialogProc�ɏ����Ă���.)

							// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

						// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
						
				}

			}

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

// DialogProc�֐��̒�`
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){	// �_�C�A���O�̏���������R�[���o�b�N�֐�.

	// �ϐ��̐錾.
	static HWND hEdit;
	static TCHAR *ptszBuf = NULL;

	// �_�C�A���O�̃��b�Z�[�W����
	switch (uMsg){	// uMsg�̓��e�Ŕ��f.

		// �_�C�A���O�̏�������.
		case WM_INITDIALOG:	// �_�C�A���O�̏�������.(uMsg��WM_INITDIALOG�̎�.)

			// WM_INITDIALOG�u���b�N
			{

				// �ϐ��̐錾
				LVCOLUMN column1;	// �}������J�������(Name)���i�[����LVCOLUMN�\���̕ϐ�column1.
				LVCOLUMN column2;	// �}������J�������(Address)���i�[����LVCOLUMN�\���̕ϐ�column2.
				LVCOLUMN column3;	// �}������J�������(PhoneNumber)���i�[����LVCOLUMN�\���̕ϐ�column3.
				HWND hList;			// ���X�g�r���[�̃n���h��hList.

				// �J����Name�̐ݒ�.
				column1.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column1.fmt = LVCFMT_LEFT;	// ����
				column1.cx = 100;	// ��100
				column1.pszText = _T("Name");	// ���ږ�"Name"
				column1.iSubItem = 0;	// �T�u�A�C�e���̃C���f�b�N�X��0.

				// �J����Address�̐ݒ�.
				column2.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column2.fmt = LVCFMT_LEFT;	// ����
				column2.cx = 100;	// ��100
				column2.pszText = _T("Address");	// ���ږ�"Address"
				column2.iSubItem = 1;	// �T�u�A�C�e���̃C���f�b�N�X��1.

				// �J����PhoneNumber�̐ݒ�.
				column3.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column3.fmt = LVCFMT_LEFT;	// ����
				column3.cx = 100;	// ��100
				column3.pszText = _T("PhoneNumber");	// ���ږ�"PhoneNumber"
				column3.iSubItem = 2;	// �T�u�A�C�e���̃C���f�b�N�X��2.

				// �J�����̑}��.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.
				ListView_InsertColumn(hList, 0, &column1);	// ListView_InsertColumn��column1�̓��e�̃J������}��.
				ListView_InsertColumn(hList, 1, &column2);	// ListView_InsertColumn��column2�̓��e�̃J������}��.
				ListView_InsertColumn(hList, 2, &column3);	// ListView_InsertColumn��column3�̓��e�̃J������}��.

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}
			
			// ������.
			break;	// break�Ŕ�����.

		// �_�C�A���O������ꂽ��.
		case WM_CLOSE:	// �_�C�A���O������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �I������.
				if (ptszBuf != NULL){	// �o�b�t�@���c���Ă���.
					delete[] ptszBuf;	// delete�ŉ��.
					ptszBuf = NULL;	// �|�C���^��NULL���Z�b�g.
				}

				// �_�C�A���O���I������.
				EndDialog(hwndDlg, IDOK);	// EndDialog�Ń_�C�A���O���I������.

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �R�����R���g���[������ʒm��������.
		case WM_NOTIFY:

			// WM_NOTIFY�u���b�N
			{

				// �ϐ��̐錾�E������
				HWND hList;					// ���X�g�r���[�̃n���h��hList.

				// ���X�g�r���[�̃n���h�����擾.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.

				// ���X�g�r���[�̎�.
				if ((int)wParam == IDC_LIST1){	// wParam��IDC_LIST1�̎�.
					LV_DISPINFO *lvi = (LV_DISPINFO *)lParam;	// lParam��LV_DISPINFO�̃|�C���^�ɕϊ�.
					switch (lvi->hdr.code){	// �ʒm�R�[�h���Ƃɕ�����.
						case LVN_BEGINLABELEDIT:	// �ҏW�J�n.
							// �f�o�b�O�o��.
							OutputDebugString(_T("LVN_BEGINLABELEDIT\n"));	// OutputDebugString��"LVN_BEGINLABELEDIT"���o��.
							hEdit = ListView_GetEditControl(hList);	// ListView_GetEditControl�ŕҏW����v�f�̃G�f�B�b�g�R���g���[���n���h�����擾.
							break;
						case LVN_ENDLABELEDIT:	// �ҏW�I��.

							// LVN_ENDLABELEDIT�u���b�N.
							{

								// �f�o�b�O�o��.
								OutputDebugString(_T("LVN_ENDLABELEDIT\n"));	// OutputDebugString��"LVN_ENDLABELEDIT"���o��.
								if (ptszBuf != NULL){	// �o�b�t�@���c���Ă���.
									delete[] ptszBuf;	// delete�ŉ��.
									ptszBuf = NULL;	// �|�C���^��NULL���Z�b�g.
								}
								int iLen = GetWindowTextLength(hEdit);	// GetWindowTextLength�Ńe�L�X�g�̒������擾.
								ptszBuf = new TCHAR[iLen + 1];	// iLen + 1����TCHAR�z��m��.
								ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));	// ptszBuf�̃N���A.
								GetWindowText(hEdit, ptszBuf, iLen + 1);	// �e�L�X�g�擾.
								ListView_SetItemText(hList, lvi->item.iItem, 0, ptszBuf);	// ListView_SetItemText�Ńe�L�X�g���Z�b�g.
								OutputDebugString(ptszBuf);	// OutputDebugString��ptszBuf���o��.
								OutputDebugString(_T("\n"));	// OutputDebugString�ŉ��s���o��.
								delete[] ptszBuf;	// delete�ŉ��.
								ptszBuf = NULL;	// �|�C���^��NULL���Z�b�g.

							}

							break;

						default:	// ����ȊO.
							break;
					}
				}			

			}

			// ����̏����֌�����.
			break;

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃R���g���[�����𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�ŃR���g���[���̃��\�[�XID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// Button1�̎�.
					case ID_BUTTON1:

						// ID_BUTTON1�u���b�N
						{

							// �ϐ��̐錾�E������.
							HWND hEditName;				// Name����͂���G�f�B�b�g�{�b�N�X�̃n���h��hEditName.
							HWND hEditAddress;			// Address����͂���G�f�B�b�g�{�b�N�X�̃n���h��hEditAddress.
							HWND hEditPhoneNumber;		// PhoneNumber����͂���G�f�B�b�g�{�b�N�X�̃n���h��hEditPhoneNumber.
							TCHAR tszName[64];			// ���O(����64)
							TCHAR tszAddress[128];		// �Z��(����128)
							TCHAR tszPhoneNumber[32];	// �d�b�ԍ�(����32)
							HWND hList;					// ���X�g�r���[�̃n���h��hList.
							LVITEM name = {0};			// ���ڂ��i�[����LVITEM�\���̕ϐ�name��0�ŏ�����.
							LVITEM address = {0};		// ���ڂ��i�[����LVITEM�\���̕ϐ�address��0�ŏ�����.
							LVITEM phonenumber = {0};	// ���ڂ��i�[����LVITEM�\���̕ϐ�phonenumber��0�ŏ�����.

							// �G�f�B�b�g�{�b�N�X�̓��e���擾.
							hEditName = GetDlgItem(hwndDlg, ID_EDIT_NAME);	// GetDlgItem��Name����͂���G�f�B�b�g�{�b�N�X�̃n���h���擾.
							GetWindowText(hEditName, tszName, 64);	// GetWindowText�ŃG�f�B�b�g�{�b�N�X�̓��e��tszName�Ɋi�[.
							hEditAddress = GetDlgItem(hwndDlg, ID_EDIT_ADDRESS);	// GetDlgItem��Address����͂���G�f�B�b�g�{�b�N�X�̃n���h���擾.
							GetWindowText(hEditAddress, tszAddress, 128);	// GetWindowText�ŃG�f�B�b�g�{�b�N�X�̓��e��tszAddress�Ɋi�[.
							hEditPhoneNumber = GetDlgItem(hwndDlg, ID_EDIT_PHONENUMBER);	// GetDlgItem��PhoneNumber����͂���G�f�B�b�g�{�b�N�X�̃n���h���擾.
							GetWindowText(hEditPhoneNumber, tszPhoneNumber, 32);	// GetWindowText�ŃG�f�B�b�g�{�b�N�X�̓��e��tszPhoneNumber�Ɋi�[.

							// LVITEM�\���̕ϐ�name�ɐݒ�.
							name.mask = LVIF_TEXT;	// �\���e�L�X�g�̂݃Z�b�g.
							name.iItem = 0;			// ��ԏォ��}��.
							name.pszText = tszName;	// �\���e�L�X�g��tszName.

							// name�̑}��.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.
							ListView_InsertItem(hList, &name);		// ListView_InsertItem��hList��name��}��.

							// LVITEM�\���̕ϐ�address�ɐݒ�.
							address.mask = LVIF_TEXT;		// �\���e�L�X�g�̂݃Z�b�g.
							address.iItem = 0;				// ��ԏ�̂ɃZ�b�g.
							address.iSubItem = 1;			// 0���琔����1�ԖڂɃZ�b�g.
							address.pszText = tszAddress;	// �\���e�L�X�g��tszAddress.

							// address�̑}��.
							ListView_SetItem(hList, &address);	// ListView_SetItem��hList��address���Z�b�g.

							// LVITEM�\���̕ϐ�phonenumber�ɐݒ�.
							phonenumber.mask = LVIF_TEXT;			// �\���e�L�X�g�̂݃Z�b�g.
							phonenumber.iItem = 0;					// ��ԏ�̂ɃZ�b�g.
							phonenumber.iSubItem = 2;				// 0���琔����2�ԖڂɃZ�b�g.
							phonenumber.pszText = tszPhoneNumber;	// �\���e�L�X�g��tszPhoneNumber.

							// phonenumber�̑}��.
							ListView_SetItem(hList, &phonenumber);	// ListView_SetItem��hList��phonenumber���Z�b�g.

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// Button2�̎�.
					case ID_BUTTON2:

						// ID_BUTTON2�u���b�N
						{

							// �ϐ��̐錾�E������
							HWND hList;					// ���X�g�r���[�̃n���h��hList.
							int idx = -1;				// �I������Ă��鍀�ڂ̃C���f�b�N�X���i�[����int�^�ϐ�idx��-1�ɏ�����.
							TCHAR tszName[256];			// �I���s��Name���i�[����tszName.(����256)
							TCHAR tszAddress[256];		// �I���s��Address���i�[����tszAddress.(����256)
							TCHAR tszPhoneNumber[256];	// �I���s��PhoneNumber���i�[����tszPhoneNumber.(����256)
							HWND hEditName;				// Name�̃G�f�B�b�g�{�b�N�X�̃n���h��hEditName.
							HWND hEditAddress;			// Address�̃G�f�B�b�g�{�b�N�X�̃n���h��hEditAddress.
							HWND hEditPhoneNumber;		// PhoneNumber�̃G�f�B�b�g�{�b�N�X�̃n���h��hEditPhoneNumber.

							// ���X�g�r���[�̃n���h�����擾.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.

							// �I������Ă���s(�ŏ���1�̂�)�̃C���f�b�N�X���擾.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItem�őI�����ڂ̃C���f�b�N�X�擾.

								// �I������Ă���s�̊e�e�L�X�g���擾��, �\��.
								ListView_GetItemText(hList, idx, 0, tszName, 256);				// ListView_GetItemText��i�s�ڂ�0��ڂ̃e�L�X�g��tszName�Ɋi�[.
								hEditName = GetDlgItem(hwndDlg, ID_EDIT_NAME);					// GetDlgItem��ID_EDIT_NAME�̃n���h�����擾.
								SetWindowText(hEditName, tszName);								// SetWindowText�ŃG�f�B�b�g�{�b�N�X�ɃZ�b�g.
								ListView_GetItemText(hList, idx, 1, tszAddress, 256);				// ListView_GetItemText��i�s�ڂ�1��ڂ̃e�L�X�g��tszAddress�Ɋi�[.
								hEditAddress = GetDlgItem(hwndDlg, ID_EDIT_ADDRESS);			// GetDlgItem��ID_EDIT_ADDRESS�̃n���h�����擾.
								SetWindowText(hEditAddress, tszAddress);						// SetWindowText�ŃG�f�B�b�g�{�b�N�X�ɃZ�b�g.
								ListView_GetItemText(hList, idx, 2, tszPhoneNumber, 256);			// ListView_GetItemText��i�s�ڂ�2��ڂ̃e�L�X�g��tszPhoneNumber�Ɋi�[.
								hEditPhoneNumber = GetDlgItem(hwndDlg, ID_EDIT_PHONENUMBER);	// GetDlgItem��ID_EDIT_PHONENUMBER�̃n���h�����擾.
								SetWindowText(hEditPhoneNumber, tszPhoneNumber);				// SetWindowText�ŃG�f�B�b�g�{�b�N�X�ɃZ�b�g.

							}

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// Button3�̎�.
					case ID_BUTTON3:

						// ID_BUTTON3�u���b�N
						{

							// �ϐ��̐錾�E������
							HWND hList;					// ���X�g�r���[�̃n���h��hList.
							int idx = -1;				// �I������Ă��鍀�ڂ̃C���f�b�N�X���i�[����int�^�ϐ�idx��-1�ɏ�����.

							// ���X�g�r���[�̃n���h�����擾.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.

							// �I������Ă���s(�ŏ���1�̂�)�̃C���f�b�N�X���擾.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItem�őI�����ڂ̃C���f�b�N�X�擾.

								// �I������Ă���s�̍폜.
								ListView_DeleteItem(hList, idx);	// ListView_DeleteItem�őI���s�̍폜.

							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// ��L�ȊO�̎�.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �����ɗ���Ƃ��͏����ł��Ă��Ȃ�.
	return FALSE;	// �����ł��Ă��Ȃ��̂�FALSE.

}