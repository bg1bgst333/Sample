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
	ON_WM_HSCROLL()
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
	// スクロールバーの初期化.
	CScrollBar *pScrollBar1 = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR1);	// GetDlgItemでスクロールバーコントロールIDC_SCROLLBAR1のオブジェクトポインタをpScrollBar1に格納.((CScrollBar *)にキャスト.)
	pScrollBar1->SetScrollRange(0, 100);	// pScrollBar1->SetScrollRangeで範囲を0～100にする.
	pScrollBar1->SetScrollPos(0);	// pScrollBar1->SetScrollPosで位置を0にする.

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


void CWnd_Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
	// 渡されたCScrollBarオブジェクトポインタがNULLの時.
	if (pScrollBar == NULL){	// pScrollBarがNULLの時.
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);	// 引数をCDialog::OnHScrollに渡して任せる.
		return;	// ここで終了.
	}
	// スクロールバーの位置更新.
	int iNewPos = pScrollBar->GetScrollPos();	// 更新後の位置iNewPosをひとまずpScrollBar->GetScrollPos(), つまり現在位置にする.
	int iMinPos = 0;	// 最小値iMinPos.
	int iMaxPos = 0;	// 最大値iMaxPos.
	pScrollBar->GetScrollRange(&iMinPos, &iMaxPos);	// pScrollBar->GetScrollRangeで最小値, 最大値を取得.
	switch (nSBCode){	// nSBCodeの値で振り分け.
		case SB_THUMBTRACK:		// スクロールつまみを持った時.
		case SB_THUMBPOSITION:	// スクロールつまみが離された時.
			iNewPos = (int)nPos;	// iNewPosにnPosをセット.(更新後もnPos.)
			break;
		case SB_LEFT:	// 左端の時.
			iNewPos = iMinPos;	// iNewPosにiMinPosをセット.
			break;
		case SB_RIGHT:	// 右端の時.
			iNewPos = iMaxPos;	// iNewPosにiMaxPosをセット.
			break;
		case SB_LINERIGHT:	// 右端のボタンを押す.
			if ((int)nPos < iMaxPos - 1 + 1){	// 最大値より小さいなら下げられる.(今回は1行で1ページとする.)
				iNewPos++;	// 1つ増やす.
			}
			break;
		case SB_LINELEFT:	//	左端のボタンを押す.
			if ((int)nPos > iMinPos){	// 最小値より大きいなら上げられる.(今回は1行で1ページ.)
				iNewPos--;	// 1つ減らす.
			}
			break;
		case SB_PAGERIGHT:	// 右の余白を押す.
			iNewPos += 1;	// 1ページ分増やす.(今回は1行下げる.)
			break;
		case SB_PAGELEFT:	// 左の余白を押す.
			iNewPos -= 1;	// 1ページ分減らす.(今回は1行上げる.)
			break;
		default:
			break;
	}
	// 新しい位置をセット.
	pScrollBar->SetScrollPos(iNewPos);	// pScrollBar->SetScrollPosでiNewPosをセット.
	// あと親クラスのOnHScrollに任せる.
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
