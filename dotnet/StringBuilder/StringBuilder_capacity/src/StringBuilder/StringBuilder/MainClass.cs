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
        StringBuilder sb1 = new StringBuilder(8);   // sb1���R���X�g���N�^��8��n���ď�����.

        // ������Ɨe�ʂ��o��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacity���o��.

        // �������A��.
        sb1.Append("����������");   // sb1.Append��"����������"��A��.

        // ������Ɨe�ʂ��o��.
        Console.WriteLine("-----"); // ��؂�����o��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacity���o��.

        // �������A��.
        sb1.Append("����������");   // sb1.Append��"����������"��A��.

        // ������Ɨe�ʂ��o��.
        Console.WriteLine("-----"); // ��؂�����o��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());    // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);    // sb1.Capacity���o��.
     
    }

}