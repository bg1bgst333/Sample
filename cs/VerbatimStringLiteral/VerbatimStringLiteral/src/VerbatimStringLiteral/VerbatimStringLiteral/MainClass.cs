// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // '\'�̒���I�����񃊃e�����̗�.
        string str1a = "C:\\Path\\To\\File.txt";    // �ʏ핶���񃊃e����.
        string str1b = @"C:\Path\To\File.txt";  // ����I�����񃊃e����.
        Console.WriteLine(str1a);   // str1a�̏o��.
        Console.WriteLine(str1b);   // str1b�̏o��.

        // Unicode�̒���I�����񃊃e�����̗�.
        string str2a = "\u0061";    // �ʏ핶���񃊃e����.
        string str2b = @"\u0061";   // ����I�����񃊃e����.
        Console.WriteLine(str2a);   // str2a�̏o��.
        Console.WriteLine(str2b);   // str2b�̏o��.

    }

}
