// _AfxDispatchCmdMsgDoc.h : C_AfxDispatchCmdMsgDoc クラスのインターフェイス
//


#pragma once


class C_AfxDispatchCmdMsgDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	C_AfxDispatchCmdMsgDoc();
	DECLARE_DYNCREATE(C_AfxDispatchCmdMsgDoc)

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
	virtual ~C_AfxDispatchCmdMsgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


