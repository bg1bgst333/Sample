// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������.
        string[] strings = new string[] { "aaa", "bbb", "ccc", "ddd" };
        string result = string.Empty;

        // 2�A��.
        result = String.Concat(strings[0], strings[1]); // String.Concat��strings[0], strings[1]��A��.
        Console.WriteLine(result);

        // 3�A��.
        result = String.Concat(strings[0], strings[1], strings[2]); // String.Concat��strings[0], strings[1], strings[2]��A��.
        Console.WriteLine(result);

        // 4�A��.
        result = String.Concat(strings[0], strings[1], strings[2], strings[3]); // String.Concat��strings[0], strings[1], strings[2], strings[3]��A��.
        Console.WriteLine(result);

        // �z��̗v�f�S�ĘA��.
        result = String.Concat(strings);    // String.Concat��strings�̑S�v�f��A��.
        Console.WriteLine(result);

    }

}