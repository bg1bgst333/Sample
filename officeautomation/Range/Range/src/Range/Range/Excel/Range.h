// ��d�C���N���[�h�h�~
#ifndef __EXCEL__RANGE_H__
#define __EXCEL__RANGE_H__

// ���O���Excel�̒�`
namespace Excel {

	// �����W�N���XCRange�̒�`
	class CRange {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CRange();	// �R���X�g���N�^CRange(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CRange(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)					
			// �f�X�g���N�^
			virtual ~CRange();	// �f�X�g���N�^~CRange

	};

}

#endif