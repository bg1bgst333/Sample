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

        // ���O��"Jiro"�̒l���n�b�V���`���Ŏ擾���o��.
        Console.WriteLine("col[Jiro] = " + col["Jiro"]);    // col["Jiro"]���o��.

    }

}