// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Xml.Serialization; // XML�V���A���C�U(System.Xml.Serialization���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �V���A���C�U�̐���.
        XmlSerializer serializer = new XmlSerializer(typeof(UserInfo)); // UserInfo��XmlSerializer�I�u�W�F�N�gserializer�𐶐�.
        
        // �I�u�W�F�N�g�̐����Ə�����.
        UserInfo userInfo = new UserInfo(); // UserInfo�I�u�W�F�N�g�𐶐�.
        userInfo.name = "Taro";
        userInfo.age = 20;
        userInfo.address = "Tokyo";

        // test.xml�ɃI�u�W�F�N�g���V���A���C�Y.
        using (FileStream fs = new FileStream("test.xml", FileMode.Create)) // FileStream��test.xml���J��.
        {
            serializer.Serialize(fs, userInfo); // serializer.Serialize��fs��userInfo���V���A���C�Y.
        }

    }

}