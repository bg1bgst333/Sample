// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
  
        // �ϐ��̏�����.
        int value1 = 30;  // value1��30�ŏ�����.
        int value2 = 30;  // value2��30�ŏ�����.

        // value2��object�ɕϊ�.
        object value3 = value2; // object��value3��value2����.

        // Equals(object)��object(int)��n��.
        Console.WriteLine(value1.Equals(value3));    // value1.Equals(value3)���o��.

        // short�������ꍇ.
        short value4 = 30;  // value4��30�ŏ�����.

        // value4��object�ɕϊ�.
        object value5 = value4; // object��value5��value4����.

        // Equals(object)��object(short)��n��.
        Console.WriteLine(value1.Equals(value5));    // value1.Equals(value5)���o��.

        // long�������ꍇ.
        long value6 = 30;  // value6��30�ŏ�����.

        // value6��object�ɕϊ�.
        object value7 = value6; // object��value7��value6����.

        // Equals(object)��object(long)��n��.
        Console.WriteLine(value1.Equals(value7));    // value1.Equals(value7)���o��.

    }

}