// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <winsock2.h>	// Windowsソケット
#include <iphlpapi.h>	// IPヘルパーAPI
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.
	
	// 変数の初期化
	PIP_INTERFACE_INFO pIpInterfaceInfo = NULL;	// インターフェース情報pIpInterfaceInfoをNULLに初期化.
	DWORD dwOutBufLen = 0;	// インターフェース情報のサイズdwOutBufLenを0に初期化.
	int i = 0;	// ループ用変数iを0に初期化.

	// インターフェース情報を格納するのに必要なバッファサイズを取得.
	GetInterfaceInfo(NULL, &dwOutBufLen);	// GetInterfaceInfoの第1引数にNULLを指定すると必要なバッファサイズを取得できる.

	// バッファを確保.
	pIpInterfaceInfo = (PIP_INTERFACE_INFO)new BYTE[dwOutBufLen];	// newでdwOutBufLen分のメモリを確保し, PIP_INTERFACE_INFOにキャストして, pIpInterfaceInfoに格納.

	// インターフェース情報の取得.
	GetInterfaceInfo(pIpInterfaceInfo, &dwOutBufLen);	// GetInterfaceInfoでインターフェース情報を取得し, pIpInterfaceInfoに格納.

	// インターフェース一覧の列挙.
	for (i = 0; i < pIpInterfaceInfo->NumAdapters; i++){	// for文でpIpInterfaceInfo->NumAdaptersの分だけ繰り返す.

		// インターフェースのIndexとNameを列挙.
		_tprintf(_T("pIpInterfaceInfo->Adapter[%d].Index = %u, pIpInterfaceInfo->Adapter[%d].Name = %s\n"), i, pIpInterfaceInfo->Adapter[i].Index, i, pIpInterfaceInfo->Adapter[i].Name);	// _tprintfでpIpInterfaceInfo->Adapter[i].IndexとpIpInterfaceInfo->Adapter[i].Nameを出力.

	}

	// バッファの破棄.
	delete [] pIpInterfaceInfo;

	// プログラムの終了
	return 0;

}