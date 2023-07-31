// _AfxDispatchCmdMsgView.cpp : C_AfxDispatchCmdMsgView クラスの実装
//

#include "stdafx.h"
#include "_AfxDispatchCmdMsg.h"

#include "_AfxDispatchCmdMsgDoc.h"
#include "_AfxDispatchCmdMsgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_AfxDispatchCmdMsgView

IMPLEMENT_DYNCREATE(C_AfxDispatchCmdMsgView, CView)

BEGIN_MESSAGE_MAP(C_AfxDispatchCmdMsgView, CView)
END_MESSAGE_MAP()

// C_AfxDispatchCmdMsgView コンストラクション/デストラクション

C_AfxDispatchCmdMsgView::C_AfxDispatchCmdMsgView()
{
	// TODO: 構築コードをここに追加します。

}

C_AfxDispatchCmdMsgView::~C_AfxDispatchCmdMsgView()
{
}

BOOL C_AfxDispatchCmdMsgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// C_AfxDispatchCmdMsgView 描画

void C_AfxDispatchCmdMsgView::OnDraw(CDC* /*pDC*/)
{
	C_AfxDispatchCmdMsgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// C_AfxDispatchCmdMsgView 診断

#ifdef _DEBUG
void C_AfxDispatchCmdMsgView::AssertValid() const
{
	CView::AssertValid();
}

void C_AfxDispatchCmdMsgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C_AfxDispatchCmdMsgDoc* C_AfxDispatchCmdMsgView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C_AfxDispatchCmdMsgDoc)));
	return (C_AfxDispatchCmdMsgDoc*)m_pDocument;
}
#endif //_DEBUG


// C_AfxDispatchCmdMsgView メッセージ ハンドラ
