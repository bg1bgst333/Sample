// AfxFindMessageEntryDoc.h : CAfxFindMessageEntryDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CAfxFindMessageEntryDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CAfxFindMessageEntryDoc();
	DECLARE_DYNCREATE(CAfxFindMessageEntryDoc)

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
	virtual ~CAfxFindMessageEntryDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


