// _AfxDispatchCmdMsgDoc.cpp : C_AfxDispatchCmdMsgDoc �N���X�̎���
//

#include "stdafx.h"
#include "_AfxDispatchCmdMsg.h"

#include "_AfxDispatchCmdMsgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C_AfxDispatchCmdMsgDoc

IMPLEMENT_DYNCREATE(C_AfxDispatchCmdMsgDoc, CDocument)

BEGIN_MESSAGE_MAP(C_AfxDispatchCmdMsgDoc, CDocument)
END_MESSAGE_MAP()


// C_AfxDispatchCmdMsgDoc �R���X�g���N�V����/�f�X�g���N�V����

C_AfxDispatchCmdMsgDoc::C_AfxDispatchCmdMsgDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

C_AfxDispatchCmdMsgDoc::~C_AfxDispatchCmdMsgDoc()
{
}

BOOL C_AfxDispatchCmdMsgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// C_AfxDispatchCmdMsgDoc �V���A����

void C_AfxDispatchCmdMsgDoc::Serialize(CArchive& ar)
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


// C_AfxDispatchCmdMsgDoc �f�f

#ifdef _DEBUG
void C_AfxDispatchCmdMsgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C_AfxDispatchCmdMsgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C_AfxDispatchCmdMsgDoc �R�}���h
