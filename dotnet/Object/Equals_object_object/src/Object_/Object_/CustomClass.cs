// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �J�X�^���N���X
public class CustomClass    // CustomClass�N���X�̒�`
{
    public int num; // int�^num.
    public CustomClass(int num) // num�����炤�R���X�g���N�^.
    {
        this.num = num; // num���i�[.
    }
    public override bool Equals(object obj) // Equals���I�[�o�[���C�h.
    {
        Console.WriteLine("Equals Start");
        if (obj == null || !(obj is CustomClass))   // null�܂���CustomClass�ł͂Ȃ�.
        {
            Console.WriteLine("Equals End");
            return false;   // false��Ԃ�.
        }
        else   // CustomClass�ł���.
        {
            Console.WriteLine("Equals End");
            return num == ((CustomClass)obj).num;   // �l���r.  
        }
    }
}