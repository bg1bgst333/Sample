// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // "ABCDE"��"BCD"���܂܂�Ă��邩.
        Console.WriteLine("ABCDE".Contains("BCD"));   // String.Contains��"BCD"���܂܂�Ă��邩.

        // "ABCDE"��"DE"���܂܂�Ă��邩.
        Console.WriteLine("ABCDE".Contains("DE"));   // String.Contains��"DE"���܂܂�Ă��邩.

        // "ABCCE"��"CD"���܂܂�Ă��邩.
        Console.WriteLine("ABCCE".Contains("CD"));   // String.Contains��"CD"���܂܂�Ă��邩.

    }

}