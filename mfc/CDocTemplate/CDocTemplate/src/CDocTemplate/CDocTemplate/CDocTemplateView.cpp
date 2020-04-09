// CDocTemplateView.cpp : CDocTemplateView クラスの実装
//

#include "stdafx.h"
#include "CDocTemplate.h"

#include "CDocTemplateDoc.h"
#include "CDocTemplateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocTemplateView

IMPLEMENT_DYNCREATE(CDocTemplateView, CView)

BEGIN_MESSAGE_MAP(CDocTemplateView, CView)
END_MESSAGE_MAP()

// CDocTemplateView コンストラクション/デストラクション

CDocTemplateView::CDocTemplateView()
{
	// TODO: 構築コードをここに追加します。

}

CDocTemplateView::~CDocTemplateView()
{
}

BOOL CDocTemplateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDocTemplateView 描画

void CDocTemplateView::OnDraw(CDC* /*pDC*/)
{
	CDocTemplateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CDocTemplateView 診断

#ifdef _DEBUG
void CDocTemplateView::AssertValid() const
{
	CView::AssertValid();
}

void CDocTemplateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocTemplateDoc* CDocTemplateView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocTemplateDoc)));
	return (CDocTemplateDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocTemplateView メッセージ ハンドラ
