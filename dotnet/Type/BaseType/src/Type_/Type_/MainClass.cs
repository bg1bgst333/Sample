// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �p�����̌^���擾.
        int i = 10; // i��10�ŏ�����.
        Type tint = i.GetType();    // i��Type���擾.
        Console.WriteLine("tint = " + tint);    // i��Type��tint���o��.
        Type baseType = tint.BaseType;  // tint.BaseType��i�̌p�����̌^�����擾.
        Console.WriteLine("baseType = " + baseType);    // baseType�̏o��.

    }

}