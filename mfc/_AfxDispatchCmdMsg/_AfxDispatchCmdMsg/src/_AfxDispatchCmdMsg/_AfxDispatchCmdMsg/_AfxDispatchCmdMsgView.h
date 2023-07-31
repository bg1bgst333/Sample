// _AfxDispatchCmdMsgView.h : C_AfxDispatchCmdMsgView クラスのインターフェイス
//


#pragma once


class C_AfxDispatchCmdMsgView : public CView
{
protected: // シリアル化からのみ作成します。
	C_AfxDispatchCmdMsgView();
	DECLARE_DYNCREATE(C_AfxDispatchCmdMsgView)

// 属性
public:
	C_AfxDispatchCmdMsgDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~C_AfxDispatchCmdMsgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // _AfxDispatchCmdMsgView.cpp のデバッグ バージョン
inline C_AfxDispatchCmdMsgDoc* C_AfxDispatchCmdMsgView::GetDocument() const
   { return reinterpret_cast<C_AfxDispatchCmdMsgDoc*>(m_pDocument); }
#endif

