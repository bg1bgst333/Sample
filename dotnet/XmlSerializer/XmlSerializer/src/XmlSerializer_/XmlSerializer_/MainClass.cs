// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Xml.Serialization; // XML�V���A���C�U(System.Xml.Serialization���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �V���A���C�U�̐���.
        XmlSerializer serializer = new XmlSerializer(typeof(UserInfo)); // UserInfo��XmlSerializer�I�u�W�F�N�gserializer�𐶐�.
        Console.WriteLine(serializer);  // ���̂܂܏o��.

    }

}