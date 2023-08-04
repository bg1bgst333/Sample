// CCmdTarget_View.h : CCmdTarget_View クラスのインターフェイス
//


#pragma once


class CCmdTarget_View : public CView
{
protected: // シリアル化からのみ作成します。
	CCmdTarget_View();
	DECLARE_DYNCREATE(CCmdTarget_View)

// 属性
public:
	CCmdTarget_Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CCmdTarget_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CCmdTarget_View.cpp のデバッグ バージョン
inline CCmdTarget_Doc* CCmdTarget_View::GetDocument() const
   { return reinterpret_cast<CCmdTarget_Doc*>(m_pDocument); }
#endif

