// DDX_TextDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_Text.h"
#include "DDX_TextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// DDX_TextDlg ダイアログ




DDX_TextDlg::DDX_TextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DDX_TextDlg::IDD, pParent)
	, m_xvEdit1(0)
	, m_xvEdit2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void DDX_TextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_xvEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_xvEdit2);
}

BEGIN_MESSAGE_MAP(DDX_TextDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &DDX_TextDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// DDX_TextDlg メッセージ ハンドラ

BOOL DDX_TextDlg::OnInitDialog()
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

void DDX_TextDlg::OnPaint()
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
HCURSOR DDX_TextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void DDX_TextDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	UpdateData();	// UpdateData(デフォルト引数は1(TRUE))でDDX変数を更新.
	m_xvEdit2 = m_xvEdit1;	// m_xvEdit1の内容をm_xvEdit2に代入.
	UpdateData(FALSE);	// UpdateData(FALSE)でDDX変数の内容をコントロールに反映.
}
