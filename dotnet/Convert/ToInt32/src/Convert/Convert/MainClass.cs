// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // int��object���o�R����int�ɖ߂�.
        int i = 10;
        int j;
        object o;
        o = i;
        j = (int)o; // �����I�ȃL���X�g���K�v.
        System.Console.WriteLine("i = " + i);
        System.Console.WriteLine("o = " + o);
        System.Console.WriteLine("j = " + j);

        // long��object���o�R����int�ɂ���.
        long k = 20L;
        o = k;
        j = Convert.ToInt32(o); // Convert.ToInt32��object����int�֕ϊ�.
        System.Console.WriteLine("k = " + k);
        System.Console.WriteLine("o = " + o);
        System.Console.WriteLine("j = " + j);

    }

}