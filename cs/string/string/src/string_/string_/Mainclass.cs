// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������.
        string strTypeValue1 = "ABC";
        String strClassValue1 = "XYZ";

        // �l�̏o��.
        System.Console.WriteLine("strTypeValue1 = " + strTypeValue1);
        System.Console.WriteLine("strClassValue1 = " + strClassValue1);

        // ���.
        string strTypeValue2 = "LMN";
        String strClassValue2 = "OPQ";
        strTypeValue1 = strTypeValue2;
        strClassValue1 = strClassValue2;

        // �l�̏o��.
        System.Console.WriteLine("strTypeValue1 = " + strTypeValue1);
        System.Console.WriteLine("strClassValue1 = " + strClassValue1);

        // �A��.
        string strTypeRet = strTypeValue1 + "����������";
        string strClassRet = strClassValue1 + "����������";

        // �l�̏o��.
        System.Console.WriteLine("strTypeRet = " + strTypeRet);
        System.Console.WriteLine("strClassRet = " + strClassRet);

    }

}
