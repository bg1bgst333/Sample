// CWinApp_View.h : CWinApp_View クラスのインターフェイス
//


#pragma once


class CWinApp_View : public CView
{
protected: // シリアル化からのみ作成します。
	CWinApp_View();
	DECLARE_DYNCREATE(CWinApp_View)

// 属性
public:
	CWinApp_Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CWinApp_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CWinApp_View.cpp のデバッグ バージョン
inline CWinApp_Doc* CWinApp_View::GetDocument() const
   { return reinterpret_cast<CWinApp_Doc*>(m_pDocument); }
#endif

