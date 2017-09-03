// DDX_RadioDlg.cpp : 実装ファイル
//

#include <stdio.h>
#include <tchar.h>

#include "stdafx.h"
#include "DDX_Radio.h"
#include "DDX_RadioDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_RadioDlg ダイアログ




CDDX_RadioDlg::CDDX_RadioDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_RadioDlg::IDD, pParent)
	, m_xvRadio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_RadioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_xvRadio1);
}

BEGIN_MESSAGE_MAP(CDDX_RadioDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_RadioDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_RadioDlg メッセージ ハンドラ

BOOL CDDX_RadioDlg::OnInitDialog()
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

void CDDX_RadioDlg::OnPaint()
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
HCURSOR CDDX_RadioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_RadioDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	UpdateData();	// UpdateDataで変数を更新.
	TCHAR tszRadio1[128] = {0};	// TCHAR型配列tszRadio1(長さ128)を0で初期化.
	_stprintf(tszRadio1, _T("m_xvRadio1 = %d"), m_xvRadio1);	// _stprintfでm_xvRadio1をtszRadio1に変換.
	AfxMessageBox(tszRadio1);	// AfxMessageBoxでtszRadio1を表示.
}
