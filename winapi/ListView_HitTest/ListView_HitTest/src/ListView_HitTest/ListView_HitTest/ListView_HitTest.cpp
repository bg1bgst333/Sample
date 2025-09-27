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
int CALLBACK CompProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParam3);	// �\�[�g�̒l��r�p�v���V�[�W��.
// �O���[�o���ϐ��̐錾
BYTE g_btAsc[4] = {0};
HWND g_hwndDlg = NULL;

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��̐錾
	HWND hWnd;					// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;					// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;				// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("ListView_HitTest");					// �E�B���h�E�N���X����"ListView_HitTest".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ListView_HitTest"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("ListView_HitTest"), _T("ListView_HitTest"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"ListView_HitTest"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ListView_HitTest"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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
	static HIMAGELIST hSmall = NULL;
	static HBITMAP hBitmap1 = NULL;
	static HBITMAP hBitmap2 = NULL;

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
				LVCOLUMN column4;	// �}������J�������(Age)���i�[����LVCOLUMN�\���̕ϐ�column4.
				HWND hList;			// ���X�g�r���[�̃n���h��hList.

				// �O���[�o���ɑ��.
				g_hwndDlg = hwndDlg;

				// �J����Name�̐ݒ�.
				column1.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column1.fmt = LVCFMT_LEFT;	// ����
				column1.cx = 80;	// ��80
				column1.pszText = _T("Name");	// ���ږ�"Name"
				column1.iSubItem = 0;	// �T�u�A�C�e���̃C���f�b�N�X��0.

				// �J����Address�̐ݒ�.
				column2.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column2.fmt = LVCFMT_LEFT;	// ����
				column2.cx = 80;	// ��80
				column2.pszText = _T("Address");	// ���ږ�"Address"
				column2.iSubItem = 1;	// �T�u�A�C�e���̃C���f�b�N�X��1.

				// �J����PhoneNumber�̐ݒ�.
				column3.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column3.fmt = LVCFMT_LEFT;	// ����
				column3.cx = 80;	// ��80
				column3.pszText = _T("PhoneNumber");	// ���ږ�"PhoneNumber"
				column3.iSubItem = 2;	// �T�u�A�C�e���̃C���f�b�N�X��2.

				// �J����Age�̐ݒ�.
				column4.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// ���̃J�����ɂ�, ��̌`��, ��̕�, �e�L�X�g, �T�u�A�C�e���̃C���f�b�N�X���Z�b�g����.
				column4.fmt = LVCFMT_LEFT;	// ����
				column4.cx = 80;	// ��80
				column4.pszText = _T("Age");	// ���ږ�"Age"
				column4.iSubItem = 3;	// �T�u�A�C�e���̃C���f�b�N�X��3.

				// �J�����̑}��.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.
				ListView_InsertColumn(hList, 0, &column1);	// ListView_InsertColumn��column1�̓��e�̃J������}��.
				ListView_InsertColumn(hList, 1, &column2);	// ListView_InsertColumn��column2�̓��e�̃J������}��.
				ListView_InsertColumn(hList, 2, &column3);	// ListView_InsertColumn��column3�̓��e�̃J������}��.
				ListView_InsertColumn(hList, 3, &column4);	// ListView_InsertColumn��column4�̓��e�̃J������}��.

				// �C���[�W���X�g�̍쐬.
				HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);
				hSmall = ImageList_Create(16, 16, ILC_COLOR24, 2, 1);
				ListView_SetImageList(hList, hSmall, LVSIL_SMALL);
				hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("image1s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("image2s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				ImageList_Add(hSmall, hBitmap1, NULL);
				ImageList_Add(hSmall, hBitmap2, NULL);

				// LVITEM�\���̕ϐ�name�ɐݒ�.
				LVITEM name = {0};
				name.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
				name.iItem = 0;			// ��ԏォ��}��.
				name.iSubItem = 0;
				name.pszText = _T("Taro");	// �\���e�L�X�g��"Taro".
				name.iImage = 0;
				name.lParam = name.iItem;	// �\�[�g�p.
				ListView_InsertItem(hList, &name);		// ListView_InsertItem��hList��name��}��.
				// LVITEM�\���̕ϐ�address�ɐݒ�.
				LVITEM address = {0};
				address.mask = LVIF_TEXT;		// �T�u�A�C�e����LVIF_PARAM�����Ă͂����Ȃ�!
				address.iItem = 0;				// ��ԏ�̂ɃZ�b�g.
				address.iSubItem = 1;			// 0���琔����1�ԖڂɃZ�b�g.
				address.pszText = _T("Tokyo");	// �\���e�L�X�g��"Tokyo".
				address.lParam = address.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &address);	// ListView_SetItem��hList��address���Z�b�g.
				// LVITEM�\���̕ϐ�phonenumber�ɐݒ�.
				LVITEM phonenumber = {0};
				phonenumber.mask = LVIF_TEXT;
				phonenumber.iItem = 0;					// ��ԏ�̂ɃZ�b�g.
				phonenumber.iSubItem = 2;				// 0���琔����2�ԖڂɃZ�b�g.
				phonenumber.pszText = _T("11111111");	// �\���e�L�X�g��"11111111".
				phonenumber.lParam = phonenumber.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItem��hList��phonenumber���Z�b�g.
				// LVITEM�\���̕ϐ�age�ɐݒ�.
				LVITEM age = {0};
				age.mask = LVIF_TEXT;
				age.iItem = 0;	// ��ԏ�̂ɃZ�b�g.
				age.iSubItem = 3;	// 0���琔����3�ԖڂɃZ�b�g.
				age.pszText = _T("30");	// �\���e�L�X�g��"30".
				age.lParam = age.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &age);	// ListView_SetItem��hList��age���Z�b�g.

				// LVITEM�\���̕ϐ�name�ɐݒ�.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
				name.iItem = 1;			// ��Ԗڂ���}��.
				name.iSubItem = 0;
				name.pszText = _T("Jiro");	// �\���e�L�X�g��"Jiro".
				name.iImage = 1;
				name.lParam = name.iItem;	// �\�[�g�p.
				ListView_InsertItem(hList, &name);		// ListView_InsertItem��hList��name��}��.
				// LVITEM�\���̕ϐ�address�ɐݒ�.
				ZeroMemory(&address, sizeof(address));
				address.mask = LVIF_TEXT;
				address.iItem = 1;				// ��ԖڂɃZ�b�g.
				address.iSubItem = 1;			// 0���琔����1�ԖڂɃZ�b�g.
				address.pszText = _T("Osaka");	// �\���e�L�X�g��"Osaka".
				address.lParam = address.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &address);	// ListView_SetItem��hList��address���Z�b�g.
				// LVITEM�\���̕ϐ�phonenumber�ɐݒ�.
				ZeroMemory(&phonenumber, sizeof(phonenumber));
				phonenumber.mask = LVIF_TEXT;
				phonenumber.iItem = 1;					// ��ԖڃZ�b�g.
				phonenumber.iSubItem = 2;				// 0���琔����2�ԖڂɃZ�b�g.
				phonenumber.pszText = _T("22222222");	// �\���e�L�X�g��"22222222".
				phonenumber.lParam = phonenumber.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItem��hList��phonenumber���Z�b�g.
				// LVITEM�\���̕ϐ�age�ɐݒ�.
				ZeroMemory(&age, sizeof(age));
				age.mask = LVIF_TEXT;
				age.iItem = 1;	// ��ԖڂɃZ�b�g.
				age.iSubItem = 3;	// 0���琔����3�ԖڂɃZ�b�g.
				age.pszText = _T("28");	// �\���e�L�X�g��"28".
				age.lParam = age.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &age);	// ListView_SetItem��hList��age���Z�b�g.

				// LVITEM�\���̕ϐ�name�ɐݒ�.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
				name.iItem = 2;			// �O�Ԗڂ���}��.
				name.iSubItem = 0;
				name.pszText = _T("Saburo");	// �\���e�L�X�g��"Saburo".
				name.iImage = 0;
				name.lParam = name.iItem;	// �\�[�g�p.
				ListView_InsertItem(hList, &name);		// ListView_InsertItem��hList��name��}��.
				// LVITEM�\���̕ϐ�address�ɐݒ�.
				ZeroMemory(&address, sizeof(address));
				address.mask = LVIF_TEXT;
				address.iItem = 2;				// �O�Ԗڂ���}��.
				address.iSubItem = 1;			// 0���琔����1�ԖڂɃZ�b�g.
				address.pszText = _T("Nagoya");	// �\���e�L�X�g��"Nagoya".
				address.lParam = address.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &address);	// ListView_SetItem��hList��address���Z�b�g.
				// LVITEM�\���̕ϐ�phonenumber�ɐݒ�.
				ZeroMemory(&phonenumber, sizeof(phonenumber));
				phonenumber.mask = LVIF_TEXT;
				phonenumber.iItem = 2;					// �O�Ԗڂ���}��..
				phonenumber.iSubItem = 2;				// 0���琔����2�ԖڂɃZ�b�g.
				phonenumber.pszText = _T("33333333");	// �\���e�L�X�g��"33333333".
				phonenumber.lParam = phonenumber.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItem��hList��phonenumber���Z�b�g.
				// LVITEM�\���̕ϐ�age�ɐݒ�.
				ZeroMemory(&age, sizeof(age));
				age.mask = LVIF_TEXT;
				age.iItem = 2;	// �O�ԖڂɃZ�b�g.
				age.iSubItem = 3;	// 0���琔����3�ԖڂɃZ�b�g.
				age.pszText = _T("26");	// �\���e�L�X�g��"26".
				age.lParam = age.iItem;	// �\�[�g�p.
				ListView_SetItem(hList, &age);	// ListView_SetItem��hList��age���Z�b�g.

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}
			
			// ������.
			break;	// break�Ŕ�����.

		// �_�C�A���O������ꂽ��.
		case WM_CLOSE:	// �_�C�A���O������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �r�b�g�}�b�v�̔j��.
				if (hBitmap2 != NULL){
					DeleteObject(hBitmap2);
					hBitmap2 = NULL;
				}
				if (hBitmap1 != NULL){
					DeleteObject(hBitmap1);
					hBitmap1 = NULL;
				}
				// �C���[�W���X�g�̔j��.
				if (hSmall != NULL){
					ImageList_Destroy(hSmall);
					hSmall = NULL;
				}

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
						case LVN_COLUMNCLICK:	// �J�����N���b�N.

							// LVN_COLUMNCLICK�u���b�N.
							{

								// �f�o�b�O�o��
								OutputDebugString(_T("LVN_COLUMNCLICK\n"));	// OutputDebugString��"OutputDebugString"���o��.
								NM_LISTVIEW *pNMLV = (NM_LISTVIEW *)lParam;
								if (g_btAsc[pNMLV->iSubItem] == 1){
									g_btAsc[pNMLV->iSubItem] = 0;
								}
								else{
									g_btAsc[pNMLV->iSubItem] = 1;
								}
								ListView_SortItems(hList, CompProc, pNMLV->iSubItem);	// ListView_SortItems�Ń\�[�g.

							}

							break;
						default:	// ����ȊO.
							break;
					}
				}			

			}

			// ����̏����֌�����.
			break;

		// �R���e�L�X�g���j���[�̕\����v�����ꂽ��.
		case WM_CONTEXTMENU:

			// WM_CONTEXTMENU�u���b�N
			{

				// �ϐ��E�\���̂̐錾
				HWND hList;					// ���X�g�r���[�̃n���h��hList.
				LV_HITTESTINFO lvhti;	// LV_HITTESTINFO�\����lvhti.

				// ���X�g�r���[�̃n���h�����擾.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.

				// �X�N���[�����W�̎擾�Əo��.
				lvhti.pt.x = LOWORD(lParam);
				lvhti.pt.y = HIWORD(lParam);
				TCHAR tszScreenXY[256] = {0};
				_stprintf(tszScreenXY, _T("Screen: x = %d, y = %d\n"), lvhti.pt.x, lvhti.pt.y);
				OutputDebugString(tszScreenXY);

				// �X�N���[�����W����N���C�A���g���W�ւ̕ϊ��Əo��.
				ScreenToClient(hList, &lvhti.pt);	// ScreenToClient�ō��W�ϊ�.
				TCHAR tszClientXY[256] = {0};
				_stprintf(tszClientXY, _T("Client: x = %d, y = %d\n"), lvhti.pt.x, lvhti.pt.y);
				OutputDebugString(tszClientXY);

				// �ǂ̃A�C�e�����E�N���b�N���ꂽ�����ׂ�.
				int i = ListView_HitTest(hList, &lvhti);	// ListView_HitTest�ŉE�N���b�N���ꂽ�A�C�e���̈ʒu���擾.
				if (i != -1){	// �ǂꂩ���I������Ă���.
					
					// hInstance���擾.
					HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);	// GetWindowLong�ŃA�v���P�[�V�����C���X�^���X�n���h�����擾��, hInstance�Ɋi�[.

					// �R���e�L�X�g���j���[�̕\��.
					HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_CONTEXTMENU));
					HMENU hSub = GetSubMenu(hMenu, 0);
					TrackPopupMenu(hSub, TPM_RIGHTBUTTON, LOWORD(lParam), HIWORD(lParam), 0, hwndDlg, NULL);
					DestroyMenu(hMenu);

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

					// Button3�܂��̓R���e�L�X�g���j���[��Delete�̎�.
					case ID_BUTTON3:
					case ID_DELETE_ITEM:

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
								ListView_Arrange(hList, LVA_ALIGNLEFT);	// ListView_Arrange�ō����琮��.

							}

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// Button4�̎�.
					case ID_BUTTON4:

						// ID_BUTTON4�u���b�N
						{

							// �ϐ��̐錾�E������
							HWND hList;					// ���X�g�r���[�̃n���h��hList.
							int idx = -1;				// �I������Ă��鍀�ڂ̃C���f�b�N�X���i�[����int�^�ϐ�idx��-1�ɏ�����.

							// ���X�g�r���[�̃n���h�����擾.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItem��IDC_LIST1�̃n���h���擾.

							// �I������Ă���s(�ŏ���1�̂�)�̃C���f�b�N�X���擾.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItem�őI�����ڂ̃C���f�b�N�X�擾.
								SetFocus(hList);	// ���ꂪ�Ȃ��ƃt�H�[�J�X�O��Ă�̂ŕҏW��ԂɂȂ�Ȃ�.
								ListView_EditLabel(hList, idx);	// ListView_EditLabel�ŕҏW��Ԃɂ���.
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

// �\�[�g�̒l��r�p�v���V�[�W��.
int CALLBACK CompProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParam3){

	// �ϐ��̐錾
	static LV_FINDINFO lvfi;
	static int iItem1, iItem2;
	static TCHAR tszBuf1[256], tszBuf2[256];

	// �f�o�b�O�o��
	OutputDebugString(_T("CompProc\n"));	// OutputDebugString��"CompProc"���o��.

	// ���X�g�r���[�n���h���擾.
	HWND hList = GetDlgItem(g_hwndDlg, IDC_LIST1);

	// 1�ڂ̃A�C�e���T��.
	lvfi.flags = LVFI_PARAM;
	lvfi.lParam = lParam1;
	iItem1 = ListView_FindItem(hList, -1, &lvfi);	// ListView_FindItem�ŃA�C�e���T��.

	// 2�ڂ̃A�C�e���T��.
	lvfi.lParam = lParam2;
	iItem2 = ListView_FindItem(hList, -1, &lvfi);	// ListView_FindItem�ŃA�C�e���T��.

	// �e�L�X�g�擾.
	ListView_GetItemText(hList, iItem1, (int)lParam3, tszBuf1, sizeof(tszBuf1));
	ListView_GetItemText(hList, iItem2, (int)lParam3, tszBuf2, sizeof(tszBuf2));

	// �e�L�X�g��r.
	if (g_btAsc[(int)lParam3] == 1){
		return (_tcscmp(tszBuf1, tszBuf2));
	}
	else{
		return (_tcscmp(tszBuf1, tszBuf2) * -1);
	}

}