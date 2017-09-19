// DDX_CBIndexDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DDX_CBIndex.h"
#include "DDX_CBIndexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDX_CBIndexDlg ダイアログ




CDDX_CBIndexDlg::CDDX_CBIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDDX_CBIndexDlg::IDD, pParent)
	, m_xvComboBox1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDX_CBIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_xcComboBox1);
	DDX_CBIndex(pDX, IDC_COMBO1, m_xvComboBox1);
}

BEGIN_MESSAGE_MAP(CDDX_CBIndexDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDDX_CBIndexDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDDX_CBIndexDlg メッセージ ハンドラ

BOOL CDDX_CBIndexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	// アイテムの追加.
	m_xcComboBox1.AddString(_T("Item1"));	// m_xcComboBox1.AddStringで"Item1"を追加.
	m_xcComboBox1.AddString(_T("Item2"));	// m_xcComboBox1.AddStringで"Item2"を追加.
	m_xcComboBox1.AddString(_T("Item3"));	// m_xcComboBox1.AddStringで"Item3"を追加.

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDDX_CBIndexDlg::OnPaint()
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
HCURSOR CDDX_CBIndexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDDX_CBIndexDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// 更新.
	UpdateData();	// UpdateDataでデータの更新.
	// 選択されたインデックスの表示.
	TCHAR tszIndex[32] = {0};	// TCHAR型文字列バッファtszIndex(長さ32)を0で初期化.
	_stprintf(tszIndex, _T("tszIndex = %d\n"), m_xvComboBox1);	// _stprintfでm_xvComboBox1をtszIndexに変換.
	AfxMessageBox(tszIndex);	// tszIndexを表示.
}
