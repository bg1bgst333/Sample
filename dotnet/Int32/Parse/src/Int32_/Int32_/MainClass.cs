// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������𐮐��ɕϊ�.
        int value1 = Int32.Parse("123");   // Int32.Parse��"123"�𐮐��ɕϊ���, value1�Ɋi�[.
        System.Console.WriteLine("value1 = " + value1); // value1���o��.

        // �}�C�i�X�̏ꍇ.
        int value2 = Int32.Parse("-123");   // Int32.Parse��"-123"�𐮐��ɕϊ���, value2�Ɋi�[.
        System.Console.WriteLine("value2 = " + value2); // value2���o��.

    }

}
