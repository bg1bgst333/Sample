// CWinApp_Doc.cpp : CWinApp_Doc クラスの実装
//

#include "stdafx.h"
#include "CWinApp_.h"

#include "CWinApp_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinApp_Doc

IMPLEMENT_DYNCREATE(CWinApp_Doc, CDocument)

BEGIN_MESSAGE_MAP(CWinApp_Doc, CDocument)
END_MESSAGE_MAP()


// CWinApp_Doc コンストラクション/デストラクション

CWinApp_Doc::CWinApp_Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CWinApp_Doc::~CWinApp_Doc()
{
}

BOOL CWinApp_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CWinApp_Doc シリアル化

void CWinApp_Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
	}
}


// CWinApp_Doc 診断

#ifdef _DEBUG
void CWinApp_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinApp_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWinApp_Doc コマンド
