// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
  
        // �ϐ��̏�����.
        int value1 = 10;  // value1��10�ŏ�����.
        int value2 = 20;  // value2��20�ŏ�����.

        // Equals(int)�Ŕ�r.
        Console.WriteLine(value1.Equals(value2));    // value1.Equals(value2)���o��.

        // �l�𓯂��ɂ���.
        value1 = value1 + 20;   // 20������30��.
        value2 = value2 + 10;   // 10������30��.

        // Equals(int)�Ŕ�r.
        Console.WriteLine(value1.Equals(value2));    // value1.Equals(value2)���o��.

        // short�Ɣ�r.
        short value3 = 30;  // value3��30�ŏ�����.

        // Equals(int)��short��n��.
        Console.WriteLine(value1.Equals(value3));    // value1.Equals(value3)���o��.

        // long�Ɣ�r.
        long value4 = 30;  // value4��30�ŏ�����.

        // Equals(int)��long��n��.
        Console.WriteLine(value1.Equals(value4));    // value1.Equals(value4)���o��.

    }

}