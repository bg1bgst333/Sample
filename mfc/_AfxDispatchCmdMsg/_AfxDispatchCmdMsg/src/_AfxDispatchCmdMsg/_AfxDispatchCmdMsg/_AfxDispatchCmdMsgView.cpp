// _AfxDispatchCmdMsgView.cpp : C_AfxDispatchCmdMsgView �N���X�̎���
//

#include "stdafx.h"
#include "_AfxDispatchCmdMsg.h"

#include "_AfxDispatchCmdMsgDoc.h"
#include "_AfxDispatchCmdMsgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_AfxDispatchCmdMsgView

IMPLEMENT_DYNCREATE(C_AfxDispatchCmdMsgView, CView)

BEGIN_MESSAGE_MAP(C_AfxDispatchCmdMsgView, CView)
END_MESSAGE_MAP()

// C_AfxDispatchCmdMsgView �R���X�g���N�V����/�f�X�g���N�V����

C_AfxDispatchCmdMsgView::C_AfxDispatchCmdMsgView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

C_AfxDispatchCmdMsgView::~C_AfxDispatchCmdMsgView()
{
}

BOOL C_AfxDispatchCmdMsgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// C_AfxDispatchCmdMsgView �`��

void C_AfxDispatchCmdMsgView::OnDraw(CDC* /*pDC*/)
{
	C_AfxDispatchCmdMsgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// C_AfxDispatchCmdMsgView �f�f

#ifdef _DEBUG
void C_AfxDispatchCmdMsgView::AssertValid() const
{
	CView::AssertValid();
}

void C_AfxDispatchCmdMsgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C_AfxDispatchCmdMsgDoc* C_AfxDispatchCmdMsgView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C_AfxDispatchCmdMsgDoc)));
	return (C_AfxDispatchCmdMsgDoc*)m_pDocument;
}
#endif //_DEBUG


// C_AfxDispatchCmdMsgView ���b�Z�[�W �n���h��
