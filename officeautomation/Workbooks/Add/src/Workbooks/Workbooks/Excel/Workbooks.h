// ��d�C���N���[�h�h�~
#ifndef __EXCEL__WORKBOOKS_H__
#define __EXCEL__WORKBOOKS_H__

// ���O���Excel�̒�`
namespace Excel {

	// ���[�N�u�b�N�X�N���XCWorkbooks�̒�`
	class CWorkbooks {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CWorkbooks();	// �R���X�g���N�^CWorkbooks(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CWorkbooks(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
			// �f�X�g���N�^
			virtual ~CWorkbooks();	// �f�X�g���N�^~CWorkbooks
			IDispatch * Add();	// Workbook�̒ǉ�.

	};

}

#endif