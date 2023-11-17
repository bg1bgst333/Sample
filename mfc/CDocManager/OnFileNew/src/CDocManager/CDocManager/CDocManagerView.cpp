// CDocManagerView.cpp : CDocManagerView クラスの実装
//

#include "stdafx.h"
#include "CDocManager.h"

#include "CDocManagerDoc.h"
#include "CDocManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocManagerView

IMPLEMENT_DYNCREATE(CDocManagerView, CView)

BEGIN_MESSAGE_MAP(CDocManagerView, CView)
END_MESSAGE_MAP()

// CDocManagerView コンストラクション/デストラクション

CDocManagerView::CDocManagerView()
{
	// TODO: 構築コードをここに追加します。

}

CDocManagerView::~CDocManagerView()
{
}

BOOL CDocManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDocManagerView 描画

void CDocManagerView::OnDraw(CDC* /*pDC*/)
{
	CDocManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CDocManagerView 診断

#ifdef _DEBUG
void CDocManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CDocManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocManagerDoc* CDocManagerView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocManagerDoc)));
	return (CDocManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocManagerView メッセージ ハンドラ
