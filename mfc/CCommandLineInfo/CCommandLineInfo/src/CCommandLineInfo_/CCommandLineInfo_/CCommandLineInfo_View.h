// CCommandLineInfo_View.h : CCommandLineInfo_View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CCommandLineInfo_View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CCommandLineInfo_View();
	DECLARE_DYNCREATE(CCommandLineInfo_View)

// ����
public:
	CCommandLineInfo_Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CCommandLineInfo_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CCommandLineInfo_View.cpp �̃f�o�b�O �o�[�W����
inline CCommandLineInfo_Doc* CCommandLineInfo_View::GetDocument() const
   { return reinterpret_cast<CCommandLineInfo_Doc*>(m_pDocument); }
#endif

