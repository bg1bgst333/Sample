// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <ddraw.h>		// DirectDraw

// マクロの定義
// ポインタ解放用マクロSAFE_RELEASE
#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.
 
// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// 変数の宣言
	HWND hWnd;									// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;									// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;								// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	int lCount = 0;								// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.
	HDC hDC = NULL;								// このウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	int iPhase = 0;								// フェーズを表すint型変数iPhaseを0に初期化.
	HRESULT hResult = S_FALSE;					// 結果を格納するHRESULT型変数hResultをS_FALSEに初期化.
	
	LPDIRECTDRAW7 lpDD = NULL;					// IDirectDraw7オブジェクトポインタlpDDをNULLに初期化.
	LPDIRECTDRAWCLIPPER lpClip = NULL;			// クリッパーlpClipをNULLに初期化.
	DDSURFACEDESC2 ddsd;						// サーフェイスディスクリプタddsd.
	LPDIRECTDRAWSURFACE7 lpDDSPrimary = NULL;	// プライマリサーフェイスlpDDSPrimaryをNULLに初期化.
	DDSCAPS2 ddscapsBackBuffer;					// DDSCAPS2型ddscapsBackBuffer.
	LPDIRECTDRAWSURFACE7 lpDDSBack = NULL;		// バックサーフェイスlpDDSBackをNULLに初期化.
	
	HBITMAP hBitmap = NULL;						// HBITMAP型hBitmapをNULLに初期化.
	HDC hMemDC = NULL;							// HDC型メモリデバイスコンテキストhMemDCをNULLに初期化.
	HBITMAP hOldBitmap = NULL;					// HBTIMAP型hOldBitmapをNULLに初期化.
	BITMAP bitmap = {0};						// BITMAP型bitmapを0で初期化.
	LPDIRECTDRAWSURFACE7 lpDDSBitmap = NULL;	// ビットマップを描画したサーフェイスlpDDSBitmapをNULLに初期化.
	DDSURFACEDESC2 ddsdBitmap;					// lpDDSBitmapのサーフェイスディスクリプタddsdBitmap.
	HDC hDDSBitmapDC = NULL;					// lpDDSBitmapのデバイスコンテキストhDDSBitmapDCをNULLに初期化.
	RECT rc = {0};								// RECT型rcを0で初期化.
	
	HBITMAP hBitmap2 = NULL;					// HBITMAP型hBitmap2をNULLに初期化.
	HDC hMemDC2 = NULL;							// HDC型メモリデバイスコンテキストhMemDCをNULLに初期化.
	HBITMAP hOldBitmap2 = NULL;					// HBITMAP型hOldBitmap2をNULLに初期化.
	BITMAP bitmap2 = {0};						// BITMAP型bitmap2を0で初期化.
	LPDIRECTDRAWSURFACE7 lpDDSBitmap2 = NULL;	// ビットマップを描画したもうひとつのサーフェイスlpDDSBitmap2をNULLに初期化.
	DDSURFACEDESC2 ddsdBitmap2;					// lpDDSBitmap2のサーフェイスディスクリプタddsdBitmap2.
	HDC hDDSBitmapDC2 = NULL;					// lpDDSBitmap2のデバイスコンテキストhDDSBitmapDC2をNULLに初期化.
	RECT rc2 = {0};								// RECT型rc2を0で初期化.

	int x = 0;									// lpDDSBitmap2の描画位置のx座標.
	int y = 0;									// lpDDSBitmap2の描画位置のy座標.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("IDirectDrawSurface7");			// ウィンドウクラス名は"IDirectDrawSurface7".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.
 
	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IDirectDrawSurface7"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}
 
	// ウィンドウの作成
	hWnd = CreateWindow(_T("IDirectDrawSurface7"), _T("IDirectDrawSurface7"), WS_POPUP | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"IDirectDrawSurface7"ウィンドウクラスのウィンドウを作成.(WS_POPUP | WS_VISIBLEで枠なしウィンドウにしている.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.
 
		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IDirectDrawSurface7"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)
 
	}
 
	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.
 
	// デバイスコンテキストの取得.
	hDC = GetDC(hWnd);	// GetDCでデバイスコンテキストハンドルhDCを取得.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else{	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// lCount増加.
			lCount++;	// lCountを1増やす.

			// メイン処理
			if (iPhase == 0){	// 初期化(iPhase == 0)

				// DirectDrawオブジェクトの生成
				hResult = DirectDrawCreateEx(NULL, (LPVOID *)&lpDD, IID_IDirectDraw7, NULL);	// DirectDrawCreateExでDirectDrawオブジェクトを生成, lpDDにポインタが格納される.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// 協調レベル設定
				hResult = lpDD->SetCooperativeLevel(hWnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);	// 今回はフルスクリーンアプリケーションとするので, lpDD->SetCooperativeLevelではDDSCL_EXCLUSIVE | DDSCL_FULLSCREENを指定.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// ディスプレイモードの設定
				hResult = lpDD->SetDisplayMode(640, 480, 24, 0, 0);	// lpDD->SetDisplayModeで640x480で24bit表示にする.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// クリッパーの作成
				hResult = lpDD->CreateClipper(NULL, &lpClip, NULL);	// lpDD->CreateClipperでクリッパーを作成, lpClipにポインタが格納される.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}
				lpClip->SetHWnd(0, hWnd);	// lpClip->SetHWndでウィンドウハンドルのセット.

				// プライマリサーフェイスディスクリプタ設定
				ZeroMemory(&ddsd, sizeof(ddsd));	// ZeroMemoryでddsdを0で埋めて初期化.
				ddsd.dwSize = sizeof(ddsd);	// サイズ設定
				ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;	// フラグはDDSD_CAPS | DDSD_BACKBUFFERCOUNT.
				ddsd.ddsCaps.dwCaps =  DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;	// プライマリサーフェイスでフリップ可能で複合サーフェイス.
				ddsd.dwBackBufferCount = 1;	// バックバッファの数は1.

				// プライマリサーフェイスの作成
				hResult = lpDD->CreateSurface(&ddsd, &lpDDSPrimary, NULL);	// lpDD->CreateSurfaceでプライマリサーフェイスを作成.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					
					break;	// breakで抜ける.
				}

				// プライマリサーフェイスにクリッパーをセット.
				lpDDSPrimary->SetClipper(lpClip);	// lpDDSPrimary->SetClipperでlpClipをセット.

				// バックバッファの生成
				ZeroMemory(&ddscapsBackBuffer, sizeof(ddscapsBackBuffer));	// ZeroMemoryでddscapsBackBufferを0で埋めて初期化.
				ddscapsBackBuffer.dwCaps = DDSCAPS_BACKBUFFER;	// バックバッファ.
				hResult = lpDDSPrimary->GetAttachedSurface(&ddscapsBackBuffer, &lpDDSBack);	// lpDDSPrimary->GetAttachedSurfaceでバックサーフェイスを取得.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// バックファーフェイスにもクリッパーをセット.(これをやらないと, はみ出た画像が表示されない.)
				lpDDSBack->SetClipper(lpClip);	// lpDDSBack->SetClipperでlpClipをセット.

				// ビットマップのロード(test.bmp)
				hBitmap = (HBITMAP)LoadImage(hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"test.bmp"をロード.
				if (hBitmap == NULL){	// NULLなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// メモリデバイスコンテキストの作成.(test.bmp)
				hMemDC = CreateCompatibleDC(NULL);	// CreateCompatibleDCでメモリデバイスコンテキスト作成.
				if (hMemDC == NULL){	// NULLなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// メモリデバイスコンテキストとビットマップの紐付け.(test.bmp)
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObjectでhMemDCとhBitmapを紐付け.

				// ビットマップ情報の取得.(test.bmp)
				GetObject(hBitmap, sizeof(BITMAP), &bitmap);	// GetObjectでビットマップ情報を取得し, bitmapに格納.

				// ビットマップサーフェイスディスクリプタ設定(test.bmp)
				ZeroMemory(&ddsdBitmap, sizeof(ddsdBitmap));	// ZeroMemoryでddsdBitmapを0で埋めて初期化.
				ddsdBitmap.dwSize = sizeof(ddsdBitmap);	// サイズ設定
				ddsdBitmap.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;	// フラグはDDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT.
				ddsdBitmap.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;	// システムメモリでオフスクリーン.
				ddsdBitmap.dwWidth = bitmap.bmWidth;	// ビットマップの幅をセット.
				ddsdBitmap.dwHeight = bitmap.bmHeight;	// ビットマップの高さをセット.

				// ビットマップサーフェイスの作成(test.bmp)
				hResult = lpDD->CreateSurface(&ddsdBitmap, &lpDDSBitmap, NULL);	// lpDD->CreateSurfaceでビットマップサーフェイスを作成.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// ビットマップサーフェイスのデバイスコンテキストを取得.(test.bmp)
				lpDDSBitmap->GetDC(&hDDSBitmapDC);	// lpDDSBitmap->GetDCでデバイスコンテキストを取得し, hDDSBitmapDCに格納.

				// メモリデバイスコンテキストからビットマップサーフェイスへ転送.(test.bmp)
				BitBlt(hDDSBitmapDC, 0, 0, ddsdBitmap.dwWidth, ddsdBitmap.dwHeight, hMemDC, 0, 0, SRCCOPY);	// BitBltでhMemDCからhDDSBitmapDCに転送.

				// ビットマップサーフェイスのデバイスコンテキストを解放.(test.bmp)
				lpDDSBitmap->ReleaseDC(hDDSBitmapDC);	// lpDDSBitmap->ReleaseDCでデバイスコンテキストhDDSBitmapDCを解放.
				hDDSBitmapDC = NULL;	// hDDSBitmapDCにNULLをセット.

				// ビットマップのロード(test2.bmp)
				hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("test2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"test2.bmp"をロード.
				if (hBitmap2 == NULL){	// NULLなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// メモリデバイスコンテキストの作成.(test2.bmp)
				hMemDC2 = CreateCompatibleDC(NULL);	// CreateCompatibleDCでメモリデバイスコンテキスト作成.
				if (hMemDC2 == NULL){	// NULLなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// メモリデバイスコンテキストとビットマップの紐付け.(test2.bmp)
				hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBitmap2);	// SelectObjectでhMemDC2とhBitmap2を紐付け.

				// ビットマップ情報の取得.(test2.bmp)
				GetObject(hBitmap2, sizeof(BITMAP), &bitmap2);	// GetObjectでビットマップ情報を取得し, bitmap2に格納.

				// ビットマップサーフェイスディスクリプタ設定(test2.bmp)
				ZeroMemory(&ddsdBitmap2, sizeof(ddsdBitmap2));	// ZeroMemoryでddsdBitmap2を0で埋めて初期化.
				ddsdBitmap2.dwSize = sizeof(ddsdBitmap2);	// サイズ設定
				ddsdBitmap2.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;	// フラグはDDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT.
				ddsdBitmap2.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;	// システムメモリでオフスクリーン.
				ddsdBitmap2.dwWidth = bitmap2.bmWidth;	// ビットマップの幅をセット.
				ddsdBitmap2.dwHeight = bitmap2.bmHeight;	// ビットマップの高さをセット.

				// ビットマップサーフェイスの作成(test2.bmp)
				hResult = lpDD->CreateSurface(&ddsdBitmap2, &lpDDSBitmap2, NULL);	// lpDD->CreateSurfaceでビットマップサーフェイスを作成.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// ビットマップサーフェイスのデバイスコンテキストを取得.(test2.bmp)
				lpDDSBitmap2->GetDC(&hDDSBitmapDC2);	// lpDDSBitmap2->GetDCでデバイスコンテキストを取得し, hDDSBitmapDC2に格納.

				// メモリデバイスコンテキストからビットマップサーフェイスへ転送.(test2.bmp)
				BitBlt(hDDSBitmapDC2, 0, 0, ddsdBitmap2.dwWidth, ddsdBitmap2.dwHeight, hMemDC2, 0, 0, SRCCOPY);	// BitBltでhMemDC2からhDDSBitmapDC2に転送.

				// ビットマップサーフェイスのデバイスコンテキストを解放.(test2.bmp)
				lpDDSBitmap2->ReleaseDC(hDDSBitmapDC2);	// lpDDSBitmap2->ReleaseDCでデバイスコンテキストhDDSBitmapDC2を解放.
				hDDSBitmapDC2 = NULL;	// hDDSBitmapDC2にNULLをセット.

				// ループ処理に移行.
				iPhase = 1;	// iPhaseを1にして, ループ処理に移行.

			}
			else{	// ループ処理(iPhase == 1)

				// ESCキーが押されたら抜ける.
				if (GetKeyState(VK_ESCAPE) & 0x80){	// GetKeyStateでVK_ESCAPEが押されたら.
					SendMessage(hWnd, WM_CLOSE, NULL, NULL);	// SendMessageでWM_CLOSEをhWndに送ることで閉じる.
				}

				// 移動.
				if (GetKeyState(VK_LEFT) & 0x80){	// GetKeyStateでVK_LEFTが押されたら.
					x--;	// xをデクリメント.
				}
				if (GetKeyState(VK_UP) & 0x80){		// GetKeyStateでVK_UPが押されたら.
					y--;	// yをデクリメント.
				}
				if (GetKeyState(VK_RIGHT) & 0x80){	// GetKeyStateでVK_RIGHTが押されたら.
					x++;	// xをインクリメント.
				}
				if (GetKeyState(VK_DOWN) & 0x80){	// GetKeyStateでVK_DOWNが押されたら.
					y++;	// yをインクリメント.
				}

				// 移動制限.
				if (x <= 0){	// xが0を下回ったら.
					x = 0;		// xを0に戻す.
				}
				if (y <= 0){	// yが0を下回ったら.
					y = 0;		// yを0に戻す.
				}
				if (x >= ddsdBitmap.dwWidth - ddsdBitmap2.dwWidth){		// xがddsdBitmap.dwWidth - ddsdBitmap2.dwWidthを超えたら.
					x = ddsdBitmap.dwWidth - ddsdBitmap2.dwWidth;		// xをddsdBitmap.dwWidth - ddsdBitmap2.dwWidthに戻す.
				}
				if (y >= ddsdBitmap.dwHeight - ddsdBitmap2.dwHeight){	// yがddsdBitmap.dwHeight - ddsdBitmap2.dwHeightを超えたら.
					y = ddsdBitmap.dwHeight - ddsdBitmap2.dwHeight;		// yをddsdBitmap.dwHeight - ddsdBitmap2.dwHeightに戻す.
				}

				// サーフェイスの描画(test.bmp)
				GetWindowRect(hWnd, &rc);	// ウィンドウ矩形を取得.
				// フルスクリーンなので左上は(0, 0).
				rc.left = 0;	// 0にする.(GetSystemMetricsは固定値?) //+= GetSystemMetrics(SM_CXSIZEFRAME);	// 境界線の分だけ足す.
				rc.top = 0;	// 0にする.(GetSystemMetricsは固定値?) //+= GetSystemMetrics(SM_CYSIZEFRAME) + GetSystemMetrics(SM_CYCAPTION);	// 境界線とタイトルバーの分だけ足す.
				rc.right = rc.left + ddsdBitmap.dwWidth;	// rc.leftにddsdBitmap.dwWidthの分だけ足す.
				rc.bottom = rc.top + ddsdBitmap.dwHeight;	// rc.topにddsdBitmap.dwHeightの分だけ足す.
				lpDDSBack->Blt(&rc, lpDDSBitmap, NULL, DDBLT_WAIT, NULL);	// lpDDSBack->BltでlpDDSBackにlpDDSBitmapを描画.
				
				// サーフェイスの描画(test2.bmp)
				rc2.left = x;	// x.
				rc2.top = y;	// y.
				rc2.right = rc2.left + ddsdBitmap2.dwWidth;		// rc2.leftにddsdBitmap2.dwWidthの分だけ足す.
				rc2.bottom = rc2.top + ddsdBitmap2.dwHeight;	// rc2.topにddsdBitmap2.dwHeightの分だけ足す.
				lpDDSBack->Blt(&rc2, lpDDSBitmap2, NULL, DDBLT_WAIT, NULL);	// lpDDSBack2->BltでlpDDSBack2にlpDDSBitmap2を描画.

				// フリップ
				lpDDSPrimary->Flip(NULL, DDFLIP_WAIT);	// lpDDSPrimary->Flipでフリップ

			}

		}

	}

	// 終了処理(iPhase == 2)
	if (hOldBitmap2 != NULL){	// NULLでなければ.
		SelectObject(hMemDC2, hOldBitmap2);	// 元に戻す.
		hOldBitmap2 = NULL;	// hOldBitmap2にNULLをセット.
	}
	if (hMemDC2 != NULL){	// NULLでなければ.
		DeleteDC(hMemDC2);	// DeleteDCでhMemDC2を削除.
		hMemDC2 = NULL;		// hMemDC2にNULLをセット.
	}
	if (hBitmap2 != NULL){	// NULLでなければ.
		DeleteObject(hBitmap2);	// DeleteObjectでhBitmap2を削除.
		hBitmap2 = NULL;		// hBitmap2にNULLをセット.
	}
	SAFE_RELEASE(lpDDSBitmap2);	// lpDDSBitmap2をSAFE_RELEASEで解放.

	if (hOldBitmap != NULL){	// NULLでなければ.
		SelectObject(hMemDC, hOldBitmap);	// 元に戻す.
		hOldBitmap = NULL;	// hOldBitmapにNULLをセット.
	}
	if (hMemDC != NULL){	// NULLでなければ.
		DeleteDC(hMemDC);	// DeleteDCでhMemDCを削除.
		hMemDC = NULL;		// hMemDCにNULLをセット.
	}
	if (hBitmap != NULL){	// NULLでなければ.
		DeleteObject(hBitmap);	// DeleteObjectでhBitmapを削除.
		hBitmap = NULL;		// hBitmapにNULLをセット.
	}
	SAFE_RELEASE(lpDDSBitmap);	// lpDDSBitmapをSAFE_RELEASEで解放.
	
	//SAFE_RELEASE(lpBBSBack);	// lpBBSBackはlpDDSPrimaryにアタッチされているのでSAFE_RELEASEで解放しなくていい.
	SAFE_RELEASE(lpDDSPrimary);	// lpDDSPrimaryをSAFE_RELEASEで解放.
	SAFE_RELEASE(lpClip);	// lpClipをSAFE_RELEASEで解放.
	SAFE_RELEASE(lpDD);	// lpDDをSAFE_RELEASEで解放.

	// デバイスコンテキストの解放.
	if (hDC != NULL){	// hDCが解放されていなければ.

		// デバイスコンテキストを解放する.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.
		hDC = NULL;	// NULLをセット.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.
 
}
 
// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.
 
		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)
 
			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
	}
 
	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}