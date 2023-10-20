// AfxFindMessageEntryView.h : CAfxFindMessageEntryView クラスのインターフェイス
//


#pragma once


class CAfxFindMessageEntryView : public CView
{
protected: // シリアル化からのみ作成します。
	CAfxFindMessageEntryView();
	DECLARE_DYNCREATE(CAfxFindMessageEntryView)

// 属性
public:
	CAfxFindMessageEntryDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CAfxFindMessageEntryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // AfxFindMessageEntryView.cpp のデバッグ バージョン
inline CAfxFindMessageEntryDoc* CAfxFindMessageEntryView::GetDocument() const
   { return reinterpret_cast<CAfxFindMessageEntryDoc*>(m_pDocument); }
#endif

