// ��d�C���N���[�h�h�~
#ifndef __EXCEL__WORKSHEET_H__
#define __EXCEL__WORKSHEET_H__

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

	};

}

#endif