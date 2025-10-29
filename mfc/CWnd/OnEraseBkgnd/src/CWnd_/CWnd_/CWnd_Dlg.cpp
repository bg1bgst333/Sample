// CWnd_Dlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CWnd_.h"
#include "CWnd_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWnd_Dlg ダイアログ




CWnd_Dlg::CWnd_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWnd_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWnd_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWnd_Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CWnd_Dlg メッセージ ハンドラ

BOOL CWnd_Dlg::OnInitDialog()
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

void CWnd_Dlg::OnPaint()
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
HCURSOR CWnd_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWnd_Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラ コードを追加します。
	// 引数をキャプションに表示.
	TCHAR tszSize[1024] = {0};	// tszSize(長さ1024)を{0}で初期化.
	_stprintf(tszSize, _T("nType = %lu, cx = %d, cy = %d"), nType, cx, cy);	// _stprintfでnType, cx, cyをテキストtszSizeに変換.
	SetWindowText(tszSize);	// SetWindowTextでtszSizeをキャプションにセット.

	// エディットボックスのサイズがウィンドウに追随するように.
	CWnd *pEdit1 = GetDlgItem(IDC_EDIT1);
	RECT rc = {0};
	rc.left = 221;
	rc.top = 21;
	rc.right = cx - 10;
	rc.bottom = cy - 10;
	pEdit1->MoveWindow(&rc);	// CWnd::MoveWindowでpEdit1をrcの矩形に従って移動&リサイズ.

}

BOOL CWnd_Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
	RECT rc = {0};
	::GetClientRect(m_hWnd, &rc);
	HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
	HPEN hPen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(pDC->m_hDC, hBrush);
	HPEN hOldPen = (HPEN)::SelectObject(pDC->m_hDC, hPen);
	::Rectangle(pDC->m_hDC, rc.left, rc.top, rc.right, rc.bottom);
	::SelectObject(pDC->m_hDC, hOldPen);
	::SelectObject(pDC->m_hDC, hOldBrush);
	::DeleteObject(hPen);
	::DeleteObject(hBrush);
	return TRUE;
	//return CDialog::OnEraseBkgnd(pDC);
}
