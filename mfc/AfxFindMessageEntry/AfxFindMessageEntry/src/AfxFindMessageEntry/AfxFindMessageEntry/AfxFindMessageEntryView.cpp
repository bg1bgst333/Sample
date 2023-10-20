// AfxFindMessageEntryView.cpp : CAfxFindMessageEntryView クラスの実装
//

#include "stdafx.h"
#include "AfxFindMessageEntry.h"

#include "AfxFindMessageEntryDoc.h"
#include "AfxFindMessageEntryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAfxFindMessageEntryView

IMPLEMENT_DYNCREATE(CAfxFindMessageEntryView, CView)

BEGIN_MESSAGE_MAP(CAfxFindMessageEntryView, CView)
END_MESSAGE_MAP()

// CAfxFindMessageEntryView コンストラクション/デストラクション

CAfxFindMessageEntryView::CAfxFindMessageEntryView()
{
	// TODO: 構築コードをここに追加します。

}

CAfxFindMessageEntryView::~CAfxFindMessageEntryView()
{
}

BOOL CAfxFindMessageEntryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CAfxFindMessageEntryView 描画

void CAfxFindMessageEntryView::OnDraw(CDC* /*pDC*/)
{
	CAfxFindMessageEntryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CAfxFindMessageEntryView 診断

#ifdef _DEBUG
void CAfxFindMessageEntryView::AssertValid() const
{
	CView::AssertValid();
}

void CAfxFindMessageEntryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAfxFindMessageEntryDoc* CAfxFindMessageEntryView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAfxFindMessageEntryDoc)));
	return (CAfxFindMessageEntryDoc*)m_pDocument;
}
#endif //_DEBUG


// CAfxFindMessageEntryView メッセージ ハンドラ
