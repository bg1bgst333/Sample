// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �����̏����w��.
        int val0 = 123;
        string val1 = "abc";
        float val2 = 1.23f;
        Console.WriteLine("val0 = {0}, val1 = {1}, val2 = {2}", val0, val1, val2);

        // �����l���Ⴄ������.
        Console.WriteLine("val0(d) = {0:d}, val0(x) = {0:x}, val2(f) = {1:f}, val2(e) = {1:e}", val0, val2);

        // �E�����ƍ�����.
        Console.WriteLine("val0(+) = {0,5:d}", val0);
        Console.WriteLine("val0(-) = {0,-5:d}", val0);

    }

}