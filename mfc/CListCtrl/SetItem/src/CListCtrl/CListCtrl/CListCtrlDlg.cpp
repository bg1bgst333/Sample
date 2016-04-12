// CListCtrlDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CListCtrl.h"
#include "CListCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlDlg ダイアログ




CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CListCtrlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CListCtrlDlg メッセージ ハンドラ

BOOL CListCtrlDlg::OnInitDialog()
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

	// リストコントロールにカラム(列)ヘッダを挿入.
	CListCtrl *pListCtrl1 = (CListCtrl *)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	// カラム1の挿入.
	pListCtrl1->InsertColumn(0, _T("Name"), LVCFMT_LEFT, 120);	// pListCtrl1->InsertColumnで0番目にNameというカラムヘッダを挿入.
	// カラム2の挿入.
	pListCtrl1->InsertColumn(1, _T("Age"), LVCFMT_LEFT, 120);	// pListCtrl1->InsertColumnで1番目にAgeというカラムヘッダを挿入.
	// カラム3の挿入.
	pListCtrl1->InsertColumn(2, _T("Address"), LVCFMT_LEFT, 120);	// pListCtrl1->InsertColumnで2番目にAddressというカラムヘッダを挿入.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CListCtrlDlg::OnPaint()
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
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrlDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// 3つのエディットボックスに入力されたテキストをそれぞれリストコントロールの0行目の各列に挿入.
	CListCtrl *pListCtrl1 = (CListCtrl *)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	// 0列目
	CEdit *pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);	// GetDlgItemでエディットコントロールIDC_EDIT1のオブジェクトポインタをpEdit1に格納.((CEdit *)にキャスト.)
	TCHAR tszBuf1[256];	// TCHAR型バッファtszBuf1(要素数256).
	int iLen1 = pEdit1->GetLine(0, tszBuf1, 255);	// pEdit1->GetLineで0行目の文字列を取得し, tszBuf1に格納(最大255文字), 戻り値のコピーした文字数はiLen1に格納.
	tszBuf1[iLen1] = _T('\0');	// 最後の文字の次には'\0'を入れる.
	pListCtrl1->InsertItem(0, tszBuf1);	// pListCtrl1->InsertItemで0行0列にtszBuf1を挿入.
	// 1列目
	CEdit *pEdit2 = (CEdit *)GetDlgItem(IDC_EDIT2);	// GetDlgItemでエディットコントロールIDC_EDIT2のオブジェクトポインタをpEdit2に格納.((CEdit *)にキャスト.)
	TCHAR tszBuf2[256];	// TCHAR型バッファtszBuf2(要素数256).
	int iLen2 = pEdit2->GetLine(0, tszBuf2, 255);	// pEdit2->GetLineで0行目の文字列を取得し, tszBuf2に格納(最大255文字), 戻り値のコピーした文字数はiLen2に格納.
	tszBuf2[iLen2] = _T('\0');	// 最後の文字の次には'\0'を入れる.
	pListCtrl1->SetItem(0, 1, LVIF_TEXT, tszBuf2, 0, 0, 0, 0);	// pListCtrl1->SetItemで0行1列にtszBuf2をセット.
	// 2列目
	CEdit *pEdit3 = (CEdit *)GetDlgItem(IDC_EDIT3);	// GetDlgItemでエディットコントロールIDC_EDIT3のオブジェクトポインタをpEdit3に格納.((CEdit *)にキャスト.)
	TCHAR tszBuf3[256];	// TCHAR型バッファtszBuf3(要素数256).
	int iLen3 = pEdit3->GetLine(0, tszBuf3, 255);	// pEdit3->GetLineで0行目の文字列を取得し, tszBuf3に格納(最大255文字), 戻り値のコピーした文字数はiLen3に格納.
	tszBuf3[iLen3] = _T('\0');	// 最後の文字の次には'\0'を入れる.
	pListCtrl1->SetItem(0, 2, LVIF_TEXT, tszBuf3, 0, 0, 0, 0);	// pListCtrl1->SetItemで0行2列にtszBuf3をセット.
}
