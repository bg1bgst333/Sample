// CBitmapDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CBitmap.h"
#include "CBitmapDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitmapDlg ダイアログ




CBitmapDlg::CBitmapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBitmapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitmapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBitmapDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBitmapDlg メッセージ ハンドラ

BOOL CBitmapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	CBitmap *pBitmap = new CBitmap();	// CBitmapオブジェクトを生成し, ポインタをpBitmapに格納.
	BOOL bRet = pBitmap->LoadBitmap(IDB_BITMAP1);	// CBitmap::LoadBitmapでIDB_BITMAP1をロード.
	if (bRet){	// 成功.
		AfxMessageBox(_T("CBitmap::LoadBitmap Success!"));	// "CBitmap::LoadBitmap Success!"と表示.
	}
	else{	// 失敗.
		AfxMessageBox(_T("CBitmap::LoadBitmap Failed!"));	// "CBitmap::LoadBitmap Failed!"と表示.
	}
	delete pBitmap;	// pBitmapを解放.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CBitmapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CBitmapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

