// CCmdTarget_Doc.h : CCmdTarget_Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CCmdTarget_Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CCmdTarget_Doc();
	DECLARE_DYNCREATE(CCmdTarget_Doc)

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
	virtual ~CCmdTarget_Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


