// CSingleDocTemplateView.cpp : CSingleDocTemplateView クラスの実装
//

#include "stdafx.h"
#include "CSingleDocTemplate.h"

#include "CSingleDocTemplateDoc.h"
#include "CSingleDocTemplateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocTemplateView

IMPLEMENT_DYNCREATE(CSingleDocTemplateView, CEditView)

BEGIN_MESSAGE_MAP(CSingleDocTemplateView, CEditView)
END_MESSAGE_MAP()

// CSingleDocTemplateView コンストラクション/デストラクション

CSingleDocTemplateView::CSingleDocTemplateView()
{
	// TODO: 構築コードをここに追加します。

}

CSingleDocTemplateView::~CSingleDocTemplateView()
{
}

BOOL CSingleDocTemplateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ワード ラップを使用可能にします

	return bPreCreated;
}


// CSingleDocTemplateView 診断

#ifdef _DEBUG
void CSingleDocTemplateView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSingleDocTemplateView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSingleDocTemplateDoc* CSingleDocTemplateView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocTemplateDoc)));
	return (CSingleDocTemplateDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocTemplateView メッセージ ハンドラ
