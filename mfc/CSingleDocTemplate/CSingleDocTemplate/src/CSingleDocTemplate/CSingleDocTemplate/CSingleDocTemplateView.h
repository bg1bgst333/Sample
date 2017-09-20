// CSingleDocTemplateView.h : CSingleDocTemplateView クラスのインターフェイス
//


#pragma once


class CSingleDocTemplateView : public CEditView
{
protected: // シリアル化からのみ作成します。
	CSingleDocTemplateView();
	DECLARE_DYNCREATE(CSingleDocTemplateView)

// 属性
public:
	CSingleDocTemplateDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CSingleDocTemplateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CSingleDocTemplateView.cpp のデバッグ バージョン
inline CSingleDocTemplateDoc* CSingleDocTemplateView::GetDocument() const
   { return reinterpret_cast<CSingleDocTemplateDoc*>(m_pDocument); }
#endif

