// CCmdTarget_Doc.cpp : CCmdTarget_Doc クラスの実装
//

#include "stdafx.h"
#include "CCmdTarget_.h"

#include "CCmdTarget_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmdTarget_Doc

IMPLEMENT_DYNCREATE(CCmdTarget_Doc, CDocument)

BEGIN_MESSAGE_MAP(CCmdTarget_Doc, CDocument)
END_MESSAGE_MAP()


// CCmdTarget_Doc コンストラクション/デストラクション

CCmdTarget_Doc::CCmdTarget_Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CCmdTarget_Doc::~CCmdTarget_Doc()
{
}

BOOL CCmdTarget_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CCmdTarget_Doc シリアル化

void CCmdTarget_Doc::Serialize(CArchive& ar)
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


// CCmdTarget_Doc 診断

#ifdef _DEBUG
void CCmdTarget_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCmdTarget_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCmdTarget_Doc コマンド
