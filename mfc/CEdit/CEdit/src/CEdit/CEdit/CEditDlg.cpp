// CEditDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CEdit.h"
#include "CEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDlg ダイアログ




CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CEditDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CEditDlg メッセージ ハンドラ

BOOL CEditDlg::OnInitDialog()
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

void CEditDlg::OnPaint()
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
HCURSOR CEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEditDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// ボタンが押されたら, IDC_EDIT1にセットされた文字列を取得して, MessageBoxで表示.
	CEdit *pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);	// GetDlgItemでエディットコントロールIDC_EDIT1のオブジェクトポインタをpEdit1に格納.((CEdit *)にキャスト.)
	TCHAR tszBuf[256];	// TCHAR型バッファtszBuf(要素数256).
	int iLen = pEdit1->GetLine(0, tszBuf, 255);	// pEdit1->GetLineで0行目の文字列を取得し, tszBufに格納(最大255文字), 戻り値のコピーした文字数はiLenに格納.
	tszBuf[iLen] = _T('\0');	// 最後の文字の次には'\0'を入れる.
	MessageBox(tszBuf, _T("CEdit"), MB_ICONASTERISK);	// MessageBoxでtszBufを表示.
}
