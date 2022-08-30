// CButtonDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CButton.h"
#include "CButtonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonDlg ダイアログ




CButtonDlg::CButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CButtonDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CButtonDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CButtonDlg メッセージ ハンドラ

BOOL CButtonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_pButton1 = new CWnd();	// CWndオブジェクトを生成し, ポインタをm_pButton1に格納.
	RECT rc1 = {50, 50, 150, 100};	// RECT構造体rc1を{50, 50, 150, 100}で初期化.
	m_pButton1->Create(_T("BUTTON"), _T("Button1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rc1, this, WM_APP + 1);	// m_pButton1->Createでウィンドウ生成.
	m_pButton2 = new CButton();	// CButtonオブジェクトを生成し, ポインタをm_pButton2に格納.
	RECT rc2 = {50, 150, 150, 200};	// RECT構造体rc2を{50, 150, 150, 200}で初期化.
	m_pButton2->Create(_T("Button2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rc2, this, WM_APP + 2);	// m_pButton2->Createでウィンドウ生成.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CButtonDlg::OnPaint()
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
HCURSOR CButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CButtonDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ここにメッセージ ハンドラ コードを追加します。
	if (m_pButton1 != NULL){	// NULLでない.
		delete m_pButton1;	// deleteでm_pButton1を解放.
		m_pButton1 = NULL;	// m_pButton1にNULLを代入.
	}
	if (m_pButton2 != NULL){	// NULLでない.
		delete m_pButton2;	// deleteでm_pButton2を解放.
		m_pButton2 = NULL;	// m_pButton2にNULLを代入.
	}
}
