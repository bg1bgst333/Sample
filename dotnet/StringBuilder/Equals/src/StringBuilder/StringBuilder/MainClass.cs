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
        StringBuilder sb1 = new StringBuilder("ABCDE"); // sb1���R���X�g���N�^��"ABCDE"��n���ď�����.
        StringBuilder sb2 = new StringBuilder("XYZ");   // sb2���R���X�g���N�^��"XYZ"��n���ď�����.

        // �����񂪈Ⴄ�ꍇ.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()���o��.
        Console.WriteLine("sb2.ToString() = " + sb2.ToString());  // sb2.ToString()���o��.
        Console.WriteLine("sb1.Equals(sb2) = " + sb1.Equals(sb2)); // sb1.Equals��sb2�Ɣ�r.

        // sb3�𐶐�.
        StringBuilder sb3 = new StringBuilder("ABC");   // sb3���R���X�g���N�^��"ABC"��n���ď�����.
        
        // �������Ⴄ�ꍇ.
        Console.WriteLine("-----"); // ��؂��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()���o��.
        Console.WriteLine("sb1.Length = " + sb1.Length);  // sb1.Length���o��.
        Console.WriteLine("sb3.ToString() = " + sb3.ToString());  // sb3.ToString()���o��.
        Console.WriteLine("sb3.Length = " + sb3.Length);  // sb3.Length���o��.
        Console.WriteLine("sb1.Equals(sb3) = " + sb1.Equals(sb3)); // sb1.Equals��sb3�Ɣ�r.

        // sb4�𐶐�.
        StringBuilder sb4 = new StringBuilder("ABCDE");   // sb4���R���X�g���N�^��"ABCDE"��n���ď�����.
        sb4.Capacity = 32;  // sb4.Capacity��32�ɂ���.

        // �e�ʂ��Ⴄ�ꍇ.
        Console.WriteLine("-----"); // ��؂��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);  // sb1.Capacity���o��.
        Console.WriteLine("sb4.ToString() = " + sb4.ToString());  // sb4.ToString()���o��.
        Console.WriteLine("sb4.Capacity = " + sb4.Capacity);  // sb4.Capacity���o��.
        Console.WriteLine("sb1.Equals(sb4) = " + sb1.Equals(sb4)); // sb1.Equals��sb4�Ɣ�r.

        // sb5�𐶐�.
        StringBuilder sb5 = new StringBuilder("ABCDE");   // sb5���R���X�g���N�^��"ABCDE"��n���ď�����.
        sb5.Capacity = 16;  // sb5.Capacity��16�ɂ���.

        // ��������������e�ʂ������ꍇ.
        Console.WriteLine("-----"); // ��؂��.
        Console.WriteLine("sb1.ToString() = " + sb1.ToString());  // sb1.ToString()���o��.
        Console.WriteLine("sb1.Length = " + sb1.Length);  // sb1.Length���o��.
        Console.WriteLine("sb1.Capacity = " + sb1.Capacity);  // sb1.Capacity���o��.
        Console.WriteLine("sb5.ToString() = " + sb5.ToString());  // sb5.ToString()���o��.
        Console.WriteLine("sb5.Length = " + sb5.Length);  // sb5.Length���o��.
        Console.WriteLine("sb5.Capacity = " + sb5.Capacity);  // sb5.Capacity���o��.
        Console.WriteLine("sb1.Equals(sb5) = " + sb1.Equals(sb5)); // sb1.Equals��sb5�Ɣ�r.

    }

}