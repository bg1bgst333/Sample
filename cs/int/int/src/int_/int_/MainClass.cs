// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // int�����Int32��2147483647�܂œ���.
        int intValue = 2147483647;
        Int32 i32Value = 2147483647;

        // �l�̏o��.
        System.Console.WriteLine("intValue = " + intValue);
        System.Console.WriteLine("i32Value = " + i32Value);

        // ����𒴂����...
        intValue += 1;
        i32Value += 1;

        // �l�̏o��.
        System.Console.WriteLine("intValue = " + intValue);
        System.Console.WriteLine("i32Value = " + i32Value);

    }

}
