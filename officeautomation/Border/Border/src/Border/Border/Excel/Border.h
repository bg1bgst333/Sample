// ��d�C���N���[�h�h�~
#ifndef __EXCEL__BORDER_H__
#define __EXCEL__BORDER_H__

// ���O���Excel�̒�`
namespace Excel {

	// �r���N���XCBorder��`
	class CBorder {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CBorder();	// �R���X�g���N�^CBorder(new�Ő����s��.)

		// public�����o
		public:

			// public�����o�֐�
			// �R���X�g���N�^
			CBorder(IDispatch *pDispatch);	// �����t���R���X�g���N�^.(IDispatch�|�C���^pDispatch���󂯎��.)					
			// �f�X�g���N�^
			virtual ~CBorder();	// �f�X�g���N�^~CBorder

	};

}

#endif