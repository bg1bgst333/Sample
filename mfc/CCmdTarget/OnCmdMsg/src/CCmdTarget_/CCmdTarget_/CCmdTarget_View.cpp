// CCmdTarget_View.cpp : CCmdTarget_View クラスの実装
//

#include "stdafx.h"
#include "CCmdTarget_.h"

#include "CCmdTarget_Doc.h"
#include "CCmdTarget_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmdTarget_View

IMPLEMENT_DYNCREATE(CCmdTarget_View, CView)

BEGIN_MESSAGE_MAP(CCmdTarget_View, CView)
END_MESSAGE_MAP()

// CCmdTarget_View コンストラクション/デストラクション

CCmdTarget_View::CCmdTarget_View()
{
	// TODO: 構築コードをここに追加します。

}

CCmdTarget_View::~CCmdTarget_View()
{
}

BOOL CCmdTarget_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CCmdTarget_View 描画

void CCmdTarget_View::OnDraw(CDC* /*pDC*/)
{
	CCmdTarget_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CCmdTarget_View 診断

#ifdef _DEBUG
void CCmdTarget_View::AssertValid() const
{
	CView::AssertValid();
}

void CCmdTarget_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCmdTarget_Doc* CCmdTarget_View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCmdTarget_Doc)));
	return (CCmdTarget_Doc*)m_pDocument;
}
#endif //_DEBUG


// CCmdTarget_View メッセージ ハンドラ
