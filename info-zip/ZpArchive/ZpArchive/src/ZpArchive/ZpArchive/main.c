// マクロの宣言
#define API

// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <shlwapi.h>	// シェルAPI
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <structs.h>	// Info-ZIP(DLL)

// typedef
typedef int (WINAPI * _DLL_ZIP)(ZCL, LPZPOPT);
typedef int (WINAPI * _ZIP_USER_FUNCTIONS)(LPZIPUSERFUNCTIONS);

// 関数ポインタの宣言
_DLL_ZIP fpZpArchive;	// ZpArchiveの関数ポインタ
_ZIP_USER_FUNCTIONS fpZpInit;	// ZpInitの関数ポインタ

// グローバル変数の宣言
HANDLE g_hZUF = (HANDLE)NULL;	// ユーザファンクションのハンドルを(HANDLE)NULLで初期化.
LPZIPUSERFUNCTIONS g_lpZipUserFunctions;	// ユーザファンクションポインタ.
HINSTANCE g_hZipDll;	// DLLのハンドル.
ZPOPT g_ZpOpt;	// オプション情報の構造体.
ZCL g_ZpZCL;	// コマンドライン情報の構造体.
HANDLE g_hFileList;	// ファイルリストのハンドル.

// DummyPrint
int WINAPI DummyPrint(char far *buf, unsigned long size){
	return (unsigned int) size;
}
// DummyPassword
int WINAPI DummyPassword(LPSTR p, int n, LPCSTR m, LPCSTR name){
	return 1;
}
// DummyComment
int WINAPI DummyComment(char far *szBuf){
	szBuf[0] = '\0';
	return TRUE;
}

// main関数の定義
int main(int argc, char *argv[]){	// main関数

	// 変数の宣言
	int iInit;	// ZpInitの戻り値.
	char szFullPath[PATH_MAX];	// DLLのあるフォルダ位置のフルパス.
	LPSTR szFileList;	// ファイルリスト文字列ポインタ.
	char **index;	// ファイルリストインデックス.
	int cc;	// ポインタサイズxファイル数.
	char *file;	// ファイル文字列.
	int ret;	// ZpArchiveの戻り値.
	char szPath[PATH_MAX];	// パス.

	// ユーザファンクションのメモリを確保.
	g_hZUF = GlobalAlloc(GPTR, (DWORD)sizeof(ZIPUSERFUNCTIONS));	// GlobalAllocで確保.
	g_lpZipUserFunctions = (LPZIPUSERFUNCTIONS)GlobalLock(g_hZUF);	// GlobalLockでロック.

	// ユーザファンクションのセット.
	g_lpZipUserFunctions->print = DummyPrint;	// ダミー出力
	g_lpZipUserFunctions->password = DummyPassword;	// ダミーパスワード
	g_lpZipUserFunctions->comment = DummyComment;	// ダミーコメント

	// DLLのロード.
	g_hZipDll = LoadLibrary("zip32z64.dll");	// LoadLibraryで"zip32z64.dll"をロード.

	// 関数ポインタの取得.
	(_ZIP_USER_FUNCTIONS)fpZpInit = (_ZIP_USER_FUNCTIONS)GetProcAddress(g_hZipDll, "ZpInit");	// ZpInitのポインタ取得.
	(_DLL_ZIP)fpZpArchive = (_DLL_ZIP)GetProcAddress(g_hZipDll, "ZpArchive");	// ZpArchiveのポインタ取得.

	// ZpInitによる初期化の実行.
	iInit = (*fpZpInit)(g_lpZipUserFunctions);

	// g_ZpOptの初期化.
	memset(&g_ZpOpt, 0, sizeof(g_ZpOpt));	// memsetでg_ZpOptを0で初期化.
	g_ZpOpt.fLevel = '6';	// レベル6.
	g_ZpOpt.szRootDir = szFullPath;	// ルートディレクトリを szFullPathに.
	GetModuleFileName(NULL, szPath, MAX_PATH);	// モジュールパスを取得.
	PathRemoveFileSpec(szPath);	// 最後のファイル要素を削除.
	strcpy(szFullPath, szPath);	// szPathをコピー.

	// g_ZpZCLの初期化.
	g_ZpZCL.argc = 1;	// 1とする.
	g_ZpZCL.lpszZipFN = "test.zip";	// "test.zip"とする.

	// ファイルリストの作成.
	g_hFileList = GlobalAlloc(GPTR, 0x10000);	// GlobalAllocで確保.
	szFileList = (char *)GlobalLock(g_hFileList);	// GlobalLockでロック.
	index = (char **)szFileList;	// 先頭アドレスをcharのポインタポインタにキャストしてindexに格納.
	cc = (sizeof(char *) * g_ZpZCL.argc);	// ポインタサイズxファイル数.
	file = szFileList + cc;	// fileをccに.
	cc = lstrlen("test.txt");	// "test.txt"を追加.
    lstrcpy(file, "test.txt");	// fileにコピー.
    index[0] = file;	// fileを0番目に.
    file += (cc + 1);	// fileを進める.
	g_ZpZCL.FNV = (char **)szFileList;	// ファイルリストを追加.

	// ZpArchiveによる圧縮(アーカイブ作成)
	ret = (*fpZpArchive)(g_ZpZCL, &g_ZpOpt);
	if (ret == 0){	// 成功.
		MessageBox(NULL, "OK", "ZpArchive", MB_OK);
	}

	// ファイルリストの解放.
	GlobalUnlock(g_hFileList);	// GlobalUnlockでアンロック.
	GlobalFree(g_hFileList);	// GlobalFreeで解放.

	// DLLのアンロード.
	FreeLibrary(g_hZipDll);	// FreeLibraryで解放.

	// ユーザファンクションの解放.
	GlobalUnlock(g_hZUF);	// GlobalLockでアンロック.
	GlobalFree(g_hZUF);	// GlobalFreeで解放.

	// プログラムの終了.
	return 0;

}