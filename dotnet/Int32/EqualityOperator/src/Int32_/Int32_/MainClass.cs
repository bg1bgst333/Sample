// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
  
        // �ϐ��̏�����.
        Int32 value1 = 10;  // value1��10�ŏ�����.
        Int32 value2 = 20;  // value2��20�ŏ�����.

        // ==���Z�q�Ŕ�r.
        Console.WriteLine(value1 == value2);    // value1 == value2�̐^�U�l���o��.

        // �l�𓯂��ɂ���.
        value1 = value1 + 20;   // 20������30��.
        value2 = value2 + 10;   // 10������30��.

        // ==���Z�q�Ŕ�r.
        Console.WriteLine(value1 == value2);    // value1 == value2�̐^�U�l���o��.

    }

}