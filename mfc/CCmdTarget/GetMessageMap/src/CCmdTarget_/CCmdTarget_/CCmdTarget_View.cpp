// CCmdTarget_View.cpp : CCmdTarget_View �N���X�̎���
//

#include "stdafx.h"
#include "CCmdTarget_.h"

#include "CCmdTarget_Doc.h"
#include "CCmdTarget_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmdTarget_View

IMPLEMENT_DYNCREATE(CCmdTarget_View, CView)

BEGIN_MESSAGE_MAP(CCmdTarget_View, CView)
END_MESSAGE_MAP()

// CCmdTarget_View �R���X�g���N�V����/�f�X�g���N�V����

CCmdTarget_View::CCmdTarget_View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CCmdTarget_View::~CCmdTarget_View()
{
}

BOOL CCmdTarget_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CCmdTarget_View �`��

void CCmdTarget_View::OnDraw(CDC* /*pDC*/)
{
	CCmdTarget_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CCmdTarget_View �f�f

#ifdef _DEBUG
void CCmdTarget_View::AssertValid() const
{
	CView::AssertValid();
}

void CCmdTarget_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCmdTarget_Doc* CCmdTarget_View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCmdTarget_Doc)));
	return (CCmdTarget_Doc*)m_pDocument;
}
#endif //_DEBUG


// CCmdTarget_View ���b�Z�[�W �n���h��
