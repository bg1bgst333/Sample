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
        string str2;

        // �����񃊃e�����̑��.
        str1 = "ABC";

        // �ϐ�����ϐ��ւ̑��.
        str2 = str1;

        // �o��.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // ����C���X�^���X������.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEquals��str1��str2������C���X�^���X�����肵�����ʂ��o��.

        // �l������������.
        Console.WriteLine(str1 == str2);

        // str1�ɈႤ���������.
        str1 = "XYZ";

        // �o��.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // ����C���X�^���X������.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEquals��str1��str2������C���X�^���X�����肵�����ʂ��o��.

        // �l������������.
        Console.WriteLine(str1 == str2);

        // str1��str2�œ���������ł��������Ⴄ�ꍇ.
        str1 = "ABCD";  // str1��"ABCD"����.
        str2 = str2 + "D";  // str2("ABC")��"D"��A��.

        // �o��.
        Console.WriteLine("str1 = " + str1);
        Console.WriteLine("str2 = " + str2);

        // ����C���X�^���X������.
        Console.WriteLine(Object.ReferenceEquals(str1, str2));  // Object.ReferenceEquals��str1��str2������C���X�^���X�����肵�����ʂ��o��.

        // �l������������.
        Console.WriteLine(str1 == str2);

    }

}