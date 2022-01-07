// CCommandLineInfo_View.cpp : CCommandLineInfo_View �N���X�̎���
//

#include "stdafx.h"
#include "CCommandLineInfo_.h"

#include "CCommandLineInfo_Doc.h"
#include "CCommandLineInfo_View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandLineInfo_View

IMPLEMENT_DYNCREATE(CCommandLineInfo_View, CView)

BEGIN_MESSAGE_MAP(CCommandLineInfo_View, CView)
END_MESSAGE_MAP()

// CCommandLineInfo_View �R���X�g���N�V����/�f�X�g���N�V����

CCommandLineInfo_View::CCommandLineInfo_View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CCommandLineInfo_View::~CCommandLineInfo_View()
{
}

BOOL CCommandLineInfo_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CCommandLineInfo_View �`��

void CCommandLineInfo_View::OnDraw(CDC* /*pDC*/)
{
	CCommandLineInfo_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}


// CCommandLineInfo_View �f�f

#ifdef _DEBUG
void CCommandLineInfo_View::AssertValid() const
{
	CView::AssertValid();
}

void CCommandLineInfo_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandLineInfo_Doc* CCommandLineInfo_View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandLineInfo_Doc)));
	return (CCommandLineInfo_Doc*)m_pDocument;
}
#endif //_DEBUG


// CCommandLineInfo_View ���b�Z�[�W �n���h��
