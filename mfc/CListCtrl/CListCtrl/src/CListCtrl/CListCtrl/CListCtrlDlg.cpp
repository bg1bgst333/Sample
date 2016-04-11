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

	// リストコントロールにカラム(列)ヘッダと各アイテム(行項目)挿入.
	CListCtrl *pListCtrl1 = (CListCtrl *)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	// カラム1の挿入.
	LVCOLUMN lvCol1;	// カラム1
	lvCol1.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// 配置, ヘッダ名, 幅をセット.
	lvCol1.fmt = LVCFMT_LEFT;		// 左寄せ.
	lvCol1.pszText = _T("Name");	// ヘッダ名は"Name".
	lvCol1.cx = 120;	// 幅は120.
	pListCtrl1->InsertColumn(0, &lvCol1);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol1を挿入.
	// カラム2の挿入.
	LVCOLUMN lvCol2;	// カラム2
	lvCol2.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// 配置, ヘッダ名, 幅をセット.
	lvCol2.fmt = LVCFMT_LEFT;		// 左寄せ.
	lvCol2.pszText = _T("Age");		// ヘッダ名は"Age".
	lvCol2.cx = 120;	// 幅は120.
	pListCtrl1->InsertColumn(1, &lvCol2);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol2を挿入.
	// カラム3の挿入.
	LVCOLUMN lvCol3;	// カラム3
	lvCol3.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// 配置, ヘッダ名, 幅をセット.
	lvCol3.fmt = LVCFMT_LEFT;		// 左寄せ.
	lvCol3.pszText = _T("Address");		// ヘッダ名は"Address".
	lvCol3.cx = 120;	// 幅は120.
	pListCtrl1->InsertColumn(2, &lvCol3);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol3を挿入.
	// アイテム1_1～1_3の挿入.
	LVITEM lvItem1_1;	// アイテム1_1
	lvItem1_1.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_1.pszText = _T("Taro");	// アイテムテキストは"Taro".
	lvItem1_1.iItem = 0;	// 0行
	lvItem1_1.iSubItem = 0;	// 0列
	pListCtrl1->InsertItem(&lvItem1_1);	// pListCtrl1->InsertItemでlvItem1_1を挿入.
	LVITEM lvItem1_2;	// アイテム1_2
	lvItem1_2.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_2.pszText = _T("20");	// アイテムテキストは"20".
	lvItem1_2.iItem = 0;	// 0行
	lvItem1_2.iSubItem = 1;	// 1列
	pListCtrl1->SetItem(&lvItem1_2);	// pListCtrl1->SetItemでlvItem1_2を挿入.(正確にはセット.)
	LVITEM lvItem1_3;	// アイテム1_3
	lvItem1_3.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_3.pszText = _T("Tokyo");	// アイテムテキストは"Tokyo".
	lvItem1_3.iItem = 0;	// 0行
	lvItem1_3.iSubItem = 2;	// 2列
	pListCtrl1->SetItem(&lvItem1_3);	// pListCtrl1->SetItemでlvItem1_3を挿入.(正確にはセット.)
	// アイテム2_1～2_3の挿入.
	LVITEM lvItem2_1;	// アイテム2_1
	lvItem2_1.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem2_1.pszText = _T("Jiro");	// アイテムテキストは"Jiro".
	lvItem2_1.iItem = 1;	// 1行
	lvItem2_1.iSubItem = 0;	// 0列
	pListCtrl1->InsertItem(&lvItem2_1);	// pListCtrl1->InsertItemでlvItem2_1を挿入.
	LVITEM lvItem2_2;	// アイテム2_2
	lvItem2_2.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem2_2.pszText = _T("18");	// アイテムテキストは"18".
	lvItem2_2.iItem = 1;	// 1行
	lvItem2_2.iSubItem = 1;	// 1列
	pListCtrl1->SetItem(&lvItem2_2);	// pListCtrl1->SetItemでlvItem2_2を挿入.(正確にはセット.)
	LVITEM lvItem2_3;	// アイテム2_3
	lvItem2_3.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem2_3.pszText = _T("Osaka");	// アイテムテキストは"Osaka".
	lvItem2_3.iItem = 1;	// 1行 
	lvItem2_3.iSubItem = 2;	// 2列
	pListCtrl1->SetItem(&lvItem2_3);	// pListCtrl1->SetItemでlvItem2_3を挿入.(正確にはセット.)
	// アイテム3_1～3_3の挿入.
	LVITEM lvItem3_1;	// アイテム3_1
	lvItem3_1.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem3_1.pszText = _T("Saburo");	// アイテムテキストは"Saburo".
	lvItem3_1.iItem = 2;	// 2行
	lvItem3_1.iSubItem = 0;	// 0列
	pListCtrl1->InsertItem(&lvItem3_1);	// pListCtrl1->InsertItemでlvItem3_1を挿入.
	LVITEM lvItem3_2;	// アイテム3_2
	lvItem3_2.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem3_2.pszText = _T("16");	// アイテムテキストは"16".
	lvItem3_2.iItem = 2;	// 2行
	lvItem3_2.iSubItem = 1;	// 1列
	pListCtrl1->SetItem(&lvItem3_2);	// pListCtrl1->SetItemでlvItem3_2を挿入.(正確にはセット.)
	LVITEM lvItem3_3;	// アイテム3_3
	lvItem3_3.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem3_3.pszText = _T("Nagoya");	// アイテムテキストは"Nagoya".
	lvItem3_3.iItem = 2;	// 2行 
	lvItem3_3.iSubItem = 2;	// 2列
	pListCtrl1->SetItem(&lvItem3_3);	// pListCtrl1->SetItemでlvItem3_3を挿入.(正確にはセット.)

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

