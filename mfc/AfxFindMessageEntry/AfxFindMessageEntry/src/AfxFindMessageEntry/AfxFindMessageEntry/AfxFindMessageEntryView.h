// AfxFindMessageEntryView.h : CAfxFindMessageEntryView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CAfxFindMessageEntryView : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CAfxFindMessageEntryView();
	DECLARE_DYNCREATE(CAfxFindMessageEntryView)

// ����
public:
	CAfxFindMessageEntryDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CAfxFindMessageEntryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // AfxFindMessageEntryView.cpp �̃f�o�b�O �o�[�W����
inline CAfxFindMessageEntryDoc* CAfxFindMessageEntryView::GetDocument() const
   { return reinterpret_cast<CAfxFindMessageEntryDoc*>(m_pDocument); }
#endif

