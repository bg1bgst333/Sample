// CDocTemplateView.h : CDocTemplateView クラスのインターフェイス
//


#pragma once


class CDocTemplateView : public CView
{
protected: // シリアル化からのみ作成します。
	CDocTemplateView();
	DECLARE_DYNCREATE(CDocTemplateView)

// 属性
public:
	CDocTemplateDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CDocTemplateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CDocTemplateView.cpp のデバッグ バージョン
inline CDocTemplateDoc* CDocTemplateView::GetDocument() const
   { return reinterpret_cast<CDocTemplateDoc*>(m_pDocument); }
#endif

