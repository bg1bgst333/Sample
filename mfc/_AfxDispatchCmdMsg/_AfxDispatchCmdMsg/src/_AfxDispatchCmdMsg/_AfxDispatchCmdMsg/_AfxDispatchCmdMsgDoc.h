// _AfxDispatchCmdMsgDoc.h : C_AfxDispatchCmdMsgDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class C_AfxDispatchCmdMsgDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	C_AfxDispatchCmdMsgDoc();
	DECLARE_DYNCREATE(C_AfxDispatchCmdMsgDoc)

// ����
public:

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����
public:
	virtual ~C_AfxDispatchCmdMsgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


