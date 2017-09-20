// CSingleDocTemplateDoc.cpp : CSingleDocTemplateDoc クラスの実装
//

#include "stdafx.h"
#include "CSingleDocTemplate.h"

#include "CSingleDocTemplateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocTemplateDoc

IMPLEMENT_DYNCREATE(CSingleDocTemplateDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDocTemplateDoc, CDocument)
END_MESSAGE_MAP()


// CSingleDocTemplateDoc コンストラクション/デストラクション

CSingleDocTemplateDoc::CSingleDocTemplateDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CSingleDocTemplateDoc::~CSingleDocTemplateDoc()
{
}

BOOL CSingleDocTemplateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CSingleDocTemplateDoc シリアル化

void CSingleDocTemplateDoc::Serialize(CArchive& ar)
{
	// CEditView は、すべてのシリアル化を処理するエディット コントロールを含んでいます。
	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
}


// CSingleDocTemplateDoc 診断

#ifdef _DEBUG
void CSingleDocTemplateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleDocTemplateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSingleDocTemplateDoc コマンド
