// CScrollBarDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CScrollBar.h"
#include "CScrollBarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScrollBarDlg ダイアログ




CScrollBarDlg::CScrollBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollBarDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScrollBarDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CScrollBarDlg メッセージ ハンドラ

BOOL CScrollBarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	CWinApp *pApp = AfxGetApp();	// AfxGetApp()でtheAppのポインタ取得.
	HICON hIcon = ::LoadIcon(pApp->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));	// ::LoadIconでIDI_ICON1(icon1.ico)をロード, ハンドルをhIconに格納.
	SetIcon(hIcon, TRUE);	// CWnd::SetIconでhIconをセット.(TRUEなので大きいアイコンにセット.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIconでhIconをセット.(FALSEなので小さいアイコンにセット.)

	// スクロールバーの初期化(位置を真ん中にセット.)
	CScrollBar *pScrollBar1 = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR1);	// GetDlgItemでスクロールバーコントロールIDC_SCROLLBAR1のオブジェクトポインタをpScrollBar1に格納.((CScrollBar *)にキャスト.)
	pScrollBar1->SetScrollRange(0, 100);	// pScrollBar1->SetScrollRangeで範囲を0～100にする.
	pScrollBar1->SetScrollPos(50);	// pScrollBar1->SetScrollPosで位置を50にする.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CScrollBarDlg::OnPaint()
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
HCURSOR CScrollBarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

