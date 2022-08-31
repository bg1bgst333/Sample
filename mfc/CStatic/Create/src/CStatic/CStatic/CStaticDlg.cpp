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
	ON_WM_DESTROY()
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
	m_pStatic1 = new CWnd();	// CWndオブジェクトを生成し, ポインタをm_pStatic1に格納.
	RECT rc1 = {50, 50, 150, 100};	// RECT構造体rc1を{50, 50, 150, 100}で初期化.
	m_pStatic1->Create(_T("STATIC"), _T("Static1"), WS_CHILD | WS_VISIBLE | SS_LEFT, rc1, this, WM_APP + 1);	// m_pStatic1->Createでウィンドウ生成.
	m_pStatic2 = new CStatic();	// CStaticオブジェクトを生成し, ポインタをm_pStatic2に格納.
	RECT rc2 = {50, 150, 150, 200};	// RECT構造体rc2を{50, 150, 150, 200}で初期化.
	m_pStatic2->Create(_T("Static2"), WS_CHILD | WS_VISIBLE | SS_LEFT, rc2, this);	// m_pStatic2->Createでウィンドウ生成.

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


void CStaticDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ここにメッセージ ハンドラ コードを追加します。
	if (m_pStatic1 != NULL){	// NULLでない.
		delete m_pStatic1;	// deleteでm_pStatic1を解放.
		m_pStatic1 = NULL;	// m_pStatic1にNULLを代入.
	}
	if (m_pStatic2 != NULL){	// NULLでない.
		delete m_pStatic2;	// deleteでm_pStatic2を解放.
		m_pStatic2 = NULL;	// m_pStatic2にNULLを代入.
	}
}
