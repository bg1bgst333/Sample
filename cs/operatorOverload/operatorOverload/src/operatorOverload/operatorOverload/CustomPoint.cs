// �J�X�^���ʒu���W�N���X
class CustomPoint // CustomPoint�N���X�̒�`
{
    // �����o�̒�`.
    public int x;   // �����ʒu���Wx.
    public int y;   // �����ʒu���Wy
    // �R���X�g���N�^
    public CustomPoint(int x, int y)
    {
        // �����������o�ɃZ�b�g.
        this.x = x;
        this.y = y;
    }
    // +���Z�q�̃I�[�o�[���[�h.
    public static CustomPoint operator +(CustomPoint a, CustomPoint b)
    {
        // �e�v�f�𑫂����V�����C���X�^���X��Ԃ�.
        return new CustomPoint(a.x + b.x, a.y + b.y);
    }
}