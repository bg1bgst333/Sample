// ��d�C���N���[�h�h�~
#ifndef __EXCEL__WORKSHEET_H__
#define __EXCEL__WORKSHEET_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Range.h"		// Excel::CRange

// ���O���Excel�̒�`
namespace Excel {

	// ���[�N�V�[�g�N���XCWorksheet�̒�`
	class CWorksheet {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CWorksheet();	// �R���X�g���N�^CWorksheet(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CWorksheet(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)					
			// �f�X�g���N�^
			virtual ~CWorksheet();	// �f�X�g���N�^~CWorksheet
			// �����o�֐�
			CRange * get_Cells();	// Cells�v���p�e�B(Range�I�u�W�F�N�g)�̎擾.
			CRange * get_Cells(int row, int column);	// Cells�v���p�e�B(Range�I�u�W�F�N�g)�̎擾.(row, column��n��.)
			CRange * get_Range(LPCTSTR lpctszCell);	// Range�v���p�e�B�̎擾.
			CRange * get_Range(CRange * range1, CRange * range2);	// Range�v���p�e�B�̎擾.(range1, range2��n��.)

	};

}

#endif