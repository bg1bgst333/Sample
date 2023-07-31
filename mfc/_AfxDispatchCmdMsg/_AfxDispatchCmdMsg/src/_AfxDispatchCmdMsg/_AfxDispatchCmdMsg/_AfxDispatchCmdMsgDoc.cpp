// _AfxDispatchCmdMsgDoc.cpp : C_AfxDispatchCmdMsgDoc クラスの実装
//

#include "stdafx.h"
#include "_AfxDispatchCmdMsg.h"

#include "_AfxDispatchCmdMsgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_AfxDispatchCmdMsgDoc

IMPLEMENT_DYNCREATE(C_AfxDispatchCmdMsgDoc, CDocument)

BEGIN_MESSAGE_MAP(C_AfxDispatchCmdMsgDoc, CDocument)
END_MESSAGE_MAP()


// C_AfxDispatchCmdMsgDoc コンストラクション/デストラクション

C_AfxDispatchCmdMsgDoc::C_AfxDispatchCmdMsgDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

C_AfxDispatchCmdMsgDoc::~C_AfxDispatchCmdMsgDoc()
{
}

BOOL C_AfxDispatchCmdMsgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// C_AfxDispatchCmdMsgDoc シリアル化

void C_AfxDispatchCmdMsgDoc::Serialize(CArchive& ar)
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


// C_AfxDispatchCmdMsgDoc 診断

#ifdef _DEBUG
void C_AfxDispatchCmdMsgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C_AfxDispatchCmdMsgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C_AfxDispatchCmdMsgDoc コマンド
