// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // "AAA"��"AAB"�̔�r.
        Console.WriteLine(String.Compare("AAA", "AAB"));    // String.Compare��"AAA"��"AAB"�̔�r.

        // "AAB"��"AAB"�̔�r.
        Console.WriteLine(String.Compare("AAB", "AAB"));    // String.Compare��"AAB"��"AAB"�̔�r.

        // "AAC"��"AAB"�̔�r.
        Console.WriteLine(String.Compare("AAC", "AAB"));    // String.Compare��"AAC"��"AAB"�̔�r.

    }

}