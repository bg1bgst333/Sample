// CDocManagerView.h : CDocManagerView クラスのインターフェイス
//


#pragma once


class CDocManagerView : public CView
{
protected: // シリアル化からのみ作成します。
	CDocManagerView();
	DECLARE_DYNCREATE(CDocManagerView)

// 属性
public:
	CDocManagerDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CDocManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CDocManagerView.cpp のデバッグ バージョン
inline CDocManagerDoc* CDocManagerView::GetDocument() const
   { return reinterpret_cast<CDocManagerDoc*>(m_pDocument); }
#endif

