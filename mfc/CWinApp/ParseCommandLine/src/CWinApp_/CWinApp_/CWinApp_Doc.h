// CWinApp_Doc.h : CWinApp_Doc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CWinApp_Doc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CWinApp_Doc();
	DECLARE_DYNCREATE(CWinApp_Doc)

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
	virtual ~CWinApp_Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};


