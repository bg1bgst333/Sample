// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // "AAA"��"AAB"�̔�r.
        Console.WriteLine("AAA".CompareTo("AAB"));    // String.CompareTo��"AAA"��"AAB"�̔�r.

        // "AAB"��"AAB"�̔�r.
        Console.WriteLine("AAB".CompareTo("AAB"));    // String.CompareTo��"AAB"��"AAB"�̔�r.
        
        // "AAC"��"AAB"�̔�r.
        Console.WriteLine("AAC".CompareTo("AAB"));    // String.CompareTo��"AAC"��"AAB"�̔�r.

    }

}