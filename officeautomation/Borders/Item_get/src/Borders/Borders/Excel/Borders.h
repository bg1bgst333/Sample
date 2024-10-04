// ��d�C���N���[�h�h�~
#ifndef __EXCEL__BORDERS_H__
#define __EXCEL__BORDERS_H__

// ���O���Excel�̒�`
namespace Excel {

	// �񋓌^
	// �r���X�^�C��
	enum XlLineStyle {
		xlLineStyleNone = -4142,
		xlDouble = -4119,
		xlDot = -4118,
		xlDash = -4115,
		xlContinuous = 1,
		xlDashDot = 4,
		xlDashDotDot = 5,
		xlSlantDashDot = 13
	};
	// �r������
	enum XlBorderWeight {
		xlMedium = -4138,
		xlHairline = 1,
		xlThin = 2,
		xlThick = 4
	};
	// �r���ʒu
	enum XlBordersIndex {
		xlDiagonalDown = 5,
		xlDiagonalUp = 6,
		xlEdgeLeft = 7,
		xlEdgeTop = 8,
		xlEdgeBottom = 9,
		xlEdgeRight = 10,
		xlInsideVertical = 11,
		xlInsideHorizontal = 12
	};

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
			// �����o�֐�
			BOOL put_LineStyle(XlLineStyle xlLineStyle);	// LineStyle�v���p�e�B�̐ݒ�.
			BOOL put_Weight(XlBorderWeight xlBorderWeight);	// Weight�v���p�e�B�̐ݒ�.
			BOOL put_ColorIndex(int iColorIndex);	// ColorIndex�v���p�e�B�̐ݒ�.
			IDispatch * get_Item(XlBordersIndex xlBordersIndex);	// Item�v���p�e�B�̎擾.

	};

}

#endif