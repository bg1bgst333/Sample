// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �ϐ��̏�����.
        int intValue = 123;
        float floatValue = 1.23f;

        // 10�i�����̏����ŕ�����ɕϊ�.
        string strDecValue = intValue.ToString("d");

        // 16�i�����̏����ŕ�����ɕϊ�.
        string strHexValue = intValue.ToString("x");
 
        // �Œ菬���_�̏����ŕ�����ɕϊ�.
        string strFixedPointVal = floatValue.ToString("f");

        // �w���̏����ŕ�����ɕϊ�.
        string strExponentVal = floatValue.ToString("e");

        // �o��.
        Console.WriteLine(strDecValue);
        Console.WriteLine(strHexValue);
        Console.WriteLine(strFixedPointVal);
        Console.WriteLine(strExponentVal);

    }

}