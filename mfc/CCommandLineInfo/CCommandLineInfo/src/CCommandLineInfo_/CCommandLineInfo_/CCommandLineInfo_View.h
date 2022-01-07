// CCommandLineInfo_View.h : CCommandLineInfo_View クラスのインターフェイス
//


#pragma once


class CCommandLineInfo_View : public CView
{
protected: // シリアル化からのみ作成します。
	CCommandLineInfo_View();
	DECLARE_DYNCREATE(CCommandLineInfo_View)

// 属性
public:
	CCommandLineInfo_Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CCommandLineInfo_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CCommandLineInfo_View.cpp のデバッグ バージョン
inline CCommandLineInfo_Doc* CCommandLineInfo_View::GetDocument() const
   { return reinterpret_cast<CCommandLineInfo_Doc*>(m_pDocument); }
#endif

