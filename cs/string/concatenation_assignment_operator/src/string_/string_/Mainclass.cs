// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ������.
        string[] strings = new string[] { "aaa", "bbb", "ccc" };
        string result = string.Empty;

        // for���[�v
        for (int i = 0; i < 3; i++)
        {

            // �A��������Z�q("+=")�ŘA��.
            result += strings[i];

        }

        // result���o��.
        Console.WriteLine(result);

    }

}