// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // "ABCDE"��"CDE"�I��肩��r.
        Console.WriteLine("ABCDE".EndsWith("CDE"));   // String.EndsWith��"CDE"�I��肩.

        // "ABCDE"��"BCDE"�I��肩��r.
        Console.WriteLine("ABCDE".EndsWith("BCDE"));   // String.EndsWith��"BCDE"�I��肩.

        // "ABCEE"��"CDE"�I��肩��r.
        Console.WriteLine("ABCEE".EndsWith("CDE"));   // String.EndsWith��"CDE"�I��肩.

    }

}