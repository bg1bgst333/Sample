// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Text;  // �e�L�X�g(System.Text���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // StringBuilder�̏�����.
        StringBuilder sb1 = new StringBuilder("����������");    // sb1���R���X�g���N�^��"����������"��n���ď�����.
        StringBuilder sb2 = new StringBuilder("����������");    // sb2���R���X�g���N�^��"����������"��n���ď�����.
        StringBuilder sb3 = sb1;    // sb3��sb1�ŏ�����.

        // sb1��sb2��==���Z�q�Ŕ�r.
        Console.WriteLine(sb1 == sb2);    // sb1 == sb2�̐^�U�l���o��.

        // sb1��sb3��==���Z�q�Ŕ�r.
        Console.WriteLine(sb1 == sb3);    // sb1 == sb3�̐^�U�l���o��.

    }

}