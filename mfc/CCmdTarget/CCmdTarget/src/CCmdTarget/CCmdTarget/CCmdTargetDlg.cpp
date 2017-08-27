// CCmdTargetDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CCmdTarget.h"
#include "CCmdTargetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmdTargetDlg ダイアログ




CCmdTargetDlg::CCmdTargetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCmdTargetDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCmdTargetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCmdTargetDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCmdTargetDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCmdTargetDlg メッセージ ハンドラ

BOOL CCmdTargetDlg::OnInitDialog()
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

void CCmdTargetDlg::OnPaint()
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
HCURSOR CCmdTargetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCmdTargetDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// メッセージボックスの表示.
	AfxMessageBox(_T("Button1 Clicked!"));	// AfxMessageBoxで"Button1 Clicked!"と表示.
}

// OnCmdMsgをオーバーライドしてみる.
BOOL CCmdTargetDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo){

	// メッセージボックスの表示.
	AfxMessageBox(_T("OnCmdMsg!"));	// AfxMessageBoxで"OnCmdMsg!"と表示.
	//return TRUE;	// TRUEを返す.(これだと, コマンド処理すべてここで処理済になってしまう.)
	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);	// 基底クラスに任せる.

}