// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������.
        string[] strings = new string[] { "aaa", "bbb", "ccc", "ddd" };
        string result = string.Empty;

        // ������", "����؂蕶����ɂ��ĘA��.
        result = String.Join(", ", strings);    // String.Join��", "����؂蕶����ɂ��Ĕz��v�f��A��.
        Console.WriteLine(result);  // result���o��.

    }

}