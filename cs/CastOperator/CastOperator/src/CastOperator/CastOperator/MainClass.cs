// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �ÖٓI�ȃL���X�g.
        int intValue1 = 10;
        long longValue1;
        longValue1 = intValue1;
        System.Console.WriteLine("intValue1 = " + intValue1);
        System.Console.WriteLine("longValue1 = " + longValue1);

        // �����I�ȃL���X�g.
        long longValue2 = 20L;
        int intValue2;
        intValue2 = (int)longValue2;
        System.Console.WriteLine("longValue2 = " + longValue2);
        System.Console.WriteLine("intValue2 = " + intValue2);

    }

}
