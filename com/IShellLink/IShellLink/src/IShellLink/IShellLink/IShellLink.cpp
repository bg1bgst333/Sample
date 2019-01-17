// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <shlguid.h>	// シェルGUID
#include <shobjidl.h>	// シェルオブジェクトIDL

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// ポインタの初期化.
	IShellLink *pShellLink = NULL;	// IShellLinkインターフェースポインタpShellLinkをNULLで初期化.

	// インスタンス作成.
	HRESULT hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&pShellLink);	// CoCreateInstanceでIShellLinkのインスタンスポインタをpShellLinkに格納.
	if (FAILED(hr)){	// 失敗.
		_tprintf(_T("CoCreateInstance failed!\n"));	// "CoCreateInstance failed!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return 0;	// 0を返して終了.
	}

	// 成功.
	_tprintf(_T("pShellLink success!, pShellLink = 0x%08x\n"), (unsigned int)pShellLink);	// "pShellLink success!"とともにpShellLinkの値を出力.

	// 解放.
	pShellLink->Release();	// pShellLink->Releaseで解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}