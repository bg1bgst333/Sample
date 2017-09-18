// DDX_ControlDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_Control.h"
#include "DDX_ControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_ControlDlg ダイアログ




CDDX_ControlDlg::CDDX_ControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_ControlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_ControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_xcListBox1);
}

BEGIN_MESSAGE_MAP(CDDX_ControlDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_ControlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_ControlDlg メッセージ ハンドラ

BOOL CDDX_ControlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	// アイテムの追加.
	m_xcListBox1.AddString(_T("Item1"));	// m_xcListBox1.AddStringで"Item1"を追加.
	m_xcListBox1.AddString(_T("Item2"));	// m_xcListBox1.AddStringで"Item2"を追加.
	m_xcListBox1.AddString(_T("Item3"));	// m_xcListBox1.AddStringで"Item3"を追加.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDDX_ControlDlg::OnPaint()
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
HCURSOR CDDX_ControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_ControlDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// さらなるアイテムの追加.
	m_xcListBox1.AddString(_T("Item4"));	// m_xcListBox1.AddStringで"Item4"を追加.
	m_xcListBox1.AddString(_T("Item5"));	// m_xcListBox1.AddStringで"Item5"を追加.
}
