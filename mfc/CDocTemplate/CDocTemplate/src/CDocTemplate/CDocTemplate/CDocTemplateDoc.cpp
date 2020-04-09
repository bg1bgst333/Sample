// CDocTemplateDoc.cpp : CDocTemplateDoc クラスの実装
//

#include "stdafx.h"
#include "CDocTemplate.h"

#include "CDocTemplateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocTemplateDoc

IMPLEMENT_DYNCREATE(CDocTemplateDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocTemplateDoc, CDocument)
END_MESSAGE_MAP()


// CDocTemplateDoc コンストラクション/デストラクション

CDocTemplateDoc::CDocTemplateDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDocTemplateDoc::~CDocTemplateDoc()
{
}

BOOL CDocTemplateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDocTemplateDoc シリアル化

void CDocTemplateDoc::Serialize(CArchive& ar)
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


// CDocTemplateDoc 診断

#ifdef _DEBUG
void CDocTemplateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocTemplateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDocTemplateDoc コマンド
