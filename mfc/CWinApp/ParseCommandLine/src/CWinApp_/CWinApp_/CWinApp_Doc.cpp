// CWinApp_Doc.cpp : CWinApp_Doc �N���X�̎���
//

#include "stdafx.h"
#include "CWinApp_.h"

#include "CWinApp_Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinApp_Doc

IMPLEMENT_DYNCREATE(CWinApp_Doc, CDocument)

BEGIN_MESSAGE_MAP(CWinApp_Doc, CDocument)
END_MESSAGE_MAP()


// CWinApp_Doc �R���X�g���N�V����/�f�X�g���N�V����

CWinApp_Doc::CWinApp_Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CWinApp_Doc::~CWinApp_Doc()
{
}

BOOL CWinApp_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CWinApp_Doc �V���A����

void CWinApp_Doc::Serialize(CArchive& ar)
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


// CWinApp_Doc �f�f

#ifdef _DEBUG
void CWinApp_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinApp_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWinApp_Doc �R�}���h
