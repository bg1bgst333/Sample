// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // long�����Int64��9223372036854775807�܂œ���.
        long longValue = 9223372036854775807;
        Int64 i64Value = 9223372036854775807;

        // �l�̏o��.
        System.Console.WriteLine("longValue = " + longValue);
        System.Console.WriteLine("i64Value = " + i64Value);

        // ����𒴂����...
        longValue += 1;
        i64Value += 1;

        // �l�̏o��.
        System.Console.WriteLine("longValue = " + longValue);
        System.Console.WriteLine("i64Value = " + i64Value);

    }

}
