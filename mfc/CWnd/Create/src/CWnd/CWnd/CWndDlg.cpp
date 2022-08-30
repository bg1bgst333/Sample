// CWndDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CWnd.h"
#include "CWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWndDlg ダイアログ




CWndDlg::CWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWndDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWndDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CWndDlg メッセージ ハンドラ

BOOL CWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_pButton1 = new CWnd();	// CWndオブジェクトを生成し, ポインタをm_pButton1に格納.
	RECT rc = {50, 50, 150, 100};	// RECT構造体rcを{50, 50, 150, 100}で初期化.
	m_pButton1->Create(_T("BUTTON"), _T("Button1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rc, this, WM_APP + 1);	// m_pButton1->Createでウィンドウ生成.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CWndDlg::OnPaint()
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
HCURSOR CWndDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWndDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ここにメッセージ ハンドラ コードを追加します。
	if (m_pButton1 != NULL){	// NULLでない.
		delete m_pButton1;	// deleteでm_pButton1を解放.
		m_pButton1 = NULL;	// m_pButton1にNULLを代入.
	}

}
