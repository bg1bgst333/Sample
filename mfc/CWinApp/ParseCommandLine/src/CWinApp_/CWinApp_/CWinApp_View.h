// CWinApp_View.h : CWinApp_View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CWinApp_View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CWinApp_View();
	DECLARE_DYNCREATE(CWinApp_View)

// ����
public:
	CWinApp_Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CWinApp_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CWinApp_View.cpp �̃f�o�b�O �o�[�W����
inline CWinApp_Doc* CWinApp_View::GetDocument() const
   { return reinterpret_cast<CWinApp_Doc*>(m_pDocument); }
#endif

