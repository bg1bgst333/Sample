// CCmdTarget_Doc.cpp : CCmdTarget_Doc �N���X�̎���
//

#include "stdafx.h"
#include "CCmdTarget_.h"

#include "CCmdTarget_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmdTarget_Doc

IMPLEMENT_DYNCREATE(CCmdTarget_Doc, CDocument)

BEGIN_MESSAGE_MAP(CCmdTarget_Doc, CDocument)
END_MESSAGE_MAP()


// CCmdTarget_Doc �R���X�g���N�V����/�f�X�g���N�V����

CCmdTarget_Doc::CCmdTarget_Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CCmdTarget_Doc::~CCmdTarget_Doc()
{
}

BOOL CCmdTarget_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CCmdTarget_Doc �V���A����

void CCmdTarget_Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}


// CCmdTarget_Doc �f�f

#ifdef _DEBUG
void CCmdTarget_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCmdTarget_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCmdTarget_Doc �R�}���h
