// DDX_ScrollDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_Scroll.h"
#include "DDX_ScrollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_ScrollDlg ダイアログ




CDDX_ScrollDlg::CDDX_ScrollDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_ScrollDlg::IDD, pParent)
	, m_xvScrollBar1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_ScrollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_xcScrollBar1);
	DDX_Scroll(pDX, IDC_SCROLLBAR1, m_xvScrollBar1);
}

BEGIN_MESSAGE_MAP(CDDX_ScrollDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_ScrollDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_ScrollDlg メッセージ ハンドラ

BOOL CDDX_ScrollDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	// スクロールバーの初期化.
	m_xcScrollBar1.SetScrollRange(0, 100);	// m_xcScrollBar1.SetScrollRangeで範囲を(0, 100)とする.
	m_xcScrollBar1.SetScrollPos(50);	// m_xcScrollBar1.SetScrollPosで位置を50にする.
	
	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDDX_ScrollDlg::OnPaint()
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
HCURSOR CDDX_ScrollDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_ScrollDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// 更新.
	UpdateData();	// UpdateDataでデータの更新.
	// つまみ位置の表示..
	TCHAR tszPos[32] = {0};	// TCHAR型文字列バッファtszPos(長さ32)を0で初期化.
	_stprintf(tszPos, _T("tszPos = %d\n"), m_xvScrollBar1);	// _stprintfでm_xvScrollBar1をtszPosに変換.
	AfxMessageBox(tszPos);	// tszPosを表示.
}
