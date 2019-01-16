// CDocManagerDoc.cpp : CDocManagerDoc クラスの実装
//

#include "stdafx.h"
#include "CDocManager.h"

#include "CDocManagerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocManagerDoc

IMPLEMENT_DYNCREATE(CDocManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocManagerDoc, CDocument)
END_MESSAGE_MAP()


// CDocManagerDoc コンストラクション/デストラクション

CDocManagerDoc::CDocManagerDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDocManagerDoc::~CDocManagerDoc()
{
}

BOOL CDocManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDocManagerDoc シリアル化

void CDocManagerDoc::Serialize(CArchive& ar)
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


// CDocManagerDoc 診断

#ifdef _DEBUG
void CDocManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDocManagerDoc コマンド
