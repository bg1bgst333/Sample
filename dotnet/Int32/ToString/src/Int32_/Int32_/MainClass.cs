// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������𐮐��ɕϊ�.
        Int32 value1 = Int32.Parse("123");   // Int32.Parse��"123"�𐮐��ɕϊ���, value1�Ɋi�[.
        System.Console.WriteLine("value1 = " + value1); // value1���o��.

        // �����𕶎���ɕϊ�.
        string str1 = "abc" + value1.ToString() + "XYZ";    // Int32.ToString()��value1( = 123)�𕶎���ɕϊ���, '+'�őO��̕�����ƘA��.
        System.Console.WriteLine("str1 = " + str1); // str1���o��.

    }

}
