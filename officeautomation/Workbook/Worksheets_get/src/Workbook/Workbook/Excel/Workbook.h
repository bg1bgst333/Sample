// ��d�C���N���[�h�h�~
#ifndef __EXCEL__WORKBOOK_H__
#define __EXCEL__WORKBOOK_H__

// ���O���Excel�̒�`
namespace Excel {

	// ���[�N�u�b�N�N���XCWorkbook�̒�`
	class CWorkbook {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CWorkbook();	// �R���X�g���N�^CWorkbook(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CWorkbook(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
			// �f�X�g���N�^
			virtual ~CWorkbook();	// �f�X�g���N�^~CWorkbook
			// �����o�֐�
			IDispatch * get_Worksheets();	// Worksheets�I�u�W�F�N�g�v���p�e�B�̎擾.

	};

}

#endif