// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <shlwapi.h>	// シェルAPI
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <structs.h>	// Info-ZIP(DLL)

// typedef
typedef int (WINAPI * _DLL_UNZIP)(int, char **, int, char **, LPDCL, LPUSERFUNCTIONS);

// 関数ポインタの宣言
_DLL_UNZIP fpWiz_SingleEntryUnzip;	// Wiz_SingleEntryUnzipの関数ポインタ

// グローバル変数の宣言
HANDLE g_hUF = (HANDLE)NULL;	// ユーザファンクションハンドル.
LPUSERFUNCTIONS g_lpUserFunctions;	// ユーザファンクションポインタ.
HINSTANCE g_hUnzipDll;	// DLLのハンドル.
HANDLE g_hDCL = (HANDLE)NULL;	// DCLハンドル.
LPDCL g_lpDCL;	// DCLポインタ.

// GetReplaceDlgRetVal
int WINAPI GetReplaceDlgRetVal(LPSTR filename, unsigned fnbufsiz){
	return 1;
}
// password
int WINAPI password(LPSTR p, int n, LPCSTR m, LPCSTR name){
	return 1;
}
// DisplayBuf
int WINAPI DisplayBuf(LPSTR buf, unsigned long size){
	printf("%s", (char *)buf);
	return (int)(unsigned int)size;
}
// ReceiveDllMessage
void WINAPI ReceiveDllMessage(z_uint8 ucsize, z_uint8 csiz, unsigned cfactor, unsigned mo, unsigned dy, unsigned yr, unsigned hh, unsigned mm, TCHAR c, LPCSTR filename, LPCSTR methbuf, unsigned long crc, CHAR fCrypt){

}

// main関数の定義
int main(int argc, char *argv[]){	// main関数

	// 変数の宣言
	char szPath[MAX_PATH];	// パス.
	char szDest[MAX_PATH];	// 出力先.
	int ret;	// Wiz_SingleEntryUnzipの戻り値.

	// メモリを確保.
	g_hUF = GlobalAlloc(GPTR, (DWORD)sizeof(USERFUNCTIONS));	// GlobalAllocで確保.
	g_hDCL = GlobalAlloc(GPTR, (DWORD)sizeof(DCL));	// GlobalAllocで確保.

	// ポインタを取得.
	g_lpUserFunctions = (LPUSERFUNCTIONS)GlobalLock(g_hUF);	// g_hUFでロック.
	g_lpDCL = (LPDCL)GlobalLock(g_hDCL);	// GlobalLockでロック.

	// ユーザファンクションのセット.
	g_lpUserFunctions->password = password;	// パスワード
	g_lpUserFunctions->print = DisplayBuf;	// バッファ表示
	g_lpUserFunctions->sound = NULL;	// NULL
	g_lpUserFunctions->replace = GetReplaceDlgRetVal;	// リプレース
	g_lpUserFunctions->SendApplicationMessage = ReceiveDllMessage;	// DLLメッセージ受信

	// DLLのロード.
	g_hUnzipDll = LoadLibrary("unzip32.dll");	// LoadLibraryで"unzip32.dll"をロード.

	// 関数ポインタの取得.
	fpWiz_SingleEntryUnzip = (_DLL_UNZIP)GetProcAddress(g_hUnzipDll, "Wiz_SingleEntryUnzip");	// Wiz_SingleEntryUnzipのポインタ取得.

	// g_lpDCLの初期化.
	memset(g_lpDCL, 0, sizeof(DCL));	// memsetでg_lpDCLを0で初期化.
	g_lpDCL->StructVersID = UZ_DCL_STRUCTVER;
	g_lpDCL->ndflag = 1;
	g_lpDCL->noflag = 1;
	GetModuleFileName(NULL, szPath, MAX_PATH);	// モジュールパスを取得.
	PathRemoveFileSpec(szPath);	// 最後のファイル要素を削除.
	strcpy(szDest, szPath);	// パスをコピー.
	g_lpDCL->lpszExtractDir = szDest;	// 出力先.
	strcat(szPath, "\\test.zip");	// "\test.zip"を連結.
	g_lpDCL->lpszZipFN = szPath;	// 解凍元.

	// Wiz_SingleEntryUnzipによる解凍(アーカイブ展開).
	ret = (*fpWiz_SingleEntryUnzip)(0, NULL, 0, NULL, g_lpDCL, g_lpUserFunctions);
	if (ret == 0){	// 成功.
		MessageBox(NULL, "OK", "Wiz_SingleEntryUnzip", MB_OK);
	}

	// DLLのアンロード.
	FreeLibrary(g_hUnzipDll);	// FreeLibraryで解放.

	// アンロック
	GlobalUnlock(g_hUF);	// GlobalUnlockでアンロック.
	GlobalUnlock(g_hDCL);	// GlobalUnlockでアンロック.

	// 解放
	GlobalFree(g_hUF);	// GlobalFreeで解放.
	GlobalFree(g_hDCL);	// GlobalFreeで解放.

	// プログラムの終了.
	return 0;

}