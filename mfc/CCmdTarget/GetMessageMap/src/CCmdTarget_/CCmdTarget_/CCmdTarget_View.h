// CCmdTarget_View.h : CCmdTarget_View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CCmdTarget_View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CCmdTarget_View();
	DECLARE_DYNCREATE(CCmdTarget_View)

// ����
public:
	CCmdTarget_Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CCmdTarget_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CCmdTarget_View.cpp �̃f�o�b�O �o�[�W����
inline CCmdTarget_Doc* CCmdTarget_View::GetDocument() const
   { return reinterpret_cast<CCmdTarget_Doc*>(m_pDocument); }
#endif

