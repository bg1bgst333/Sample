// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Text;  // �e�L�X�g(System.Text���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // StringBuilder�̔񓙒l���Z�q.
        StringBuilder sb1 = new StringBuilder("ABC");
        StringBuilder sb2 = new StringBuilder("ABC");
        StringBuilder sb3 = sb1;
        Console.WriteLine(sb1 != sb2);
        Console.WriteLine(sb1 != sb3);

        // String�̔񓙒l���Z�q.
        Console.WriteLine("-----");
        String str1 = "ABC";
        str1 = str1 + "D";
        String str2 = "ABCD";
        String str3 = str1;
        Console.WriteLine(str1 != str2);
        Console.WriteLine(str1 != str3);

    }

}