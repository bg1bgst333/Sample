// ��d�C���N���[�h�h�~
#ifndef __EXCEL__WORKSHEETS_H__
#define __EXCEL__WORKSHEETS_H__

// ���O���Excel�̒�`
namespace Excel {

	// ���[�N�V�[�c�N���XCWorksheets�̒�`
	class CWorksheets {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CWorksheets();	// �R���X�g���N�^CWorksheets(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CWorksheets(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)
			// �f�X�g���N�^
			virtual ~CWorksheets();	// �f�X�g���N�^~CWorksheets
			IDispatch * Add();	// Worksheet�̒ǉ�.

	};

}

#endif