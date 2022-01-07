// CCommandLineInfo_Doc.h : CCommandLineInfo_Doc クラスのインターフェイス
//


#pragma once


class CCommandLineInfo_Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CCommandLineInfo_Doc();
	DECLARE_DYNCREATE(CCommandLineInfo_Doc)

// 属性
public:

// 操作
public:

// オーバーライド
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 実装
public:
	virtual ~CCommandLineInfo_Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


