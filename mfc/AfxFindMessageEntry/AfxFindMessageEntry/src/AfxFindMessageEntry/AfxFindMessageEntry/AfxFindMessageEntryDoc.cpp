// AfxFindMessageEntryDoc.cpp : CAfxFindMessageEntryDoc クラスの実装
//

#include "stdafx.h"
#include "AfxFindMessageEntry.h"

#include "AfxFindMessageEntryDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAfxFindMessageEntryDoc

IMPLEMENT_DYNCREATE(CAfxFindMessageEntryDoc, CDocument)

BEGIN_MESSAGE_MAP(CAfxFindMessageEntryDoc, CDocument)
END_MESSAGE_MAP()


// CAfxFindMessageEntryDoc コンストラクション/デストラクション

CAfxFindMessageEntryDoc::CAfxFindMessageEntryDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CAfxFindMessageEntryDoc::~CAfxFindMessageEntryDoc()
{
}

BOOL CAfxFindMessageEntryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CAfxFindMessageEntryDoc シリアル化

void CAfxFindMessageEntryDoc::Serialize(CArchive& ar)
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


// CAfxFindMessageEntryDoc 診断

#ifdef _DEBUG
void CAfxFindMessageEntryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAfxFindMessageEntryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAfxFindMessageEntryDoc コマンド
