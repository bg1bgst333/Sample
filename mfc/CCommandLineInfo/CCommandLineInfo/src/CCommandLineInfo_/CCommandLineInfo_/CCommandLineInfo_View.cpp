// CCommandLineInfo_View.cpp : CCommandLineInfo_View クラスの実装
//

#include "stdafx.h"
#include "CCommandLineInfo_.h"

#include "CCommandLineInfo_Doc.h"
#include "CCommandLineInfo_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandLineInfo_View

IMPLEMENT_DYNCREATE(CCommandLineInfo_View, CView)

BEGIN_MESSAGE_MAP(CCommandLineInfo_View, CView)
END_MESSAGE_MAP()

// CCommandLineInfo_View コンストラクション/デストラクション

CCommandLineInfo_View::CCommandLineInfo_View()
{
	// TODO: 構築コードをここに追加します。

}

CCommandLineInfo_View::~CCommandLineInfo_View()
{
}

BOOL CCommandLineInfo_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CCommandLineInfo_View 描画

void CCommandLineInfo_View::OnDraw(CDC* /*pDC*/)
{
	CCommandLineInfo_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CCommandLineInfo_View 診断

#ifdef _DEBUG
void CCommandLineInfo_View::AssertValid() const
{
	CView::AssertValid();
}

void CCommandLineInfo_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandLineInfo_Doc* CCommandLineInfo_View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandLineInfo_Doc)));
	return (CCommandLineInfo_Doc*)m_pDocument;
}
#endif //_DEBUG


// CCommandLineInfo_View メッセージ ハンドラ
