// ��d�C���N���[�h�h�~
#ifndef __EXCEL__APPLICATION_H__
#define __EXCEL__APPLICATION_H__

// ���O���Excel�̒�`
namespace Excel {

	// �A�v���P�[�V�����N���XCApplication�̒�`
	class CApplication {

		// private�����o
		private:

			// private�����o�ϐ�
			IDispatch *m_pDispatch;	// IDispatch�|�C���^m_pDispatch.

			// private�����o�֐�
			// �R���X�g���N�^
			CApplication();	// �R���X�g���N�^CApplication(new�Ő����s��.)


		// public�����o
		public:

			// public�����o�֐�
			// static�����o�֐�
			static CApplication * CreateInstance();	// static�Ȑ����֐�CreateInstance.
			// �f�X�g���N�^
			virtual ~CApplication();	// �f�X�g���N�^~CApplication

	};

}

#endif