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
	m_pStatic1 = new CStatic();	// CStaticオブジェクトを生成し, ポインタをm_pStatic1に格納.
	RECT rc1 = {50, 50, 150, 100};	// RECT構造体rc1を{50, 50, 150, 100}で初期化.
	m_pStatic1->Create(_T("Static1"), WS_CHILD | WS_VISIBLE | SS_BITMAP, rc1, this);	// m_pStatic1->Createでウィンドウ生成.
	m_pBitmap1 = new CBitmap();	// CBitmapオブジェクトを生成し, ポインタをm_pBitmap1に格納.
	BOOL bRet = m_pBitmap1->LoadBitmap(IDB_BITMAP1);	// CBitmap::LoadBitmapでIDB_BITMAP1をロード.
	if (bRet){	// 成功.
		HBITMAP hBitmap1 = (HBITMAP)(*m_pBitmap1);	// HBITMAP演算子により, ビットマップハンドルhBitmap1を取得.
		HBITMAP hOldBitmap1 = m_pStatic1->SetBitmap(hBitmap1);	// CStatic::SetBitmapでhBitmap1をセット.
	}

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
	if (m_pBitmap1 != NULL){	// NULLでない.
		delete m_pBitmap1;	// deleteでm_pBitmap1を解放.
		m_pBitmap1 = NULL;	// m_pBitmap1にNULLを代入.
	}
}
