// DDX_CheckDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_Check.h"
#include "DDX_CheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_CheckDlg ダイアログ




CDDX_CheckDlg::CDDX_CheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_CheckDlg::IDD, pParent)
	, m_xvCheck1(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_CheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_xvCheck1);
}

BEGIN_MESSAGE_MAP(CDDX_CheckDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_CheckDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_CheckDlg メッセージ ハンドラ

BOOL CDDX_CheckDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDDX_CheckDlg::OnPaint()
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
HCURSOR CDDX_CheckDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_CheckDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	UpdateData();	// UpdateDataで更新.
	if (m_xvCheck1){	// m_xvCheck1が1(TRUE)なら.
		AfxMessageBox(_T("Check1 ON!"));	// "Check1 ON!"と表示.
	}
	else{
		AfxMessageBox(_T("Check1 OFF!"));	// "Check1 OFF!"と表示.
	}
}
