// CWinApp_View.cpp : CWinApp_View クラスの実装
//

#include "stdafx.h"
#include "CWinApp_.h"

#include "CWinApp_Doc.h"
#include "CWinApp_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinApp_View

IMPLEMENT_DYNCREATE(CWinApp_View, CView)

BEGIN_MESSAGE_MAP(CWinApp_View, CView)
END_MESSAGE_MAP()

// CWinApp_View コンストラクション/デストラクション

CWinApp_View::CWinApp_View()
{
	// TODO: 構築コードをここに追加します。

}

CWinApp_View::~CWinApp_View()
{
}

BOOL CWinApp_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CWinApp_View 描画

void CWinApp_View::OnDraw(CDC* /*pDC*/)
{
	CWinApp_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CWinApp_View 診断

#ifdef _DEBUG
void CWinApp_View::AssertValid() const
{
	CView::AssertValid();
}

void CWinApp_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinApp_Doc* CWinApp_View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinApp_Doc)));
	return (CWinApp_Doc*)m_pDocument;
}
#endif //_DEBUG


// CWinApp_View メッセージ ハンドラ
