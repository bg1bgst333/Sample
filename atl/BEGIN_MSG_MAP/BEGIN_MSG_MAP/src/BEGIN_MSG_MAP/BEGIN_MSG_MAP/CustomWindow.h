// �J�X�^���E�B���h�E�N���XCCustomWindow�̒�`
class CCustomWindow : public CWindowImpl<CCustomWindow>{	// CWindowImpl<CCustomWindow>�̔h���N���X�Ƃ���, CCustomWindow���`.

	// public�����o
	public:

		// �E�B���h�E�N���X���o�^�}�N��
		DECLARE_WND_CLASS(_T("CCustomWindow"));	// �}�N��DECLARE_WND_CLASS�ŃE�B���h�E�N���X��"CCustomWindow"��o�^.

	// private�����o
	private:

		// ���b�Z�[�}�b�v�}�N��
		BEGIN_MSG_MAP(CCustomWindow)
		END_MSG_MAP()

};