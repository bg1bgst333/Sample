// CDocManagerDoc.h : CDocManagerDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDocManagerDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDocManagerDoc();
	DECLARE_DYNCREATE(CDocManagerDoc)

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
	virtual ~CDocManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


