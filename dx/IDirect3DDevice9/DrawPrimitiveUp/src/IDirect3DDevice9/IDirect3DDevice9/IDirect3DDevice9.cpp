// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <d3d9.h>		// DirectX Graphics Direct3D 9
#include <d3dx9.h>		// Direct3DX 9(ヘルパーユーティリティライブラリ)

// マクロの定義
// ポインタ解放用マクロSAFE_RELEASE
#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p)=NULL; } }

// 頂点の定義
typedef struct tagVertex{	// 頂点tagVertexの定義.
	float x;		// 頂点座標x
	float y;		// 頂点座標y
	float z;		// 頂点座標z
	float rhw;		// 除算数
	DWORD color;	// 32bitカラー
	float u;		// テクスチャ座標u
	float v;		// テクスチャ座標v
} Vertex;	// tagVertexをVertexとする.

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	int lCount = 0;				// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.
	HDC hDC = NULL;				// このウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	int iPhase = 0;				// フェーズを表すint型変数iPhaseを0に初期化.
	HRESULT hResult = S_FALSE;	// 結果を格納するHRESULT型変数hResultをS_FALSEに初期化.
	
	LPDIRECT3D9 lpD3D = NULL;				// IDirect3D9オブジェクトポインタlpD3DをNULLに初期化.
	D3DDISPLAYMODE d3ddm;					// D3DDISPLAYMODE型d3ddm.
	D3DPRESENT_PARAMETERS d3dpp;			// D3DPRESENT_PARAMETERS型d3dpp.
	LPDIRECT3DDEVICE9 lpD3DDevice = NULL;	// IDirect3DDevice9オブジェクトポインタlpD3DDeviceをNULLに初期化.
	LPDIRECT3DTEXTURE9 lpD3DTexture = NULL;	// IDirect3DDevice9オブジェクトポインタlpD3DTextureをNULLに初期化.
	Vertex vertex[4];						// Vertex型配列vertex.(要素数4)

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("IDirect3DDevice9");				// ウィンドウクラス名は"IDirect3DDevice9".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IDirect3DDevice9"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}
 
	// ウィンドウの作成
	hWnd = CreateWindow(_T("IDirect3DDevice9"), _T("IDirect3DDevice9"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"IDirect3DDevice9"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.
 
		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IDirect3DDevice9"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// Direct3Dオブジェクトの生成
				lpD3D = Direct3DCreate9(D3D_SDK_VERSION);	// Direct3DCreate9でDirect3Dオブジェクトを生成, lpD3Dにポインタが格納される.
				if (lpD3D == NULL){	// lpD3DがNULLなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// ディスプレイモードの取得
				ZeroMemory(&d3ddm, sizeof(d3ddm));	// ZeroMemoryでd3ddmを0で初期化.
				hResult = lpD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);	// lpD3D->GetAdapterDisplayModeでディスプレイモードを取得.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}

				// プレゼンテーションパラメータの設定
				ZeroMemory(&d3dpp, sizeof(d3dpp));	// ZeroMemoryでd3dppを0で初期化.
				d3dpp.BackBufferWidth = 640;	// 幅は640.
				d3dpp.BackBufferHeight = 480;	// 高さは480.
				d3dpp.BackBufferFormat = d3ddm.Format;	// 現在のディスプレイフォーマット.
				d3dpp.Windowed = FALSE;	// フルスクリーンモード.
				d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// 最適な方法を自動設定.
				d3dpp.BackBufferCount = 1;	// バックバッファの数は1.

				// Direct3Dデバイスオブジェクトの生成
				hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDeviceでデバイスオブジェクト作成.(描画と頂点処理をハードウェアで行う.)
				if (FAILED(hResult)){	// FAILEDなら.
					hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDeviceでデバイスオブジェクト作成.(描画をハードウェア, 頂点処理はCPUで行う.)
					if (FAILED(hResult)){	// FAILEDなら.
						hResult = lpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice);	// lpD3D->CreateDeviceでデバイスオブジェクト作成.(描画と頂点処理をCPUで行う.)
						if (FAILED(hResult)){	// FAILEDなら.
							// 抜ける.
							break;	// breakで抜ける.
						}
					}
				}

				// test.bmpを読み込んで, テクスチャを作成.
				hResult = D3DXCreateTextureFromFile(lpD3DDevice, _T("test.bmp"), &lpD3DTexture);	// D3DXCreateTextureFromFileで"test.bmp"からテクスチャ作成.
				if (FAILED(hResult)){	// FAILEDなら.
					// 抜ける.
					break;	// breakで抜ける.
				}
				
				// スプライトの頂点を設定.
				vertex[0].x = 640.0f;
				vertex[0].y = 0.0f;
				vertex[0].z = 0.0f;
				vertex[0].rhw = 1.0f;
				vertex[0].color = 0xffffffff;
				vertex[0].u = 1.0f;
				vertex[0].v = 0.0;
				vertex[1].x = 640.0f;
				vertex[1].y = 480.0f;
				vertex[1].z = 0.0f;
				vertex[1].rhw = 1.0f;
				vertex[1].color = 0xffffffff;
				vertex[1].u = 1.0f;
				vertex[1].v = 1.0f;
				vertex[2].x = 0.0f;
				vertex[2].y = 0.0f;
				vertex[2].z = 0.0f;
				vertex[2].rhw = 1.0f;
				vertex[2].color = 0xffffffff;
				vertex[2].u = 0.0f;
				vertex[2].v = 0.0f;
				vertex[3].x = 0.0f;
				vertex[3].y = 480.0f;
				vertex[3].z = 0.0f;
				vertex[3].rhw = 1.0f;
				vertex[3].color = 0xffffffff;
				vertex[3].u = 0.0f;
				vertex[3].v = 1.0f;

				// ループ処理に移行.
				iPhase = 1;	// iPhaseを1にして, ループ処理に移行.

			}
			else{	// ループ処理(iPhase == 1)
				
				// ESCキーが押されたら抜ける.
				if (GetKeyState(VK_ESCAPE) & 0x80){	// GetKeyStateでVK_ESCAPEが押されたら.
					SendMessage(hWnd, WM_CLOSE, NULL, NULL);	// SendMessageでWM_CLOSEをhWndに送ることで閉じる.
				}

				// 描画開始
				hResult = lpD3DDevice->BeginScene();	// lpD3DDevice->BeginSceneで描画開始.
				if (SUCCEEDED(hResult)){	// SUCCEEDEDなら.

					// クリア
					lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);	// lpD3DDevice->Clearでクリア.

					// test.bmpのスプライト描画.
					lpD3DDevice->SetTexture(0, lpD3DTexture);	// lpD3DDevice->SetTextureでテクスチャをセット.
					lpD3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);	// 頂点フォーマットの伝達.
					lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex));	// lpD3DDevice->DrawPrimitiveUpでプリミティブを描画.

					// 描画終了
					lpD3DDevice->EndScene();	// lpD3DDevice->EndSceneで描画終了.

				}
				// プライマリーバッファに転送.
				lpD3DDevice->Present(NULL, NULL, NULL, NULL);	// lpD3DDevice->Presentで転送.

			}

		}

	}

	// 終了処理(iPhase == 2)
	SAFE_RELEASE(lpD3DTexture);	// lpD3DTextureをSAFE_RELEASEで解放.
	SAFE_RELEASE(lpD3DDevice);	// lpD3DDeviceをSAFE_RELEASEで解放.
	SAFE_RELEASE(lpD3D);		// lpD3DをSAFE_RELEASEで解放.

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