// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Specialized;   // ����ȃR���N�V�����N���X(System.Collections.Specialized���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���O�ƒl�̑g�̃R���N�V����.
        NameValueCollection col = new NameValueCollection();

        // �ǉ�
        col.Add("Taro", "Tokyo");
        col.Add("Jiro", "Osaka");
        col.Add("Saburo", "Nagoya");

        // �擾
        for (int i = 0; i < col.Count; i++)
        {
            Console.WriteLine(i + ":" + col.GetKey(i) + " = " + col.Get(i));
        }

    }

}