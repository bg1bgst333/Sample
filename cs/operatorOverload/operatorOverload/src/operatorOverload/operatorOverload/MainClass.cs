// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // CustomPoint�̉��Z.
        CustomPoint a = new CustomPoint(1, 2);
        Console.WriteLine("a.x = " + a.x);
        Console.WriteLine("a.y = " + a.y);
        CustomPoint b = new CustomPoint(2, 3);
        Console.WriteLine("b.x = " + b.x);
        Console.WriteLine("b.y = " + b.y);
        CustomPoint c = a + b;
        Console.WriteLine("c.x = " + c.x);
        Console.WriteLine("c.y = " + c.y);

    }

}