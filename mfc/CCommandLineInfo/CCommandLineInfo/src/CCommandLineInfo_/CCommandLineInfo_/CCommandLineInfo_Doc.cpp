// CCommandLineInfo_Doc.cpp : CCommandLineInfo_Doc �N���X�̎���
//

#include "stdafx.h"
#include "CCommandLineInfo_.h"

#include "CCommandLineInfo_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandLineInfo_Doc

IMPLEMENT_DYNCREATE(CCommandLineInfo_Doc, CDocument)

BEGIN_MESSAGE_MAP(CCommandLineInfo_Doc, CDocument)
END_MESSAGE_MAP()


// CCommandLineInfo_Doc �R���X�g���N�V����/�f�X�g���N�V����

CCommandLineInfo_Doc::CCommandLineInfo_Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CCommandLineInfo_Doc::~CCommandLineInfo_Doc()
{
}

BOOL CCommandLineInfo_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CCommandLineInfo_Doc �V���A����

void CCommandLineInfo_Doc::Serialize(CArchive& ar)
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


// CCommandLineInfo_Doc �f�f

#ifdef _DEBUG
void CCommandLineInfo_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCommandLineInfo_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCommandLineInfo_Doc �R�}���h
