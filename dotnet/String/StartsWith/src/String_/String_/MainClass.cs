// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // "ABCDE"��"ABC"�n�܂肩��r.
        Console.WriteLine("ABCDE".StartsWith("ABC"));   // String.StartsWith��"ABC"�n�܂肩.

        // "ABCDE"��"ABCD"�n�܂肩��r.
        Console.WriteLine("ABCDE".StartsWith("ABCD"));   // String.StartsWith��"ABCD"�n�܂肩.

        // "ABDDE"��"ABC"�n�܂肩��r.
        Console.WriteLine("ABDDE".StartsWith("ABC"));   // String.StartsWith��"ABC"�n�܂肩.

    }

}