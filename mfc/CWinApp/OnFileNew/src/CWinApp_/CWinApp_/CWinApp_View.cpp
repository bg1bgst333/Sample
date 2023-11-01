// CWinApp_View.cpp : CWinApp_View �N���X�̎���
//

#include "stdafx.h"
#include "CWinApp_.h"

#include "CWinApp_Doc.h"
#include "CWinApp_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinApp_View

IMPLEMENT_DYNCREATE(CWinApp_View, CView)

BEGIN_MESSAGE_MAP(CWinApp_View, CView)
END_MESSAGE_MAP()

// CWinApp_View �R���X�g���N�V����/�f�X�g���N�V����

CWinApp_View::CWinApp_View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CWinApp_View::~CWinApp_View()
{
}

BOOL CWinApp_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CWinApp_View �`��

void CWinApp_View::OnDraw(CDC* /*pDC*/)
{
	CWinApp_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CWinApp_View �f�f

#ifdef _DEBUG
void CWinApp_View::AssertValid() const
{
	CView::AssertValid();
}

void CWinApp_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinApp_Doc* CWinApp_View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinApp_Doc)));
	return (CWinApp_Doc*)m_pDocument;
}
#endif //_DEBUG


// CWinApp_View ���b�Z�[�W �n���h��
