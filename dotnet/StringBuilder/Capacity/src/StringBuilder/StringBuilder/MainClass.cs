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
        StringBuilder sb2 = new StringBuilder("�����������������������������������Ă�");    // sb2���R���X�g���N�^��"�����������������������������������Ă�"��n���ď�����.

        // ������Ɨe�ʂ��o��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacity���o��.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());    // sb2.ToString()���o��.
        Console.WriteLine("sb2.Capacity = " + sb2.Capacity);    // sb2.Capacity���o��.

        // ���₷.
        sb1.Capacity = 64;  // sb1.Capacity��64�ɑ��₷.
        sb2.Capacity = 128; // sb2.Capacity��128�ɑ��₷.
        Console.WriteLine("-----"); // ��؂�����o��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacity���o��.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());    // sb2.ToString()���o��.
        Console.WriteLine("sb2.Capacity = " + sb2.Capacity);    // sb2.Capacity���o��.

    }

}