// CDocManagerView.cpp : CDocManagerView �N���X�̎���
//

#include "stdafx.h"
#include "CDocManager.h"

#include "CDocManagerDoc.h"
#include "CDocManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocManagerView

IMPLEMENT_DYNCREATE(CDocManagerView, CView)

BEGIN_MESSAGE_MAP(CDocManagerView, CView)
END_MESSAGE_MAP()

// CDocManagerView �R���X�g���N�V����/�f�X�g���N�V����

CDocManagerView::CDocManagerView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDocManagerView::~CDocManagerView()
{
}

BOOL CDocManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDocManagerView �`��

void CDocManagerView::OnDraw(CDC* /*pDC*/)
{
	CDocManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CDocManagerView �f�f

#ifdef _DEBUG
void CDocManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CDocManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocManagerDoc* CDocManagerView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocManagerDoc)));
	return (CDocManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocManagerView ���b�Z�[�W �n���h��
