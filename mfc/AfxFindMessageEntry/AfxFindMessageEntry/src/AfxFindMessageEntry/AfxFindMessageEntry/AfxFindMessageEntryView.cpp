// AfxFindMessageEntryView.cpp : CAfxFindMessageEntryView �N���X�̎���
//

#include "stdafx.h"
#include "AfxFindMessageEntry.h"

#include "AfxFindMessageEntryDoc.h"
#include "AfxFindMessageEntryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAfxFindMessageEntryView

IMPLEMENT_DYNCREATE(CAfxFindMessageEntryView, CView)

BEGIN_MESSAGE_MAP(CAfxFindMessageEntryView, CView)
END_MESSAGE_MAP()

// CAfxFindMessageEntryView �R���X�g���N�V����/�f�X�g���N�V����

CAfxFindMessageEntryView::CAfxFindMessageEntryView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CAfxFindMessageEntryView::~CAfxFindMessageEntryView()
{
}

BOOL CAfxFindMessageEntryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CAfxFindMessageEntryView �`��

void CAfxFindMessageEntryView::OnDraw(CDC* /*pDC*/)
{
	CAfxFindMessageEntryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CAfxFindMessageEntryView �f�f

#ifdef _DEBUG
void CAfxFindMessageEntryView::AssertValid() const
{
	CView::AssertValid();
}

void CAfxFindMessageEntryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAfxFindMessageEntryDoc* CAfxFindMessageEntryView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAfxFindMessageEntryDoc)));
	return (CAfxFindMessageEntryDoc*)m_pDocument;
}
#endif //_DEBUG


// CAfxFindMessageEntryView ���b�Z�[�W �n���h��
