// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Text;  // �e�L�X�g(System.Text���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̏�����.
        string str = "ABC"; // str1��"ABC"�ŏ�����.
        object object1 = new StringBuilder("ABC");  // object1��new StringBuilder("ABC")�ŏ�����.
        object object2 = "ABD"; // object2��"ABD"�ŏ�����.
        object object3 = "ABC"; // object3��"ABC"�ŏ�����.

        // ��r.
        Console.WriteLine(str.Equals(object1)); // str.Equals��object1�Ɣ�r�������ʂ��o��.
        Console.WriteLine(str.Equals(object2)); // str.Equals��object2�Ɣ�r�������ʂ��o��.
        Console.WriteLine(str.Equals(object3)); // str.Equals��object3�Ɣ�r�������ʂ��o��.

    }

}