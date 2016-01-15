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
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CButtonDlg::OnBnClickedButton2)
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


void CButtonDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CButton *pButton1 = (CButton *)GetDlgItem(IDC_BUTTON1);	// GetDlgItemでIDC_BUTTON1に紐付けられたボタンコントロールオブジェクトポインタをpButton1に格納.((CButton *)にキャスト.)
	CButton *pButton2 = (CButton *)GetDlgItem(IDC_BUTTON2);	// GetDlgItemでIDC_BUTTON2に紐付けられたボタンコントロールオブジェクトポインタをpButton2に格納.((CButton *)にキャスト.)

	// ボタン名の変更.
	pButton1->SetWindowText(_T("Clicked!(1)"));	// SetWindowTextでボタン名を"Clicked!(1)"に変更.(SetWindowTextはCWndのメソッド.)
	pButton2->SetWindowText(_T("Clicked!(1)"));	// SetWindowTextでボタン名を"Clicked!(1)"に変更.(SetWindowTextはCWndのメソッド.)

	// ボタンスタイルの取得.
	UINT uStyle1 = pButton1->GetButtonStyle();	// GetButtonStyleでpButton1のボタンスタイル取得.(GetButtonStyleはCButtonのメソッド.)
	if (uStyle1 == BS_PUSHBUTTON){	// プッシュボタンの場合.
		AfxMessageBox(_T("BS_PUSHBUTTON"));	// "BS_PUSHBUTTON"と表示.
	}
	else{	// デフォルトのプッシュボタンの場合.
		AfxMessageBox(_T("BS_DEFPUSHBUTTON"));	// "BS_DEFPUSHBUTTON"と表示.
	}
	UINT uStyle2 = pButton2->GetButtonStyle();	// GetButtonStyleでpButton2のボタンスタイル取得.(GetButtonStyleはCButtonのメソッド.)
	if (uStyle2 == BS_PUSHBUTTON){	// プッシュボタンの場合.
		AfxMessageBox(_T("BS_PUSHBUTTON"));	// "BS_PUSHBUTTON"と表示.
	}
	else{	// デフォルトのプッシュボタンの場合.
		AfxMessageBox(_T("BS_DEFPUSHBUTTON"));	// "BS_DEFPUSHBUTTON"と表示.
	}
}

void CButtonDlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CButton *pButton1 = (CButton *)GetDlgItem(IDC_BUTTON1);	// GetDlgItemでIDC_BUTTON1に紐付けられたボタンコントロールオブジェクトポインタをpButton1に格納.((CButton *)にキャスト.)
	CButton *pButton2 = (CButton *)GetDlgItem(IDC_BUTTON2);	// GetDlgItemでIDC_BUTTON2に紐付けられたボタンコントロールオブジェクトポインタをpButton2に格納.((CButton *)にキャスト.)

	// ボタン名の変更.
	pButton1->SetWindowText(_T("Clicked!(2)"));	// SetWindowTextでボタン名を"Clicked!(2)"に変更.(SetWindowTextはCWndのメソッド.)
	pButton2->SetWindowText(_T("Clicked!(2)"));	// SetWindowTextでボタン名を"Clicked!(2)"に変更.(SetWindowTextはCWndのメソッド.)

	// ボタンスタイルの取得.
	UINT uStyle1 = pButton1->GetButtonStyle();	// GetButtonStyleでpButton1のボタンスタイル取得.(GetButtonStyleはCButtonのメソッド.)
	if (uStyle1 == BS_PUSHBUTTON){	// プッシュボタンの場合.
		AfxMessageBox(_T("BS_PUSHBUTTON"));	// "BS_PUSHBUTTON"と表示.
	}
	else{	// デフォルトのプッシュボタンの場合.
		AfxMessageBox(_T("BS_DEFPUSHBUTTON"));	// "BS_DEFPUSHBUTTON"と表示.
	}
	UINT uStyle2 = pButton2->GetButtonStyle();	// GetButtonStyleでpButton2のボタンスタイル取得.(GetButtonStyleはCButtonのメソッド.)
	if (uStyle2 == BS_PUSHBUTTON){	// プッシュボタンの場合.
		AfxMessageBox(_T("BS_PUSHBUTTON"));	// "BS_PUSHBUTTON"と表示.
	}
	else{	// デフォルトのプッシュボタンの場合.
		AfxMessageBox(_T("BS_DEFPUSHBUTTON"));	// "BS_DEFPUSHBUTTON"と表示.
	}
}
