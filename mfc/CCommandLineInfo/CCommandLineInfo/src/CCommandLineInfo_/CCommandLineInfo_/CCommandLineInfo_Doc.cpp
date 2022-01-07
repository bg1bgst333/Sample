// CCommandLineInfo_Doc.cpp : CCommandLineInfo_Doc クラスの実装
//

#include "stdafx.h"
#include "CCommandLineInfo_.h"

#include "CCommandLineInfo_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandLineInfo_Doc

IMPLEMENT_DYNCREATE(CCommandLineInfo_Doc, CDocument)

BEGIN_MESSAGE_MAP(CCommandLineInfo_Doc, CDocument)
END_MESSAGE_MAP()


// CCommandLineInfo_Doc コンストラクション/デストラクション

CCommandLineInfo_Doc::CCommandLineInfo_Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CCommandLineInfo_Doc::~CCommandLineInfo_Doc()
{
}

BOOL CCommandLineInfo_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CCommandLineInfo_Doc シリアル化

void CCommandLineInfo_Doc::Serialize(CArchive& ar)
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


// CCommandLineInfo_Doc 診断

#ifdef _DEBUG
void CCommandLineInfo_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCommandLineInfo_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCommandLineInfo_Doc コマンド
