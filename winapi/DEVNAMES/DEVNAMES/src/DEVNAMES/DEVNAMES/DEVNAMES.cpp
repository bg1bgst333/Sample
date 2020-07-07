// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <cstring>		// C�����񏈗�
#include <commctrl.h>	// �R�����R���g���[��
#include <shlwapi.h>	// �V�F��API
// �Ǝ��̃w�b�_�t�@�C��
#include "resource.h"	// ���\�[�X

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E���b�Z�[�W�ɑ΂��ēƎ��̏���������悤�ɒ�`�����R�[���o�b�N�֐�WindowProc.

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// �ϐ��̐錾
	HWND hWnd;		// CreateWindow�ō쐬�����E�B���h�E�̃E�B���h�E�n���h�����i�[����HWND�^�ϐ�hWnd.
	MSG msg;		// �E�B���h�E���b�Z�[�W�����i�[����MSG�\���̌^�ϐ�msg.
	WNDCLASS wc;	// �E�B���h�E�N���X��������WNDCLASS�\���̌^�ϐ�wc.

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("DEVNAMES");						// �E�B���h�E�N���X����"DEVNAMES".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �E�B���h�E�v���V�[�W���͓Ǝ��̏������`����WindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h����_tWinMain�̈���.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�C�R���̓A�v���P�[�V��������̂���.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// �J�[�\���͖��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔��u���V.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// ���j���[�ɂ�IDR_MAINMENU��MAKEINTRESOURCE�}�N���Ŏw��.
	wc.cbClsExtra = 0;										// 0�ł���.
	wc.cbWndExtra = 0;										// 0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^��, 0���Ԃ�����G���[.
 
		// �G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DEVNAMES"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"�ƃG���[���b�Z�[�W��\��.
		return -1;	// �ُ�I��(1)
 
	}

	// �E�B���h�E�̍쐬.
	hWnd = CreateWindow(_T("DEVNAMES"), _T("DEVNAMES"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindow��, ��œo�^����"DEVNAMES"�E�B���h�E�N���X�̃E�B���h�E���쐬.
	if (hWnd == NULL){	// �E�B���h�E�̍쐬�Ɏ��s�����Ƃ�.
 
		// �G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DEVNAMES"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"�ƃG���[���b�Z�[�W��\��.
		return -2;	// �ُ�I��(2)
 
	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��SW_SHOW���w�肵�ăE�B���h�E�̕\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�Ń��b�Z�[�W���擾, �߂�l��0���傫���Ԃ̓��[�v��������.
 
		// �E�B���h�E���b�Z�[�W�̑��o
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

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

				// �ϐ��̐錾
				HWND hEdit1;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit1.
				HWND hEdit2;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit2.
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̂̃|�C���^lpCS.
				TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(����MAX_PATH)��{0}�ŏ�����.

				// �A�v���P�[�V�����C���X�^���X�n���h���̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// �G�f�B�b�g�R���g���[���̍쐬.
				hEdit1 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, 50, 50, 300, 30, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[�����쐬.
				if (hEdit1 == NULL){	// hEdit1��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}
				hEdit2 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL, 50, 100, 300, 30, hwnd, (HMENU)ID_EDIT2, lpCS->hInstance, NULL);	// CreateWindow��WC_EDIT�ŃG�f�B�b�g�R���g���[�����쐬.
				if (hEdit2 == NULL){	// hEdit2��NULL�Ȃ�.

					// �G���[����.
					return -1;	// -1��Ԃ�.

				}

				// ���ݎ��s���̎��s�t�@�C���̃t���p�X���擾.
				//GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileName�ł��̎��s�t�@�C���̃t���p�X���擾.

				// �t�@�C�����̕�������菜��, ��������t�H���_�p�X���擾����.
				//PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpec�Ńt�@�C�����̕�������菜��.

				// "\test.pdf"��A��.
				//_tcscat(tszModulePath, _T("\\test.pdf"));	// _tcscat��"\test.pdf"��A��.

				// hEdit2�ɃZ�b�g.
				//SetWindowText(hEdit2, tszModulePath);	// SetWindowText��hEdit2��tszModulePath���Z�b�g.

				// �E�B���h�E�쐬����
				return 0;	// return����0��Ԃ���, �E�B���h�E�쐬�����Ƃ���.
 
			}
 
			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.
 
		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:	// �E�B���h�E���j�����ꂽ��.(uMsg��WM_DESTROY�̎�.)
 
			// WM_DESTROY�u���b�N
			{

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

				// �E�B���h�E�̕`��J�n
				hDC = BeginPaint(hwnd, &ps);	// BeginPaint�ł��̃E�B���h�E�̕`��̏���������. �߂�l�ɂ̓f�o�C�X�R���e�L�X�g�n���h�����Ԃ�̂�, hDC�Ɋi�[.

				// �E�B���h�E�̕`��I��
				EndPaint(hwnd, &ps);	// EndPaint�ł��̃E�B���h�E�̕`�揈�����I������.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:	// �E�B���h�E������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.
		case WM_COMMAND:	// ���j���[���ڂ��I�����ꂽ��, �{�^���Ȃǂ̃R���g���[���������ꂽ�肵��, �R�}���h������������.(uMsg��WM_COMMAND�̎�.)

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃��j���[���ڂ��I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�őI�����ꂽ���j���[���ڂ�ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// �擾����ID���Ƃɏ����𕪊�.
					// Print���I�����ꂽ��.
					case ID_ITEM_PRINT:

						// ID_ITEM_PRINT�u���b�N
						{

							// �ϐ��̐錾
							PAGESETUPDLG psd = {0};	// PAGESETUPDLG�\����psd��0�ŏ�����.
							PRINTDLG pd = {0};	// PRINTDLG�\����pd��0�ŏ�����.
							HWND hEdit1;		// �G�f�B�b�g�R���g���[���̃n���h��hEdit1.
							int len;			// �E�B���h�E���̕�����len.
							TCHAR *ptszPrinterName;	// �E�B���h�E���ւ̃|�C���^ptszPrinterName.
							int iRetSD;	// StartDoc�̖߂�liRetSD.
							int iRetSP;	// StartPage�̖߂�liRetSP.

							// psd�̏����ݒ�
							psd.lStructSize = sizeof(PAGESETUPDLG);	// sizeof��PAGESETUPDLG�\���̂̃T�C�Y���w��.
							psd.hwndOwner = hwnd;		// hwnd���w��.
							psd.Flags = PSD_INHUNDREDTHSOFMILLIMETERS | PSD_MARGINS;	// �~���P�ʂɐݒ�, �]���̕ύX.
							psd.rtMargin.left = 500;	// ���[�}�[�W��500.
							psd.rtMargin.top = 500;		// ��[�}�[�W��500.
							psd.rtMargin.right = 500;	// �E�[�}�[�W��500.
							psd.rtMargin.bottom = 500;	// ���[�}�[�W��500.
							psd.hDevMode = GlobalAlloc(GHND, sizeof(DEVMODE));	// GlobalAlloc��DEVMODE�̃n���h�����������m��.

							// DEMOVDE�̏����ݒ�
							DEVMODE *pDevMode = (DEVMODE *)GlobalLock(psd.hDevMode);	// GlobalLock��psd.hDevMode�����b�N.
							pDevMode->dmSize = sizeof(DEVMODE);	// DEVMODE�̃T�C�Y���Z�b�g.(���ꂪ�Ȃ��ƕύX�����f����Ȃ�.)
							pDevMode->dmSpecVersion = DM_SPECVERSION;	// Windows10���Ƃ��ꂪ�Ȃ��ƕύX�����f����Ȃ�.
							pDevMode->dmFields |= DM_ORIENTATION;	// �ύX�Ώۂ͈������.
							pDevMode->dmOrientation |= DMORIENT_LANDSCAPE;	// ������������ɃZ�b�g.
							GlobalUnlock(psd.hDevMode);	// GlobalUnlock�ŃA�����b�N.

							// PageSetupDlg�̕\��.
							BOOL bRet = PageSetupDlg(&psd);	// PageSetupDlg��psd��n���ĕ\����, �߂�l��BOOL��bRet�Ɋi�[.
							if (bRet){	// bRet��TRUE.

								// pd�̏����ݒ�
								pd.lStructSize = sizeof(PRINTDLG);	// PRINTDLG�\����pd��0�ŏ�����.
								pd.hwndOwner = hwnd;	// hwnd���w��.
								pd.Flags = PD_RETURNDC;	// pd�̃����o�Ƃ���hDC��Ԃ�.
								pd.hDevMode = psd.hDevMode;	// pd.hDevMode��psd.hDevMode��n��.
								pd.hDevNames = psd.hDevNames;	// pd.hDevNames��psd.hDevNames��n��.

								// �h���C�o��, �f�o�C�X��, �o�͖��̎擾, ����̃v�����^���ǂ����\��.
								DEVNAMES *pDevNames = (DEVNAMES *)GlobalLock(pd.hDevNames);	// pDevNames�擾.
								TCHAR *ptszDriverName = (TCHAR *)((BYTE *)pDevNames + (pDevNames->wDriverOffset * sizeof(TCHAR)));	// �h���C�o���̈ʒu�ɒ���.
								MessageBox(hwnd, ptszDriverName, _T("DEVNAMES"), MB_OK);	// �h���C�o���\��.
								TCHAR *ptszDeviceName = (TCHAR *)((BYTE *)pDevNames + (pDevNames->wDeviceOffset * sizeof(TCHAR)));	// �f�o�C�X���̈ʒu�ɒ���.
								MessageBox(hwnd, ptszDeviceName, _T("DEVNAMES"), MB_OK);	// �f�o�C�X���\��.
								TCHAR *ptszOutputName = (TCHAR *)((BYTE *)pDevNames + (pDevNames->wOutputOffset * sizeof(TCHAR)));	// �o�͖��̈ʒu�ɒ���.
								MessageBox(hwnd, ptszOutputName, _T("DEVNAMES"), MB_OK);	// �o�͖��\��.
								if (pDevNames->wDefault == DN_DEFAULTPRN){	// ����̃v�����^�̏ꍇ.
									MessageBox(hwnd, _T("DN_DEFAULTPRN"), _T("DEVNAMES"), MB_OK);	// "DN_DEFAULTPRN"�ƕ\��.
								}
								GlobalUnlock(pd.hDevNames);	// �A�����b�N.

								// PrintDlg�̕\��.
								bRet = PrintDlg(&pd);	// PrintDlg��pd��n���ĕ\����, �߂�l��bRet�Ɋi�[.
								if (bRet){	// �������������TRUE.

									// �G�f�B�b�g�{�b�N�X�̃v�����^���̎擾.
									hEdit1 = GetDlgItem(hwnd, ID_EDIT1);		// GetDlgItem��ID_EDIT1�̃n���h�����擾.
									len = GetWindowTextLength(hEdit1);	// GetWindowTextLength��hEdit1�̃E�B���h�E���̕��������擾.
									ptszPrinterName = new TCHAR[len + 1];	// new�Œ���len + 1��TCHAR�z��o�b�t�@��p��.
									GetWindowText(hEdit1, ptszPrinterName, len + 1);	// GetWindowText�ŃE�B���h�E����ptszPrinterName�Ɋi�[.

									// �擾�����v�����^���̃v�����^��"ABCDE"�����.
									DOCINFO di = {0};	// DOCINFO�\����di��{0}�ŏ�����.
									di.cbSize = sizeof(DOCINFO);	// sizeof��DOCINFO�̃T�C�Y���w��.
									di.lpszDocName = _T("DEVNAMES");	// �h�L�������g����"DEVNAMES"�Ƃ���.
									iRetSD = StartDoc(pd.hDC, &di);	// StartDoc�ň���W���u�̊J�n.
									if (iRetSD > 0){	// ����J�n����.
										iRetSP = StartPage(pd.hDC);	// StartPage�Ńy�[�W�̊J�n.
										if (iRetSP > 0){	// �y�[�W�J�n����.
											TextOut(pd.hDC, 50, 50, _T("ABCDE"), _tcslen(_T("ABCDE")));	// TextOut�Ńv�����^��(50, 50)�̈ʒu��"ABCDE"��`��.
											EndPage(pd.hDC);	// EndPage�Ńy�[�W�I��.
										}
										EndDoc(pd.hDC);	// EndDoc�ň���W���u�I��.
									}

									// �I������.
									delete [] ptszPrinterName;	// delete��ptszPrinterName�����.
									DeleteDC(pd.hDC);	// DeleteDC��pd.hDC���폜.

								}

							}

							// �I������.
							GlobalFree(psd.hDevMode);	// psd.hDevMode�����.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ��L�ȊO�̎�.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

				}

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