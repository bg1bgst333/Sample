// AfxFindMessageEntryDoc.cpp : CAfxFindMessageEntryDoc �N���X�̎���
//

#include "stdafx.h"
#include "AfxFindMessageEntry.h"

#include "AfxFindMessageEntryDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAfxFindMessageEntryDoc

IMPLEMENT_DYNCREATE(CAfxFindMessageEntryDoc, CDocument)

BEGIN_MESSAGE_MAP(CAfxFindMessageEntryDoc, CDocument)
END_MESSAGE_MAP()


// CAfxFindMessageEntryDoc �R���X�g���N�V����/�f�X�g���N�V����

CAfxFindMessageEntryDoc::CAfxFindMessageEntryDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CAfxFindMessageEntryDoc::~CAfxFindMessageEntryDoc()
{
}

BOOL CAfxFindMessageEntryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CAfxFindMessageEntryDoc �V���A����

void CAfxFindMessageEntryDoc::Serialize(CArchive& ar)
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


// CAfxFindMessageEntryDoc �f�f

#ifdef _DEBUG
void CAfxFindMessageEntryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAfxFindMessageEntryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAfxFindMessageEntryDoc �R�}���h
