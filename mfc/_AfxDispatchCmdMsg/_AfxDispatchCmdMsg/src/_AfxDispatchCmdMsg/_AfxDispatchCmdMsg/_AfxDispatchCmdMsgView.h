// _AfxDispatchCmdMsgView.h : C_AfxDispatchCmdMsgView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class C_AfxDispatchCmdMsgView : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	C_AfxDispatchCmdMsgView();
	DECLARE_DYNCREATE(C_AfxDispatchCmdMsgView)

// ����
public:
	C_AfxDispatchCmdMsgDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~C_AfxDispatchCmdMsgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // _AfxDispatchCmdMsgView.cpp �̃f�o�b�O �o�[�W����
inline C_AfxDispatchCmdMsgDoc* C_AfxDispatchCmdMsgView::GetDocument() const
   { return reinterpret_cast<C_AfxDispatchCmdMsgDoc*>(m_pDocument); }
#endif

