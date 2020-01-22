// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理
#include <shlwapi.h>	// シェルAPI
#include <shlguid.h>	// シェルGUID
#include <shobjidl.h>	// シェルオブジェクトIDL

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// ポインタの初期化.
	IShellLink *pShellLink = NULL;	// IShellLinkインターフェースポインタpShellLinkをNULLで初期化.
	IPersistFile *pPersistFile = NULL;	// IPersistFileインターフェースポインタpPersistFileをNULLで初期化.
	TCHAR tszSrcPath[MAX_PATH] = {0};	// tszSrcPath(長さMAX_PATH)を{0}で初期化.

	// 実行ファイルがあるフォルダのパスを取得.
	GetModuleFileName(NULL, tszSrcPath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.
	PathRemoveFileSpec(tszSrcPath);	// PathRemoveFileSpecでファイル名の部分を取り除く.

	// ファイルの実体は上記パスの下の"test.txt".
	_tcscat(tszSrcPath, _T("\\test.txt"));	// 上記パスに"\test.txt"を連結.

	// 実体パスを出力.
	_tprintf(_T("tszSrcPath = %s\n"), tszSrcPath);	// tszSrcPathを出力.

	// インスタンス作成.
	HRESULT hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&pShellLink);	// CoCreateInstanceでIShellLinkのインスタンスポインタをpShellLinkに格納.
	if (FAILED(hr)){	// 失敗.
		_tprintf(_T("CoCreateInstance failed!\n"));	// "CoCreateInstance failed!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return 0;	// 0を返して終了.
	}

	// 成功.
	_tprintf(_T("pShellLink success!, pShellLink = 0x%08x\n"), (unsigned int)pShellLink);	// "pShellLink success!"とともにpShellLinkの値を出力.

	// ファイル実体のパスをセット.
	pShellLink->SetPath(tszSrcPath);	// pShellLink->SetPathでtszSrcPathをセット.

	// 確認のためパスを取得.
	TCHAR tszPath[MAX_PATH] = {0};	// tszPath(長さMAX_PATH)を{0}で初期化.
	pShellLink->GetPath(tszPath, MAX_PATH, NULL, SLGP_UNCPRIORITY);	// pShellLink->GetPathでパスをtszPathに格納.

	// パスを出力.
	_tprintf(_T("tszPath = %s\n"), tszPath);	// tszPathを出力.

	// IPersistFileインターフェースポインタを取得.
	hr = pShellLink->QueryInterface(IID_PPV_ARGS(&pPersistFile));	// pShellLink->QueryInterfaceでIPersistFileインターフェースポインタpPersistFileを取得.
	if (FAILED(hr)){	// 失敗.
		_tprintf(_T("pShellLink->QueryInterface failed!\n"));	// "pShellLink->QueryInterface failed!"と出力.
		pShellLink->Release();	// pShellLink->Releaseで解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return 0;	// 0を返して終了.
	}

	// 成功.
	_tprintf(_T("pPersistFile success!, pPersistFile = 0x%08x\n"), (unsigned int)pPersistFile);

	// 解放.
	pPersistFile->Release();	// pPersistFile->Releaseで解放.
	pShellLink->Release();	// pShellLink->Releaseで解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}