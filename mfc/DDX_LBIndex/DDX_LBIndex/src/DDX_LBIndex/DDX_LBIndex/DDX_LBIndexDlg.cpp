// DDX_LBIndexDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_LBIndex.h"
#include "DDX_LBIndexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_LBIndexDlg ダイアログ




CDDX_LBIndexDlg::CDDX_LBIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_LBIndexDlg::IDD, pParent)
	, m_xvListBox1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_LBIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_LBIndex(pDX, IDC_LIST1, m_xvListBox1);
	DDX_Control(pDX, IDC_LIST1, m_xcListBox1);
}

BEGIN_MESSAGE_MAP(CDDX_LBIndexDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_LBIndexDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_LBIndexDlg メッセージ ハンドラ

BOOL CDDX_LBIndexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	// アイテムの追加.
	m_xcListBox1.AddString(_T("Item1"));	// m_xcListBox1.AddStringで"Item1"を追加.
	m_xcListBox1.AddString(_T("Item2"));	// m_xcListBox1.AddStringで"Item2"を追加.
	m_xcListBox1.AddString(_T("Item3"));	// m_xcListBox1.AddStringで"Item3"を追加.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDDX_LBIndexDlg::OnPaint()
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
HCURSOR CDDX_LBIndexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_LBIndexDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// 更新.
	UpdateData();	// UpdateDataでデータの更新.
	// 選択されたインデックスの表示.
	TCHAR tszIndex[32] = {0};	// TCHAR型文字列バッファtszIndex(長さ32)を0で初期化.
	_stprintf(tszIndex, _T("tszIndex = %d\n"), m_xvListBox1);	// _stprintfでm_xvListBox1をtszIndexに変換.
	AfxMessageBox(tszIndex);	// tszIndexを表示.
}
