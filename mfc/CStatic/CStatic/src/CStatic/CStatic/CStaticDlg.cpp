// CStaticDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CStatic.h"
#include "CStaticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDlg ダイアログ




CStaticDlg::CStaticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStaticDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CStaticDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CStaticDlg メッセージ ハンドラ

BOOL CStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	HICON hIcon = theApp.LoadIcon(IDI_ICON1);	// CWnd::LoadIconでIDI_ICON1をロード.(theAppはexternなので, ここからも呼べる.)
	SetIcon(hIcon, TRUE);	// CWnd::SetIconでhIconをセット.(TRUEなので大きいアイコンにセット.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIconでhIconをセット.(FALSEなので小さいアイコンにセット.)

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CStaticDlg::OnPaint()
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
HCURSOR CStaticDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStaticDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// ボタンが押されたら, IDC_STATIC1に"Hello, world!", IDC_STATIC2にbitmap1.bmp(IDB_BITMAP1)をセット.
	CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_STATIC1);	// GetDlgItemでスタティックコントロールIDC_STATIC1のオブジェクトポインタをpStatic1に格納.((CStatic *)にキャスト.)
	pStatic1->SetWindowText(_T("Hello, world!"));	// pStatic1->SetWindowTextでIDC_STATIC1に"Hello, world!"をセット.
	m_cBitmap.LoadBitmap(IDB_BITMAP1);	// m_cBitmap.LoadBitmapでIDB_BITMAP1をロード.
	CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_STATIC2);	// GetDlgItemでスタティックコントロールIDC_STATIC2のオブジェクトポインタをpStatic2に格納.((CStatic *)にキャスト.)
	pStatic2->SetBitmap(m_cBitmap);	// pStatic2->SetBitmapでIDC_STATIC2にm_cBitmapをセット.
}
