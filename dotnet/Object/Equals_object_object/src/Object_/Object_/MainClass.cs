// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
 
        // ����null.
        Console.WriteLine(Object.Equals(null, null));
        Console.WriteLine(Object.ReferenceEquals(null, null));

        // �C���X�^���X������.
        Console.WriteLine("-----");
        CustomClass c1 = new CustomClass(10);
        CustomClass c2 = c1;
        Console.WriteLine(Object.Equals(c1, c2));
        Console.WriteLine(Object.ReferenceEquals(c1, c2));

        // �C���X�^���X���Ⴄ.
        Console.WriteLine("-----");
        CustomClass c3 = new CustomClass(10);
        CustomClass c4 = new CustomClass(10);
        Console.WriteLine(Object.Equals(c3, c4));
        Console.WriteLine(Object.ReferenceEquals(c3, c4));

        // �l���Ⴄ.
        Console.WriteLine("-----");
        CustomClass c5 = new CustomClass(10);
        CustomClass c6 = new CustomClass(20);
        Console.WriteLine(Object.Equals(c5, c6));
        Console.WriteLine(Object.ReferenceEquals(c5, c6));

    }

}