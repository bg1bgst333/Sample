// CComboBoxDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CComboBox.h"
#include "CComboBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComboBoxDlg ダイアログ




CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CComboBoxDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CComboBoxDlg メッセージ ハンドラ

BOOL CComboBoxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	// タイトルパーにアイコンの表示.
	CWinApp *pApp = AfxGetApp();	// AfxGetApp()でtheAppのポインタ取得.
	HICON hIcon = ::LoadIcon(pApp->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));	// ::LoadIconでIDI_ICON1(icon1.ico)をロード, ハンドルをhIconに格納.
	SetIcon(hIcon, TRUE);	// CWnd::SetIconでhIconをセット.(TRUEなので大きいアイコンにセット.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIconでhIconをセット.(FALSEなので小さいアイコンにセット.)

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CComboBoxDlg::OnPaint()
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
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CComboBoxDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// コンボボックスのエディット領域の文字列をコンボボックスのリスト領域に追加する.
	CComboBox *pComboBox1 = (CComboBox *)GetDlgItem(IDC_COMBO1);	// GetDlgItemでコンボボックスコントロールIDC_COMBO1のオブジェクトポインタをpComboBox1に格納.((CComboBox *)にキャスト.)
	int len = pComboBox1->GetWindowTextLength();	// pComboBox1->GetWindowTextLengthでエディット領域の文字列の長さを取得.
	TCHAR *ptszText = new TCHAR[len + 1];	// 長さlen + 1のバッファを確保.
	pComboBox1->GetWindowText(ptszText, len + 1);	// pComboBox1->GetWindowTextでテキストを取得し, ptszTextに格納.
	pComboBox1->AddString(ptszText);	// pComboBox1->AddStringでリスト領域に追加する.
	delete [] ptszText;					// ptszTextを解放.
}

void CComboBoxDlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// 選択した項目のテキストをメッセージボックスで表示.
	CComboBox *pComboBox1 = (CComboBox *)GetDlgItem(IDC_COMBO1);	// GetDlgItemでコンボボックスコントロールIDC_COMBO1のオブジェクトポインタをpComboBox1に格納.((CComboBox *)にキャスト.)
	int idx = pComboBox1->GetCurSel();	// pComboBox1->GetCurSelで選択された項目のインデックスを取得.
	int len = pComboBox1->GetLBTextLen(idx);	// pComboBox1->GetLBTextLenで選択された項目の文字列の長さを取得.
	TCHAR *ptszText = new TCHAR[len + 1];	// 長さlen + 1のバッファを確保.
	pComboBox1->GetLBText(idx, ptszText);	// pComboBox1->GetLBTextで選択された項目のテキストを取得.
	AfxMessageBox(ptszText, MB_OK | MB_ICONASTERISK);	// AfxMessageBoxでptszTextを出力.
	delete [] ptszText;	// ptszTextを解放.
}
