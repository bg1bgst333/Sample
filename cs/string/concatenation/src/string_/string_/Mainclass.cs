// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������I�u�W�F�N�g�̐錾.
        string str1;
        
        // �����, 1�����񂲂ƂɘA��.
        str1 = "ABC";
        Console.WriteLine(str1);
        str1 = str1 + "DEF";
        Console.WriteLine(str1);

        // �����̕������A�����đ����A��.
        Console.WriteLine("-----");
        str1 = "ab" + "cd";
        Console.WriteLine(str1);
        str1 = str1 + "ef" + "gh";
        Console.WriteLine(str1);

        // ���������ɘA��.
        Console.WriteLine("-----");
        string str2 = "XXX" + "YYY";
        Console.WriteLine(str2);

    }

}