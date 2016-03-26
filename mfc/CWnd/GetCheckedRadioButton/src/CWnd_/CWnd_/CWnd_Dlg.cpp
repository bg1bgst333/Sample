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
	ON_BN_CLICKED(IDC_BUTTON1, &CWnd_Dlg::OnBnClickedButton1)
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
	CWinApp *pApp = AfxGetApp();	// AfxGetApp()でtheAppのポインタ取得.
	HICON hIcon = ::LoadIcon(pApp->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));	// ::LoadIconでIDI_ICON1(icon1.ico)をロード, ハンドルをhIconに格納.
	SetIcon(hIcon, TRUE);	// CWnd::SetIconでhIconをセット.(TRUEなので大きいアイコンにセット.)
	SetIcon(hIcon, FALSE);	// CWnd::SetIconでhIconをセット.(FALSEなので小さいアイコンにセット.)

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


void CWnd_Dlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// ラジオボタンがどこにセットされているかを確認する.
	int id = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);	// GetCheckedRadioButtonでIDC_RADIO1からIDC_RADIO3までのラジオボタンのどれがチェックされているかを確認する.
	if (id == IDC_RADIO1){	// IDC_RADIO1の時.
		AfxMessageBox(_T("IDC_RADIO1"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO1"と表示.
	}
	else if (id == IDC_RADIO2){	// IDC_RADIO2の時.
		AfxMessageBox(_T("IDC_RADIO2"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO2"と表示.
	}
	else if (id == IDC_RADIO3){	// IDC_RADIO3の時.
		AfxMessageBox(_T("IDC_RADIO3"), MB_OK | MB_ICONASTERISK);	// "IDC_RADIO3"と表示.
	}
	else{	// 選択されていない時.
		AfxMessageBox(_T("Not Selected"), MB_OK | MB_ICONASTERISK);	// "Not Selected"と表示.
	}
}
