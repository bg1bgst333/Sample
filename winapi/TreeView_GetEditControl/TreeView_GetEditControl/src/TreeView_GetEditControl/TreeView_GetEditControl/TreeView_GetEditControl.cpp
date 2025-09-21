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
	wc.lpszClassName = _T("TreeView_GetEditControl");			// �E�B���h�E�N���X����"TreeView_GetEditControl".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("TreeView_GetEditControl"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(_T("TreeView_GetEditControl"), _T("TreeView_GetEditControl"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"TreeView_GetEditControl"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.

		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("TreeView_GetEditControl"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
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

	// static�ϐ��̏�����.
	static HIMAGELIST hSmall = NULL;
	static HBITMAP hBitmap1 = NULL;
	static HBITMAP hBitmap2 = NULL;

	// �_�C�A���O�̃��b�Z�[�W����
	switch (uMsg){	// uMsg�̓��e�Ŕ��f.

		// �_�C�A���O�̏�������.
		case WM_INITDIALOG:	// �_�C�A���O�̏�������.(uMsg��WM_INITDIALOG�̎�.)

			// WM_INITDIALOG�u���b�N
			{

				// �ϐ��̏�����.
				HTREEITEM hParent1 = NULL;	// �e�c���[�n���h��hParent1��NULL�ŏ�����.
				HTREEITEM hChild1 = NULL;	// �q�v�f�n���h��hChild1��NULL�ŏ�����.
				HTREEITEM hParent2 = NULL;	// �e�c���[�n���h��hParent2��NULL�ŏ�����.
				HTREEITEM hParent3 = NULL;	// �e�c���[�n���h��hParent3��NULL�ŏ�����.
				TV_INSERTSTRUCT tvis = {0};	// TV_INSERTSTRUCT�\����tvis��{0}�ŏ�����.

				// �c���[�n���h���擾.
				HWND hTree = GetDlgItem(hwndDlg, IDC_TREE1);

				// �C���[�W���X�g�̍쐬.
				HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);
				hSmall = ImageList_Create(16, 16, ILC_COLOR24, 2, 1);
				TreeView_SetImageList(hTree, hSmall, TVSIL_NORMAL);
				hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("image1s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("image2s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				ImageList_Add(hSmall, hBitmap1, NULL);
				ImageList_Add(hSmall, hBitmap2, NULL);

				// 1�Ԗڂ̃��[�g�v�f�ǉ�.
				tvis.hInsertAfter = TVI_LAST;	// ����.
				tvis.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;	// �e�L�X�g�ƃA�C�R���ƑI�����A�C�R��.
				tvis.hParent = TVI_ROOT;	// ���[�g.
				tvis.item.pszText = _T("Taro");	// "Taro".
				tvis.item.iImage = 0;	// �A�C�R��0��.
				tvis.item.iSelectedImage = 0;	// �A�C�R��0��.
				hParent1 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItem��tvis�̗v�f��}��.

				// 1�Ԗڂ̎q�v�f�ǉ�.
				tvis.hParent = hParent1;	// hParent1���e.
				tvis.item.pszText = _T("Juutaro");	// "Juutaro".
				tvis.item.iImage = 1;	// �A�C�R��1��.
				tvis.item.iSelectedImage = 1;	// �A�C�R��1��.
				hChild1 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);		// TreeView_InsertItem��tvis�̗v�f��}��.

				// 2�Ԗڂ̃��[�g�v�f�ǉ�.
				tvis.hParent = TVI_ROOT;	// ���[�g.
				tvis.item.pszText = _T("Jiro");	// "Jiro".
				tvis.item.iImage = 0;	// �A�C�R��0��.
				tvis.item.iSelectedImage = 0;	// �A�C�R��0��.
				hParent2 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItem��tvis�̗v�f��}��.

				// 3�Ԗڂ̃��[�g�v�f�ǉ�.
				tvis.item.pszText = _T("Saburo");	// "Saburo".
				hParent3 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItem��tvis�̗v�f��}��.

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
				HWND hTree;	// �c���[�r���[�̃n���h��hTree.

				// �c���[�r���[�̃n���h�����擾.
				hTree = GetDlgItem(hwndDlg, IDC_TREE1);	// GetDlgItem��IDC_TREE1�̃n���h���擾.

				// �c���[�r���[�̎�.
				if ((int)wParam == IDC_TREE1){	// wParam��IDC_TREE1�̎�.
					TV_DISPINFO *tvi = (TV_DISPINFO *)lParam;	// lParam��TV_DISPINFO�̃|�C���^�ɕϊ�.
					switch (tvi->hdr.code){	// �ʒm�R�[�h���Ƃɕ�����.
						case TVN_BEGINLABELEDIT:	// �ҏW�J�n.
							// �f�o�b�O�o��.
							OutputDebugString(_T("TVN_BEGINLABELEDIT\n"));	// OutputDebugString��"TVN_BEGINLABELEDIT"���o��.
							break;
						case TVN_ENDLABELEDIT:	// �ҏW�I��.

							// TVN_ENDLABELEDIT�u���b�N
							{

								// �f�o�b�O�o��.
								OutputDebugString(_T("TVN_ENDLABELEDIT\n"));	// OutputDebugString��"TVN_ENDLABELEDIT"���o��.

								// �G�f�B�b�g�R���g���[���̎擾.
								HWND hEdit = TreeView_GetEditControl(hTree);	// TreeView_GetEditControl��hEdit���擾.

								// �e�L�X�g�̎擾�Əo��.
								int iLen = GetWindowTextLength(hEdit);
								TCHAR *ptszBuf = new TCHAR[iLen + 1];
								ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));
								GetWindowText(hEdit, ptszBuf, iLen + 1);
								OutputDebugString(ptszBuf);
								OutputDebugString(_T("\n"));
								delete[] ptszBuf;

							}

							// ����̏����֌�����.
							break;	// break�Ŕ�����.

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
							// �ϐ��̐錾�E������
							HWND hTree;	// �c���[�r���[�̃n���h��hTree.

							// �c���[�r���[�̃n���h�����擾.
							hTree = GetDlgItem(hwndDlg, IDC_TREE1);	// GetDlgItem��IDC_TREE1�̃n���h���擾.

							// �I�����ꂽ�c���[�r���[�A�C�e���n���h���̎擾�Əo��.
							HTREEITEM hItem = TreeView_GetSelection(hTree);	// TreeView_GetSelection��hItem���擾.
							TCHAR tszHItem[256] = {0};
							_stprintf(tszHItem, _T("hItem = 0x%08x\n"), (unsigned long)hItem);
							OutputDebugString(tszHItem);	// OutputDebugString��hItem�̒l���o��.

							// �A�C�e����ҏW���[�h�ɂ���.
							TreeView_EditLabel(hTree, hItem);	// TreeView_EditLabel�ŃA�C�e����ҏW���[�h�ɂ���.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����.

				}

				// ����̏����֌�����.
				break;	// break�Ŕ�����.

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