// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // char�����Char��0xffff(65535)�܂œ���.
        char charValue = (char)0xffff;
        Char charStructValue = (Char)0xffff;

        // �l�̏o��.
        System.Console.WriteLine("charValue = " + charValue);
        System.Console.WriteLine("charStructValue = " + charStructValue);
        System.Console.WriteLine("charValue(int) = " + (int)charValue);
        System.Console.WriteLine("charStructValue(Int32) = " + (Int32)charStructValue);

        // ����𒴂����...
        charValue = (char)((int)charValue + 1);
        charStructValue = (Char)((Int32)charStructValue + 1);

        // �l�̏o��.
        System.Console.WriteLine("charValue = " + charValue);
        System.Console.WriteLine("charStructValue = " + charStructValue);
        System.Console.WriteLine("charValue(int) = " + (int)charValue);
        System.Console.WriteLine("charStructValue(Int32) = " + (Int32)charStructValue);


    }

}
