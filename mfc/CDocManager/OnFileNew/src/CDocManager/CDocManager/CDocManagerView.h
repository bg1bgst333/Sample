// CDocManagerView.h : CDocManagerView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDocManagerView : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDocManagerView();
	DECLARE_DYNCREATE(CDocManagerView)

// ����
public:
	CDocManagerDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CDocManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CDocManagerView.cpp �̃f�o�b�O �o�[�W����
inline CDocManagerDoc* CDocManagerView::GetDocument() const
   { return reinterpret_cast<CDocManagerDoc*>(m_pDocument); }
#endif

