// CDocManagerDoc.cpp : CDocManagerDoc �N���X�̎���
//

#include "stdafx.h"
#include "CDocManager.h"

#include "CDocManagerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocManagerDoc

IMPLEMENT_DYNCREATE(CDocManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocManagerDoc, CDocument)
END_MESSAGE_MAP()


// CDocManagerDoc �R���X�g���N�V����/�f�X�g���N�V����

CDocManagerDoc::CDocManagerDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDocManagerDoc::~CDocManagerDoc()
{
}

BOOL CDocManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDocManagerDoc �V���A����

void CDocManagerDoc::Serialize(CArchive& ar)
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


// CDocManagerDoc �f�f

#ifdef _DEBUG
void CDocManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDocManagerDoc �R�}���h
