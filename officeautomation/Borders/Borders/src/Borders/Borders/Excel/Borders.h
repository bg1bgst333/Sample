// ��d�C���N���[�h�h�~
#ifndef __EXCEL__BORDERS_H__
#define __EXCEL__BORDERS_H__

// ���O���Excel�̒�`
namespace Excel {

	// �r���W���N���XCBorders�̒�`
	class CBorders {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CBorders();	// �R���X�g���N�^CBorders(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CBorders(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)					
			// �f�X�g���N�^
			virtual ~CBorders();	// �f�X�g���N�^~CBorders

	};

}

#endif